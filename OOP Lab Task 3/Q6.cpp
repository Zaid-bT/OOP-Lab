#include<iostream>
#include<vector>
using namespace std;



class Matrix{
	int row, col;
    vector<vector<int> > matrix;
	
	public:
		Matrix(int row,int col){
			this->row=row;
			this->col=col;
    		for (int i = 0; i < row; i++) {
        		for (int j = 0; j < col; j++) {
        			cout << "Enter element:";
            		cin >> matrix[i][j];
        		}
    		}
		}
		
		int getRow(){
			return row;
		}
		int getColumn(){
			return col;
		}
		
		void setElement(int i,int j){
			cout<<"Enter new element: ";
            cin>>matrix[i][j];
		}
		
		void addMatrix(const Matrix& other) {
        	if (this->row != other.row || this->col != other.col) {
            	cout << "Matrices cannot be added" << endl;
            	return; 
        	}
			for (int i = 0; i < row; ++i) {
            	for (int j = 0; j < col; ++j) {
                	this->matrix[i][j] += other.matrix[i][j];
            	}
        	}	
    	}
    	
    	void multiplyMatrix(const Matrix& other) {
        	if (this->col != other.row) {
            	cout << "Matrices cannot be multiplied"<<endl;
            	return; 
        	}
        	Matrix result(this->row, other.col); //create a resultant matrix for the product
        	for (int i = 0; i < this->row; ++i) {
            	for (int j = 0; j < other.col; ++j) {
                	for (int k = 0; k < this->col; ++k) {
                    	result.matrix[i][j] += this->matrix[i][k]*other.matrix[k][j];
                	}
            	}
        	}
		}
		
		void display(){
	   		for (int i = 0; i < row; i++) {
        		for (int j = 0; j <col; j++) {
        			cout << matrix[i][j]<<" ";
        		}cout<<endl;
    		}
		}
		
};



int main(int argc, char* argv[]){
	int row1 = 3, col1 = 3, row2 = 3, col2 = 3;
    Matrix mat1(row1, col1);  
    Matrix mat2(row2, col2);  

    cout << "Matrix 1: " << endl;
    mat1.display();
    cout << "Matrix 2: " << endl;
    mat2.display();

    cout << "Matrix 1 has " << mat1.getRow() << " rows and " << mat1.getColumn() << " columns." << endl;
    cout << "Matrix 2 has " << mat2.getRow() << " rows and " << mat2.getColumn() << " columns." << endl;

    int i = 1, j = 1;
    cout << "Changing element at position (" << i + 1 << ", " << j + 1 << ") in Matrix 1." << endl;
    mat1.setElement(i, j);

    cout << "Matrix 1 after modification: " << endl;
    mat1.display();

    mat1.addMatrix(mat2);
    cout << "Matrix 1 after addition with Matrix 2: " << endl;
    mat1.display();

    mat1.multiplyMatrix(mat2);

    return 0;
}
	
	
	

