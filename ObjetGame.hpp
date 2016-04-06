#ifndef My_First_SMFL_App_ObjetGame_h
#define My_First_SMFL_App_ObjetGame_h
/*!
 * \file ObjetGame.hpp
 * \brief Gestion des ObjetsGame
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Objet.hpp"

/*! \class ObjetGame
 * \brief classe qui cree un ObjetGame
 *
 *  La classe gere les ObjetGame */

class ObjetGame : public Objet{
    public:
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ObjetGame
         *
         */
        ObjetGame(){}
        /*!
        *  \brief Récupere la vie  de l'ObjetGame
        *
        *  Methode qui permet de récupérer la vie de l'ObjetGame
        *  \return la vie de l'ObjetGame
        */
        float getVie() const { return _vie;}
        /*!
         *  \brief Vérifie l'état de vie
         *
         *  Methode qui permet de savoir si l'objet est en vie ou non
         *  \return false si vie inférieur ou égale à 0 , true sinon
         */
        bool estVivant()
        {
            if (_vie <= 0.f) { return false; }
            return true;
        }
        /*!
         *  \brief Initilialise la vie 
         *
         *  Methode qui permet d'initialiser la vie à 192
         */
        void initilisationVie() { _vie = 192.f; }
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe ObjetGame
         */
        ~ObjetGame(){}
    
    protected:
        float _vie;  /*!< vie de l'ObjetGame*/
        
    
    
};


#endif
