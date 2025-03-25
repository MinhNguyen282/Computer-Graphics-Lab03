#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include <vector>
#include <memory>

class ShapeFactory {
public:
	enum ShapeType
	{
		line = 0,
		triangle = 1,
		rectangle = 2,
		circle = 3
	};
	static std::unique_ptr<Shape> createShape(ShapeType shapeType, const std::vector<int> &params);
	static std::unique_ptr<Shape> createShape(int type, const std::vector<int> &params);
private:
	static bool validateType(ShapeType shapeType, const std::vector<int> &params);
};

#endif // !SHAPEFACTORY_H
