#include "../../Header/Shapes/Rectangle.h"
#include <cmath>

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Shape(2, x1, y1), x2(x2), y2(y2) {
	// Two other coordinates
	x3 = x1;
	y3 = y2;
	x4 = x2;
	y4 = y1;
	// Calculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}

void Rectangle::drawLine(float x1, float y1, float x2, float y2) {
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

void Rectangle::draw() {
	drawLine(x1, y1, x3, y3);
	drawLine(x3, y3, x2, y2);
	drawLine(x2, y2, x4, y4);
	drawLine(x4, y4, x1, y1);
}

void Rectangle::scale(float Sx, float Sy) {
	// Calculate the new coordinates
	x1 = x1 * Sx + xf * (1 - Sx);
	y1 = y1 * Sy + yf * (1 - Sy);
	x2 = x2 * Sx + xf * (1 - Sx);
	y2 = y2 * Sy + yf * (1 - Sy);
	x3 = x3 * Sx + xf * (1 - Sx);
	y3 = y3 * Sy + yf * (1 - Sy);
	x4 = x4 * Sx + xf * (1 - Sx);
	y4 = y4 * Sy + yf * (1 - Sy);
	// Recalculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}

void Rectangle::translate(float x, float y) {
	x1 += x;
	y1 += y;
	x2 += x;
	y2 += y;
	x3 += x;
	y3 += y;
	x4 += x;
	y4 += y;
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}

void Rectangle::rotate(float angle) {
	// Move the rectangle to the origin
	float x1New = x1 - xf;
	float y1New = y1 - yf;
	float x2New = x2 - xf;
	float y2New = y2 - yf;
	float x3New = x3 - xf;
	float y3New = y3 - yf;
	float x4New = x4 - xf;
	float y4New = y4 - yf;
	// Rotate the rectangle
	x1New = x1New * cos(angle) - y1New * sin(angle);
	y1New = x1New * sin(angle) + y1New * cos(angle);

	x2New = x2New * cos(angle) - y2New * sin(angle);
	y2New = x2New * sin(angle) + y2New * cos(angle);

	x3New = x3New * cos(angle) - y3New * sin(angle);
	y3New = x3New * sin(angle) + y3New * cos(angle);

	x4New = x4New * cos(angle) - y4New * sin(angle);
	y4New = x4New * sin(angle) + y4New * cos(angle);
	// Move the rectangle back
	x1 = x1New + xf;
	y1 = y1New + yf;
	x2 = x2New + xf;
	y2 = y2New + yf;
	x3 = x3New + xf;
	y3 = y3New + yf;
	x4 = x4New + xf;
	y4 = y4New + yf;
	// Recalculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}