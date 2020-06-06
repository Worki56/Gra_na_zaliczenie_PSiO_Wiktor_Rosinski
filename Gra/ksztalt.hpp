#ifndef ksztalt_hpp
#define ksztalt_hpp
#include "kwadrat.hpp"
#include "ustalone.hpp"
#include <cstdlib>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <memory>
#include <math.h>
#include <fstream>
#include <sstream>
#define GL_SILENCE_DEPRECATION
#include <SFML/OpenGL.hpp>
#ifdef __APPLE__
#include <OpenGL/glu.h> // macOS
#else
#include <GL/glu.h> // Windows/Linux
#endif

class Ksztalt
{
public:
    int diameter=100;
    std::vector<Kwadrat> elementy;
    int color1;
    int color2;
    int color3;
    int iloelem=2;
    int koniec=1;
    int zwal=0;

    Ksztalt(Plansza & asde)
    {
        std::vector<int> asd;
        asd.emplace_back(asde.rozmiarx);
        asd.emplace_back(asde.rozmiary);
        asd.emplace_back(asde.rozmiarz);
        asd.emplace_back(asde.szybkosc);
        //srand( time( NULL ) );
        color1=( std::rand() % 255 );
        color2=( std::rand() % 255 );
        color3=( std::rand() % 255 );
        iloelem=( std::rand() % 5 );

        switch (iloelem)
        {
        case 0:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,0,diameter);
            elementy.emplace_back(asd,0,diameter,0);
            elementy.emplace_back(asd,0,-diameter,0);
            break;
        case 1:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,0,diameter);
            elementy.emplace_back(asd,0,diameter,diameter);
            elementy.emplace_back(asd,0,diameter,0);
            elementy.emplace_back(asd,diameter,0,0);
            elementy.emplace_back(asd,diameter,0,diameter);
            elementy.emplace_back(asd,diameter,diameter,diameter);
            elementy.emplace_back(asd,diameter,diameter,0);
            break;
        case 2:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,0,diameter);
            elementy.emplace_back(asd,0,0,2*diameter);
            elementy.emplace_back(asd,0,0,3*diameter);
            break;
        case 3:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,0,diameter);
            elementy.emplace_back(asd,0,diameter,0);
            elementy.emplace_back(asd,0,2*diameter,0);
            break;
        case 4:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,diameter,0);
            elementy.emplace_back(asd,0,diameter,diameter);
            elementy.emplace_back(asd,0,2*diameter,diameter);
            break;
        case 5:
            elementy.emplace_back(asd,0,0,0);
            elementy.emplace_back(asd,0,0,diameter);
            elementy.emplace_back(asd,0,diameter,diameter);
            elementy.emplace_back(asd,0,-diameter,diameter);
            elementy.emplace_back(asd,0,0,2*diameter);
            break;
        }

        for(auto &reca : elementy)
        {
            reca.color1=color1;
            reca.color2=color2;
            reca.color3=color3;
        }
    }


    int step(int kat, Ustalone & asd)
    {
        if(zwal==0)
        {
            int ui8=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                for(auto &reca : elementy)
                {

                    if(reca.kolizja1(asd.elementyus)==0)
                    {ui8++;}
                }
                std::cout<<ui8<<std::endl;

                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {

                        reca.kolizja11();
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                for(auto &reca : elementy)
                {
                    reca.pustawienie1=reca.ustawienie1+1;
                    reca.pustawienie2=reca.ustawienie2;
                    if(reca.kolizjaprob(asd.elementyus)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.ustawienie1=reca.ustawienie1+1;
                        reca.zamiana();
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {

                for(auto &reca : elementy)
                {
                    reca.pustawienie1=reca.ustawienie1-1;
                    reca.pustawienie2=reca.ustawienie2;
                    if(reca.kolizjaprob(asd.elementyus)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.ustawienie1=reca.ustawienie1-1;
                        reca.zamiana();
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                for(auto &reca : elementy)
                {
                    reca.pustawienie2=reca.ustawienie2+1;
                    reca.pustawienie1=reca.ustawienie1;
                    if(reca.kolizjaprob(asd.elementyus)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.ustawienie2=reca.ustawienie2+1;
                        reca.zamiana();
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                for(auto &reca : elementy)
                {
                    reca.pustawienie2=reca.ustawienie2-1;
                    reca.pustawienie1=reca.ustawienie1;
                    if(reca.kolizjaprob(asd.elementyus)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.ustawienie2=reca.ustawienie2-1;
                        reca.zamiana();
                    }
                    zwal++;
                }

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                for(auto &reca : elementy)
                {

                    if(reca.kolizjaprob(asd.elementyus,-1,0)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.distancex1=reca.distancex1-reca.przesuniecie1;
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                for(auto &reca : elementy)
                {
                    if(reca.kolizjaprob(asd.elementyus,1,0)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.distancex1=reca.distancex1+reca.przesuniecie1;
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                for(auto &reca : elementy)
                {

                    if(reca.kolizjaprob(asd.elementyus,0,-1)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.distancey1=reca.distancey1-reca.przesuniecie1;
                    }
                    zwal++;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {
                for(auto &reca : elementy)
                {
                    if(reca.kolizjaprob(asd.elementyus,0,1)==0)
                    {ui8++;}
                }
                if(ui8==0)
                {
                    for(auto &reca : elementy)
                    {
                        reca.distancey1=reca.distancey1+reca.przesuniecie1;
                    }
                    zwal++;
                }
            }
        }
        else
        {
            zwal++;
            if(zwal>10)
            {
                zwal=0;
            }
        }



        for(auto &reca : elementy)           
        {
            int alas=reca.step(kat,asd.elementyus);
            if(alas!=1)
            {
                for(auto &reca : elementy)
                {
                    reca.as(alas);

                }
                 koniec=0;
                break;

            }

        }
        if(koniec==0)
        {
            for(auto &reca : elementy)
            {
                reca.dziala=0;
            }

            for(auto &reca : elementy)
            {
                asd.elementyus.emplace_back(reca);
            }
          return 0;
        }
        return 1;
    }

};

#endif
