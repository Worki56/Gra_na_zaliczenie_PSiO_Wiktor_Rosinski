#ifndef ustalone_hpp
#define ustalone_hpp
#include "kwadrat.hpp"
#include "ksztalt.hpp"
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

int klo=0;
Ustalone(Plansza asd)
{
    wymiarx=asd.rozmiarx;
    wymiary=asd.rozmiary;
    wymiarz=asd.rozmiarz;


}


void step(int kat)
{
    for(auto &reca : elementyus)
    {
        reca.step(kat);


    }


}

void sprawdzanie()
{
    klo=0;
    std::vector<int> pelne;
    for(int i=0; i<=wymiarz; i=i+100)
    {
        for(int j1=-wymiarx;j1<=wymiarx;j1=j1+100)
        {
            for(int j2=-wymiary;j2<=wymiary;j2=j2+100)
            {
                int asd=0;
                for(auto &reca : elementyus)
                {
                    if((reca.prawdziwez==i && reca.prawdziwex==j1) && reca.prawdziwey==j2)
                    {
                        asd=1;
                        break;
                    }
                }
                if(asd==0)
                {
                    klo=1;
                    break;
                }
            }
            if(klo==1){break;}
        }
        if(klo==0)
        {
            pelne.emplace_back(i);
        }
        klo=0;
    }

    for(auto &reca : pelne)
    {
        int asdd=0;
        for(auto &rec : elementyus)
        {
            if(reca>rec.prawdziwez )
            {
                elementyus.erase(elementyus.begin()+asdd);
                elementyus2.emplace_back(rec);
            }
            else if(reca<rec.prawdziwez)
            {
                rec.prawdziwez=rec.prawdziwez-100;
                elementyus2.emplace_back(rec);
            }
            asdd++;
        }
        for(auto &reca : pelne)
        {
            reca=reca-100;
        }
        elementyus.clear();
        for(auto &reca : elementyus2)
        {
            elementyus.emplace_back(reca);
        }
        elementyus2.clear();

    }
}


};



#endif
