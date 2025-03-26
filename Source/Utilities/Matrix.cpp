#include "../../Header/Utilities/Matrix.h"

Matrix::Matrix(int rows, int cols) {
	data.resize(rows);
	for (int i = 0; i < rows; i++) {
		data[i].resize(cols);
	}
}

Matrix::Matrix(const Matrix& other) {
	data = other.data;
}

Matrix& Matrix::operator =(const Matrix& other) {
	data = other.data;
	return *this;
}

void Matrix::set(int row, int col, int value) {
	data[row][col] = value;
}

int Matrix::get(int row, int col) const {
	return data[row][col];
}