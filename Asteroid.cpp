/*!
 * \file Asteroid.cpp
 * \brief Gestion des Asteroid
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Asteroid.hpp"

Asteroid::Asteroid(){
    int xRan;
    xRan = rand() % 500 - 50;
    
    std::cout<<"created\n";
    
    _visible = true;
    _asteroid.loadFromFile(resourcePath() + "asteroid2.png");
    _asteroid.createMaskFromColor(sf::Color::White,0);
    _objet.loadFromImage(_asteroid);
    _sprite.setTexture(_objet);
    _sprite.setPosition(xRan, rand()%200-1450);
    _sprite.setScale(sf::Vector2f(0.5f,0.5f));
    _py = -800;

}

Asteroid::Asteroid(int py)
{
    int xRan;
    xRan = rand()% 500 - 50;
    
    std::cout<<"created\n";
    _visible = true;
    _asteroid.loadFromFile(resourcePath() + "asteroid2.png");
    _asteroid.createMaskFromColor(sf::Color::White,0);
    _objet.loadFromImage(_asteroid);
    _sprite.setTexture(_objet);
    _sprite.setPosition(xRan, py);
    _py = py;
    
}