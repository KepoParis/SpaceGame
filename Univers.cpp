/*!
 * \file Univers.cpp
 * \brief Gestion de L'Univers
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */


#include "Univers.hpp"


void surbrillerText(sf::Text & text,sf::Text & text_prev,sf::Text & text_next);


void Univers::init_tab(){
    int i;
    for(i = 0;i < 5;i++){
        tab_score[i]=0;
    }
}


void Univers::tri_score(int x ){
    int i;
    int n(5);
    for(i = (n-1); i >= 0 && tab_score[i]<x; i--){
        tab_score[i]= tab_score[i-1];
    }
    tab_score[i]= x;
    
}

void constructText(sf::Text & t,const std::string & string, const sf::Font & f, unsigned int characterSize)
{
    t.setFont(f);
    t.setCharacterSize(characterSize);
    t.setColor(sf::Color::White);
    t.setString(string);
    
}

void surbrillerText(sf::Text & text,sf::Text & text_prev,sf::Text & text_next)
{
    text.setCharacterSize(45);
    text.setColor(sf::Color::Yellow);
    text_prev.setCharacterSize(25);
    text_prev.setColor(sf::Color::White);
    text_next.setCharacterSize(25);
    text_next.setColor(sf::Color::White);
}

Univers::Univers()
{
    window.setFramerateLimit(60);
    window.create(sf::VideoMode((int)WINDOW_SIZE.x, (int)WINDOW_SIZE.y)," Poly'Terre ");
    a2.setPosition(rand() % 500 - 50, -(rand()%200+1110));
    a3.setPosition(rand() % 500 - 50, -(rand()%200+1450));
    chaineAsteroide.push_back(a1);
    chaineAsteroide.push_back(a2);
    chaineAsteroide.push_back(a3);
    chaineAsteroide.push_back(a4);
    chaineAsteroide.push_back(a5);
    chaineAsteroide.push_back(a6);
    chaineAsteroide.push_back(a7);
    chaineAsteroide.push_back(a8);
    chaineAsteroide.push_back(a9);
    chaineAsteroide.push_back(a10);
    init_tab();
    
    if (!icon.loadFromFile(resourcePath() + "vaisseau.png")) { std::cout<<"errreur chargement l'icone "<<std::endl;}
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) { std::cout<<"errreur chargement Font sansation "<<std::endl;}
    if (!star.loadFromFile(resourcePath() + "sansation.ttf")) { std::cout<<"errreur chargement Font starwars "<<std::endl;}
    
    constructText(titre, "BACK To PoLY'TERRE", star, 35);
    titre.setPosition(70, 150);
    constructText(t_gameOver, "GAME oVER", star, 35);
    t_gameOver.setPosition(130, 150);
    constructText(t_pause, "PAuSE", star, 35);
    t_pause.setPosition(170, 150);
    titre.setColor(sf::Color::Yellow);
    constructText(t_selShip, "SCORE", star,20);
    t_selShip.setColor(sf::Color::Yellow);
    t_selShip.setPosition(50,50);
    constructText(t_play,"PLAY", star, 25);
    t_play.setPosition(170,300);
    constructText(t_ship,"SCoRE", star, 25);
    t_ship.setPosition(200,250);
    constructText(t_quit, "ExiT", star,25);
     t_quit.setPosition(210,350);
    constructText(coordoV, "CoordonneesV", font,20);
    coordoV.setPosition(230, 0);
    constructText(coordoS, "CoordonneesS", font,20);
    coordoS.setPosition(230, 22);
    constructText(t_score,"score", font, 20);
    t_score.setPosition(200, 0);
    t_score.setColor(sf::Color::Yellow);
    constructText(t_score1,"n°1:", font, 20);
    t_score1.setColor(sf::Color::White);
    t_score1.setPosition(150,300);
    constructText(t_score2,"n°2:", font, 20);
    t_score2.setColor(sf::Color::White);
    t_score2.setPosition(150,330);
    constructText(t_score3,"n°3.", font, 20);
    t_score3.setColor(sf::Color::White);
    t_score3.setPosition(150,360);
    constructText(t_score4,"n°4:", font, 20);
    t_score4.setColor(sf::Color::White);
    t_score4.setPosition(150,390);
    constructText(t_score5,"n°5:", font, 20);
    t_score5.setColor(sf::Color::White);
    t_score5.setPosition(150,420);
    
    scor = 0;
    
    page = Menu;
    
    for (std::list<Asteroid>::iterator i = chaineAsteroide.begin(); i != chaineAsteroide.end(); ++i)
        colManager.push_back(new CollisionManager(vaisseau,(*i)));
    
    init = false;
    soninit = false;

}


