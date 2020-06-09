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



#include "fun.hpp"
#include "ksztalt.hpp"
#include "ustalone.hpp"
#include "plansza.hpp"

int Opcja1(int &a1,int &a2,int &a3,int &a4)
{




    int z=0;
    double sekunda=0;
    int licznik=0;
    int licznik1=0;
    sf::Clock clk;
    int pausa=0;

    int dlu=200;
    int dlu1=600;
    int dlu2=150;
    int wys=600;
    int szyb1=3;
    int szyb=3;
    double szyb3=3;
    srand( time( NULL ) );

    dlu=((a1-1)/2)*100;
    dlu1=((a2-1)/2)*100;
    wys=(a3-1)*100;
    szyb1=a4;




    if(dlu<=dlu1){dlu2=dlu1;}
    else{dlu2=dlu;}

    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    set_viewport(window.getSize().x, window.getSize().y,wys,dlu2);
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);



    bool running = true;
    Plansza plan(dlu,dlu1,wys,szyb);
    Ustalone pk4(plan);
    std::vector<Ksztalt> pk5;
    int ala=0;
    std::string ust1;
    pk5.emplace_back(plan);
    sf::Event event;
    if(szyb1==3)
    {
        szyb=9;
    }
    else if(szyb1==2)
    {
       if(pk4.punkty>100)
       {
          szyb=9;
       }
       else{szyb=4;}
    }
    else if(szyb1==1)
    {
        if(pk4.punkty>1000)
         {
           szyb=9;
         }
        else if(pk4.punkty>100)
        {
            szyb=4;

        }
        else{szyb=1;}

    }
    while (running)
    {


        sf::Time elapsed1 = clk.restart();
        licznik++;
        sekunda=sekunda+elapsed1.asSeconds();        
        if(sekunda>1.0)
        {
            sekunda=sekunda-1.0;
            //std::cout<<licznik<<std::endl;
            licznik1=licznik;
            licznik=0;
        }
        if(z==0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                if(pausa==0){pausa=1;}
                 else{pausa=0;}
            }
            z++;
        }
        else
        {
            z++;
            if(z>10)
            {
                z=0;
            }
        }

        while (window.pollEvent(event))
        {



            if (event.type == sf::Event::MouseWheelScrolled)
            {
                ala=ala+event.mouseWheelScroll.delta*10;
            }

            if (event.type == sf::Event::Closed)
            {
                std::cout<<"Koniec gry"<<std::endl;
                pausa=pk4.punkty;
                running = false;
                window.close();
            }
            else if (event.type == sf::Event::Resized)
            {

                set_viewport(event.size.width, event.size.height,wys,dlu2);
            }

        }

        if(pausa==0)
        {
            szyb3=szyb*(licznik1/60);

            for(auto &reca : pk5[0].elementy)
            {
                reca.pre(szyb3);
            }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
            glEnable (GL_COLOR_MATERIAL);

            plan.drawpomoc(ala);
            if(pk5[0].step(ala,pk4)==0)
            {
                pk5.clear();
                plan.szybkosc=szyb3;
                pk5.emplace_back(plan);


                if(pk4.sprawdzanie()==0)
                {

                    pausa=pk4.punkty;
                    running = false;
                    //window.close();
                }
                else
                {


                    if(szyb1==3)
                    {
                        szyb=9;
                    }
                    else if(szyb1==2)
                    {
                       if(pk4.punkty>100)
                       {
                          szyb=9;
                       }
                       else{szyb=4;}
                    }
                    else if(szyb1==1)
                    {
                        if(pk4.punkty>1000)
                         {
                           szyb=9;
                         }
                        else if(pk4.punkty>100)
                        {
                            szyb=4;

                        }
                        else{szyb=1;}

                    }
                }
            }
            pk4.step(ala);
        }
        else
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
            glEnable (GL_COLOR_MATERIAL);
            plan.drawpomoc(ala);
            pk4.step(ala);
            pk5[0].draw(ala);
        }
        window.display();
    }


    return pausa;

}



void czyszczenie()
{
    std::cin.clear();
    std::cin.sync();
    std::cout<<"Podałeś złą wartość "<<std::endl;
}

