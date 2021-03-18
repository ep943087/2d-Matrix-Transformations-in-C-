#include "Shape.h"

namespace trans {
	Shape::~Shape() {
		delete points;
		std::cout << "SHAPE WAS DELETED" << std::endl;
	}

	int Shape::getSize() {
		return size;
	}

	Point* Shape::getPoints() {
		return points;
	}
}