#include <iostream>
#include "fun.hpp"
#include <fstream>



int main()
{

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


    system("chcp 65001");
    int op;

    system("cls");
    std::cout<<"Witaj w Tetris3D"<<std::endl;
    while(1){
        std::cout<<"Wybierz Opcje"<<std::endl;
        std::cout<<"1.Gra"<<std::endl;
        std::cout<<"2.Wyniki"<<std::endl;
        std::cout<<"3.Jak działa gra"<<std::endl;
        std::cout<<"4.Koniec"<<std::endl;

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
                Opcja1();
                system("cls");
                break;
            case 2:
                Opcja3();
                system("cls");
                break;
            case 3:
                Opcja4();
                system("cls");
                break;
            case 4:
                return 0;
                break;
            default:
                system("cls");
                std::cout<<"Podałeś złą opcje spróbuj jeszcze raz"<<std::endl;
                break;
            }
        }
    }
}
