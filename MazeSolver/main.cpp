//
//  main.cpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//
#include "utils/utils.hpp"

int main(int, char const**)
{
    int zoom = 1;
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "maze solver");

    bool end = false;
    sf::Event sf_event;
    sf::RectangleShape pixel;
    pixel.setSize(sf::Vector2f(zoom, zoom));
    std::vector<std::vector<int>> maze;

    while (window.isOpen())
    {
        events(sf_event, window, end);

        window.clear();

        window.display();
    }

    return EXIT_SUCCESS;
}
