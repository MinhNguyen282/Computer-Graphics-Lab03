#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	void set(int row, int col, int value);
	int get(int row, int col) const;
	int getRows() const { return data.size(); }
	int getCols() const { return data[0].size(); }
private:
	std::vector<std::vector<float>> data;
};

#endif // !MATRIX_H
