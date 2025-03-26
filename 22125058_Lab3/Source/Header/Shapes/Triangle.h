#ifndef TRIANGLE
#define TRIANGLE

#include "../Shape.h"
#include <GL/glut.h>

class Triangle : public Shape {
private:
	float x2, y2, x3, y3;
	void drawLine(int x1, int y1, int x2, int y2);
public:
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void draw() override;
	void scale(float x, float y) override;
	void rotate(float angle) override;
	void translate(float x, float y) override;
	std::string getName() override { return "Triangle"; }

};

#endif // !TRIANGLE
