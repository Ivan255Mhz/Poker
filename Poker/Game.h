#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <algorithm>

using namespace std;



struct Playing_card
{
    string Card{};

    string Suit{};
};

struct Deck
{
    Playing_card Deck_card[52]{};
};

struct Player
{
    int chips{ 100 };
    string name{};
    Playing_card Privat_card[2]{};
};

struct Game_table
{
    Player One{};
    Player Two{};

    Playing_card Play_deck[9]{};

};

void Fill_the_deck(Deck& deck, int size_card, int size_suit, std::string* card, std::string* suit);

void Print_card(Playing_card& card);

void Print_deck(Deck& deck, int size = 52);

void Shuffle_card(Deck& deck, int size = 52);

void Game_deck(Game_table& game, Deck& deck, int size_game = 9);

void Privat_card(Player& one, Player& two, Game_table& game);