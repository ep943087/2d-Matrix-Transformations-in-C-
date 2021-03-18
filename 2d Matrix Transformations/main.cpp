// 2d Matrix Transformations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Rectangle.h"
#include "Transformations.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600),"2d Matrix Transformations");
    trans::Rectangle rect(200, 200, 100, 100);

    trans::Point camera = { 400,300 };
    trans::Point anchor = { 400,300 };
    trans::Transformations transforms(&window, 2.0f, camera, anchor);

    while(window.isOpen()){

        window.setFramerateLimit(60);

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Up) {
                transforms.moveCamera(0, -1);
            }
            if (event.key.code == sf::Keyboard::Down) {
                transforms.moveCamera(0, 1);
            }
            if (event.key.code == sf::Keyboard::Left) {
                transforms.moveCamera(-1, 0);
            }
            if (event.key.code == sf::Keyboard::Right) {
                transforms.moveCamera(1, 0);
            }
            if (event.key.code == sf::Keyboard::I) {
                transforms.moveScale(1);
            }
            if (event.key.code == sf::Keyboard::O) {
                transforms.moveScale(-1);
            }
            if (event.MouseWheelScrolled && abs(event.mouseWheelScroll.delta) > .1) {
                if (event.mouseWheelScroll.delta > 0) {
                    transforms.moveScale(-1);
                }
                else {
                    transforms.moveScale(1);
                }
            }
        }

        window.clear(sf::Color(0,0,0));

        transforms.drawShape(&rect);

        window.display();
    }
}
