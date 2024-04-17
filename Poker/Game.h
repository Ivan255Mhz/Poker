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

    int sort{};

    int su_vel{};
};

struct Deck
{
    Playing_card Deck_card[52]{};
};

struct Player
{
    int chips{ 100 };
    string name{};
    Playing_card Privat_card[7]{};
    Playing_card arm[2]{};
};

struct Game_table
{
    Player One{};
    Player Two{};

    int bet{};

    Playing_card Play_deck[5]{};

};

void Fill_the_deck(Deck& deck, int size_card, int size_suit, std::string* card, std::string* suit, int* rank_values, int* suit_values);

void Print_card(Playing_card& card);

void Print_deck(Deck& deck, int size = 52);


void Shuffle_card(Deck& deck, int size = 52);

void Preparing_game(Deck& deck, Player& one, Player& two, Game_table& game);

void Game_deck(Game_table& game, Deck& deck, int size_game = 9);

//void Privat_card(Player& one, Player& two, Deck& game);

//void Player_p_table(Game_table& game, Player& one, Player& two);

//Playing_card* Arm(Player& ply, Game_table& game);

void Table(Game_table& game);

void Table_t_2(Game_table& game);

void Table_t_3(Game_table& game);

void Print_Arm1(Game_table& game);

void Print_Arm2(Game_table& game);

void Sort_card(Playing_card* arm, int size);

void Senior_card(Game_table& game);

bool Pairs(Playing_card* arm1, int size);

bool Set(Playing_card* arm1 ,int size);

bool Two_pairs(Playing_card* arm, int size);

bool Straight(Playing_card* arm, int size);

bool Four_of_a_kind(Playing_card* arm, int size);

bool FullHouse(Playing_card* arm, int size);

bool StraightFlush(Playing_card* arm, int size);

bool Royal_flush(Playing_card* arm, int size);

void P_Check_combo(Playing_card* arm, int size);

int Combo_val(Playing_card* arm, int size);

void Win_loss(Game_table& game, Playing_card* arm, Playing_card* arm1, int size);

void Bet(Game_table& game, Player& ply, int amount);

void Print_chips(Player& ply);

void Phaise_1_ply1(Game_table& game);

void Phaise_1_ply2(Game_table& game);
