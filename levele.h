#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class Mapa  :public sf::Drawable, sf::Transformable
{
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    string nazwa;

    public:
    sf::Texture teksturatlo;//okreslanie zmiennej odpowiadajacej za teksture
    sf::Sprite tlo;//okreslenie zmiennej odpowiadajacej za sprita(to co bedzie wyswietlane)
    sf::Texture tekstura[100];
    sf::Sprite obrazek[100];
    Mapa(string="brak");
    void stworz();

};

