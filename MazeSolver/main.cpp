//
//  main.cpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//
#include "utils/utils.hpp"
#include "maze/maze.hpp"

int main(int, char const**)
{
    int size = 10;
    
    sf::RenderWindow window(sf::VideoMode(WIDTH-size, HEIGHT-size), "maze solver");
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(100);

    bool end = false;
    sf::Event sf_event;

    Maze maze(WIDTH/size-1,HEIGHT/size-1);
    maze.initialize();
    
    while (window.isOpen())
    {
        events(sf_event, window, end);

        window.clear(sf::Color::White);
        
        maze.generate(sf_event, window, end, size);

        //sf::sleep(sf::seconds(1));
    }

    return EXIT_SUCCESS;
}