void set_viewport(int  width, int  height,int & wys, int & dlu)
{
    int as;
    const float ar = (float)width / (float)height;
    if(wys>dlu){as=wys;}
    else{as=dlu;}
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, as*20);
    gluLookAt(dlu*4,0,wys*2+500, 0, 0, 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


std::vector<sf::Text> opdff(int &as, sf::Font &asf)
{
    int i=1;
    std::vector<sf::Text> ads;
    switch (as)
    {
    case 1:
       ads.emplace_back(L"Witaj w Tetris3D",asf);
       ads.emplace_back(L"Wybierz Opcje",asf);
       ads.emplace_back(L"1.Gra",asf);
       ads.emplace_back(L"2.Wyniki",asf);
       ads.emplace_back(L"3.Jak działa gra",asf);
       ads.emplace_back(L"4.Koniec",asf);
       ads[0].setPosition(400,100);
       ads[1].setPosition(100,200);
       ads[2].setPosition(100,300);
       ads[3].setPosition(100,400);
       ads[4].setPosition(100,500);
       ads[5].setPosition(100,600);
       for(auto &reca : ads)
       {
           reca.setFillColor(sf::Color::White);
           reca.setCharacterSize(34);
       }
        break;
    case 2:

        ads.emplace_back(L"Gra opiera się na mechanice znanej z gry tetris.",asf);
        ads.emplace_back(L"Strzałkami góra/dół obracamy klocek w osi x",asf);
        ads.emplace_back(L"a strzałkami w bok w osi z o 90 stopni.",asf);
        ads.emplace_back(L"Klawiszem W przesuwamy obiekt w osi x w przód",asf);
        ads.emplace_back(L" a S w tył.",asf);
        ads.emplace_back(L"Klawiszem D przesuwamy obiekt w osi y w przód",asf);
        ads.emplace_back(L" a A w tył.",asf);
        ads.emplace_back(L"Klawiszem P urachamiamy pause.",asf);
        ads.emplace_back(L"Spacją przesuwamy w dół obiekt.",asf);
        ads.emplace_back(L"Sroolem myszy obracmy plansze.",asf);
        ads.emplace_back(L"Autor Wiktor Rosiński",asf);
        ads.emplace_back(L"Nacińskij BackSpace a wrócić do Menu",asf);
        for(auto &reca : ads)
        {
            reca.setPosition(100,i*50);
            reca.setFillColor(sf::Color::White);
            reca.setCharacterSize(30);
            i++;
        }
        break;
    case 10:
        ads.emplace_back(L"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta",asf);
         ads.emplace_back(L" Podaj illośc kratek x",asf);
         ads[0].setPosition(100,100);
         ads[0].setFillColor(sf::Color::White);
         ads[0].setCharacterSize(20);
         ads[1].setPosition(100,200);
         ads[1].setFillColor(sf::Color::White);
         ads[1].setCharacterSize(20);
        break;
    case 11:
        ads.emplace_back(L"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta",asf);
         ads.emplace_back(L" Podaj illośc kratek y",asf);
         ads[0].setPosition(100,100);
         ads[0].setFillColor(sf::Color::White);
         ads[0].setCharacterSize(20);
         ads[1].setPosition(100,200);
         ads[1].setFillColor(sf::Color::White);
         ads[1].setCharacterSize(20);
         break;
    case 12:
        ads.emplace_back(L"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta",asf);
         ads.emplace_back(L" Podaj illośc kratek z",asf);
         ads[0].setPosition(100,100);
         ads[0].setFillColor(sf::Color::White);
         ads[0].setCharacterSize(20);
         ads[1].setPosition(100,200);
         ads[1].setFillColor(sf::Color::White);
         ads[1].setCharacterSize(20);
         break;
    case 13:
         ads.emplace_back(L"Podaj szybkość początkową {1,2,3}",asf);
         ads[0].setPosition(100,100);
         ads[0].setFillColor(sf::Color::White);
         ads[0].setCharacterSize(20);

         break;
    case 14:
         ads.emplace_back(L"Zdobyte punkty:",asf);
         ads[0].setPosition(100,400);
         ads[0].setFillColor(sf::Color::White);
         ads[0].setCharacterSize(30);
         ads.emplace_back(L"Podaj pseudonim:",asf);
         ads[1].setPosition(400,100);
         ads[1].setFillColor(sf::Color::White);
         ads[1].setCharacterSize(30);

         break;

    case 4:
        std::fstream file("wynik.txt");

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::stringstream str(line);

                ads.emplace_back(line,asf);
            }
        }
        for(auto &reca : ads)
        {
            reca.setPosition(100,50+i*20);
            reca.setFillColor(sf::Color::White);
            reca.setCharacterSize(20);

            i++;
        }
        sf::Text te(L"Nacińskij BackSpace a wrócić do Menu",asf);
        te.setPosition(100,20);
        te.setFillColor(sf::Color::White);
        te.setCharacterSize(20);
        ads.emplace_back(te);

        break;


   }


    return ads;
}
