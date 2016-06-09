#include "postaci.h"
#include "levele.h"
#include "wrogowie.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace std;

void Postac::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(cien);
    target.draw(obrazek);
}

void Postac::stworz()
{

    tekstura.loadFromFile( "bandytass.png" );
    obrazek.setTexture( tekstura );
    obrazek.setOrigin( 16, 17 );
    obrazek.setPosition( postacx, postacy );
    obrazek.setRotation( 0 );
    obrazek.setScale( 2, 2 );
    teksturacios.loadFromFile( "cios.png" );
    cios.setTexture( teksturacios );
    cios.setOrigin( 8, 8 );
    cios.setScale( 3, 3 );
    cios.setRotation( 0 );
    teksturacien.loadFromFile( "cien.png" );
    cien.setTexture( teksturacien );
    cien.setOrigin( 8, 8 );
    cien.setScale( 2, 2 );
    cien.setRotation( 0 );
}
Postac::Postac(string n, int h, int s,int bx, int by,char k, bool ih)
{
    nazwa=n;
    hp=h;
    sila=s;
    postacx=bx;
    postacy=by;
    kierunek=k;
    IsHitting=ih;
}
void Postac::ruch(Wrog*enemy,Mapa*las1)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&IsHitting==false)
    {
        obrazek.move(sf::Vector2f(-6,0) );
        postacx-=6;
        kierunek='a';
        tekstura.loadFromFile( "bandytaas.png" );
        obrazek.setTexture( tekstura );
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&IsHitting==false)
    {
        if(postacx+40<las1->obrazek[0].getPosition().x||postacy-16>las1->obrazek[0].getPosition().y||postacy+64<las1->obrazek[0].getPosition().y)
        {
            obrazek.move(sf::Vector2f(6,0));
            postacx+=6;
            kierunek='d';
            tekstura.loadFromFile( "bandytads.png" );
            obrazek.setTexture( tekstura );
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&IsHitting==false)
    {
        obrazek.move(sf::Vector2f(0,6) );
        postacy+=6;
        kierunek='s';
        tekstura.loadFromFile( "bandytass.png" );
        obrazek.setTexture( tekstura );
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&IsHitting==false)
    {
        obrazek.move(sf::Vector2f(0,-6) );
        postacy-=6;
        kierunek='w';
        tekstura.loadFromFile( "bandytaws.png" );
        obrazek.setTexture( tekstura );
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)&&IsHitting==false)
    {
        switch(kierunek)
        {
        case('a'):
        {
            cios.setPosition( postacx-32, postacy );
            cios.setRotation( 180 );
            break;
        }
        case('d'):
        {
            cios.setPosition( postacx+32, postacy );
            cios.setRotation( 0 );
            break;
        }
        case('s'):
        {
            cios.setPosition( postacx, postacy+32 );
            cios.setRotation( 90 );
            break;
        }
        case('w'):
        {
            cios.setPosition( postacx, postacy-32 );
            cios.setRotation( 270 );
            break;
        }
        }
        IsHitting=true;
        if(enemy->postacx-32<=cios.getPosition().x+24&&enemy->postacy-34<=cios.getPosition().y+24&&enemy->postacx+32>=cios.getPosition().x-24&&enemy->postacy+34>=cios.getPosition().y-24)
        {
            enemy->setHp(-10);
        }
    }
    cien.setPosition( postacx, postacy+40 );
}
void Postac::atak()
{
    Sleep(100);
    IsHitting=false;
    Sleep(200);
}
