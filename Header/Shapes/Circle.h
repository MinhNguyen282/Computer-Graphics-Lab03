#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Shape.h"
#include <GL/glut.h>

class Circle : public Shape {
private:
	float radius;
public:
	Circle(float x, float y, float r);
	void draw() override;
	void scale(float x, float y) override;
	void rotate(float angle) override;
	void translate(float x, float y) override;
	std::string getName() override { return "Circle"; }
};

#endif // !CIRCLE_H
