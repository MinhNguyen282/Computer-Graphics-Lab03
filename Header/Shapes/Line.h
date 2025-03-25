#ifndef LINE_H
#define LINE_H

#include "../Shape.h"
#include <GL/glut.h>

class Line : public Shape {
private:
	int x2, y2;
public:
	Line(int x1, int y1, int x2, int y2);
	void draw() override;
};

#endif // !LINE_H
