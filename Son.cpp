/*!
 * \file Son.cpp
 * \brief Gestion du Son
 * \author Kevin & Dieu-nel
 * \date   17 Janvier 2014
 * \version 1.0
 */

#include "Son.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"

Son::Son(){
    
    _sound.loadFromFile(resourcePath() + "son-icon.png");
    _sound.createMaskFromColor(sf::Color::White,0);
    _objet.loadFromImage(_sound);
    _sprite.setTexture(_objet);
    _sprite.setTextureRect(sf::IntRect(0,0,47,41));
    _sprite.setPosition(460, 10);
    _game1.openFromFile(resourcePath() + "space1.aif");
    _game2.openFromFile(resourcePath() + "space2.aif");
    _game2.setLoop(true);
    _game1.setVolume(50.f);
    _game2.setVolume(50.f);
    buffer.loadFromFile(resourcePath() + "welcom.wav");
    _welcom.setBuffer(buffer);
    _welcom.setVolume(20.f);
    initialized = true;
    playing2 = playing1 = true;
    activated = true;
    
}

void Son::soundInit()
{
    _game1.setPitch(1.0);
    _game2.setPitch(1.0);
    _game1.setVolume(50.f);
    _game2.setVolume(50.f);
    initialized = true;
    activated = true;
    
}

void Son::breakeffect(sf::Music & music){
    
    initialized =false;
    static float pitcpt(1.0), volcpt(50.0);
    
    music.setPitch(pitcpt);
    music.setVolume(volcpt);
    
    if(volcpt > 0) { volcpt -= 0.1; }
    if( pitcpt > -12.0) {  pitcpt -= 0.004; }
}

void Son::playGame(void)
{
    
    if (_game1.getStatus() == sf::SoundSource::Stopped && playing1) {
        playing1 = false;
        _game1.play();
        
    }
    
    if (_game1.getStatus() == sf::SoundSource::Stopped && playing2) {
        playing2 = false;
        _game2.play();
    }
    
}

void Son::stopGame()
{
    static int cpt(0);
    
    
    if (cpt < 500) {
        if ( _game1.getStatus() == sf::SoundSource::Playing ) { breakeffect(_game1); }
        if ( _game2.getStatus() == sf::SoundSource::Playing ) { breakeffect(_game2); }
    }
    
    if (cpt >= 500) {
        if ( _game1.getStatus() == sf::SoundSource::Playing ) { _game1.stop(); }
        if ( _game2.getStatus() == sf::SoundSource::Playing ) { _game2.stop(); }
    }
    playing1 = true;
    playing2 = true;
    cpt++;
}

void Son::set(sf:: Music& music,sf:: Sprite& Spsound){
    sf::SoundSource::Status status;
    status = music.getStatus();
    if(status == 2){
        music.pause();
        Spsound.setTextureRect(sf::IntRect(0,40,25,45));
    }
    else{
        music.play();
        Spsound.setTextureRect(sf::IntRect(0,40,47,45));
    }
    
}

void Son::nosound(){
    _welcom.setVolume(0.f);
    _game1.setVolume(0.f);
    _game2.setVolume(0.f);
    activated = false;
    
}
void Son::sound(){
    _welcom.setVolume(20.f);
    _game1.setVolume(50.f);
    _game2.setVolume(50.f);
    activated = true;

}