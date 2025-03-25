#include "../Header/ShapeFactory.h"
#include "../Header/ShapeManager.h"
#include <iostream>

void ShapeManager::drawAll() {
	for (const auto& shape : shapes) {
		shape->draw();
	}
}

void ShapeManager::addShape(std::unique_ptr<Shape> shape) {
	shapes.push_back(std::move(shape));
}

void ShapeManager::removeShape(int index) {
	if (index >= 0 && index < shapes.size()) {
		shapes.erase(shapes.begin() + index);
	}
}

void ShapeManager::clearShapes() {
	shapes.clear();
}