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



//void Print_card(Playing_card& card)//  это больше для проверки
//{
//    cout << "|-------|" << endl;
//    cout << "|       |" << endl;
//    cout << "|   " << card.Card << "  |" << endl;
//    cout <<"| "<< card.Suit <<"  |" << endl;
//    cout << "|       |" << endl;
//    cout << "|-------|" << endl;
//}
//
//void Print_deck(Deck& deck, int size ) // тоже для проверки 
//{
//    for (int i{}; i < size; ++i)
//    {
//        
//        Print_card(deck.Deck_card[i]);
//    }
//}

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

//void Game_deck(Game_table& game, Deck& deck, int size_game) // коллода карт для раздачи 
//{
//    int index = 0;
//    for (int i = 4; i < size_game; ++i)
//    {
//        game.Play_deck[index] = deck.Deck_card[i];
//        ++index;
//    }
//}

//void Privat_card(Player& one, Player& two, Deck& game) // даем карты в руку игрокам 
//{
//    one.Privat_card[0] = game.Deck_card[0];
//    one.Privat_card[1] = game.Deck_card[2];
//    two.Privat_card[0] = game.Deck_card[1];
//    two.Privat_card[1] = game.Deck_card[3];
//
//}

//void Player_p_table(Game_table& game, Player& one, Player& two) // добовляем игроков к столу 
//{
//    game.One = one;
//    game.Two = two;
//}

void Apm_game(Deck& deck, Player& one, Player& two, Game_table& game)
{
    int index = 0;
    for (int i = 0; i < 4; ++i)
    {
        one.Privat_card[i] = deck.Deck_card[index];
        two.Privat_card[i] = deck.Deck_card[index + 1];
        index += 2;
    }

    for (int i = 4; i < 7; ++i)
    {
        game.Play_deck[i] = deck.Deck_card[index];
        one.Privat_card[i] = deck.Deck_card[index];
        two.Privat_card[i] = deck.Deck_card[index];
        ++index;
    }

    game.One = one;
    game.Two = two;
}

//Playing_card* Arm(Player& ply, Game_table& game)
//{
//    Playing_card* arm = new Playing_card[7]{};
//    int index{};
//    for (int i{}; i < 2; ++i)
//    {
//        arm[index] = ply.Privat_card[i];
//        ++index;
//    }
//
//    for (int i{}; i < 5; ++i)
//    {
//        arm[index] = game.Play_deck[i];
//        ++index;
//    }
//
//    return arm;
//}

    




void Table(Game_table& game) // 1 этап ставок
{
    cout << "\t\t\t\t     ---Карты на столе тур 1---" << endl;
    cout << "\t\t\t\t       +------+------+------+" << endl;
    cout << "\t\t\t\t       |  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card <<"  |" << endl;
    cout << "\t\t\t\t       | " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " |" << endl;
    cout << "\t\t\t\t       +------+------+------+" << endl;
}

void Table_t_2(Game_table& game) // 2 этап ставок 
{
    cout << "\t\t\t\t     ---Карты на столе тур 2---" << endl;
    cout << "\t\t\t\t    +------+------+------+------+" << endl;
    cout << "\t\t\t\t    |  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  "<< game.Play_deck[3].Card<<"  |" << endl;
    cout << "\t\t\t\t    | " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit <<" | " <<game.Play_deck[3].Suit <<" |" << endl;
    cout << "\t\t\t\t    +------+------+------+------+" << endl;
}

