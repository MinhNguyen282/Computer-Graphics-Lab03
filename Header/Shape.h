#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glut.h>

class Shape {
protected:
	int type; //Type of this shape
	int x1, y1; //Starting point of this shape
public:
	Shape(int type, int x1, int y1);
	virtual void draw() = 0;
	virtual ~Shape();
	int getType();
};

#endif // !SHAPE_H
