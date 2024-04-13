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
    cout << "|-------|" << endl;
    cout << "|       |" << endl;
    cout << "|   " << card.Card << "  |" << endl;
    cout <<"| "<< card.Suit <<"  |" << endl;
    cout << "|       |" << endl;
    cout << "|-------|" << endl;
}

void Print_deck(Deck& deck, int size )
{
    for (int i{}; i < size; ++i)
    {
        
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
    int index = 0;
    for (int i = 4; i < size_game; ++i)
    {
        game.Play_deck[index] = deck.Deck_card[i];
        ++index;
    }
}

void Privat_card(Player& one, Player& two, Deck& game)
{
    one.Privat_card[0] = game.Deck_card[0];
    one.Privat_card[1] = game.Deck_card[2];
    two.Privat_card[0] = game.Deck_card[1];
    two.Privat_card[1] = game.Deck_card[3];

}

void Player_p_table(Game_table& game, Player& one, Player& two)
{
    game.One = one;
    game.Two = two;
}

Playing_card* Arm(Player& ply, Game_table& game)
{
    Playing_card* arm = new Playing_card[7]{};
    int index{};
    for (int i{}; i < 2; ++i)
    {
        arm[index] = ply.Privat_card[i];
        ++index;
    }

    for (int i{}; i < 5; ++i)
    {
        arm[index] = game.Play_deck[i];
        ++index;
    }

    return arm;
}



void Table(Game_table& game)
{
    cout << "  ---Карты на столе тур 1--" << endl;
    cout << "|---------------------|" << endl;
    cout << "|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card <<"   |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << "  |" << endl;
    cout << "|---------------------|" << endl;
}

void Table_t_2(Game_table& game)
{
    cout << "  ---Карты на столе тур 2--" << endl;
    cout << "|----------------------------|" << endl;
    cout << "|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  "<< game.Play_deck[3].Card<<"   |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit <<" | " <<game.Play_deck[3].Suit <<"  |" << endl;
    cout << "|----------------------------|" << endl;
}

void Table_t_3(Game_table& game)
{
    cout << "     ---Карты на столе тур 3--" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  " << game.Play_deck[3].Card << "  |  " << game.Play_deck[4].Card<<"   |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " | " << game.Play_deck[3].Suit << " | " << game.Play_deck[4].Suit<<"  |" << endl;
    cout << "|-----------------------------------|" << endl;
}

void Print_Arm(Game_table& game)
{
    cout << "  ---Ваша рука---" << endl;
    cout << "  |-------------|" << endl;
    cout << "  |  " << game.One.Privat_card[0].Card << "  |  " << game.One.Privat_card[1].Card << "  |" << endl;
    cout << "  | " << game.Play_deck[0].Suit << " | " << game.One.Privat_card[1].Suit << " |" << endl;
    cout << "  |-------------|" << endl;
}

void Sort_card(Playing_card* arm, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arm[j].Card > arm[j + 1].Card)
            {
                Playing_card temp = arm[j];
                arm[j] = arm[j + 1];
                arm[j + 1] = temp;
            }
        }
    }
}