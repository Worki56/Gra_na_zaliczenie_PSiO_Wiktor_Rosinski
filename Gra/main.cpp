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
#include "ksztalt.hpp"
#include "ustalone.hpp"
#include "plansza.hpp"








void set_viewport(int width, int height,int wys, int dlu)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, dlu*20);
    gluLookAt(dlu*4,0,wys*2.75, 0, 0, 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main()
{
int dlu=500;
int wys=600;
int szyb=1;

    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    set_viewport(window.getSize().x, window.getSize().y,wys,dlu);
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

    Plansza plan(dlu,dlu,wys,szyb);
    Ustalone pk4(plan);

    int asddf=0;
    std::vector<Ksztalt> pk5;


    int ala=0;
    std::string ust1;
    pk5.emplace_back(plan);

    while (running)
    {



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

                set_viewport(event.size.width, event.size.height,wys,dlu);
            }
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        plan.drawpomoc(ala);

       if(pk5[asddf].step(ala,pk4)==0){
           pk5.emplace_back(plan);
           asddf++;
           pk4.sprawdzanie();
       }
       pk4.step(ala);
       if(plan.punkty>1000)
       {
           plan.szybkosc=2;
       }

       window.display();
    }

    return 0;
}
