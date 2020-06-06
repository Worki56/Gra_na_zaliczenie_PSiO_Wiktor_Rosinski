#include "plansza.hpp"



Plansza::Plansza(int x, int y ,int z,int szy)
{
    rozmiarx=x;
    rozmiary=y;
    rozmiarz=z;
    szybkosc=szy;
}

void Plansza::drawpomoc(int kat)
{
    for(int i=-rozmiarx-50;i<rozmiarx+50+1;i=i+100)
    {
        glPushMatrix();
        glRotated(kat, 0.0, 0.0, 1.0);
        glColor3d(1, 1,1);
        glBegin(GL_POLYGON);
        glVertex3d(i, -rozmiary-50,-50 );
        glVertex3d(i+10,-rozmiary-50 , -50);
        glVertex3d(i, rozmiary+50,-50) ;
        glVertex3d(i+10,rozmiary+50 , -50);
        glEnd();
        glPopMatrix();
    }

    for(int i=-rozmiary-50;i<rozmiary+50+1;i=i+100)
    {
        glPushMatrix();
        glRotated(kat, 0.0, 0.0, 1.0);
        glColor3d(1, 1,1);
        glBegin(GL_POLYGON);
        glVertex3d(-rozmiarx-50,i,-50 );
        glVertex3d(-rozmiarx-50 ,i+10, -50);
        glVertex3d(rozmiarx+50,i,-50) ;
        glVertex3d(rozmiarx+50,i+10 , -50);
        glEnd();
        glPopMatrix();
    }

    if((kat%360>280  || kat%360<100  ) && (kat%360>-90 || kat%360<-280))
    {
        for(int i=-50;i<rozmiarz+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(-rozmiarx-50,-rozmiary-50,i );
            glVertex3d(-rozmiarx-50 ,-rozmiary-50, i+10);
            glVertex3d(-rozmiarx-50,rozmiary+50,i) ;
            glVertex3d(-rozmiarx-50,rozmiary+50, i+10);
            glEnd();
            glPopMatrix();
        }

        for(int i=-rozmiary-50;i<rozmiary+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(-rozmiarx-50,i,-50 );
            glVertex3d(-rozmiarx-50,i+10, rozmiarz+50);
            glVertex3d(-rozmiarx-50,i,rozmiarz+50 );
            glVertex3d(-rozmiarx-50,i+10,-50) ;
            glEnd();
            glPopMatrix();
        }
    }
    if((kat%360>80 && kat%360<280 )|| (kat%360<-80 && kat%360>-280))
    {
        for(int i=-50;i<rozmiarz+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(rozmiarx+50,-rozmiary-50,i );
            glVertex3d(rozmiarx+50 ,-rozmiary-50, i+10);
            glVertex3d(rozmiarx+50,rozmiary+50,i) ;
            glVertex3d(rozmiarx+50,rozmiary+50, i+10);
            glEnd();
            glPopMatrix();
        }
        for(int i=-rozmiary-50;i<rozmiary+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(rozmiarx+50,i,-50 );
            glVertex3d(rozmiarx+50,i+10, rozmiarz+50);
            glVertex3d(rozmiarx+50,i,rozmiarz+50 );
            glVertex3d(rozmiarx+50,i+10,-50) ;
            glEnd();
            glPopMatrix();
        }
    }
    if((kat%360>160  ) || (kat%360<0 && kat%360>-190))
    {
        for(int i=-50;i<rozmiarz+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(-rozmiarx-50,-rozmiary-50,i );
            glVertex3d(-rozmiarx-50 ,-rozmiary-50, i+10);
            glVertex3d(rozmiarx+50,-rozmiary-50,i) ;
            glVertex3d(rozmiarx+50,-rozmiary-50, i+10);
            glEnd();
            glPopMatrix();
        }

        for(int i=-rozmiarx-50;i<rozmiarx+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(i,-rozmiary-50,-50 );
            glVertex3d(i+10,-rozmiary-50, rozmiarz+50);
            glVertex3d(i ,-rozmiary-50,rozmiarz+50 );
            glVertex3d(i+10,-rozmiary-50,-50) ;
            glEnd();
            glPopMatrix();
        }
    }

    if((kat%360>340  || kat%360<200  ) && (kat%360>-10 || kat%360<-170))
    {
        for(int i=-50;i<rozmiarz+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(-rozmiarx-50,rozmiary+50,i );
            glVertex3d(-rozmiarx-50 ,rozmiary+50, i+10);
            glVertex3d(rozmiarx+50,rozmiary+50,i) ;
            glVertex3d(rozmiarx+50,rozmiary+50, i+10);
            glEnd();
            glPopMatrix();
        }

        for(int i=-rozmiarx-50;i<rozmiarx+50+1;i=i+100)
        {
            glPushMatrix();
            glRotated(kat, 0.0, 0.0, 1.0);
            glColor3d(1, 1,1);
            glBegin(GL_POLYGON);
            glVertex3d(i,rozmiary+50,-50 );
            glVertex3d(i+10,rozmiary+50, rozmiarz+50);
            glVertex3d(i ,rozmiary+50,rozmiarz+50 );
            glVertex3d(i+10,rozmiary+50,-50) ;
            glEnd();
            glPopMatrix();
        }
    }
}

