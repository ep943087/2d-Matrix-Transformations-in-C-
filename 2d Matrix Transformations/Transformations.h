#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

namespace trans {
	class Transformations
	{
	private:
		float scale;
		Point camera, anchor;
		sf::RenderWindow* window;
	public:
		Transformations(sf::RenderWindow*,float,Point,Point);
		void moveCamera(float,float);
		void setCamera(float, float);
		void setAnchor(float, float);
		void setScale(float);
		void moveScale(float);
		sf::VertexArray transform(Shape*);
		void drawShape(Shape* );
	};
}



