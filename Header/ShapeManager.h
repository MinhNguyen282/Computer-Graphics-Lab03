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
	std::vector<std::string> getShapeNames() const;
	void drawAll();
	void scale(int index, float x, float y);
	void translate(int index, float x, float y);
	void rotate(int index, float angle);
	void addShape(std::unique_ptr<Shape> shape);
	void removeShape(int index);
	void clearShapes();
};

#endif // !SHAPEMANAGER_H
