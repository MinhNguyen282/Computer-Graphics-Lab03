#ifndef TRIANGLE
#define TRIANGLE

#include "../Shape.h"
#include <GL/glut.h>

class Triangle : public Shape {
private:
	int x2, y2, x3, y3;
	void drawLine(int x1, int y1, int x2, int y2);
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	void draw() override;
};

#endif // !TRIANGLE
