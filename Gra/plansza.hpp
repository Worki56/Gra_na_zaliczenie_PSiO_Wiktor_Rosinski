#ifndef plansza_hpp
#define plansza_hpp

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

class Plansza{
friend class Ksztalt;
public:

int rozmiarz=1000;
int rozmiarx=1000;
int rozmiary=1000;
float szybkosc=1;
    Plansza(int &x, int &y ,int &z,int &szy);

    void drawpomoc(int &kat);
	
};
#endif
