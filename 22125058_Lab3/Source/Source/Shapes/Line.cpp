#include "../../Header/Shapes/Line.h"
#include <cmath>
#include <utility>
#include <iostream>

// Constructor
Line::Line(float x1, float y1, float x2, float y2) : Shape(0, x1, y1) {
	this->x2 = x2;
	this->y2 = y2;
	
	//Calculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}

// Draw the line
void Line::draw() {
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

void Line::scale(float Sx, float Sy) {
	x1 = x1 * Sx + xf * (1 - Sx);
	y1 = y1 * Sy + yf * (1 - Sy);
	x2 = x2 * Sx + xf * (1 - Sx);
	y2 = y2 * Sy + yf * (1 - Sy);
	// Recalculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
	std::cout << "Line scaled" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
}

void Line::rotate(float angle) {
	// Move the line to the origin
	float x1New = x1 - xf;
	float y1New = y1 - yf;
	float x2New = x2 - xf;
	float y2New = y2 - yf;
	// Rotate the line
	x1New = x1New * cos(angle) - y1New * sin(angle);
	y1New = x1New * sin(angle) + y1New * cos(angle);
	x2New = x2New * cos(angle) - y2New * sin(angle);
	y2New = x2New * sin(angle) + y2New * cos(angle);
	// Move the line back to its original position
	x1 = x1New + xf;
	y1 = y1New + yf;
	// Recalculate the focus point
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
}

void Line::translate(float x, float y) {
	x1 += x;
	y1 += y;
	x2 += x;
	y2 += y;
	xf = (x1 + x2) / 2.0;
	yf = (y1 + y2) / 2.0;
	std::cout << "Line translated" << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
}