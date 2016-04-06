#ifndef My_First_SMFL_App_Asteroid_h
#define My_First_SMFL_App_Asteroid_h

/*!
 * \file Asteroid.hpp
 * \brief Gestion des Asteroid
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "ObjetGame.hpp"

/*! \class Asteroid
 * \brief classe qui cree un Asteroid
 *
 *  La classe gere les Asteroid*/

class Asteroid : public ObjetGame{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Asteroid
     *
     */
    Asteroid();
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Asteroid
     *  \param py ; position y de l'Asteroid créé
     */
    Asteroid(int py);
    /*!
     *  \brief Déplace un Asteroid
     *
     *  Bouge un Asteroid à la vitesse choisie
     *  \param vitesse: la vitesse de l'Asteroid
     */
    void Move(int vitesse){
        _sprite.move(0,vitesse);
        _py = _sprite.getPosition().y;
        if (_py >=750) { _sprite.setPosition(rand() % 500 - 50,rand()%200-450);}
    }
    /*!
     *  \brief Récupere _mort
     *
     *  Methode qui permet de récupérer _mort
     *  \return _mort
     */
    bool isDead(){return _mort;}
    /*!
     *  \brief Tue l'Asteroid
     *
     *  Methode qui permet de mettre _mort à true
     */
    void Dead(){_mort = true;}
    /*!
     *  \brief Initialise la position de Asteroid
     *
     *  Methode qui permet d'initialiser la position de l'Asteroid
     */
    void init() { _sprite.setPosition(rand() % 500 - 50, rand()%200-1450);}
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Asteroid
     */
    ~Asteroid(){}
    
protected:
    sf::Image _asteroid;/*!< image de l'Asteroid*/
    bool _mort;/*!< si l'Asteroid est mort ou pas*/
    
    
    
};


#endif
