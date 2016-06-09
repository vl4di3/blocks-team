#pragma once
#include "postaci.h"
#include "levele.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Wrog :public sf::Drawable, sf::Transformable
{
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    string nazwa;
    int sila;
    char kierunek;
    int hp;
public:
    void setHp(int x);
    int getHp();
    int postacx,postacy;
    sf::Texture tekstura;
    sf::Sprite obrazek;
    sf::Texture teksturacien;
    sf::Sprite cien;
    sf::RectangleShape hpb;
    sf::RectangleShape hpn;


    Wrog(string="brak",int=100,int=10,int=200,int=400, char='s');

    void stworz();
    void zabij();
};
