#include "../../Header/Shapes/Circle.h"
#include <cmath>

Circle::Circle(float x1, float y1, float r) : Shape(1, x1, y1), radius(r) {
	// Calculate the focus point
	xf = x1;
	yf = y1;
}

void Circle::draw() {
	int x = radius, y = 0;
	int p = 1 - radius;
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	while (x > y) {
		y++;
		if (p <= 0) p += 2 * y + 1;
		else {
			x--;
			p += 2 * (y - x) + 1;
		}
		if (x < y) break;
		glVertex2i(xf + x, yf + y);
		glVertex2i(xf - x, yf + y);
		glVertex2i(xf + x, yf - y);
		glVertex2i(xf - x, yf - y);
		if (x != y) {
			glVertex2i(xf + y, yf + x);
			glVertex2i(xf - y, yf + x);
			glVertex2i(xf + y, yf - x);
			glVertex2i(xf - y, yf - x);
		}
	}
	glEnd();
}

void Circle::scale(float Sx, float Sy) {
	radius *= Sx;
}

void Circle::rotate(float angle) {
	// Do nothing
}

void Circle::translate(float x, float y) {
	xf += x;
	yf += y;
}