void Univers::afficheScore(){
    
    ostringstream sco1;
    sco1 << tab_score[4];
    string score1 = sco1.str();
    string tscore1("n.1: "+score1);
    t_score1.setString(tscore1);
    ostringstream sco2;
    sco2 << tab_score[3];
    string score2 = sco2.str();
    string tscore2("n.2: "+score2);
    t_score2.setString(tscore2);
    ostringstream sco3;
    sco3 << tab_score[2];
    string score3 = sco3.str();
    string tscore3("n.3: "+score3);
    t_score3.setString(tscore3);
    ostringstream sco4;
    sco4 << tab_score[1];
    string score4 = sco4.str();
    string tscore4("n.4: "+score4);
    t_score4.setString(tscore4);
    ostringstream sco5;
    sco5 << tab_score[0];
    string score5 = sco5.str();
    string tscore5("n.5: "+score5);
    t_score5.setString(tscore5);
    
}

void Univers::EventMenu(){
    static int cpt(0);
    int mouseX(0), mouseY(0);
    bool canClic(false);
    
    if (event.type == sf::Event::KeyPressed ){
        titre.setColor(sf::Color::White);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cpt--;
            if (cpt < 1) { cpt = TAILLE_PAGE; }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cpt++;
            if(cpt > TAILLE_PAGE) { cpt = 1; }
        }
        
    }
    if (event.type == sf::Event::MouseMoved) {
        mouseX = event.mouseMove.x;
        mouseY = event.mouseMove.y;
    }
    
    if ((cpt ==  1) || ((mouseX >120 && mouseX < 300) && (mouseY>250 && mouseY<295))){
        canClic = true;
        surbrillerText(t_play, t_ship, t_quit);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || (((event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left) || event.type == sf::Mouse::isButtonPressed(sf::Mouse::Right)) && canClic) )){
            page = Game;
            
        }
        canClic = false;
    }
    if ((cpt ==  2) || ((mouseX > 120 && mouseX < 300) && (mouseY>300 && mouseY<345))){
        surbrillerText(t_ship,t_play, t_quit);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            page = Score;
        }
    }
    if((cpt ==  3) || ((mouseX >120 && mouseX < 300) && (mouseY>350 && mouseY<495 ) )){
        surbrillerText(t_quit, t_ship, t_play);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            window.close();
        }
    }
    
    if ((40 > mouseY) && (mouseY > 20) && (490 > mouseX) && (mouseX > 474)) {
        son.subrillerIcon();
        
        if (event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (son.estActive()){
                son.nosound();
                for (std::list<CollisionManager*>::iterator j = colManager.begin(); j != colManager.end(); ++j)
                    (*j)->nosound();
            }
            else {
                son.sound();
                for (std::list<CollisionManager*>::iterator j = colManager.begin(); j != colManager.end(); ++j)
                    (*j)->sound();
            }
        }
    }
    else {
        son.desubrillerIcon();
    }

}

void Univers::keyboardControl()
{
    if (event.type == sf::Event::KeyPressed ){
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))// la touche "flèche gauche"
        {
            vaisseau.getSprite().setPosition(sf::Vector2f(vaisseau.getPosition().x - 20,vaisseau.getPosition().y));
            if( vaisseau.getPosition().x< -45){ vaisseau.setPosition(347+110,vaisseau.getPosition().y); }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))// la touche "flèche droite"
        {
            vaisseau.getSprite().setPosition(sf::Vector2f(vaisseau.getPosition().x + 20,vaisseau.getPosition().y));
            if( vaisseau.getPosition().x  > 348+110){ vaisseau.setPosition(-44,vaisseau.getPosition().y); }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))// la touche "flèche haut"
        {
            if(vaisseau.getPostionY() > 0) { vaisseau.getSprite().setPosition(sf::Vector2f(vaisseau.getPosition().x,vaisseau.getPosition().y - 20)); }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))// la touche "flèche droite"
        {
            if(vaisseau.getPostionY() < WINDOW_SIZE.y - DIM_VAISSEAU_HEIGHT ) { vaisseau.getSprite().setPosition(sf::Vector2f(vaisseau.getPosition().x,vaisseau.getPosition().y + 20)); }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // la touche "flèche droite" est enfoncée : on bouge le personnage
            //sf:: Sprite Spsound = s1.getSprite();
            //s1.set(music,Spsound);
        }
        
    }

}

void Univers::mouseControl()
{
    static int mouseX(0), mouseY(0);
    
    //Mouse mouvement : ship move
    if (event.type == sf::Event::MouseMoved) {
        mouseX = event.mouseMove.x;
        mouseY = event.mouseMove.y;
        if (mouseX > 495) { sf::Mouse::setPosition(sf::Vector2i(8, mouseY),window);}
        if (mouseX < 8) { sf::Mouse::setPosition(sf::Vector2i(480, mouseY),window);}
        vaisseau.setPosition(mouseX-48, mouseY-48);//48 : Dimmension vaisseau/2
        
    }
    
}

