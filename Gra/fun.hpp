#ifndef fun_hpp
#define fun_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SFML/OpenGL.hpp>
#ifdef __APPLE__
#include <OpenGL/glu.h> // macOS
#else
#include <GL/glu.h> // Windows/Linux
#endif

std::vector<sf::Text> opdff(int &as , sf::Font &asf);
int Opcja1(int &a1,int &a2,int &a3,int &a4);
void czyszczenie();
void set_viewport(int  width, int  height,int & wys, int & dlu);


#endif
