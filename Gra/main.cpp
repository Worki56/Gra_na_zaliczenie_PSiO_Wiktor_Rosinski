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

    void step()
    {
       if(dziala==1)
       {
       distancez=distancez-przesuniecie;
       }
    }

    void draw(int kat)
    {


       glPushMatrix();

       glRotated(kat*2, 0.0, 0.0, 1.0);
       glTranslated(distancex, distancey,distancez);

       glRotated(90*ustawienie1, 0.0, 1.0, 0.0);
       glRotated(90*ustawienie2, 1.0, 0.0, 0.0);
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
    int distancex=0;
    int distancey=0;
    int diameter=100;
    double spint;
    int przesuniecie=10;

    int color1;
    int color2;
    int color3;
    bool dziala=1;
    int ustawienie1=0;
    int ustawienie2=0;






};

class Ksztalt
{
public:
    int diameter=100;
    std::vector<Kwadrat> elementy;
    Ksztalt()
    {
       color1=( std::rand() % 255 );
        color2=( std::rand() % 255 );
        color3=( std::rand() % 255 );
        iloelem=( std::rand() % 5 );

        switch (iloelem)
        {
        case 0:
        elementy.emplace_back(0,0,0);
        elementy.emplace_back(0,0,diameter);
        elementy.emplace_back(0,diameter,0);
        elementy.emplace_back(0,-diameter,0);
        break;
        case 1:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(diameter,0,0);
            elementy.emplace_back(diameter,0,diameter);
            elementy.emplace_back(diameter,diameter,diameter);
            elementy.emplace_back(diameter,diameter,0);

        break;
        case 2:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,0,2*diameter);
            elementy.emplace_back(0,0,3*diameter);
        break;
        case 3:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(0,2*diameter,0);

        break;
        case 4:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,diameter,0);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,2*diameter,diameter);

        break;
        case 5:
            elementy.emplace_back(0,0,0);
            elementy.emplace_back(0,0,diameter);
            elementy.emplace_back(0,diameter,diameter);
            elementy.emplace_back(0,-diameter,diameter);
            elementy.emplace_back(0,0,2*diameter);
        break;


        }




    }

    void ahk(){}

    int step()
    {
        for(auto &reca : elementy)
        {
        reca.step();


        }

        return 0;
    }

    int color1;
    int color2;
    int color3;
    int iloelem;






};




void set_viewport(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 10000.0);
    gluLookAt(1000, -1000,300, 0, 0, 0, 0, 0, 1);

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


    GLfloat light_position[] = { 2.0, 0.0, 2.0, 1.0 };
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




    int ala=0;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::MouseWheelScrolled)
            {
                ala=ala+event.mouseWheel.delta;


                running = false;
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



        glPushMatrix();

        window.display();
    }

    return 0;
}
