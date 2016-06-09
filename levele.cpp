#include "levele.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(tlo);
    //Tutaj rysuje się tekstury ( w nawiasie jest nazwa rysowanego sprita)
}
Mapa::Mapa(string n)
{
    nazwa=n;
}
void Mapa::stworz()
{
    teksturatlo.loadFromFile( "tlo.png" );//zaladowanie tekstury z pliku (w nawiasie jest nazwa pliku, ktory ma sie znajdowac w folderze projektu i folderze z plikiem .exe
    tlo.setTexture( teksturatlo );//podpiecie tekstury pod sprita
    tlo.setOrigin( 500, 500 );//srodek planszy
    tlo.setPosition( 0, 0 );//okreslenie pozycji mapy wzgledem lewego gornego rogu okna(tymczasowo niech zostanie 200,200)
    tlo.setScale( 2, 2);//powiekszenie tekstury (niech zostanie 2,2)
    tekstura[0].loadFromFile( "drzewo.png" );
    obrazek[0].setTexture( tekstura[0] );
    obrazek[0].setOrigin( 16, 16 );
    obrazek[0].setPosition( 300, 300 );
    obrazek[0].setRotation( 0 );
    obrazek[0].setScale( 2, 2 );
    //tak samo z obiektami na mapie jak i z mapa

}

