//
//  maze.hpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef maze_hpp
#define maze_hpp

#include <stdio.h>
#include "../utils/utils.hpp"

class Maze{
public:
    int maze_width;
    int maze_height;
    
    std::vector<std::vector<int>> grid;
    
    Maze(int,int);
    
    void show(sf::RenderWindow& window, int size);
    void initialize();
    void generate(sf::Event& sf_event, sf::RenderWindow& window, bool& end, int size);
private:
    bool finished();
    void show_pixel(int x, int y, const sf::Color& color, int size, sf::RenderWindow& window);
    
};

#endif /* maze_hpp */