void Univers::EventGame()
{
    static bool attente(false);
    static int i(0);
    static sf::Clock clock,clignotement;
    //Initialisation de score à 0
    
    
    
    mouseControl();
    if ((!vaisseau.estVisible() || attente ) && vaisseau.estVivant()){
        if (!attente) {
            clock.restart();
            attente = true;
            
        }
        
        if (clock.getElapsedTime() >= sf::seconds(1.0)) {
            if(!vaisseau.estTransparent()) { vaisseau.transparent(); }
            
            if (clignotement.restart() >= sf::seconds(0.05)) {
                if( i % 2 == 0) { vaisseau.ouiVisible(); }
                if (i % 2 == 1) { vaisseau.nonVisible(); }
                i++;
            }
                
            if (clock.getElapsedTime() >= sf::seconds(5.0)) {
                attente = false;
                i = 0;
                vaisseau.nontransparent();
                if( !vaisseau.estVisible()) { vaisseau.ouiVisible(); }
            }
        }
        
    }
    if (event.type == sf::Event::KeyPressed ){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { page = Pause;}
        
    }
    if (!vaisseau.estVivant()) {
        page = GameOver;
        tri_score(scor);
        scor = 0;
    }
   
}
void Univers::EventScore()
{
    if (event.type == sf::Event::KeyPressed ){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { page = Pause;}
    }
    afficheScore();
    
}


void Univers::processEvent()
{
    if(vaisseau.estVisible() && page == Game){ scor++; }
    while (window.pollEvent(event)) {
        
        // Close window : exit
        if (event.type == sf::Event::Closed) { window.close(); }
        
        switch (page) {
            case Menu:
                EventMenu();
                break;
            case Game:
                if (!son.estInitialise()) {
                    son.soundInit();
                }
                if (soninit) {
                    if (son.isPlaying1() || son.isPlaying2()) {
                        son.stop();
                    }
                    soninit = false;
                }
                son.playGame();
                EventGame();
                break;
            case Score:
                EventScore();
                break;
            case Pause:
                EventMenu();
                break;
            case GameOver:
                init = true;
                 for (std::list<Asteroid>::iterator it3 = chaineAsteroide.begin(); it3 != chaineAsteroide.end(); ++it3)
                     (*it3).init();
                
                soninit = true;
                vaisseau.initvitesse();
                vaisseau.initilisationVie();
            
                EventMenu();
                break;
            default:
                break;
        }
    }
}

void Univers::update()
{
    static sf::Clock clk;
    static int limite(3);
    int indice(0);
    if (init) {
        limite = 3;
        init = false;
    }
    
    if (clk.getElapsedTime() >= sf::seconds(20.f)) {
        clk.restart();
        limite++;
        vaisseau.setVitesse(vaisseau.getVitesse() + 1);
    }
    
    ostringstream sco;
    sco << scor;
    string score = sco.str();
    string tscore("Score:"+score);
    t_score.setString(tscore);
    
    //Vie Update
    vaisseau.updateVie();
    
    indice = 0;
    //Asteroid Mouvement Update
    for (std::list<Asteroid>::iterator it3 = chaineAsteroide.begin(); it3 != chaineAsteroide.end(); ++it3){
        if (indice < limite){
            (*it3).Move(vaisseau.getVitesse());
        }
        indice++;
    }
    
    //Collision Update
    for (std::list<CollisionManager*>::iterator j = colManager.begin(); j != colManager.end(); ++j)
        (*j)->ManageCollisions();
    
    //Mouvement du Background
    std::list<Asteroid>::iterator it3 = chaineAsteroide.begin();
    if((*it3).estVisible())background.update(vaisseau.getVitesse());
    
    
}

void Univers::Draw()
{
    
    window.clear();                                                     // Clear screen
    window.draw(background.getSprite());                                // Draw the background
    
    if (page == Menu || page == GameOver || page == Pause) {
        if(page == Menu) { window.draw(titre); }
        if (page == GameOver) { window.draw(t_gameOver); }
        if (page == Pause) { window.draw(t_pause); }
        window.draw(t_play);
        window.draw(t_ship);
        window.draw(t_quit);
    }
    
    if (page == Game || page == Pause) {
        
        
        //Draw the Asteroid
        for (std::list<Asteroid>::iterator it3 = chaineAsteroide.begin(); it3 != chaineAsteroide.end(); ++it3)
            window.draw((*it3).getSprite());
    
        if(vaisseau.estVisible()){ window.draw(vaisseau.getSprite()); }     //Draw the ship
        
        //Draw Collision
        for (std::list<CollisionManager*>::iterator j = colManager.begin(); j != colManager.end(); ++j)
            if ((*j)->siCollision()){ window.draw((*j)->getSprite()); }
        
       
        
        window.draw(t_score);
        window.draw(vaisseau.getvie());
    }
    
    else if (page == Score){
        window.draw(t_selShip);
        window.draw(t_score1);
        window.draw(t_score2);
        window.draw(t_score3);
        window.draw(t_score4);
        window.draw(t_score5);
        
    }
    
    //window.draw(titre);// Draw the string
    //window.draw(coordoS);
    //window.draw(coordoV);
    window.draw(son.getSprite());
    window.display();// Update the window

}

void Univers::Run()
{
    son.playwelcom();
    while (window.isOpen()) 
    {
        
        processEvent();
        if(page == Game) { update(); }
        if (page == GameOver) { 
            son.stopGame();
        }
        Draw();
    }
    
}

Univers::~Univers()
{
    for (std::list<CollisionManager*>::iterator j = colManager.begin(); j != colManager.end(); ++j)
        delete (*j);

}