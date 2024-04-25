#include <iostream>
#include <Windows.h>
#include <random>
#include <algorithm>
#include "Game.h"


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    string Card[13]{ "2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K ","A " };       // подготовка колоды 
    string Suit[4]{ "Крес" ,"Черв","Пики","Буби" };
    int Rank_values[13]{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int Suit_values[4]{ 1,2,3,4 };
    Deck stack;
                                               // НАЧАЛО ИГРЫ

    
    Fill_the_deck( stack, 13, 4, Card, Suit, Rank_values, Suit_values); // заполнение коллоды
    Shuffle_card(stack);
    Player one; // создание игроков 
    Player two;
    string ply1{};
    string ply2{};
    cout << "Введите имя Игрока №1 : ";
    cin >> ply1;
    cout << "Введите имя Игрока №2 : ";
    cin >> ply2;
    one.name = ply1;
    two.name = ply2;
    Game_table game; // создание игрального стола 
    Preparing_game(stack, one, two, game); // подготовка к игре ( раздача карт игрокам + их сортировка , на стол , и добовление игроков к столу )
   
    
    system("cls");

    cout << "\t\t\tКурсовая работа \"Покер\" : студент Беляев Иван Александрович" << endl;
    cout << endl << endl;
    
    Menu(game,stack);


    return 0;
}

    