#pragma once
#include <iostream>
namespace trans {

	typedef struct {
		float x;
		float y;

	} Point;

	class Shape
	{
	protected:
		Point* points;
		int size;
		float x, y;
	public:
		virtual void initialize() = 0;
		int getSize();
		Point* getPoints();
		~Shape();
	};
}


