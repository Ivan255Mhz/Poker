#include "Game.h"

void Fill_the_deck(Deck& deck, int size_card, int size_suit, string* card, string* suit, int* rank_values, int *suit_values)// создание массива карт
{
    int index{};
    for (int i{}; i < size_suit; ++i)
    {
        for (int j{}; j < size_card; ++j)
        {
            deck.Deck_card[index].Card = card[j];
            deck.Deck_card[index].Suit = suit[i];
            deck.Deck_card[index].sort = rank_values[j];
            deck.Deck_card[index].su_vel = suit_values[i];
            ++index;
        }
    }
}



void Print_card(Playing_card& card)//  это больше для проверки
{
    cout << "|-------|" << endl;
    cout << "|       |" << endl;
    cout << "|   " << card.Card << "  |" << endl;
    cout <<"| "<< card.Suit <<"  |" << endl;
    cout << "|       |" << endl;
    cout << "|-------|" << endl;
}

void Print_deck(Deck& deck, int size ) // тоже для проверки 
{
    for (int i{}; i < size; ++i)
    {
        
        Print_card(deck.Deck_card[i]);
    }
}

void Shuffle_card(Deck& deck, int size )    // тосовка колоды 
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

void Game_deck(Game_table& game, Deck& deck, int size_game) // коллода карт для раздачи 
{
    int index = 0;
    for (int i = 4; i < size_game; ++i)
    {
        game.Play_deck[index] = deck.Deck_card[i];
        ++index;
    }
}

void Privat_card(Player& one, Player& two, Deck& game) // даем карты в руку игрокам 
{
    one.Privat_card[0] = game.Deck_card[0];
    one.Privat_card[1] = game.Deck_card[2];
    two.Privat_card[0] = game.Deck_card[1];
    two.Privat_card[1] = game.Deck_card[3];

}

void Player_p_table(Game_table& game, Player& one, Player& two) // добовляем игроков к столу 
{
    game.One = one;
    game.Two = two;
}

Playing_card* Arm(Player& ply, Game_table& game) // заполнения массива для комбинаций
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



void Table(Game_table& game) // 1 этап ставок
{
    cout << "  ---Карты на столе тур 1--" << endl;
    cout << "|---------------------|" << endl;
    cout << "|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card <<"   |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << "  |" << endl;
    cout << "|---------------------|" << endl;
}

void Table_t_2(Game_table& game) // 2 этап ставок 
{
    cout << "  ---Карты на столе тур 2--" << endl;
    cout << "|----------------------------|" << endl;
    cout << "|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  "<< game.Play_deck[3].Card<<"   |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit <<" | " <<game.Play_deck[3].Suit <<"  |" << endl;
    cout << "|----------------------------|" << endl;
}

void Table_t_3(Game_table& game) // 3 этап ставок 
{
    cout << "     ---Карты на столе тур 3--" << endl;
    cout << "+------+------+------+------+------+" << endl;
    cout << "|  " << game.Play_deck[0].Card <<  "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  " << game.Play_deck[3].Card << "  |  " << game.Play_deck[4].Card<<"  |" << endl;
    cout << "| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " | " << game.Play_deck[3].Suit << " | " << game.Play_deck[4].Suit<<" |" << endl;
    cout << "+------+------+------+------+------+" << endl;
}

void Print_Arm1(Game_table& game) // принт руки 1 игрока 
{
    cout << "  ---Ваша рука---" << endl;
    cout << "  +------+------+" << endl;
    cout << "  |  " << game.One.Privat_card[0].Card << "  |  " << game.One.Privat_card[1].Card << "  |" << endl;
    cout << "  | " << game.One.Privat_card[0].Suit << " | " << game.One.Privat_card[1].Suit << " |" << endl;
    cout << "  +------+------+" << endl;
}

void Print_Arm2(Game_table& game) // принт руки 2 игрока 
{
    cout << "  ---Ваша рука---" << endl;
    cout << "  +-------------+" << endl;
    cout << "  |  " << game.Two.Privat_card[0].Card << "  |  " << game.Two.Privat_card[1].Card << "  |" << endl;
    cout << "  | " << game.Two.Privat_card[0].Suit << " | " << game.Two.Privat_card[1].Suit << " |" << endl;
    cout << "  +-------------+" << endl;
}

void Sort_card(Playing_card* arm, int size) // сортировка массива для комбинаций
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arm[j].sort > arm[j + 1].sort)
            {
                Playing_card temp = arm[j];
                arm[j] = arm[j + 1];
                arm[j + 1] = temp;
            }
        }
    }
}

