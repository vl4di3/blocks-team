#pragma once
#include <iostream>
#include "levele.h"
#include "wrogowie.h"
#include <SFML/Graphics.hpp>
using namespace std;
class Postac :public sf::Drawable, sf::Transformable
{
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    string nazwa;
    string klasa;
    int sila;
    char kierunek;
    int odliczanie;

public:
    bool IsHitting;
    int hp;
    int postacx,postacy;
    sf::Texture tekstura;
    sf::Sprite obrazek;
    sf::Texture teksturacios;
    sf::Sprite cios;
    sf::Texture teksturacien;
    sf::Sprite cien;

    Postac(string="brak",int=100,int=10,int=200,int=200, char='s',bool=false,int=0);

    void stworz();
    void ruch(Wrog*enemy,Mapa*las1);
    void atak();
    void skillbandyta();
};
