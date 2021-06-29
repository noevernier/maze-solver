//
//  utils.cpp
//  MazeSolver
//
//  Created by Noé on 29/06/2021.
//  Copyright © 2021 Noé. All rights reserved.
//

#include "utils.hpp"

void events(sf::Event& sf_event, sf::RenderWindow& window, bool& end)
{
    while (window.pollEvent(sf_event))
    {
        switch (sf_event.type)
        {
            case sf::Event::Closed:
                
                window.close();
                end = true;
                break;
        }
    }
}
