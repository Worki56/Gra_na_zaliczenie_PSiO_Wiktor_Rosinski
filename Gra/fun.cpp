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
//#include "kwadrat.hpp"
#include "ksztalt.hpp"
#include "ustalone.hpp"
#include "plansza.hpp"

int Opcja1(){

    int spr=0;
    int a1;
    int a2;
    int a3;


    int dlu=200;
    int dlu1=600;
    int dlu2=150;
    int wys=600;
    int szyb1=3;
    int szyb=3;
    srand( time( NULL ) );
    std::cout<<"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta"<<std::endl;
    while(spr==0){
    std::cout<<"Podaj illośc kratek x"<<std::endl;
    std::cin>>a1;
    if(a1%2==1 && a1>=3){spr=1;}
    else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
    }
    spr=0;
    while(spr==0){
    std::cout<<"Podaj illośc kratek y"<<std::endl;
    std::cin>>a2;
    if(a1%2==1 && a1>=3){spr=1;}
    else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
    }
    spr=0;
    while(spr==0){
    std::cout<<"Podaj illośc kratek z"<<std::endl;
    std::cin>>a3;
    if(a1>=3){spr=1;}
    else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
    }

    dlu=((a1-1)/2)*100;
    dlu1=((a2-1)/2)*100;
    wys=(a3-1)*100;
    if(dlu<=dlu1){dlu2=dlu1;}
    else{dlu2=dlu;}
    spr=0;
    while(spr==0){
    std::cout<<"Podaj szybkość początkową {1,2,3}"<<std::endl;
    std::cin>>a1;
    if(a1==3 || a1==2 || a1==1)
    {
        spr=1;
    szyb1=a1;
    }
    else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
    }



    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    set_viewport(window.getSize().x, window.getSize().y,wys,dlu2);
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);


    GLfloat light_position[] = { 100.0, 100.0, 100.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );


    GLfloat global_ambient[] = {0.3, 0.3, 0.3, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glEnable(GL_NORMALIZE) ;
    bool running = true;

    Plansza plan(dlu,dlu1,wys,szyb);
    Ustalone pk4(plan);


    std::vector<Ksztalt> pk5;


    int ala=0;
    std::string ust1;
    pk5.emplace_back(plan);

    while (running)
    {
        system("cls");
        if(szyb1==3){
            szyb=3;
        }
        else if(szyb1==2){
           if(pk4.punkty>100)
            {
              szyb=3;
            }
           else{szyb=2;}
        }
        else if(szyb1==1)
        {
            if(pk4.punkty>1000)
             {
               szyb=3;
             }
            else if(pk4.punkty>100)
            {
                szyb=2;

            }
            else{szyb=1;}

        }
        plan.szybkosc=szyb;




        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                ala=ala+event.mouseWheelScroll.delta*10;

            }

            if (event.type == sf::Event::Closed)
            {

                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {

                set_viewport(event.size.width, event.size.height,wys,dlu2);
            }
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        plan.drawpomoc(ala);

       if(pk5[0].step(ala,pk4)==0){
           pk5.clear();
           pk5.emplace_back(plan);


           if(pk4.sprawdzanie()==0){

               std::cout<<"Koniec gry"<<std::endl;
               running = false;
           }
       }
       pk4.step(ala);

       window.display();


    }

    return 0;




};
void Opcja2(){};
void Opcja3(){};
void Opcja4(){};

void set_viewport(int width, int height,int wys, int dlu)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, dlu*20);
    gluLookAt(dlu*4,0,wys*2.5+500, 0, 0, 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


