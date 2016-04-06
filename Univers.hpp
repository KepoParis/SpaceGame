#ifndef Poly_Terre_Univers_h
#define Poly_Terre_Univers_h
/*!
 * \file Univers.hpp
 * \brief Gestion de L'Univers
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <list>
#include <ctime> 
#include <cstdlib>
#include <sstream>
#include <string>
#include "ResourcePath.hpp"
#include "Background.hpp"
#include "CollisionManager.hpp"
#include "Objet.hpp"
#include "ObjetGame.hpp"
#include "Vaisseau.hpp"
#include "Son.hpp"
#include "Asteroid.hpp"

using namespace std;



//Constante

// Taille de l'écran
const sf::Vector2f WINDOW_SIZE(510,800);

//Dimension Vaisseau
const int DIM_VAISSEAU_WIDTH(96);
const int DIM_VAISSEAU_HEIGHT(96);

//Taille du tableau Page
const int TAILLE_PAGE(3);


/*!
 *  \brief Liste des pages du jeu
 *
 *  \enum Page
 *
 */

enum Page {
    Menu,/*!<menu du jeu*/
    Game,/*!<page du jeu*/
    Score,/*!<page de score*/
    Pause,/*!<pause du jeu*/
    GameOver,/*!<fin de partie*/
    Quit/*!<quitte le jeu*/
};

/*! \class Objet
 * \brief classe qui cree un Univers
 *
 *  La classe gere les Univers 
 */

class Univers
{
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Son
     *
     */
    Univers();
    /*!
     *  \brief Lance le jeu
     *
     *  Methode qui permet de lancer le jeu
     */
    void Run();
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Univers
     */
    ~Univers();
    
protected:
    
    int tab_score [5];/*!< tableau de score de taille 5*/
    int scor;/*!< score de la partie*/
    Page page;/*!< page de l'Univers */
    sf::RenderWindow window;/*!< fenetre de l'Univers*/
    sf::Event event;/*!< evenement de l'Univers*/
    sf::Image icon;/*!< Icone du jeu*/
    sf::Font font,star;/*!< font des textes*/
    Background background;/*!< background de l'Univers */
    Vaisseau vaisseau;/*!< vaisseau du jeu*/
    Asteroid a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;/*!< les Asteroid*/
    std::list<Asteroid> chaineAsteroide;/*!< liste d'Asteroid*/
    std::list<CollisionManager*> colManager;/*!< liste de CollisionManager*/
    Son son;/*!< Son du jeu*/
    sf::Text titre,t_selShip,t_gameOver, t_pause;/*!< les textes */
    sf::Text t_play,t_ship,t_quit;/*!< les textes*/
    sf::Text t_score,t_score1,t_score2;/*!< les textes*/
    sf::Text t_score3,t_score4,t_score5;/*!<les textes*/
    
    sf::Text coordoV,coordoS;/*!< les textes des coordonnés*/
    
    bool soninit; /*!< si le Son est initialisé ou non*/
    bool init;/*!< si l'Univers est initialisé ou non*/
    /*!
     *  \brief Gére les Events
     *
     *  Methode qui permet de gérer les Events
     */
    void processEvent();
    /*!
     *  \brief Gére la mise à jour de la fenêtre
     *
     *  Methode qui permet de gérer la mise à jour de l'Univers
     */
    void update();
    /*!
     *  \brief Gére la répresentations de l'Univers
     *
     *  Methode qui permet de gérer la représentation de l'Univers
     */
    void Draw();
    /*!
     *  \brief Affiche les scores
     *
     *  Methode qui permet d'afficher les scores
     */
    void afficheScore();
    /*!
     *  \brief Gére les évenements du Clavier
     *
     *  Methode qui permet de gérer les évenements du clavier
     */
    void keyboardControl();
    /*!
     *  \brief Gére les évenements de la Souris
     *
     *  Methode qui permet de gérer les évenements de la Souris
     */
    void mouseControl();
    /*!
     *  \brief Gére la page Menu
     *
     *  Methode qui permet de gérer la page Menu
     */
    void EventMenu();
    /*!
     *  \brief Gére la page Game
     *
     *  Methode qui permet de gérer la page Game
     */
    void EventGame();
    /*!
     *  \brief Gére la page Score
     *
     *  Methode qui permet de gérer la page Score
     */
    void EventScore();
    /*!
     *  \brief Initialise les valeurs tab_score
     *
     *  Methode qui permet d'initialiser tab_score
     */
    void init_tab();
    /*!
     *  \brief Tri par insertion
     *
     *  Methode qui permet de trier le tab_score dans l'ordre décroissant quand il ya un nouveau score
     */
    void tri_score(int x);
    
};
/*!
 *  \brief construit le sprite text
 *
 *  Fonction qui permet de créer un objet Text
 *  \param &text: texte
 *  \param &string: texte à mettre dans text
 *  \param &font : style d'écriture de text
 *  \param &characterSize : taille de text
 */
void constructText(sf::Text & text,const std::string &string, const sf::Font &font, unsigned int characterSize = 30);
/*!
 *  \brief Surbriller le text
 *
 *  Fonction qui permet de faire surbriller le text
 *  \param &text: texte à surbriller
 *  \param &text_prev : texte précédent à désurbriller
 *  \param &text_next : texte suivant à désurbriller
 */
void surbrillerText(sf::Text & text,sf::Text & text_prev,sf::Text & text_next);




#endif
