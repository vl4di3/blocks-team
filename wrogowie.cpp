#include "postaci.h"
#include "levele.h"
#include "wrogowie.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace std;
void Wrog::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(obrazek);
    target.draw(cien);
}
void Wrog::stworz()
{

    tekstura.loadFromFile( "enemy.png" );
    obrazek.setTexture( tekstura );
    obrazek.setColor(sf::Color(255,255,255));
    obrazek.setOrigin( 16, 16 ); //INFO: dopisane w tym rozdziale
    obrazek.setPosition( postacx, postacy ); //INFO: dopisane w tym rozdziale
    obrazek.setRotation( 0 ); //INFO: dopisane w tym rozdziale
    obrazek.setScale( 2, 2 );
    teksturacien.loadFromFile( "cien.png" );
    cien.setTexture( teksturacien );
    cien.setOrigin( 8, 8 );
    cien.setScale( 2, 2 );
    cien.setRotation( 0 );
    cien.setPosition( postacx, postacy+40 );
    hpb.setOrigin( 50, 50 );
    hpn.setOrigin( 50, 50 );
    hpb.setPosition(postacx,postacy);
    hpn.setPosition(postacx,postacy);
    hpb.setFillColor(sf::Color(0,0,0));
    hpn.setFillColor(sf::Color(255,0,0));
    hpb.setSize(sf::Vector2f(100,10));
    hpn.setSize(sf::Vector2f(getHp(),10));
}
Wrog::Wrog(string n, int h, int s,int bx, int by,char k)
{
    nazwa=n;
    hp=h;
    sila=s;
    postacx=bx;
    postacy=by;
    kierunek=k;
}
void Wrog::setHp(int x)
{
    if(hp>0)
        hp+=x;
}
int Wrog::getHp()
{
    return hp;
}
void Wrog::zabij()
{
    if(hp<=0)
    {
        obrazek.setPosition(-1000,-1000);
        cien.setPosition(-1000,-1000);
        hpb.setPosition(-1000,-1000);
        hpn.setPosition(-1000,-1000);
    }
}
