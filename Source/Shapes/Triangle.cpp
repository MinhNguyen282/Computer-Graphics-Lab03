#include "../../Header/Shapes/Triangle.h"
#include <cmath>
#include <utility>

// Constructor
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(1, x1, y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

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
	glColor3f(1.0, 0.0, 0.0);
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