void Table_t_3(Game_table& game) // 3 этап ставок 
{
    cout << "\t\t\t\t     ---Карты на столе тур 3---" << endl;
    cout << "\t\t\t\t+------+------+------+------+------+" << endl;
    cout << "\t\t\t\t|  " << game.Play_deck[0].Card <<  "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  " << game.Play_deck[3].Card << "  |  " << game.Play_deck[4].Card<<"  |" << endl;
    cout << "\t\t\t\t| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " | " << game.Play_deck[3].Suit << " | " << game.Play_deck[4].Suit<<" |" << endl;
    cout << "\t\t\t\t+------+------+------+------+------+" << endl;
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

void Senior_card(Game_table &game)  // старшая карта 
{
    Sort_card(game.One.Privat_card, 2);
    Sort_card(game.Two.Privat_card, 2);

    if (game.One.Privat_card[1].sort > game.Two.Privat_card[1].sort)
    {
        cout << "Ваша старшая карта сильнее : победа !" << endl;
    }
    else if (game.One.Privat_card[1].sort < game.Two.Privat_card[1].sort)
    {
        cout << "Ваша старшая карта слабее : проигрыш !" << endl;
    }
    else if (game.One.Privat_card[0].sort > game.Two.Privat_card[0].sort)
    {
        cout << "Ваша старшая карта сильнее : победа !" << endl;
    }
    else if (game.One.Privat_card[0].sort < game.Two.Privat_card[0].sort)
    {
        cout << "Ваша старшая карта слабее : проигрыш !" << endl;
    }
    else
    {
        cout << "Ничья !" << endl;
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
        
        return true;
    }

    return false;
}

void P_Check_combo(Playing_card* arm)
{
  
    if (Royal_flush(arm))
    {
        cout << "Комбинация : ФЛЕШ РОЯЛЬ!" << endl;
       
    }
    else if (StraightFlush(arm))
    {
        cout << "Комбинация : СТРИТ ФЛЕШ!" << endl;
       
    }
    else if (Four_of_a_kind(arm))
    {
        cout << "Комбинация : КАРЭ!" << endl;
       
    }
    else if (FullHouse(arm))
    {
        cout << "Комбинация : ФУЛЛ ХАУС!" << endl;
        
    }
    else if (Flush(arm))
    {
        cout << "Комбинация : ФЛЕШ!" << endl;
       
    }
    else if (Straight(arm))
    {
        cout << "Комбинация : СТРИТ!" << endl;
    }
    else if (Set(arm))
    {
        cout << "Комбинация : СЕТ!" << endl;
        
    }
    else if (Two_pairs(arm))
    {
        cout << "Комбинация : ДВЕ ПАРЫ!" << endl;
    }
    else if (Pairs(arm))
    {
        cout << "Комбинация : ПАРА!" << endl;
    }
    
}

int Combo_val(Playing_card* arm)
{
    int val{};
    if (Royal_flush(arm))
    {
        val = 9;
    }
    else if (StraightFlush(arm))
    {
        val = 8;
    }
    else if (Four_of_a_kind(arm))
    {
        val = 7;
    }
    else if (FullHouse(arm))
    {
        val = 6;
    }
    else if (Flush(arm))
    {
        val = 5;
    }
    else if (Straight(arm))
    {
        val = 4;
    }
    else if (Set(arm))
    {
        val = 3;
    }
    else if (Two_pairs(arm))
    {
        val = 2;
    }
    else if (Pairs(arm))
    {
        val = 1;
    }

    return val;
}

void Win_loss(Game_table& game, Playing_card* arm, Playing_card* arm1)
{
    int val_p1 = Combo_val(arm);
    int val_p2 = Combo_val(arm1);

    if (val_p1 == val_p2)
    {
        Senior_card(game);
    }
    else if (val_p1 > val_p2)
    {
        cout << "Ваша комбинация сильнее : победа !" << endl;
        game.One.chips += game.bet;
        game.Two.chips -= game.bet;
    }
    else
    {
        cout << "Ваша комбинация слабее : проигрыш !" << endl;
        game.One.chips -= game.bet;
        game.Two.chips += game.bet;
    }
}

void Bet(Player& player, int amount)
{
    if (player.chips >= amount)
    {
        player.chips -= amount;
        cout << player.name << " сделал ставку на сумму " << amount << endl;
    }
    else
    {
        cout << player.name << " не может сделать ставку, недостаточно фишек" << endl;
    }
}
