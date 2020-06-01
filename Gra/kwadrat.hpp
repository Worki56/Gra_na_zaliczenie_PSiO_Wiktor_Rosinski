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
#include <math.h>
#define GL_SILENCE_DEPRECATION
#include <SFML/OpenGL.hpp>
#ifdef __APPLE__
#include <OpenGL/glu.h> // macOS
#else
#include <GL/glu.h> // Windows/Linux
#endif

class Kwadrat {
public:

    Kwadrat(std::vector<int> asd,int x,int y ,int z)
    {
        wymiarx=asd[0];
        wymiary=asd[1];

        distancez1=asd[2]+500;
        szyb=asd[3];

        distancex=x;
        distancey=y;
        distancez=z;
        zamiana();

    }

    void step(int kat)
    {

       draw(kat);

    }
    void zamiana()
    {
        if(abs(ustawienie1%4)==0)
        {
            pdx1=distancex;
            pdz1=distancez;
            pdy1=distancey;
        }
        else if(abs(ustawienie1%4)==1)
        {
            pdx1=distancez;
            pdz1=distancex;
            pdy1=distancey;
        }
        else if(abs(ustawienie1%4)==2)
        {
            pdx1=-distancex;
            pdz1=-distancez;
            pdy1=distancey;
        }
        else if(abs(ustawienie1%4)==3)
        {
            pdx1=-distancez;
            pdz1=-distancex;
            pdy1=distancey;
        }

        if(abs(ustawienie2%4)==0)
        {
            pdy2=pdy1;
            pdz2=pdz1;
            pdx2=pdx1;
        }
        else if(abs(ustawienie2%4)==1)
        {
            pdy2=pdz1;
            pdz2=pdy1;
            pdx2=pdx1;
        }
        else if(abs(ustawienie2%4)==2)
        {
            pdy2=-pdy1;
            pdz2=-pdz1;
            pdx2=pdx1;
        }
        else if(abs(ustawienie2%4)==3)
        {
            pdy2=-pdz1;
            pdz2=-pdy1;
            pdx2=pdx1;
        }
    }
    void przamiana()
    {
        if(abs(pustawienie1%4)==0)
        {
            ppdx1=distancex;
            ppdz1=distancez;
            ppdy1=distancey;
        }
        else if(abs(pustawienie1%4)==1)
        {
            ppdx1=distancez;
            ppdz1=distancex;
            ppdy1=distancey;
        }
        else if(abs(pustawienie1%4)==2)
        {
            ppdx1=-distancex;
            ppdz1=-distancez;
            ppdy1=distancey;
        }
        else if(abs(pustawienie1%4)==3)
        {
            ppdx1=-distancez;
            ppdz1=-distancex;
            ppdy1=distancey;
        }
        if(abs(pustawienie2%4)==0)
        {
            ppdy2=ppdy1;
            ppdz2=ppdz1;
            ppdx2=ppdx1;
        }
        else if(abs(pustawienie2%4)==1)
        {
            ppdy2=ppdz1;
            ppdz2=ppdy1;
            ppdx2=ppdx1;
        }
        else if(abs(pustawienie2%4)==2)
        {
            ppdy2=-ppdy1;
            ppdz2=-ppdz1;
            ppdx2=ppdx1;
        }
        else if(abs(pustawienie2%4)==3)
        {
            ppdy2=-ppdz1;
            ppdz2=-ppdy1;
            ppdx2=ppdx1;
        }
    }


   int kolizja(std::vector<Kwadrat> & asd)
   {
       for(auto &reca : asd)
       {
           if((reca.prawdziwez+100==prawdziwez && reca.prawdziwex==prawdziwex ) && reca.prawdziwey==prawdziwey)
           {
           return 0;
          }
       }
       return  1;
   }

   int kolizjaprob(std::vector<Kwadrat> & asd)
   {
       przamiana();
       probnez=distancez1+ppdz2;
       probney=distancey1+ppdy2;
       probnex=distancex1+ppdx2;


       for(auto &reca : asd)
       {
           if(probnez<0)
           {
               return 0;
           }
           if(probnex<-wymiarx || probnex >wymiarx)
           {
               return 0;
           }
           if(probney<-wymiary || probney >wymiary)
           {
               return 0;
           }


           if(((reca.prawdziwez+99>=probnez && reca.prawdziwez-99<=probnez )&& (reca.prawdziwex+99>=probnex && reca.prawdziwex-99<=probnex) ) && (reca.prawdziwey+99>=probney && reca.prawdziwey-99<=probney))
           {
               return 0;
           }

       }
       return  1;
   }

   int kolizjaprob(std::vector<Kwadrat> & asd,int xd,int yd)
   {
       pustawienie1=ustawienie1;
       pustawienie2=ustawienie2;
       przamiana();
       probnez=distancez1+ppdz2;
       probney=distancey1+ppdy2+yd*przesuniecie1;
       probnex=distancex1+ppdx2+xd*przesuniecie1;


       for(auto &reca : asd)
       {

           if(probnez<0)
           {
               return 0;
           }
           if(probnex<-wymiarx || probnex >wymiarx)
           {
               return 0;
           }
           if(probney<-wymiary || probney >wymiary)
           {
               return 0;
           }

           if(((reca.prawdziwez+100>=probnez && reca.prawdziwez-100<=probnez )&& (reca.prawdziwex+100>=probnex && reca.prawdziwex-100<=probnex) ) && (reca.prawdziwey+100>=probney && reca.prawdziwey-100<=probney))
           {
               return 0;
           }

       }
       return  1;
   }


