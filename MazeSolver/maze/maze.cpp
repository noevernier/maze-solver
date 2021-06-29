//
//  maze.cpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "maze.hpp"

/*void Maze::show_pixel(int x, int y, const sf::Color& color, int size, sf::RenderWindow& window)
{
    
    sf::RectangleShape rec(sf::Vector2f(size, size));
    
    rec.setPosition(sf::Vector2f(size * y, size * x));
    rec.setFillColor(color);
    window.draw(rec);
    window.display();
}*/

Maze::Maze(const int maze_width, const int maze_height){
    this->maze_width = maze_width;
    this->maze_height = maze_height;
}

bool Maze::finished(){
    int i,j;
    for (i = 1; i < maze_width-1; i+=2) {
        for (j = 1; j < maze_height-1; j+=2) {
            if(grid[i][j] != grid[1][1]){
                return false;
            }
        }
    }
    return true;
}

void Maze::initialize(){
    int id = 0;
    std::vector<int> wall;
    std::vector<int> line;
    
    for (int i = 0; i < maze_width; i++)
    {
        wall.push_back(-1);
        
        if (i % 2 == 1)
            line.push_back(0);
        
        else
            line.push_back(-1);
    }
    
    for (int i = 0; i < maze_height; i++)
    {
        if (i % 2 == 0)
            grid.push_back(wall);
        
        else
            grid.push_back(line);
    }
    
    for (int i = 0; i < maze_width; i++)
    {
        for (int j = 0; j < maze_height; j++)
        {
            if (grid[i][j] == 0)
            {
                id++;
                grid[i][j] = id;
            }
        }
    }
    
    grid[1][0] = 1;
    grid[maze_width - 2][maze_height - 1] = id;
}

void Maze::show(sf::RenderWindow& window, int size){
    for (int i = 0; i < maze_width; i++)
    {
        for (int j = 0; j < maze_height; j++)
        {
            if (grid[i][j] == -1)
            {
                sf::RectangleShape rec(sf::Vector2f(size, size));
                
                rec.setPosition(sf::Vector2f(size * i, size * j));
                rec.setFillColor(sf::Color::Black);
                window.draw(rec);
            } else {
                float hue = map_value(grid[i][j], 0, maze_width * maze_height * 10, 0, 255);
                sf::RectangleShape rec(sf::Vector2f(size, size));
                
                rec.setPosition(sf::Vector2f(size * i, size * j));
                rec.setFillColor(HSVtoRGB(hue, 255, 255));
                window.draw(rec);
            }
        }
    }
    
    window.display();
}

void Maze::generate(sf::Event &sf_event, sf::RenderWindow &window, bool &end, int size){
    
    //this->show( window, size);
    
    while (!this->finished())
    {
        events(sf_event, window, end);
        window.clear(sf::Color::White);
        
        int x = rand() % (maze_width - 2) + 1;
        int y;
        
        if (x % 2 == 0)
            y = ((rand() % ((maze_height - 1) / 2))) * 2 + 1;
        
        else
            y = ((rand() % ((maze_height - 2) / 2))) * 2 + 2;
        
        int cell_1;
        int cell_2;
        
        if (grid[x - 1][y] == -1)
        {
            cell_1 = grid[x][y - 1];
            cell_2 = grid[x][y + 1];
        }
        
        else
        {
            cell_1 = grid[x - 1][y];
            cell_2 = grid[x + 1][y];
        }
        
        if (cell_1 != cell_2)
        {
            grid[x][y] = 0;
            
            //show_pixel(x, y, sf::Color(255, 255, 255), size, window);

            
            for (int i = 1; i < maze_width - 1; i += 2)
            {
                for (int j = 1; j < maze_height - 1; j += 2)
                {
                    if (grid[i][j] == cell_2)
                        grid[i][j] = cell_1;
                }
            }
        }
        this->show( window, size);
    }
    
    std::cout << "Finish" << std::endl;
}
