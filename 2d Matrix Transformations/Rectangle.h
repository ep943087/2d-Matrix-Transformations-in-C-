#pragma once

#include "Shape.h"

namespace trans {
	class Rectangle: public Shape
	{
	private:
		int width, height;
	public:
		Rectangle(float,float,float,float);
		void initialize();
	};
}


