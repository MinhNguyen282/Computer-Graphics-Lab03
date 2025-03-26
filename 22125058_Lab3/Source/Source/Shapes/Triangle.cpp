#include "../../Header/Shapes/Triangle.h"
#include <cmath>
#include <utility>

// Constructor
Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) : Shape(1, x1, y1), x2(x2), y2(y2), x3(x3), y3(y3) {
	// Calculate the focus point
	xf = (x1 + x2 + x3) / 3.0;
	yf = (y1 + y2 + y3) / 3.0;
}

// Draw the triangle
void Triangle::draw() {
	drawLine(x1, y1, x2, y2);
	drawLine(x2, y2, x3, y3);
	drawLine(x3, y3, x1, y1);
}

void Triangle::drawLine(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	// Determine the sign of the direction
	int signX = x1 < x2 ? 1 : -1;
	int signY = y1 < y2 ? 1 : -1;

	int x = x1;
	int y = y1;

	int err;
	bool steep = false;

	if (dy > dx) {
		std::swap(dx, dy);
		steep = true;
	}

	err = 2 * dy - dx;

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	for (int i = 0; i <= dx; i++) {
		glVertex2i(x, y);
		while (err >= 0) {
			if (steep) x += signX;
			else y += signY;
			err -= 2 * dx;
		}
		if (steep) y += signY;
		else x += signX;
		err += 2 * dy;
	}
	glEnd();
}

// Scale the triangle
void Triangle::scale(float x, float y) {
	//TODO
	x1 = x1 * x + xf * (1 - x);
	y1 = y1 * y + yf * (1 - y);

	x2 = x2 * x + xf * (1 - x);
	y2 = y2 * y + yf * (1 - y);

	x3 = x3 * x + xf * (1 - x);
	y3 = y3 * y + yf * (1 - y);

	// Recalculate the focus point
	xf = (x1 + x2 + x3) / 3.0;
	yf = (y1 + y2 + y3) / 3.0;
}

// Rotate the triangle
void Triangle::rotate(float angle) {
	// Move the triangle to the origin
	float x1New = x1 - xf;
	float y1New = y1 - yf;
	float x2New = x2 - xf;
	float y2New = y2 - yf;
	float x3New = x3 - xf;
	float y3New = y3 - yf;
	// Rotate the triangle
	x1New = x1New * cos(angle) - y1New * sin(angle);
	y1New = x1New * sin(angle) + y1New * cos(angle);

	x2New = x2New * cos(angle) - y2New * sin(angle);
	y2New = x2New * sin(angle) + y2New * cos(angle);

	x3New = x3New * cos(angle) - y3New * sin(angle);
	y3New = x3New * sin(angle) + y3New * cos(angle);
	// Move the triangle back to its original position
	x1 = x1New + xf;
	y1 = y1New + yf;
	x2 = x2New + xf;
	y2 = y2New + yf;
	x3 = x3New + xf;
	y3 = y3New + yf;

	// Recalculate the focus point
	xf = (x1 + x2 + x3) / 3.0;
	yf = (y1 + y2 + y3) / 3.0;
}

// Translate the triangle
void Triangle::translate(float x, float y) {
	x1 += x;
	y1 += y;
	x2 += x;
	y2 += y;
	x3 += x;
	y3 += y;
	// Move the focus point
	xf = (x1 + x2 + x3) / 3.0;
	yf = (y1 + y2 + y3) / 3.0;
}