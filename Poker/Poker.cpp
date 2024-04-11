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
    string Card[13]{ "Двойка","Тройка","Четыре","Пятерка","Шестерка","Семерка","Восьмерка","Девятка","Десятка","Валет","Дама","Король","Туз" };
    string Suit[4]{ "Пики","Буби","Черви","Крести" };

    Deck game;
    Fill_the_deck(game, 13, 4, Card, Suit);
    Shuffle_card(game);
    Print_deck(game);

}