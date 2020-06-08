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



#include "fun.hpp"
#include "ksztalt.hpp"
#include "ustalone.hpp"
#include "plansza.hpp"

void Opcja1()
{
    int spr=0;
    int a1;


    int z=0;
    double sekunda=0;
    int licznik=0;
    int licznik1=0;
    sf::Clock clk;
    int pausa=0;

    int dlu=200;
    int dlu1=600;
    int dlu2=150;
    int wys=600;
    int szyb1=3;
    int szyb=3;
    double szyb3=3;
    srand( time( NULL ) );
    system("cls");
    std::cout<<"Zalecane ilość kratek to 5 do 21 dla x y z oraz powinna byc nieparzysta"<<std::endl;
    while(spr==0)
    {
        std::cout<<"Podaj illośc kratek x"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1%2==1 && a1>=5)
            {
                dlu=((a1-1)/2)*100;
                spr=1;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }
    spr=0;
    while(spr==0)
    {
        std::cout<<"Podaj illośc kratek y"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1%2==1 && a1>=5)
            {
                dlu1=((a1-1)/2)*100;
                spr=1;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }
    spr=0;
    while(spr==0)
    {
        std::cout<<"Podaj illośc kratek z"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1>=5)
            {
                wys=(a1-1)*100;
                spr=1;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }





    if(dlu<=dlu1){dlu2=dlu1;}
    else{dlu2=dlu;}
    spr=0;
    while(spr==0){
        std::cout<<"Podaj szybkość początkową {1,2,3}"<<std::endl;
        std::cin>>a1;
        if( !std::cin )
        {
            czyszczenie();
        }
        else
        {
            if(a1==3 || a1==2 || a1==1)
            {
                spr=1;
                szyb1=a1;
            }
            else{std::cout<<"Podałeś złą liczbe"<<std::endl;}
        }
    }




    sf::Window window(sf::VideoMode(1024, 768), "Tetris3D", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    set_viewport(window.getSize().x, window.getSize().y,wys,dlu2);
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

     system("cls");
     std::cout<<"Posiadane punkty:0"<<std::endl;

    bool running = true;

    Plansza plan(dlu,dlu1,wys,szyb);
    Ustalone pk4(plan);


    std::vector<Ksztalt> pk5;


    int ala=0;
    std::string ust1;
    pk5.emplace_back(plan);

    sf::Event event;

    while (running)
    {


        if(szyb1==3)
        {
            szyb=3;
        }
        else if(szyb1==2)
        {
           if(pk4.punkty>100)
           {
              szyb=3;
           }
           else{szyb=2;}
        }
        else if(szyb1==1)
        {
            if(pk4.punkty>1000)
             {
               szyb=3;
             }
            else if(pk4.punkty>100)
            {
                szyb=2;

            }
            else{szyb=1;}

        }
        szyb=szyb*2;


        sf::Time elapsed1 = clk.restart();
        licznik++;
        sekunda=sekunda+elapsed1.asSeconds();
        //std::cout<<elapsed.asMicroseconds()<<std::endl;
        if(sekunda>1.0)
        {
            sekunda=sekunda-1.0;
            //std::cout<<licznik<<std::endl;
            licznik1=licznik;
            licznik=0;
        }

        if(z==0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                if(pausa==0){pausa=1;}
                 else{pausa=0;}
            }
            z++;
        }
        else
        {
            z++;
            if(z>10)
            {
                z=0;
            }
        }

        if(pausa==0)
        {
            szyb3=szyb*(licznik1/60);

            for(auto &reca : pk5[0].elementy)
            {
                reca.pre(szyb3);
            }


            while (window.pollEvent(event))
            {



                if (event.type == sf::Event::MouseWheelScrolled)
                {
                    ala=ala+event.mouseWheelScroll.delta*10;
                }

                if (event.type == sf::Event::Closed)
                {
                    std::cout<<"Koniec gry"<<std::endl;
                    pausa=pk4.punkty;
                    running = false;
                    window.close();
                }
                else if (event.type == sf::Event::Resized)
                {

                    set_viewport(event.size.width, event.size.height,wys,dlu2);
                }

            }


            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
            glEnable (GL_COLOR_MATERIAL);

            plan.drawpomoc(ala);
            if(pk5[0].step(ala,pk4)==0)
            {
                pk5.clear();
                plan.szybkosc=szyb3;
                pk5.emplace_back(plan);


                if(pk4.sprawdzanie()==0)
                {
                    std::cout<<"Koniec gry"<<std::endl;
                    pausa=pk4.punkty;
                    running = false;
                    window.close();
                }
            }
            pk4.step(ala);
        }
        window.display();
    }
    std::string pseudonim;
    std::cout<<"Otrzymałeś: "<<pausa<<" punktów"<<std::endl;
    std::cout<<"Podaj pseudonim"<<std::endl;
    std::cin>>pseudonim;
    std::string nazwa_pliku="wynik.txt";
    std::ofstream plik1(nazwa_pliku.c_str(),std::ios::app);

    plik1<<pseudonim<<"  "<<pausa<<std::endl;
    plik1.close();



}
void Opcja2()
{
    int i=0;
    int op;
    std::fstream file("opcje.txt");

    if (file.is_open())
    {
        std::cout<<"ala"<<std::endl;
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            std::cout<<line<<std::endl;
        }
    }



    system("cls");

    while(i==0){
        std::cout<<"Wybierz opcje zmiany przypisanego Klawisza"<<std::endl;
        std::cout<<"1.Ruch w przód x"<<std::endl;
        std::cout<<"2.Ruch w tył x"<<std::endl;
        std::cout<<"3.Ruch w przód y"<<std::endl;
        std::cout<<"4.Ruch w tył y"<<std::endl;
        std::cout<<"5.Pausa"<<std::endl;
        std::cout<<"6.Linie pomocnicze"<<std::endl;
        std::cout<<"7.Koniec"<<std::endl;
        std::cin>>op;
        if( !std::cin )
        {
            system("cls");
            czyszczenie();
        }
        else
        {
            switch (op)
            {
            case 1:
                Opcja5();
                system("cls");
                break;
            case 2:
                Opcja2();
                system("cls");
                break;
            case 3:
                Opcja3();
                system("cls");
                break;
            case 4:
                Opcja4();
                system("cls");
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                i=1;
                break;
            default:
                system("cls");
                std::cout<<"Podałeś złą opcje spróbuj jeszcze raz"<<std::endl;
                break;
            }
        }
    }


}
void Opcja3()
{

    int a=1;
    std::fstream file("wynik.txt");

    if (file.is_open())
    {

        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream str(line);
            std::cout<<line<<std::endl;
        }
    }
    std::cout<<"Nacińskij BackSpace a wrócić do Menu"<<std::endl;
    while (a !=0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            a=0;
        }
    }




}
void Opcja4()
{
    int a=1;
    system("cls");
    std::cout<<"Gra opiera się na mechanice znanej z gry tetris."<<std::endl;
    std::cout<<"Strzałkami góra/dół obracamy klocek w osi y a strzałkami w bok w osi z o 90 stopni "<<std::endl;
    std::cout<<"Domyślnie klawiszem E przesuwamy obiekt w osi x w przód a R w tył "<<std::endl;
    std::cout<<"Klawiszem F przesuwamy obiekt w osi y w przód a D w tył "<<std::endl;
    std::cout<<"Klawiszem P urachamiamy pause "<<std::endl;
    std::cout<<"Spacją przesuwamy w dół obiekt"<<std::endl;
    std::cout<<"Sroolem myszy obracmy plansze"<<std::endl;
    std::cout<<"W opcjach można wyłączyć linie pomocnicze"<<std::endl;
    std::cout<<"Autor Wiktor Rosiński"<<std::endl;
    std::cout<<"Nacińskij BackSpace a wrócić do Menu"<<std::endl;
    while (a !=0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            a=0;
        }
    }
}
void Opcja5()
{

    sf::Keyboard::Key asd;
    bool running = true;



    sf::Window window(sf::VideoMode(1, 1), "Ust");;



    sf::Event event;
    std::cout<<"Wybierz klawisz"<<std::endl;
    while (running)
    {

        while (window.pollEvent(event))
        {

        if( event.type == sf::Event::KeyPressed  )
        {

            asd=event.key.code ;

            window.close();
        }
        }
   }


}
void czyszczenie()
{
    std::cin.clear();
    std::cin.sync();
    std::cout<<"Podałeś złą wartość "<<std::endl;

}

void set_viewport(int width, int height,int wys, int dlu)
{
    int as;
    const float ar = (float)width / (float)height;
    if(wys>dlu){as=wys;}
    else{as=dlu;}

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, as*20);
    gluLookAt(dlu*4,0,wys*2+500, 0, 0, 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


