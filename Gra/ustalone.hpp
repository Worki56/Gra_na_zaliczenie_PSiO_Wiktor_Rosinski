#ifndef ustalone_hpp
#define ustalone_hpp
#include "ksztalt.hpp"
#include "kwadrat.hpp"
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
friend class Ksztalt;

int klo=0;
Ustalone(){}


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
    for(int i=0; i<1000; i=i+100)
    {
        for(int j1=-1000;j1<1000;j1=j1+100)
        {
            for(int j2=-1000;j2<1000;j2=j2+100)
            {
                int asd=0;
                for(auto &reca : elementyus)
                {
                    if((reca.distancez1==i && reca.distancex1==j1) && reca.distancey1==j2)
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
            if(reca==rec.distancez1 )
            {
                elementyus.erase(elementyus.begin()+asdd);
            }
            else if(reca<rec.distancez1)
            {
                rec.distancez1=rec.distancez1-100;
            }
            asdd++;
        }
        for(auto &reca : pelne)
        {
            reca=reca-100;
        }
        
    }
}


};



#endif
