#include "../Header/ShapeFactory.h"
#include "../Header/Shapes/Triangle.h"
#include "../Header/Shapes/Line.h"
#include "../Header/Shapes/Rectangle.h"
#include "../Header/Shapes/Circle.h"


std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType shapeType, const std::vector<int>& params) {
	if (validateType(shapeType, params)) {
		switch (shapeType) {
			case line:
				return std::make_unique<Line>(params[0], params[1], params[2], params[3]);
			case triangle:
				return std::make_unique<Triangle>(params[0], params[1], params[2], params[3], params[4], params[5]);
			case rectangle:
				return std::make_unique<Rectangle>(params[0], params[1], params[2], params[3]);
			case circle:
				return std::make_unique<Circle>(params[0], params[1], 
					sqrt(
						(params[2]-params[0])*(params[2]-params[0]) + 
						(params[3]-params[1])*(params[3]-params[1])
					)
				);
		}
	}
	return nullptr;
}

std::unique_ptr<Shape> ShapeFactory::createShape(int type, const std::vector<int>& params) {
	return createShape(static_cast<ShapeType>(type), params);
}

bool ShapeFactory::validateType(ShapeType shapeType, const std::vector<int>& params) {
	switch (shapeType) {
		case line:
			return params.size() == 4;
		case triangle:
			return params.size() == 6;
		case rectangle:
			return params.size() == 4;
		case circle:
			return params.size() == 4;
	}
	return false;
}