/*!
 * \file Vaisseau.cpp
 * \brief Gestion des Vaisseau
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Vaisseau.hpp"

Vaisseau::Vaisseau(){
    
    //if(vn == 1)
    _vaisseau.loadFromFile(resourcePath() + "vaisseau.png");
    _sprite.setPosition(110, 400);
    //}
   // else if(vn == 2){
        //_vaisseau.loadFromFile(resourcePath() + "vaisseau2.png");
        //_sprite.setPosition(300, 400);
        //_sprite.setScale(0.3,0.3);
   // }
    _vaisseau.createMaskFromColor(sf::Color::White,0);
    _objet.loadFromImage(_vaisseau);
    _sprite.setTexture(_objet);
    
    _transparent = false;
    _vie = 192;
    _vitesse = 4;
    
    image_vie.loadFromFile(resourcePath() + "vie.png");
    image_vie.setSmooth(true);
    sprite_vie.setTexture(image_vie);
    sprite_vie.setScale(0.5, 0.5);
    sprite_vie.setPosition(8, 5);
    
    
    
    
}

