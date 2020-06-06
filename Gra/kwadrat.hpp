#ifndef kwadrat_hpp
#define kwadrat_hpp
//#include "ksztalt.hpp"

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

class Kwadrat {
public:

    int wymiarx=1000;
    int wymiary=1000;
    int wymiarz=1000;

    int distancez=1000;
    int distancez1=1000;
    int distancex1=0;
    int distancey1=0;
    int distancez1p=1000;
    int distancex=0;
    int distancey=0;
    int diameter=100;

    int pdx1=0;
    int pdy1=0;
    int pdz1=0;
    int pdx2=0;
    int pdy2=0;
    int pdz2=0;

    int ppdx1=0;
    int ppdy1=0;
    int ppdz1=0;
    int ppdx2=0;
    int ppdy2=0;
    int ppdz2=0;

    int prawdziwez=0;
    int prawdziwex=0;
    int prawdziwey=0;

    int probnez=0;
    int probney=0;
    int probnex=0;

    int przesuniecie=1;
    int przesuniecie1=100;
    int color1;
    int color2;
    int color3;

    bool dziala=1;

    int ustawienie1=0;
    int ustawienie2=0;

    int pustawienie1=0;
    int pustawienie2=0;


    Kwadrat(std::vector<int> asd,int x,int y ,int z);
    void step(int kat);

    void zamiana();

    void przamiana();


   int kolizja(std::vector<Kwadrat> & asd);

   int kolizja1(std::vector<Kwadrat> & asd);

   void kolizja11();


   int kolizjaprob(std::vector<Kwadrat> & asd);

   int kolizjaprob(std::vector<Kwadrat> & asd,int xd,int yd);


    int step(int kat, std::vector<Kwadrat> & asd);

    void as(int a);

    void draw(int kat);

    void draw_cube(double size, double color1, double color2, double color3);


};
#endif
