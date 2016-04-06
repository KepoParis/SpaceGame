#ifndef My_First_SMFL_App_Objet_h
#define My_First_SMFL_App_Objet_h
/*!
 * \file Objet.hpp
 * \brief Gestion des Objets
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */
#include <SFML/Graphics.hpp>

/*! \class Objet
 * \brief classe qui cree un Objet
 *
 *  La classe gere les Objet */
class Objet {
    public:
        /*!
        *  \brief Constructeur
        *
        *  Constructeur de la classe Objet
        *
        */
        Objet(){ _visible = true;}
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Objet
         */
        ~Objet(){}
        /*!
         *  \brief Déplace un Objet
         *
         *  Bouge un Objet à la vitesse choisie
         * \param vitesse: la vitesse de l'Objet
         */
        virtual void Move(int vitesse);
        /*!
         *  \brief Récupere la position de l'Objet
         *
         *  Methode qui permet de récuperer la positionde l'objet
         *  \return la position de l'Objet dans un vector de float
         */
        sf::Vector2f getPosition() const{return _sprite.getPosition();}
        /*!
         *  \brief Récupere le sprite de l'Objet
         *
         *  Methode qui permet de récuperer le sprite de l'objet
         *  \return le sprite de l'Objet
         */
        sf::Sprite getSprite() const{ return _sprite; }
        /*!
         *  \brief Récupere le Rect de l'Objet
         *
         *  Methode qui permet de récupérer le Rect de l'Objet
         *
         *  \return le Rect de l'Objet
         */
        sf::IntRect getIntRect() const { return _sprite.getTextureRect(); }
        /*!
         *  \brief Modifie le Rect de l'Objet
         *
         *  Redimensionne le Rect de l'Objet
         * \param &rectancle : les nouvelles dimension du Rect
         */
        void setIntRect(const sf::IntRect & rectangle){ _sprite.setTextureRect(rectangle); }
        /*!
         *  \brief Règle la position de l'Objet
         *
         *  Modifie la position de l'Objet
         * \param px : position en x
         * \param py : position en y
         */
        void setPosition(int px,int py);
        /*!
         *  \brief Récupere la position Y de l'Objet
         *
         *  Methode qui permet de récupérer la position Y de l'Objet
         *  \return la position Y de l'Objet
         */
        int getPostionY() const { return _py; }
        /*!
         *  \brief Récupere la position X de l'Objet
         *
         *  Methode qui permet de récupérer la position Y de l'Objet
         *  \return la position X de l'Objet
         */
        int getPostionX() const { return _px; }
        /*!
         *  \brief Récupere l'attribut _visible de l'Objet
         *
         *  Methode qui permet de récupérer l'attribut de l'Objet
         *
         *  \return _visible
         */
        bool estVisible() { return _visible; }
        /*!
         *  \brief Rend l'Objet non visible
         *
         *  Mets l'attrinut _visible de l'Objet à false
         */
        void nonVisible() { _visible = false; }
        /*!
         *  \brief Rend l'Objet visible
         *
         *  Mets l'attrinut _visible de l'Objet à true
         */
        void ouiVisible() { _visible = true; }

    
    
    
    
    
    
    protected:
        sf::Sprite _sprite; /*!< Sprite de l'Objet*/
        sf::Texture _objet; /*!< Texture de l'Objet*/
        int _px,_py; /*!< position de l'Objet*/
        int _width; /*!< largeur taille de l'Objet*/
        int _heigth; /*!< hauteur taille de l'Objet*/
        int _ID;    /*!< numéro de l'Objet*/
        bool _visible; /*!< variable d'aide pour affichage de l'Objet*/
};

#endif

