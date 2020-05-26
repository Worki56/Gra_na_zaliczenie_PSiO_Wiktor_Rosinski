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









class CelestialBody
{

public:

    CelestialBody(){}

    int step(float time)
    {
        czasf=czasf+time;

        return 0;
    }

    void draw()
    {


       glPushMatrix();
       if(orbitt!=0){
       glRotated((czasf/orbitt)*360, 0.0, 0.0, 1.0);
       }
       glTranslated(0.0, distance*skala2, 0.0);
       glRotated((czasf/spint)*360, 0, 0.0, 1.0);
       draw_cube(diameter*skala,(1.0f/255)*color1,(1.0f/255)*color2,(1.0f/255)*color3);
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


    std::string nazwa;
    int distance;
    int diameter;
    double spint;
    double orbitt;
    double gravity;
    int moons;
    int color1;
    int color2;
    int color3;
    double skala=0.1;
    double skala2=0.2;
    float czasf=0;





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
    std::fstream file("solar_system.txt");
    std::vector<CelestialBody> rates;
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            std::string double_str;
            std::vector<std::string> double_str1;
            int i=0;
            while(i!=7)
            {
                std::getline(str, double_str, '\t');
                if(double_str==""){}
                else{
                    double_str1.emplace_back(double_str);
                    i++;
                }
            }
            CelestialBody er;
            std::string  alae;
            std::getline(str, alae, ' ');
            er.color1=std::stoi(alae);
            std::string  alae1;
            std::getline(str, alae1, ' ');
            er.color2=std::stoi(alae1);
            std::string  alae2;
            std::getline(str, alae2, ' ');
            er.color3=std::stoi(alae2);
            er.nazwa=double_str1[0];
            er.distance = std::stod(double_str1[1]);
            er.diameter = std::stoi(double_str1[2]);
            er.spint = std::stod(double_str1[3]);
            er.orbitt = std::stod(double_str1[4]);
            er.gravity = std::stod(double_str1[5]);
            er.moons = std::stoi(double_str1[6]);
            rates.emplace_back(er);
        }
    }



    // create the window
    sf::Window window(sf::VideoMode(1024, 768), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // set viewport according to current window size
    set_viewport(window.getSize().x, window.getSize().y);

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);

    // setup lights

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

    // load resources, initialize the OpenGL states, ...

    // run the main loop
    bool running = true;

    sf::Clock clk;


    double sekunda=0;
    int licznik=0;

    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                set_viewport(event.size.width, event.size.height);
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        // draw stuff

        glPushMatrix();

        //float rot = clk.getElapsedTime().asSeconds()*365.25;// 1sekunda=1rok
        float rot = clk.getElapsedTime().asSeconds()*30.4375;// 1sekunda=1miesiąc
        //float rot = clk.getElapsedTime().asSeconds()*91.3125;// 1sekunda=1dzień
        glTranslated(0.0, 0.0, 0.0);


         sf::Time elapsed1 = clk.restart();

                   /*
                   licznik++;
                   sekunda=sekunda+elapsed1.asSeconds();
                   //std::cout<<elapsed.asMicroseconds()<<std::endl;
                   if(sekunda>1.0)
                   {
                       sekunda=sekunda-1.0;
                       //std::cout<<licznik<<std::endl;
                       licznik=0;
                   }
                   */

        for(int i=0; i<9;i++)
        {
            rates[i].step(rot);
            rates[i].draw();


        }


        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;
}
