#include "../Header/Shape.h"

Shape::Shape(int type, int x1, int y1) {
	this->type = type;
	this->x1 = x1;
	this->y1 = y1;
}

Shape::~Shape() {
}

int Shape::getType() {
	return type;
}