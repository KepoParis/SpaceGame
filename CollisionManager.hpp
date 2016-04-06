#ifndef My_First_SMFL_App_CollisionManager_h
#define My_First_SMFL_App_CollisionManager_h
/*!
 * \file CollisionManager.hpp
 * \brief Gestion des collisions
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "Objet.hpp"
#include "ObjetGame.hpp"
#include "Vaisseau.hpp"

/*! \class CollisionManager
 * \brief classe qui cree une Collision
 *
 *  La classe gere les Collisions entre Objet */

class CollisionManager
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe CollisionManager
     *
     *  \param &objet1 : Vaisseau
     *  \param &objet2 : Objet
     */
    CollisionManager(Vaisseau & objet1, Objet & objet2);
    /*!
     *  \brief Récupère le sprite du CollisionManager
     *
     *  Methode qui permet de récupérer le sprite
     *   du CollisionManager
     *
     *  \return le sprite de CollisionManager
     */
    sf::Sprite getSprite() const{return sprite;}
    /*!
     *  \brief Réupere _collision
     *
     *  Methode qui permet de récupérer _collision
     *
     *  \return l'attribut _collision de CollisionManager
     */
    bool siCollision(){return _collision;}
    /*!
     *  \brief Coupe le son des bombes
     *
     *  Coupe le bruit des explosions
     */
    void nosound() { bombe.setVolume(0.f); }
    /*!
     *  \brief Déclenche le son de bombe
     *
     *  Déclenche le bruit d'une explosion
     */
    void sound() { bombe.setVolume(15.f); }
    /*!
     *  \brief Gère les collisions
     *
     *  Gère les collisions
     */
    void ManageCollisions();
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe CollisionManager
     */
    ~CollisionManager();
    
private:
    
    Vaisseau & _objet1;/*!< vaisseau le premier objet*/
    Objet & _objet2;/*!< le second objet*/
    sf::Image explosion;/*!< image de collision*/
    sf::Texture effet;/*!< texture des collision*/
    sf::Sprite sprite;/*!< Sprite de collision*/
    bool _collision;/*!< etat collision*/
    sf::SoundBuffer buffer;/*!< provenance du son*/
    sf::Sound bombe;/*!< son d'une explosion*/
    
    
};


#endif
