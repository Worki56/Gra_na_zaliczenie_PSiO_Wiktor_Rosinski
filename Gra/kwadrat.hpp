#ifndef kwadrat_hpp
#define kwadrat_hpp
#include "ksztalt.hpp"
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

class Kwadrat
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
#endif