bool Senior_card(Playing_card* arm1, Playing_card *arm2)  // старшая карта 
{
    if (arm1[6].sort > arm2[6].sort)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pairs(Playing_card* arm) // пара
{
    for (int i = 0; i < 7; i++) 
    {
        for (int j = i + 1; j < 7; j++) 
        {
            if (arm[i].sort == arm[j].sort) 
            {
                cout << "Комбинация : пара !"<<endl;
                return true;
            }
        }
    }
    return false;
}

bool Two_pairs(Playing_card* arm) // 2 пары 
{
    int pairs_count = 0;
    bool pair_found[15] = { false };

    for (int i = 0; i < 7; i++)
    {
        if (pair_found[arm[i].sort])
        {
            pairs_count++;
        }
        else
        {
            pair_found[arm[i].sort] = true;
        }
    }

    if (pairs_count == 2)
    {
        cout << "Комбинация: 2 пары!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Set(Playing_card* arm) // сет
{
    int rank_counts[15] = { 0 }; 

    for (int i = 0; i < 7; ++i)
    {
        rank_counts[arm[i].sort]++;
    }

    for (int i = 0; i < 15; ++i)
    {
        if (rank_counts[i] == 3)
        {
            cout << "Комбинация : сет !" << endl;
            return true;
        }
    }

    return false;
}

bool Straight(Playing_card* arm)  // стрит
{
    
    for (int i = 0; i < 7 - 1; ++i)
    {
        if (arm[i + 1].sort - arm[i].sort != 1)
        {
            return false;
        }
    }
    cout << "Комбинация : стрит !"<<endl;
   return true;
}


bool Flush(Playing_card* arm) // флеш
{
    
    int count = 1;
    for (int i = 0; i < 7 - 1; ++i)
    {
        if (arm[i].su_vel == arm[i + 1].su_vel)
        {
            count++;
            if (count == 5)
            {
                cout << "Комбинация : флеш !" << endl;
                return true;
            }
        }
        else
        {
            count = 1;
        }
    }
    return false;
}

bool Four_of_a_kind(Playing_card* arm) // карэ
{
    int rank_counts[15] = { 0 }; 
    for (int i = 0; i < 7; ++i)
    {
        rank_counts[arm[i].sort]++;
    }

    for (int i = 0; i < 15; ++i)
    {
        if (rank_counts[i] == 4)
        {
            cout << "Комбинация: каре!" << endl;
            return true;
        }
    }

    return false;
}

bool FullHouse(Playing_card* arm) // фулхаус
{
    int rank_counts[15] = { 0 }; 

    for (int i = 0; i < 7; ++i)
    {
        rank_counts[arm[i].sort]++;
    }

    bool has_three_of_a_kind = false;
    bool has_pair = false;

    for (int i = 0; i < 15; ++i)
    {
        if (rank_counts[i] == 3)
        {
            has_three_of_a_kind = true;
        }
        else if (rank_counts[i] == 2)
        {
            has_pair = true;
        }
    }

    if (has_three_of_a_kind && has_pair)
    {
        cout << "Комбинация: фул хаус!" << endl;
        return true;
    }

    return false;
}

bool StraightFlush(Playing_card* arm) // стрит-флеш
{
   
    int count = 1;
    for (int i = 0; i < 7 - 1; ++i)
    {
        if (arm[i].su_vel == arm[i + 1].su_vel && arm[i + 1].sort - arm[i].sort == 1)
        {
            count++;
            if (count == 5)
            {
                cout << "Комбинация: стрит-флеш!" << endl;
                return true;
            }
        }
        else
        {
            count = 1;
        }
    }
    return false;
}

bool Royal_flush(Playing_card* arm) // флеш-рояль
{
   if (arm[0].sort == 10 && arm[1].sort == 11 && arm[2].sort == 12 && arm[3].sort == 13 && arm[4].sort == 14 &&
        arm[0].su_vel == arm[1].su_vel && arm[1].su_vel == arm[2].su_vel && arm[2].su_vel == arm[3].su_vel && arm[3].su_vel == arm[4].su_vel)
    {
        cout << "Комбинация: Флеш-рояль!" << endl;
        return true;
    }

    return false;
}

void Check_combo(Playing_card* arm)
{
    Pairs(arm);
    Two_pairs(arm);
    Set(arm);
    Straight(arm);
    Flush(arm);

}