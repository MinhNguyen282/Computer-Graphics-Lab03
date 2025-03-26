#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <vector>
#include "Matrix.h"

class Transformation {
public:
	static Matrix scaling(const Matrix &value, const Matrix &fixed, const Matrix &scaleFactor);
};

#endif // !TRANSFORMATION_H
