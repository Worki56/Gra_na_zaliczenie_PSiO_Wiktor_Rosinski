#include <iostream>
#include "fun.hpp"




int main()
{
    system("chcp 65001");
    int op;
    int i=0;
    system("cls");
    std::cout<<"Witaj w Tetris3D"<<std::endl;
    while(i==0){
        std::cout<<"Wybierz Opcje"<<std::endl;
        std::cout<<"1.Gra"<<std::endl;
        std::cout<<"2.Opcje"<<std::endl;
        std::cout<<"3.Wyniki"<<std::endl;
        std::cout<<"4.Jak działa gra"<<std::endl;
        std::cout<<"5.Koniec"<<std::endl;
        std::cin>>op;
        switch (op)
        {
        case 1:
            Opcja1();
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
            return 0;
            break;
        default:
            system("cls");
            std::cout<<"Podałeś złą opcje spróbuj jeszcze raz"<<std::endl;
            break;
        }
    }
}
