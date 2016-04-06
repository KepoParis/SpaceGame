#ifndef __Poly_Terre_SFML__Son__
#define __Poly_Terre_SFML__Son__

/*!
 * \file Son.hpp
 * \brief Gestion du Son
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ObjetGame.hpp"

/*! \class Son
 * \brief classe qui cree un Son
 *
 *  La classe gere les Son */

class Son : public ObjetGame{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Son
     *
     */
    Son();
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Son
     */
    ~Son(){}
    /*!
     *  \brief Récupere initialized
     *
     *  Methode qui permet de récupérer initialized
     *  \return initialized
     */
    bool estInitialise() const { return initialized; }
    /*!
     *  \brief Initialise Son
     *
     *  Methode qui permet d'initialiser le Son
     */
    void soundInit();
    /*!
     *  \brief Regle le Son avec une musique et un sprite
     *
     *  Methode qui permet de régler Son
     *  \param &music : musique du Son
     *  \param &spsound : sprite du Son
     */
    void set(sf::Music& music, sf::Sprite& Spsound );
    /*!
     *  \brief Lecture de _welcom
     *
     *  Methode qui permet de lancer la lecture de _welcom
     */
    void playwelcom(){ _welcom.play(); }
    /*!
     *  \brief Lecture du Son du jeu
     *
     *  Methode qui permet de lancer la lecture du Son dans le jeu
     */
    void playGame();
    /*!
     *  \brief Arret du Son du Jeu
     *
     *  Methode qui permet d'arréter le Son dans le jeu
     */
    void stopGame();
    /*!
     *  \brief coupe le Son
     *
     *  Methode qui permet de couper le Son
     */
    void nosound();
    /*!
     *  \brief Récupere l'etat du son _game1
     *
     *  Methode qui permet de récuperer l'état de_game1
     *  \return false si la _game1 ne joue pas, true sinon
     */
    bool isPlaying1()
    {
        if (_game1.getStatus() != sf::SoundSource::Playing) {
            return false;
        }
        return true;
    }
    /*!
     *  \brief Récupere l'etat du son _game2
     *
     *  Methode qui permet de récuperer l'état de_game2
     *  \return false si la _game2 ne joue pas, true sinon
     */
    bool isPlaying2()
    {
        if (_game2.getStatus() != sf::SoundSource::Playing) {
            return false;
        }
        return true;
    }
    /*!
     *  \brief Arrête le Son
     *
     *  Methode qui permet d'arréter le Son
     */
    void stop()
    {
        _game1.stop();
        _game2.stop();
    }
    /*!
     *  \brief Mets le son
     *
     *  Methode qui permet de remettre du son
     */
    void sound();
    /*!
     *  \brief Récupere activated
     *
     *  Methode qui permet de récupérer activated
     *  \return activated
     */
    bool estActive() const { return activated; }
    /*!
     *  \brief Surbriller icone du son
     *
     *  Methode qui permet de faire surbriller l'icone de son
     */
    void subrillerIcon() { _sprite.setTextureRect(sf::IntRect(47,0,47,41)); }
    /*!
     *  \brief Désurbriller icone du son
     *
     *  Methode qui permet de faire désurbriller l'icone de son
     */
    void desubrillerIcon() { _sprite.setTextureRect(sf::IntRect(0,0,47,41)); }
    
    
protected:
    sf::Image _sound;/*!< Image de Son*/
    sf::Music _game1;/*!< musique 1 du game*/
    sf::Music _game2;/*!< musique 2 du game*/
    sf::SoundBuffer buffer;/*!< buffer de Son*/
    sf::Sound _welcom;/*!< son du menu*/
    
    bool activated;/*!< Son est activé ou non*/
    
    bool initialized;/*!< Son est initialisé ou non*/
    bool playing1,playing2;/*!< Pour transition du début du son space à la boucle parfaite infini de space*/
    /*!
     *  \brief Diminue le son rapidement
     *
     *  Methode qui permet de diminuer le son rapidement avec quelque seconde de retard
     */
    void breakeffect(sf::Music & music);
    
    
   
    
    
};

#endif /* defined(__Poly_Terre_SFML__Son__) */
