#ifndef ustalone_hpp
#define ustalone_hpp

#include "kwadrat.hpp"

#include "plansza.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <math.h>


class Ustalone {
public:
std::vector<Kwadrat> elementyus;
std::vector<Kwadrat> elementyus2;
friend class Ksztalt;

int wymiarx=1000;
int wymiary=1000;
int wymiarz=1000;
int zlicz=0;
double punkty=0;

int klo=0;

Ustalone(Plansza asd);


void step(int kat);

int sprawdzanie();




};



#endif
