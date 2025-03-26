#ifndef LINE_H
#define LINE_H

#include "../Shape.h"
#include <GL/glut.h>

class Line : public Shape {
private:
	float x2, y2;
public:
	Line(float x1, float y1, float x2, float y2);
	void draw() override;
	void scale(float x, float y) override;
	void rotate(float angle) override;
	void translate(float x, float y) override;
	std::string getName() override { return "Line"; }
};

#endif // !LINE_H
