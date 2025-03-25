#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <vector>
#include "Shape.h"
#include <string>
#include <memory>

class ShapeManager {
private:
	std::vector<std::unique_ptr<Shape>> shapes;
public:
	void drawAll();
	void addShape(std::unique_ptr<Shape> shape);
	void removeShape(int index);
	void clearShapes();
};

#endif // !SHAPEMANAGER_H
