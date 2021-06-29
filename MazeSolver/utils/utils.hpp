//
//  utils.hpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h> 

#define WIDTH 800
#define HEIGHT 800

void events(sf::Event& sf_event, sf::RenderWindow& window, bool& end);
sf::Color HSVtoRGB(float H, float S, float V);
float map_value(float inValue, float minInRange, float maxInRange, float minOutRange,float maxOutRange);

#endif /* utils_hpp */
