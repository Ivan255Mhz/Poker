#include "Game.h"

void Fill_the_deck(Deck& deck, int size_card, int size_suit, string* card, string* suit)
{
    int index{};
    for (int i{}; i < size_suit; ++i)
    {
        for (int j{}; j < size_card; ++j)
        {
            deck.Deck_card[index].Card = card[j];
            deck.Deck_card[index].Suit = suit[i];
            ++index;
        }
    }

}

void Print_card(Playing_card& card)
{
    cout << card.Card << " ";
    cout << card.Suit << " " << endl;;
}

void Print_deck(Deck& deck, int size )
{
    for (int i{}; i < size; ++i)
    {
        cout << "---------------" << endl;
        Print_card(deck.Deck_card[i]);
    }
}

void Shuffle_card(Deck& deck, int size )   
{
    random_device rd;
    mt19937 gen(rd());
    for (int i = size - 1; i > 0; --i)
    {
        uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        swap(deck.Deck_card[i], deck.Deck_card[j]);
    }
}

void Game_deck(Game_table& game, Deck& deck, int size_game)
{
    for (int i{}; i < size_game; ++i)
    {
        game.Play_deck[i] = deck.Deck_card[i];
    }
}

void Privat_card(Player& one, Player& two, Game_table& game)
{
    one.Privat_card[0] = game.Play_deck[0];
    one.Privat_card[1] = game.Play_deck[2];
    two.Privat_card[0] = game.Play_deck[1];
    two.Privat_card[1] = game.Play_deck[3];

}