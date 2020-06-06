#ifndef ksztalt_hpp
#define ksztalt_hpp
#include "kwadrat.hpp"
#include "ustalone.hpp"
#include "plansza.hpp"
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

    Ksztalt(Plansza & asde);



    int step(int kat, Ustalone & asd);


};

#endif
