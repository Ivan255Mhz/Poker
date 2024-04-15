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
    string Card[13]{ "2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","J ","Q ","K ","A " };
    string Suit[4]{ "Крес" ,"Черв","Пики","Буби" };
    int Rank_values[13]{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int Suit_values[4]{ 1,2,3,4 };
    Deck game;

    Fill_the_deck(game, 13, 4, Card, Suit, Rank_values,Suit_values);// заполнение
    Shuffle_card(game);// тасовка
    /*Print_deck(game);*/// вывод колоды
    Game_table one{};// струтура игрального стола
    Game_deck(one, game);// заолняем игральный стол картами
    Player user{};// игрок 1
    Player pc{};// игрок 2
    Privat_card(user, pc, game);// раздача приватных карт 
    Player_p_table(one, user, pc);// добовлякм игроковс картами 
    
    Table(one);
    Table_t_2(one);
    Table_t_3(one);// разные варианты раскада на столе 
    Print_Arm1(one);// печать руки
    Print_Arm2(one);
    
    Playing_card* arm = Arm(user, one);// массив для проверки на комбинации;
    Playing_card* arm1 = Arm(pc, one);
    
    
    Sort_card(arm, 7); // сортировка массива
    Sort_card(arm1, 7);

    for (int i{}; i < 7; ++i)
    {
        Print_card(arm[i]);
    }
    cout << endl;
    for (int i{}; i < 7; ++i)
    {
        Print_card(arm1[i]);
    }
}