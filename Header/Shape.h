#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glut.h>
#include <string>

class Shape {
protected:
	int type; //Type of this shape
	float x1, y1; //Starting point of this shape
	float xf, yf; //Focus point of this shape
public:
	Shape(int type, float x1, float y1);
	virtual void draw() = 0;
	virtual void scale(float x, float y) = 0;
	virtual void rotate(float angle) = 0;
	virtual void translate(float x, float y) = 0;
	virtual std::string getName() = 0;
	virtual ~Shape();
	int getType();
};

#endif // !SHAPE_H
