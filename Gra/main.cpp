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
#include "kwadrat.hpp"





/*
class Kwadrat : public Ksztalt
{

public:

    Kwadrat(int x,int y ,int z)
    {
        distancex=x;
        distancey=y;
        distancez=z;

    }

    int step(int kat)
    {
       if(dziala==1)
       {

       distancez1=distancez1-przesuniecie;
       if(zwal==0){
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
               {


                  ustawienie1=ustawienie1+1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                  ustawienie1=ustawienie1-1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
               {
                  ustawienie2=ustawienie2+1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
               {
                  ustawienie2=ustawienie2-1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
               {
                  ustawienie3=ustawienie3+1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
               {
                  ustawienie3=ustawienie3-1;
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
               {
           if(distancey1>-1000){
                  distancey1=distancey1-przesuniecie1;
           }
                  zwal++;
               }

       if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
               {
           if(distancey1<1000){
                  distancey1=distancey1+przesuniecie1;
                  }
                  zwal++;
               }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
               {
           if(distancex1>-1000){
                  distancex1=distancex1-przesuniecie1;
                  zwal++;
           }
               }

       if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
               {
           if(distancex1<1000){
                  distancex1=distancex1+przesuniecie1;
                  zwal++;
           }
               }

       }
       else
       {
           zwal++;
           if(zwal>10)
           {
               zwal=0;

           }
       }
       }




       draw(kat);
       if(distancez1==0)
       {
        dziala=0;
        return 0;
       }
       else{return 1;}
    }

    void draw(int kat)
    {


       glPushMatrix();

       glRotated(kat*10, 0.0, 0.0, 1.0);
       glTranslated(distancex1, distancey1,distancez1);
       glRotated(90*ustawienie1, 0.0, 1.0, 0.0);
       glRotated(90*ustawienie2, 1.0, 0.0, 0.0);
       glRotated(90*ustawienie3, 0.0, 0.0, 1.0);
       glTranslated(distancex, distancey,distancez);


       draw_cube(diameter,(1.0f/255)*color1,(1.0f/255)*color2,(1.0f/255)*color3);
       glPopMatrix();


    }
    void draw_cube(double size, double color1, double color2, double color3)
    {
        double half_cube_size = size / 2.0;

        // bottom

        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // top
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glEnd();

        // left
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // right
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // front
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // back
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glEnd();
    }



    int distancez=1000;
    int distancez1=300;
    int distancex=0;
    int distancey=0;
    int distancex1=0;
    int distancey1=0;
    int diameter=100;
    double spint;
    int przesuniecie=1;
    int przesuniecie1=100;
    int color1;
    int color2;
    int color3;
    bool dziala=1;
    int ustawienie1=0;
    int ustawienie2=0;
    int ustawienie3=0;
    int zwal=0;




};
*/



void set_viewport(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 10000.0);
    gluLookAt(1000, -1000,1000, 0, 0, 0, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main()
{

int diameter=100;

    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    window.setActive(true);

    set_viewport(window.getSize().x, window.getSize().y);

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

    Ksztalt pk5 ;


    int ala=0;
    std::string ust1;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                ala=ala+event.mouseWheelScroll.delta;



            }







            if (event.type == sf::Event::Closed)
            {

                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {

                set_viewport(event.size.width, event.size.height);
            }
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

       pk5.step(ala);

       //std::cout<<"zrobiłem"<<std::endl;
        glPushMatrix();

        window.display();
    }

    return 0;
}
