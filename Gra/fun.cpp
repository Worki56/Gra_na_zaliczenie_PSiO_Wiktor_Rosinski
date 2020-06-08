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

void Opcja1()
{

    int a1;


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
    system("cls");
    std::cout<<"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta"<<std::endl;
    while(1)
    {
        std::cout<<"Podaj illośc kratek x"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1%2==1 && a1>=5)
            {
                dlu=((a1-1)/2)*100;
                break;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }

    while(1)
    {
        std::cout<<"Podaj illośc kratek y"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1%2==1 && a1>=5)
            {
                dlu1=((a1-1)/2)*100;
                break;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }

    while(1)
    {
        std::cout<<"Podaj illośc kratek z"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1>=5)
            {
                wys=(a1-1)*100;
                break;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }


    if(dlu<=dlu1){dlu2=dlu1;}
    else{dlu2=dlu;}

    while(1){
        std::cout<<"Podaj szybkość początkową {1,2,3}"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1==3 || a1==2 || a1==1)
            {
                szyb1=a1;
                break;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }


    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    set_viewport(window.getSize().x, window.getSize().y,wys,dlu2);
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);

    system("cls");
    std::cout<<"Posiadane punkty:0"<<std::endl;
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
                    std::cout<<"Koniec gry"<<std::endl;
                    pausa=pk4.punkty;
                    running = false;
                    window.close();
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
    std::string pseudonim;
    std::cout<<"Otrzymałeś: "<<pausa<<" punktów"<<std::endl;
    std::cout<<"Podaj pseudonim"<<std::endl;
    std::cin>>pseudonim;
    std::string nazwa_pliku="wynik.txt";
    std::ofstream plik1(nazwa_pliku.c_str(),std::ios::app);

    plik1<<pseudonim<<"  "<<pausa<<std::endl;
    plik1.close();



}

void Opcja3()
{
    std::fstream file("wynik.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            std::cout<<line<<std::endl;
        }
    }
    std::cout<<"Nacińskij BackSpace a wrócić do Menu"<<std::endl;
    while (1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            break;
        }
    }
}
void Opcja4()
{
    system("cls");
    std::cout<<"Gra opiera się na mechanice znanej z gry tetris."<<std::endl;
    std::cout<<"Strzałkami góra/dół obracamy klocek w osi x a strzałkami w bok w osi z o 90 stopni "<<std::endl;
    std::cout<<"Klawiszem E przesuwamy obiekt w osi x w przód a R w tył "<<std::endl;
    std::cout<<"Klawiszem F przesuwamy obiekt w osi y w przód a D w tył "<<std::endl;
    std::cout<<"Klawiszem P urachamiamy pause "<<std::endl;
    std::cout<<"Spacją przesuwamy w dół obiekt"<<std::endl;
    std::cout<<"Sroolem myszy obracmy plansze"<<std::endl;
    std::cout<<"Autor Wiktor Rosiński"<<std::endl;
    std::cout<<"Nacińskij BackSpace a wrócić do Menu"<<std::endl;
    while (1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            break;
        }
    }
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


