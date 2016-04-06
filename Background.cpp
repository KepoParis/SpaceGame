/*!
 * \file Background.cpp
 * \brief Gestion de l'image de fond du jeu
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Background.hpp"

using namespace std;
using namespace sf;


Background::Background()
{
    if (!texture.loadFromFile(resourcePath() + "univers.png")){ cout<<"Echec du chargement de l'arrière plan"<<endl; }
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,510,800));

}

void Background::update(int vitesse)
{
    static int y(1700);
    
    if (y <= vitesse*2) {
        y = 1706;
    }
    y -= vitesse*2;
    sprite.setTextureRect(sf::IntRect(0,y,510,800));
}