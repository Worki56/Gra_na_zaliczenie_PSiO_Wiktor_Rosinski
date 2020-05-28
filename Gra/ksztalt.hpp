#ifndef ksztalt_hpp
#define ksztalt_hpp
#include "kwadrat.hpp"
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
    int iloelem=4;
    int koniec=1;
    Ksztalt()
    {
        color1=( std::rand() % 255 );
         color2=( std::rand() % 255 );
         color3=( std::rand() % 255 );
        //iloelem=( std::rand() % 5 );

        switch (iloelem)
        {
        case 0:
        elementy.emplace_back(0,0,0);
        elementy.emplace_back(0,0,diameter);
        elementy.emplace_back(0,diameter,0);
        elementy.emplace_back(0,-diameter,0);
        break;
        case 1:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(diameter,0,0);
            elementy.emplace_back(diameter,0,diameter);
            elementy.emplace_back(diameter,diameter,diameter);
            elementy.emplace_back(diameter,diameter,0);

        break;
        case 2:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,0,2*diameter);
            elementy.emplace_back(0,0,3*diameter);
        break;
        case 3:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(0,2*diameter,0);

        break;
        case 4:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,2*diameter,diameter);

        break;
        case 5:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,-diameter,diameter);
            elementy.emplace_back(0,0,2*diameter);
        break;




        }




    }

    void ahk(){}

    int step(int kat)
    {
        for(auto &reca : elementy)
        {
        reca.color1=color1;
        reca.color2=color2;
        reca.color3=color3;

        }

        for(auto &reca : elementy)
        {
            if(reca.step(kat)==0)
            {

                koniec=0;


            }

        }
        if(koniec==0){
        for(auto &reca : elementy)
        {

         reca.dziala=0;

        }
        }

        return 0;
    }








};

#endif