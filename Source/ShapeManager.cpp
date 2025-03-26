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

std::vector<std::string> ShapeManager::getShapeNames() const {
	std::vector<std::string> names;
	int i = 0;
	for (const auto& shape : shapes) {
		names.push_back(shape->getName() + " " + std::to_string(i));
		i++;
	}
	return names;
}

void ShapeManager::scale(int index, float x, float y) {
	if (index >= 0 && index < shapes.size()) {
		shapes[index]->scale(x, y);
	}
}

void ShapeManager::translate(int index, float x, float y) {
	if (index >= 0 && index < shapes.size()) {
		shapes[index]->translate(x, y);
	}
}

void ShapeManager::rotate(int index, float angle) {
	if (index >= 0 && index < shapes.size()) {
		shapes[index]->rotate(angle);
	}
}