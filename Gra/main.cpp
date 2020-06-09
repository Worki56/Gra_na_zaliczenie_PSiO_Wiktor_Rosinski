#include <iostream>
#include "fun.hpp"
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <SFML/OpenGL.hpp>
#ifdef __APPLE__
#include <OpenGL/glu.h> // macOS
#else
#include <GL/glu.h> // Windows/Linux
#endif




int main()
{

    sf::Font font;
    font.loadFromFile("segoepr.ttf");
    std::string liczba="";
    std::string pseudonim="";
    int liczba12;
    int kolejnosc=0;
    int punkty;
    int uwaga=0;
    sf::Text uwaga1(L"Podałeś zła wartośc",font);
    uwaga1.setPosition(200,200);
    uwaga1.setFillColor(sf::Color::White);
    uwaga1.setCharacterSize(30);
    std::vector<int> wejs;
    std::fstream plik1;
    plik1.open( "wynik.txt", std::ios::in | std::ios::out );
    if( plik1.good() == true ){}
    else
    {
        plik1.close();
        std::string nazwa_pliku="wynik.txt";
        std::ofstream plik1(nazwa_pliku.c_str());
        plik1<< "Pseudonim   Wynik"<<std::endl;
        plik1.close();

    }

    std::vector<sf::Text> ads;
    sf::RenderWindow window3(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));

    int z =0;
    int op=1;
    int asdf=1;
    bool running=1;
    sf::Event event;
    window3.setFramerateLimit(60);

    while(window3.isOpen())
    {

        window3.clear(sf::Color::Black);
        if(op==4 )
        {
            sf::Text uwaga3(liczba,font);
            uwaga3.setPosition(200,300);
            uwaga3.setFillColor(sf::Color::White);
            uwaga3.setCharacterSize(30);
            window3.draw(uwaga3);

        }
        if(op==11)
        {
            sf::Text uwaga3(liczba,font);
            uwaga3.setPosition(400,400);
            uwaga3.setFillColor(sf::Color::White);
            uwaga3.setCharacterSize(30);
            window3.draw(uwaga3);
        }
        if(op==11)
        {
            sf::Text uwaga3(pseudonim,font);
            uwaga3.setPosition(300,200);
            uwaga3.setFillColor(sf::Color::White);
            uwaga3.setCharacterSize(30);
            window3.draw(uwaga3);
        }

        for(auto &reca : ads)
        {
             window3.draw(reca);
        }
        ads=opdff(asdf,font);
        if(uwaga==1)
        {
            window3.draw(uwaga1);
        }

        while (window3.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
                window3.close();
            }
            if(op==1)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                {
                    op=4;
                    asdf=10;
                    z=0;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                {
                   asdf=4;
                   op=3;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                {
                   asdf=2;
                   op=2;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                {
                    return 0;
                }
            }
            else if(op==2)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                {
                    asdf=1;
                    op=1;
                }

            }
            else if(op==3)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                {
                    asdf=1;
                    op=1;
                }

            }
            else if(op==4)
            {
                if(z>10)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                    {
                        liczba=liczba+"1";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                    {
                        liczba=liczba+"2";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                    {
                        liczba=liczba+"3";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                    {
                        liczba=liczba+"4";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                    {
                        liczba=liczba+"5";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                    {
                        liczba=liczba+"6";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                    {
                        liczba=liczba+"7";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                    {
                        liczba=liczba+"8";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                    {
                        liczba=liczba+"9";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                    {
                        liczba=liczba+"0";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                    {
                        if(liczba!="")
                        {
                            liczba.pop_back();
                            z=0;
                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        liczba12=std::stoi(liczba);

                        if(kolejnosc==0 || kolejnosc==1)
                        {
                            if(liczba12%2==1 && liczba12>=5)
                           {
                               wejs.emplace_back(liczba12);
                               kolejnosc++;
                               asdf++;
                               uwaga=0;

                           }
                            else{uwaga=1;}

                        }
                        else if(kolejnosc==2)
                        {
                            if(liczba12>=5)
                            {
                                wejs.emplace_back(liczba12);
                                kolejnosc++;
                                asdf=13;
                                uwaga=0;

                            }
                            else{uwaga=1;}
                        }
                        else if(kolejnosc==3)
                        {
                            if(liczba12==1 || liczba12==2 || liczba12==3  )
                            {
                                wejs.emplace_back(liczba12);
                                op=10;
                                kolejnosc=0;
                                uwaga=0;
                                asdf=14;

                            }
                            else{uwaga=1;}
                        }
                        liczba="";
                        z=0;

                    }

                }
            }
            else if(op==10)
            {
                window3.setVisible(false);
                punkty=Opcja1(wejs[0],wejs[1],wejs[2],wejs[3]);
                op=11;
                window3.setVisible(true);
            }
            else if(op==11)
            {
                if(z>10)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                    {
                        pseudonim=pseudonim+"1";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                    {
                        pseudonim=pseudonim+"2";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                    {
                        pseudonim=pseudonim+"3";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                    {
                        pseudonim=pseudonim+"4";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                    {
                        pseudonim=pseudonim+"5";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                    {
                        pseudonim=pseudonim+"6";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
                    {
                        pseudonim=pseudonim+"7";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                    {
                        pseudonim=pseudonim+"8";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
                    {
                        pseudonim=pseudonim+"9";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                    {
                        pseudonim=pseudonim+"0";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    {
                        pseudonim=pseudonim+"Q";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        pseudonim=pseudonim+"W";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    {
                        pseudonim=pseudonim+"E";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                    {
                        pseudonim=pseudonim+"R";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                    {
                        pseudonim=pseudonim+"T";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
                    {
                        pseudonim=pseudonim+"Y";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                    {
                        pseudonim=pseudonim+"U";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                    {
                        pseudonim=pseudonim+"I";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
                    {
                        pseudonim=pseudonim+"O";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    {
                        pseudonim=pseudonim+"P";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        pseudonim=pseudonim+"A";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        pseudonim=pseudonim+"S";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        pseudonim=pseudonim+"D";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    {
                        pseudonim=pseudonim+"F";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                    {
                        pseudonim=pseudonim+"G";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                    {
                        pseudonim=pseudonim+"H";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                    {
                        pseudonim=pseudonim+"J";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                    {
                        pseudonim=pseudonim+"K";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                    {
                        pseudonim=pseudonim+"L";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    {
                        pseudonim=pseudonim+"Z";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    {
                        pseudonim=pseudonim+"X";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                    {
                        pseudonim=pseudonim+"C";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                    {
                        pseudonim=pseudonim+"V";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    {
                        pseudonim=pseudonim+"B";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                    {
                        pseudonim=pseudonim+"N";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    {
                        pseudonim=pseudonim+"M";
                        z=0;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                    {
                        if(pseudonim!="")
                        {
                            pseudonim.pop_back();
                             z=0;
                        }
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        op=12;
                    }
                }

                liczba= std::to_string(punkty);

            }
            else if(op==12)
            {
                std::string nazwa_pliku="wynik.txt";
                std::ofstream plik1(nazwa_pliku.c_str(),std::ios::app);
                plik1<<pseudonim<<"  "<<liczba<<std::endl;
                plik1.close();
                pseudonim="";
                op=1;
                asdf=1;
                liczba="";
            }

        }
        z++;
        window3.display();

    }

}
