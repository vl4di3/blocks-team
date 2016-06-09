#include <iostream>
#include <SFML/Graphics.hpp>
#include "postaci.h"
#include "levele.h"
#include <Windows.h>

using namespace std;


int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 1000, 32 ), "#TEAM::BLOCKS" );
    Mapa las1;
    las1.stworz();
    Postac hero;
    hero.stworz();
    Wrog enemy;
    enemy.stworz();
    sf::Thread thread(&Postac::atak,&hero);
    while( oknoAplikacji.isOpen() )
    {
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                oknoAplikacji.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                oknoAplikacji.close();
            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                oknoAplikacji.close();
        }
        oknoAplikacji.draw(las1);
        enemy.hpn.setSize(sf::Vector2f(enemy.getHp(),10));
        hero.ruch(&enemy,&las1);
        if(hero.postacy>enemy.postacy)
        {
            oknoAplikacji.draw(enemy);
            oknoAplikacji.draw(hero);
        }
        else
        {
            oknoAplikacji.draw(hero);
            oknoAplikacji.draw(enemy);
        }
        oknoAplikacji.draw(las1.obrazek[0]);
        if(hero.IsHitting==true)
            thread.launch();
        if(hero.IsHitting==true)
            oknoAplikacji.draw(hero.cios);
        oknoAplikacji.draw(enemy.hpb);
        oknoAplikacji.draw(enemy.hpn);
        enemy.zabij();






        oknoAplikacji.display();
        Sleep(8);



    }
    return 0;
}
