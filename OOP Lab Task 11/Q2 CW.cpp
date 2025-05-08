#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;



class DimensionMismatchException : public exception{
    const char* what() const noexcept override {
        return "Matrix dimensions do not match";
    }
};

template<typename T>
class Matrix{
    vector<vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, vector<T>(c)) {}
    T& at(size_t r, size_t c){
        if(r >= rows || c >= cols) throw out_of_range("Index out of bounds");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const{
        if(r >= rows || c >= cols) throw out_of_range("Index out of bounds");
        return data[r][c];
    }

    size_t rowCount() const { return rows; }
    size_t colCount() const { return cols; }

    Matrix<T> operator+(const Matrix<T>& other) const{
        if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
        Matrix<T> result(rows, cols);
        for(size_t i = 0; i < rows; ++i)
            for(size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const{
        if (cols != other.rows) throw DimensionMismatchException();
        Matrix<T> result(rows, other.cols);
        for(size_t i = 0; i < rows; ++i)
            for(size_t j = 0; j < other.cols; ++j)
                for(size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }
};

int main(){
    try{
        Matrix<int> a(2, 2);
        Matrix<int> b(2, 2);
        a.at(0, 0) = 1; a.at(0, 1) = 2;
        a.at(1, 0) = 3; a.at(1, 1) = 4;

        b.at(0, 0) = 5; b.at(0, 1) = 6;
        b.at(1, 0) = 7; b.at(1, 1) = 8;

        Matrix<int> sum = a + b;
        Matrix<int> product = a * b;

        for(size_t i = 0; i < sum.rowCount(); ++i) {
            for(size_t j = 0; j < sum.colCount(); ++j)
                cout << sum.at(i, j) << " ";
            cout << endl;
        }

        cout << endl;

        for(size_t i = 0; i < product.rowCount(); ++i) {
            for(size_t j = 0; j < product.colCount(); ++j)
                cout << product.at(i, j) << " ";
            cout << endl;
        }

    }catch(const exception& e) {
        cerr << e.what() << endl;
    }



    return 0;
}

