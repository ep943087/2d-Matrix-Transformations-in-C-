#include "Transformations.h"

namespace trans {

	Transformations::Transformations(sf::RenderWindow* window, float scale,Point camera, Point anchor) {
		this->window = window;
		this->scale = scale;
		this->camera = camera;
		this->anchor = anchor;
	}

	sf::VertexArray Transformations::transform(Shape *shape) {
		int size = shape->getSize();
		sf::VertexArray lines(sf::LineStrip, size + 1);
		Point* points = shape->getPoints();

		for (int i = 0;i < size;i++) {
			float x = points[i].x - camera.x;
			float y = points[i].y - camera.y;

			x = x * scale + anchor.x;
			y = y * scale + anchor.y;
			lines[i].position = sf::Vector2f(x,y);
		}

		// draw line back to original point
		lines[size].position = lines[0].position;
		
		return lines;
	}

	void Transformations::drawShape(Shape* shape) {
		sf::VertexArray lines = transform(shape);

		window->draw(lines);
	}

	void Transformations::moveCamera(float x, float y) {
		float ch = 10 / scale;
		if (x < 0) {
			camera.x -= ch;
		}
		else if (x > 0) {
			camera.x += ch;
		}
		if (y < 0) {
			camera.y -= ch;
		}
		else if (y > 0) {
			camera.y += ch;
		}
	}
	void Transformations::setCamera(float, float) {

	}
	void Transformations::setScale(float) {

	}
	void Transformations::setAnchor(float, float) {

	}
	void Transformations::moveScale(float ch) {
		if (ch < 0) {
			scale *= .9;
		}
		else {
			scale /= .9;
		}
	}

}