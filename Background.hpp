#ifndef My_First_SMFL_App_Background_h
#define My_First_SMFL_App_Background_h

/*!
 * \file Background.hpp
 * \brief Gestion de l'image de fond du jeu
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

/*! \class Background
 * \brief classe representant l'arriere plan du jeu
 *
 *  La classe gere le fond graphique du jeu
 */
class Background {
    
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Background
     *
     *  
     */
    Background();
    /*!
     *  \brief mise a jour du Background
     *
     *  Methode qui permet de mettre à jour le fond du jeu
     *
     *  \param vitesse : vitesse de défilement du jeu
     */
    void update(int vitesse);
    /*!
     *  \brief Récupère le sprite du Background
     *
     *  Methode qui permet de récuperer le sprite
     *   du background
     *
     *  \return le sprite du background
     */
    sf::Sprite getSprite() const{ return sprite; }
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Background
     */
    ~Background(){}
    
    
private:
    sf::Texture texture;/*!< texture du fond*/
    sf::Sprite sprite;/*!< sprite du fond*/
    
};



#endif
