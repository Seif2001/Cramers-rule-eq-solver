#include <iostream>
#include <string>
#include <cmath>
//#include<boost/python.hpp>
using namespace std;

void deepCopy(double** arr1, double** arr2, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
double** alocMatrix(int n) {
	double** m = new double* [n];
	for (int i = 0; i < n; ++i) m[i] = new double[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
		}
	}

	return m;
}
void printMatrix(double** m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
double get_detertminent(double** matrix, int size) {
	//printMatrix(matrix, size);
	if (size == 2) {
		double deter = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		//cout << deter << endl;
		return deter;
	}
	else {
		double sum = 0;
		for (int i = 0; i < size; i++) {
			double* coeff = new double[size];
			if (i % 2 == 1) {
				coeff[i] = -1.0 * matrix[0][i];
			}
			else {
				coeff[i] = matrix[0][i];
			}
			double** mat = alocMatrix(size - 1);
			int a = 0;
			int b = 0;
			for (int x = 1; x < size; x++) {

				for (int y = 0; y < size; y++) {

					if (y != i && x != 0) {
						mat[a][b] = matrix[x][y];
						b++;
						//cout << a;
						if (b > size - 2) {
							a++;
							b = 0;

						}

					}
					//cout << mat[a][b];

				}
			}
			//cout << mat[1][1];
			//printMatrix(mat, size-1);

			sum += coeff[i] * get_detertminent(mat, size - 1);

		}
		return sum;
	}

}


int main() {
	int n;
	double element, constant;
	do {
		cout << "Please enter the number of rows and columns of the matrix: ";
		cin >> n;
	} while (n <= 0);
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
	double* consMat = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Please enter row " << i + 1 << " elements:" << endl;
		for (int j = 0; j < n; j++) {
			cin >> element;

			matrix[i][j] = element;

		}
		cout << "Enter " << i + 1 << "constant: " << endl;
		cin >> constant;
		consMat[i] = constant;
	}

	//printMatrix(matrix, n);

	double dElkebeera = get_detertminent(matrix, n);
	if (dElkebeera == 0) {
		cout << "Matrix is singular" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			double** augMat = alocMatrix(n);
			deepCopy(augMat, matrix, n);
			for (int j = 0; j < n; j++) {
				augMat[j][i] = consMat[j];
			}
			//printMatrix(augMat, n);
			double D = get_detertminent(augMat, n) / dElkebeera;

			cout << "Unkown Variable " << i + 1 << " = " << D << endl;
		}
	}
}