/*!
 * \file CollisionManager.cpp
 * \brief Gestion des collisions
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "CollisionManager.hpp"

using namespace std;
using namespace sf;

bool Collision(const Sprite & a, const Sprite & b)
{
    sf::Uint8 AlphaLimit = 127;
    
    sf::FloatRect Intersection; 
    if (a.getGlobalBounds().intersects(b.getGlobalBounds(), Intersection)) {
        sf::IntRect O1SubRect = a.getTextureRect();
        sf::IntRect O2SubRect = b.getTextureRect();
        
        
        for (int i = Intersection.left; i < Intersection.left+Intersection.width; i++) {
            for (int j = Intersection.top; j < Intersection.top+Intersection.height; j++) {
                
                sf::Vector2f o1v = a.getInverseTransform().transformPoint(i, j);
                sf::Vector2f o2v = b.getInverseTransform().transformPoint(i, j);
                
                if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
                    o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
                    o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {
                    
                    if ((a.getTexture()->copyToImage().getPixel(static_cast<int> (o1v.x), static_cast<int> (o1v.y)).a > AlphaLimit) &&
                        (b.getTexture()->copyToImage().getPixel(static_cast<int> (o2v.x), static_cast<int> (o2v.y)).a > AlphaLimit))                         return true;
                }
            }
        }
    }
    return false;
}

CollisionManager::CollisionManager(Vaisseau & objet1, Objet & objet2): _objet1(objet1),_objet2(objet2)
{
    if (!buffer.loadFromFile(resourcePath() + "booom.wav")){ std::cout<<"Erreur chargement bombe\n";}
    bombe.setBuffer(buffer);
    bombe.setVolume(15.f);
    //bombe.stop();
    explosion.loadFromFile(resourcePath() + "explosion_vaisseau.png");
    explosion.createMaskFromColor(sf::Color::White,0);
    effet.loadFromImage(explosion);
    sprite.setTexture(effet);
    sprite.setTextureRect(sf::IntRect(0,0,192,192));
    _collision = false;
    
}

void CollisionManager::ManageCollisions()
{
    static bool explosionEnCours(false);
    if ((Collision(_objet1.getSprite(),_objet2.getSprite())&& _objet1.estVisible() && !_objet1.estTransparent()) || explosionEnCours) {
        if (bombe.getStatus() == sf::Sound::Stopped){ bombe.play();}
        _collision = explosionEnCours = true;
        static int cpt(0), x(0),y(0);
        
        
        if (cpt == 25) {_objet1.nonVisible();}
        
        //Actualisation de l'explosion
        if(_objet1.estVisible()) { sprite.setPosition(_objet1.getSprite().getPosition().x - 50,_objet1.getSprite().getPosition().y - 50); }
        sprite.setTextureRect(sf::IntRect(x,y,192,192));
        
        if (cpt % 8 == 0) { y += 192; }
        x += 192;
        cpt++;
        
        if (x == 1536) {
            x = 0;
            if (y==1536 - 192) 
            { 
                _objet1.boom();
                y = 0; 
                cpt = 0;
                explosionEnCours = false;
            }
        }
        
    }
    else{
        _collision = false;
    }
}

CollisionManager::~CollisionManager()
{}



