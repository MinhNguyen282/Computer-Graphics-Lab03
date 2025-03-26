#include "../Header/Shape.h"

Shape::Shape(int type, float x1, float y1) {
	this->type = type;
	this->x1 = x1;
	this->y1 = y1;

	r = 1.0f;
	g = 0.0f;
	b = 0.0f;
}

Shape::~Shape() {
}

int Shape::getType() {
	return type;
}