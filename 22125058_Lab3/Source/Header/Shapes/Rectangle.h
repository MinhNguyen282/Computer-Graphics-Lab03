#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Shape.h"
#include <GL/glut.h>

class Rectangle : public Shape {
public:
	Rectangle(int x1, int y1, int x2, int y2);
	void draw() override;
	void scale(float x, float y) override;
	void rotate(float angle) override;
	void translate(float x, float y) override;
	std::string getName() override { return "Rectangle"; }
private:
	float x2, y2, x3, y3, x4, y4;
	void drawLine(float x1, float y1, float x2, float y2);
};

#endif // !RECTANGLE_H
