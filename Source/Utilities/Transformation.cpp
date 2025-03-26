#include "../../Header/Utilities/Transformation.h"

Matrix Transformation::scaling(const Matrix& value, const Matrix& fixed, const Matrix& scaleFactor) {
	Matrix scaleA(value);
	for (int i = 0; i < value.getRows(); i++) {
		for (int j = 0; j < scaleFactor.getCols(); j++) {
			for (int k = 0; k < value.getCols(); k++) {
				scaleA.set(i, j, value.get(i, k) * scaleFactor.get(k, j));
			}
		}
	}
	Matrix scaleB(fixed);
	for (int i = 0; i < fixed.getRows(); i++) {
		for (int j = 0; j < scaleFactor.getCols(); j++) {
			for (int k = 0; k < fixed.getCols(); k++) {
				scaleB.set(i, j, fixed.get(i, k) * scaleFactor.get(k, j));
			}
		}
	}
	Matrix result(scaleA.getRows(), scaleA.getCols());
	for (int i = 0; i < scaleA.getRows(); i++) {
		for (int j = 0; j < scaleA.getCols(); j++) {
			result.set(i, j, scaleA.get(i, j) + scaleB.get(i, j));
		}
	}
	return result;
}