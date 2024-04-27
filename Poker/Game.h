#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <algorithm>
#include <iomanip>

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
	int chips{ 1000 };
	string name;
	Playing_card Privat_card[7]{};
	Playing_card arm[7]{};
};

struct Game_table
{
	Player One{};
	Player Two{};
	int bet{};
	Playing_card Play_deck[5]{};
};

void Fill_the_deck(Deck& deck, int size_card, int size_suit, std::string* card, std::string* suit, int* rank_values, int* suit_values);

void Shuffle_card(Deck& deck, int size = 52);

void Preparing_game(Deck& deck, Player& one, Player& two, Game_table& game);

void Game_deck(Game_table& game, Deck& deck, int size_game = 9);

void Table(const Game_table& game, int var);

//void Table_t_2(Game_table& game);
//
//void Table_t_3(Game_table& game);

void Print_Arm(const Player& ply);

void Sort_card(Playing_card* arm, int size);

int Senior_card(Game_table& game, Player& ply1, Player& ply2);

bool Pairs(Player& ply, int size);

bool Set(Player& ply, int size);

bool Two_pairs(Player& ply, int size);

bool Straight(Player& ply, int size);

bool Flush(Player& ply, int size);

bool Four_of_a_kind(Player& ply, int size);

bool FullHouse(Player& ply, int size);

bool StraightFlush(Player& ply, int size);

bool Royal_flush(Player& ply, int size);

void P_Check_combo(Player& ply, int size);

int Combo_val(Player& ply, int size);

int Win_loss(Game_table& game, Player& ply1, Player& ply2, int size);

void Bet(Game_table& game, Player& ply);

void Print_chips(const Player& ply);

void Print_bet(const Game_table& game);

void Start_Check_combo(Player ply, int size);

int Start_Combo_val(Player ply, int size);

void Eq_bet(Game_table& game, Player& ply, int  bet);

void Up_bet(Game_table& game, Player& ply);

void Menu(Game_table& game, Deck& stack);

void Pas_bet(Game_table& game, Player& ply);

void Coin_flip(Game_table& game, Deck& stack);

void Start_p1(Game_table& game, Deck& stack);

void Start2_p1(Game_table& game, Deck& stack);

void Start_p2(Game_table& game, Deck& stack);

void Start2_p2(Game_table& game, Deck& stack);

void Erl_p1(Game_table& game, Deck& stack);

void Erl2_p1(Game_table& game, Deck& stack);

void Erl_p2(Game_table& game, Deck& stack);

void Erl2_p2(Game_table& game, Deck& stack);

void Mid_p1(Game_table& game, Deck& stack);

void Mid2_p1(Game_table& game, Deck& stack);

void Mid_p2(Game_table& game, Deck& stack);

void Mid2_p2(Game_table& game, Deck& stack);

void Erl_WL_p1(Game_table& game, Deck& stack);

void Erl_WL_p2(Game_table& game, Deck& stack);

void Erl_pas_p1(Game_table& game, Deck& stack);

void Erl_pas_p2(Game_table& game, Deck& stack);

void Mid_WL_p1(Game_table& game, Deck& stack);

void Erl_pas_p1(Game_table& game, Deck& stack);

void Mid_WL_p2(Game_table& game, Deck& stack);

void Lt_WL_p1(Game_table& game, Deck& stack);

void Lt_WL_p2(Game_table& game, Deck& stack);

void Lt_p1(Game_table& game, Deck& stack);

void Lt2_p1(Game_table& game, Deck& stack);

void Lt_p2(Game_table& game, Deck& stack);

void Lt2_p2(Game_table& game, Deck& stack);

void Mid_pas_p2(Game_table& game, Deck& stack);

void Mid_pas_p1(Game_table& game, Deck& stack);

void Game_over(Game_table& game, Deck& stack);

void Low_bat(Game_table& game, Player& ply);

void Print_bet();

void Print_rules();