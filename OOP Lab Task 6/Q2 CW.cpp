#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    int size;
public:
    MediaFile(const string& path, int s) : filePath(path), size(s) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;
public:
    VisualMedia(const string& path, int s, const string& res) : MediaFile(path, s), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(const string& path, int s, int rate) : MediaFile(path, s), sampleRate(rate) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(const string& path, int s, const string& res, int rate)
        : MediaFile(path, s), VisualMedia(path, s, res), AudioMedia(path, s, rate) {}

    void play() override {
        cout << "Playing video: " << filePath << ", resolution: " << resolution << ", sampleRate: " << sampleRate << endl;
    }

    void stop() override {
        cout << "Stopping video: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(const string& path, int s, const string& res)
        : MediaFile(path, s), VisualMedia(path, s, res) {}

    void play() override {
        cout << "Displaying image: " << filePath << ", resolution: " << resolution << endl;
    }

    void stop() override {
        cout << "Hiding image: " << filePath << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(const string& path, int s, int rate)
        : MediaFile(path, s), AudioMedia(path, s, rate) {}

    void play() override {
        cout << "Playing audio: " << filePath << ", sampleRate: " << sampleRate << endl;
    }

    void stop() override {
        cout << "Stopping audio: " << filePath << endl;
    }
};

int main() {
    MediaFile* media[3];

    media[0] = new VideoFile("video.mp4", 1024, "1920x1080", 44100);
    media[1] = new ImageFile("photo.jpg", 500, "1280x720");
    media[2] = new AudioFile("song.mp3", 300, 44100);

    for (int i = 0; i < 3; i++) {
        media[i]->play();
        media[i]->stop();
        delete media[i];
    }

    return 0;
}