    int step(int kat, std::vector<Kwadrat> & asd)
    {
       if(dziala==1)
       {
           distancez1=distancez1-przesuniecie;
           prawdziwez=distancez1+pdz2;
           prawdziwey=distancey1+pdy2;
           prawdziwex=distancex1+pdx2;

       }
       draw(kat);

       if(kolizja(asd)==0)
       {
           prawdziwez=distancez1+pdz2;
           prawdziwey=distancey1+pdy2;
           prawdziwex=distancex1+pdx2;

           return 0;

       }

       if(prawdziwez==0)
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

       glTranslated(pdx2, pdy2,pdz2);

       draw_cube(diameter,(1.0f/255)*color1,(1.0f/255)*color2,(1.0f/255)*color3);
       glPopMatrix();


    }
    void draw_cube(double size, double color1, double color2, double color3)
    {

        double half_cube_size = size / 2.0;


        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size+5, half_cube_size-5, -half_cube_size);
        glVertex3d(half_cube_size-5, half_cube_size-5, -half_cube_size);
        glVertex3d(half_cube_size-5, -half_cube_size+5, -half_cube_size);
        glVertex3d(-half_cube_size+5, -half_cube_size+5, -half_cube_size);
        glEnd();


        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size+1);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size+1);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size+1);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size+1);
        glEnd();

        // top
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size+5, half_cube_size-5, half_cube_size);
        glVertex3d(half_cube_size-5, half_cube_size-5, half_cube_size);
        glVertex3d(half_cube_size-5, -half_cube_size+5, half_cube_size);
        glVertex3d(-half_cube_size+5, -half_cube_size+5, half_cube_size);
        glEnd();

        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size-1);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size-1);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size-1);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size-1);
        glEnd();

        // left
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size+5, half_cube_size-5);
        glVertex3d(-half_cube_size, half_cube_size-5, half_cube_size-5);
        glVertex3d(-half_cube_size, half_cube_size-5, -half_cube_size+5);
        glVertex3d(-half_cube_size, -half_cube_size+5, -half_cube_size+5);
        glEnd();

        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size+1, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size+1, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size+1, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size+1, -half_cube_size, -half_cube_size);
        glEnd();



        // right

        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size, -half_cube_size+5, half_cube_size-5);
        glVertex3d(half_cube_size, half_cube_size-5, half_cube_size-5);
        glVertex3d(half_cube_size, half_cube_size-5, -half_cube_size+5);
        glVertex3d(half_cube_size, -half_cube_size+5, -half_cube_size+5);
        glEnd();

        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size-1, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size-1, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size-1, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size-1, -half_cube_size, -half_cube_size);
        glEnd();

        // front
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size+5, -half_cube_size, half_cube_size-5);
        glVertex3d(half_cube_size-5, -half_cube_size, half_cube_size-5);
        glVertex3d(half_cube_size-5, -half_cube_size, -half_cube_size+5);
        glVertex3d(-half_cube_size+5, -half_cube_size, -half_cube_size+5);
        glEnd();

        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size+1, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size+1, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size+1, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size+1, -half_cube_size);
        glEnd();


        // back
        glColor3d(color1, color2, color3);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size+5, half_cube_size, half_cube_size-5);
        glVertex3d(half_cube_size-5, half_cube_size, half_cube_size-5);
        glVertex3d(half_cube_size-5, half_cube_size, -half_cube_size+5);
        glVertex3d(-half_cube_size+5, half_cube_size, -half_cube_size+5);
        glEnd();

        glColor3d(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size-1, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size-1, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size-1, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size-1, -half_cube_size);
        glEnd();





    }

    int wymiarx=1000;
    int wymiary=1000;
    int wymiarz=1000;
    int szyb=1;

    int distancez=1000;
    int distancez1=1000;
    int distancex=0;
    int distancey=0;
    int distancex1=0;
    int distancey1=0;
    int diameter=100;

    int pdx1=0;
    int pdy1=0;
    int pdz1=0;
    int pdx2=0;
    int pdy2=0;
    int pdz2=0;

    int ppdx1=0;
    int ppdy1=0;
    int ppdz1=0;
    int ppdx2=0;
    int ppdy2=0;
    int ppdz2=0;



    int prawdziwez=0;
    int prawdziwex=0;
    int prawdziwey=0;


    int probnez=0;
    int probney=0;
    int probnex=0;

    double spint;
    int przesuniecie=1;
    int przesuniecie1=100;
    int color1;
    int color2;
    int color3;
    bool dziala=1;
    int ustawienie1=0;
    int ustawienie2=0;

    int pustawienie1=0;
    int pustawienie2=0;

};
#endif
