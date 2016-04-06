#ifndef My_First_SMFL_App_Vaisseau_h
#define My_First_SMFL_App_Vaisseau_h 
/*!
 * \file Vaisseau.hpp
 * \brief Gestion des Vaisseau
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "ObjetGame.hpp"

/*! \class Objet
 * \brief classe qui cree un Objet
 *
 *  La classe gere les Objets */
class Vaisseau : public ObjetGame{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Vaisseau
     *
     */
    Vaisseau();
    /*!
     *  \brief Modifie la vie
     *
     *  Methode qui permet décremente la vie de 64
     */
    void boom() { _vie -= 64.f; }
    /*!
     *  \brief Récupere la vitesse  du Vaisseau
     *
     *  Methode qui permet de récupérer la vitesse du Vaisseau
     *  \return la vitsse du Vaisseau
     */
    int getVitesse() const { return _vitesse; }
    /*!
     *  \brief Règle la vitesse
     *
     *  Methode qui permet de régler la vie
     * \param v: la vitesse du vaisseau
     */
    void setVitesse(int v) { _vitesse = v; }
    /*!
     *  \brief Récupere le sprite de vie du Vaisseau
     *
     *  Methode qui permet de récupérer le sprite de vie d Vaisseau
     *  \return sprite_vie : le sprite de vie
     */
    sf::Sprite getvie() const { return sprite_vie; }
    /*!
     *  \brief Mets à jour la vie
     *
     *  Methode qui permet d'augmenter la vie
     */
    void updateVie(){
        static sf::Clock clock_vie;
        
        if ((_vie < 192)) {
            _vie += 0.01;
        }
        sprite_vie.setTextureRect(sf::IntRect(0,0,(int)_vie,64));
    }
    /*!
     *  \brief Rend le vaisseau transparent
     *
     *  Methode qui permet de mettre _transparent à true
     */
    void transparent()
    {
        _transparent = true;
        _sprite.setColor(sf::Color(255, 255, 255, 128));
    }
    /*!
     *  \brief Rend le vaisseau non transparent
     *
     *  Methode qui permet de mettre _transparent à false
     */
    void nontransparent()
    {
        _transparent = false;
        _sprite.setColor(sf::Color(255, 255, 255, 255));
        
    }
    /*!
     *  \brief Récupere _transparent
     *
     *  Methode qui permet de récupérer _transparent
     *  \return _transparent
     */
    bool estTransparent() const { return _transparent; }
    /*!
     *  \brief Initilialise la vitesse
     *
     *  Methode qui permet d'initialiser la vitesse à 4
     */
    void initvitesse() {  _vitesse = 4; }
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Vaisseau
     */
    ~Vaisseau(){}

protected:
    sf::Image _vaisseau; /*!<image du Vaisseau*/
    sf::Texture image_vie;/*!< image de la vie*/
    sf::Sprite sprite_vie;/*!< sprite de la vie du Vaisseau*/
    bool _transparent;/*!< etat de si le Vaisseau est transparent ou non*/
    int _batterie; /*!< batterie du Vaisseau*/
    int _vitesse; /*!< vitesse du Vaisseau*/
    

    
};


#endif
