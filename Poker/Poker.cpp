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
    
     // НАЧАЛО ИГРЫ

    Deck stack; // создание колоды 
    Fill_the_deck(stack, 13, 4, Card, Suit, Rank_values, Suit_values); // заполнение коллоды
    Shuffle_card(stack);
    Player one; // создание игроков 
    Player two;
    Game_table game; // создание игрального стола 
    Preparing_game(stack, one, two, game); // подготовка к игре ( раздача карт игрокам + их сортировка , на стол , и добовление игроков к столу )
    Phaise_1_ply1(game);
}

    