/*!
 * \file Objet.cpp
 * \brief Gestion des Objets
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Objet.hpp"

void Objet::setPosition(int px,int py)
{   
    _px=px; 
    _py=py;
    _sprite.setPosition(sf::Vector2f(px,py));
    
}

void Objet::Move(int vitesse)
{
    _px= _sprite.getPosition().x;
    _py = _sprite.getPosition().y + vitesse;
    _sprite.move(0, vitesse);
    
}