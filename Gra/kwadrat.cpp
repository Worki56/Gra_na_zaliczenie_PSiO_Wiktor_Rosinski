#include "kwadrat.hpp"




Kwadrat::Kwadrat(std::vector<int>  asd,int  x,int  y ,int  z):wymiarx(asd[0]),wymiary(asd[1]),distancez(z),distancez1(asd[2]+500),distancex(x),distancey(y)
{
    przesuniecie=przesuniecie*asd[3];   
    zamiana();
}

void Kwadrat::pre(int  kat)
{
    przesuniecie=1*kat;
}

void Kwadrat::step(int & kat)
{
   draw(kat);
}

void Kwadrat::zamiana()
{
    int pdx1;
    int pdy1;
    int pdz1;

    if(ustawienie1%4==0)
    {
        pdx1=distancex;
        pdz1=distancez;
        pdy1=distancey;
    }
    else if(ustawienie1%4==1 || ustawienie1%4==-3)
    {
        pdx1=distancez;
        pdz1=distancex;
        pdy1=distancey;
    }
    else if(ustawienie1%4==2 || ustawienie1%4==-2)
    {
        pdx1=-distancex;
        pdz1=-distancez;
        pdy1=distancey;
    }
    else if(ustawienie1%4==3 ||  ustawienie1%4==-1)
    {
        pdx1=-distancez;
        pdz1=-distancex;
        pdy1=distancey;
    }

    if(ustawienie2%4==0)
    {
        pdy2=pdy1;
        pdz2=pdz1;
        pdx2=pdx1;
    }
    else if(ustawienie2%4==1 || ustawienie2%4==-3)
    {
        pdy2=pdx1;
        pdz2=pdz1;
        pdx2=pdy1;
    }
    else if(ustawienie2%4==2 || ustawienie2%4==-2)
    {
        pdy2=-pdy1;
        pdz2=pdz1;
        pdx2=-pdx1;
    }
    else if(ustawienie2%4==3 || ustawienie2%4==-1)
    {
        pdy2=-pdx1;
        pdz2=pdz1;
        pdx2=-pdy1;
    }
}

void Kwadrat::przamiana()
{
    int ppdx1;
    int ppdy1;
    int ppdz1;

    if(pustawienie1%4==0 )
    {
        ppdx1=distancex;
        ppdz1=distancez;
        ppdy1=distancey;
    }
    else if(pustawienie1%4==1 || pustawienie1%4==-3 )
    {
        ppdx1=distancez;
        ppdz1=distancex;
        ppdy1=distancey;
    }
    else if(pustawienie1%4==2 || pustawienie1%4==-2)
    {
        ppdx1=-distancex;
        ppdz1=-distancez;
        ppdy1=distancey;
    }
    else if(pustawienie1%4==3 ||  pustawienie1%4==-1)
    {
        ppdx1=-distancez;
        ppdz1=-distancex;
        ppdy1=distancey;
    }

    if(pustawienie2%4==0)
    {
        ppdy2=ppdy1;
        ppdz2=ppdz1;
        ppdx2=ppdx1;
    }
    else if(pustawienie2%4==1 || pustawienie2%4==-3)
    {
        ppdy2=ppdx1;
        ppdz2=ppdz1;
        ppdx2=ppdy1;
    }
    else if(pustawienie2%4==2 ||  pustawienie2%4==-2)
    {
        ppdy2=-ppdy1;
        ppdz2=ppdz1;
        ppdx2=-ppdx1;
    }
    else if(pustawienie2%4==3 || pustawienie2%4==-1)
    {
        ppdy2=-ppdx1;
        ppdz2=ppdz1;
        ppdx2=-ppdy1;
    }
}

int Kwadrat::kolizja(std::vector<Kwadrat> & asd)
{
   for(auto &reca : asd)
   {
       if((reca.prawdziwez+100>=prawdziwez && reca.prawdziwex==prawdziwex ) && reca.prawdziwey==prawdziwey)
       {
           distancez1=reca.prawdziwez+100-pdz2;
           prawdziwey=distancey1+pdy2;
           prawdziwex=distancex1+pdx2;

           return 0;
       }
   }
   return  1;
}

int Kwadrat::kolizja1(std::vector<Kwadrat> & asd)
{
   for(auto &reca : asd)
   {
       distancez1p=distancez1-100;
       prawdziwez=distancez1p+pdz2;
       prawdziwey=distancey1+pdy2;
       prawdziwex=distancex1+pdx2;
       if((reca.prawdziwez+100>=prawdziwez && reca.prawdziwex==prawdziwex ) && reca.prawdziwey==prawdziwey)
       {
           return 0;
       }
       if(prawdziwez<0)
       {
           return 0;
       }
   }
   return  1;
}

void Kwadrat::kolizja11()
{
   distancez1=distancez1-100;
}

int Kwadrat::kolizjaprob(std::vector<Kwadrat>  asd)
{
   przamiana();
   int probnez=distancez1+ppdz2;
   int probney=distancey1+ppdy2;
   int probnex=distancex1+ppdx2;

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

   for(auto &reca : asd)
   {
       if((reca.prawdziwez+100>=probnez && reca.prawdziwez-100<=probnez )&& (reca.prawdziwex==probnex && reca.prawdziwey==probney))
       {
           return 0;
       }
   }
   return 1;
}

int Kwadrat::kolizjaprob(std::vector<Kwadrat>  asd,int  xd,int  yd)
{
   pustawienie1=ustawienie1;
   pustawienie2=ustawienie2;
   przamiana();
   int probnez=distancez1+ppdz2;
   int probney=distancey1+ppdy2+yd*przesuniecie1;
   int probnex=distancex1+ppdx2+xd*przesuniecie1;

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

   for(auto &reca : asd)
   {
       if((reca.prawdziwez+100>=probnez && reca.prawdziwez-100<=probnez )&& (reca.prawdziwex==probnex && reca.prawdziwey==probney))
       {
           return 0;
       }
   }
   return  1;
}

int Kwadrat::step(int & kat, std::vector<Kwadrat> & asd)
{
   if(dziala==1)
   {
       distancez1=distancez1-przesuniecie;
       prawdziwez=distancez1+pdz2;
       prawdziwey=distancey1+pdy2;
       prawdziwex=distancex1+pdx2;
   }

   if(kolizja(asd)==0)
   {
       return distancez1;
   }
   draw(kat);

   if(prawdziwez<=0)
   {
       prawdziwez=0;
       distancez1=prawdziwez-pdz2;
       prawdziwey=distancey1+pdy2;
       prawdziwex=distancex1+pdx2;

       dziala=0;
       return distancez1;
   }
   else{return 1;}
}

void Kwadrat::as(int & a)
{
    prawdziwez=a+pdz2;
}

void Kwadrat::draw(int & kat)
{
   glPushMatrix();
   glRotated(kat, 0.0, 0.0, 1.0);
   glTranslated(prawdziwex, prawdziwey,prawdziwez);
   draw_cube(diameter,(1.0f/255)*color1,(1.0f/255)*color2,(1.0f/255)*color3);
   glPopMatrix();
}

void Kwadrat::draw_cube(double  size, double  color1, double  color2, double  color3)
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

