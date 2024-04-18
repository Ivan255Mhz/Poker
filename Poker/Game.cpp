#include "Game.h"

int bet{};
enum Result { Lose, Win, Draw };

void Fill_the_deck(Deck& deck, int size_card, int size_suit, string* card, string* suit, int* rank_values, int* suit_values)// �������� ������� ����
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



void Print_card(Playing_card& card)//  ��� ������ ��� ��������
{
	cout << "|-------|" << endl;
	cout << "|       |" << endl;
	cout << "|   " << card.Card << "  |" << endl;
	cout << "| " << card.Suit << "  |" << endl;
	cout << "|       |" << endl;
	cout << "|-------|" << endl;
}

void Print_deck(Deck& deck, int size) // ���� ��� �������� 
{
	for (int i{}; i < size; ++i)
	{

		Print_card(deck.Deck_card[i]);
	}
}

void Shuffle_card(Deck& deck, int size)    // ������� ������ 
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

void Game_deck(Game_table& game, Deck& deck, int size_game) // ������� ���� ��� ������� 
{
	int index = 0;
	for (int i = 4; i < size_game; ++i)
	{
		game.Play_deck[index] = deck.Deck_card[i];
		++index;
	}
}

//void Privat_card(Player& one, Player& two, Deck& game) // ���� ����� � ���� ������� 
//{
//    one.Privat_card[0] = game.Deck_card[0];
//    one.Privat_card[1] = game.Deck_card[2];
//    two.Privat_card[0] = game.Deck_card[1];
//    two.Privat_card[1] = game.Deck_card[3];
//
//}

//void Player_p_table(Game_table& game, Player& one, Player& two) // ��������� ������� � ����� 
//{
//    game.One = one;
//    game.Two = two;
//}

void Preparing_game(Deck& deck, Player& one, Player& two, Game_table& game)
{
	one.Privat_card[0] = deck.Deck_card[0];
	one.Privat_card[1] = deck.Deck_card[2];
	two.Privat_card[0] = deck.Deck_card[1];
	two.Privat_card[1] = deck.Deck_card[3];

	one.arm[0] = deck.Deck_card[0];
	one.arm[1] = deck.Deck_card[2];
	two.arm[0] = deck.Deck_card[1];
	two.arm[1] = deck.Deck_card[3];


	Game_deck(game, deck);
	int index{};
	for (int i = 2; i < 7; ++i)
	{
		one.Privat_card[i] = game.Play_deck[index];
		two.Privat_card[i] = game.Play_deck[index];
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






void Table(Game_table& game) // 1 ���� ������
{
	cout << "\t\t\t\t     ---����� �� ����� ��� 1---" << endl;
	cout << "\t\t\t\t       +------+------+------+" << endl;
	cout << "\t\t\t\t       |  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |" << endl;
	cout << "\t\t\t\t       | " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " |" << endl;
	cout << "\t\t\t\t       +------+------+------+" << endl;
}

void Table_t_2(Game_table& game) // 2 ���� ������ 
{
	cout << "\t\t\t\t     ---����� �� ����� ��� 2---" << endl;
	cout << "\t\t\t\t    +------+------+------+------+" << endl;
	cout << "\t\t\t\t    |  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  " << game.Play_deck[3].Card << "  |" << endl;
	cout << "\t\t\t\t    | " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " | " << game.Play_deck[3].Suit << " |" << endl;
	cout << "\t\t\t\t    +------+------+------+------+" << endl;
}

void Table_t_3(Game_table& game) // 3 ���� ������ 
{
	cout << "\t\t\t\t     ---����� �� ����� ��� 3---" << endl;
	cout << "\t\t\t\t+------+------+------+------+------+" << endl;
	cout << "\t\t\t\t|  " << game.Play_deck[0].Card << "  |  " << game.Play_deck[1].Card << "  |  " << game.Play_deck[2].Card << "  |  " << game.Play_deck[3].Card << "  |  " << game.Play_deck[4].Card << "  |" << endl;
	cout << "\t\t\t\t| " << game.Play_deck[0].Suit << " | " << game.Play_deck[1].Suit << " | " << game.Play_deck[2].Suit << " | " << game.Play_deck[3].Suit << " | " << game.Play_deck[4].Suit << " |" << endl;
	cout << "\t\t\t\t+------+------+------+------+------+" << endl;
}

void Print_Arm1(Game_table& game) // ����� ���� 1 ������ 
{
	cout << " ---���� 1 ������---" << endl;
	cout << "  +------+------+" << endl;
	cout << "  |  " << game.One.Privat_card[0].Card << "  |  " << game.One.Privat_card[1].Card << "  |" << endl;
	cout << "  | " << game.One.Privat_card[0].Suit << " | " << game.One.Privat_card[1].Suit << " |" << endl;
	cout << "  +------+------+" << endl;
	Print_chips(game.One);
	Print_bet(game);
}

void Print_Arm2(Game_table& game) // ����� ���� 2 ������ 
{
	cout << " ---���� 2 ������---" << endl;
	cout << "  +-------------+" << endl;
	cout << "  |  " << game.Two.Privat_card[0].Card << "  |  " << game.Two.Privat_card[1].Card << "  |" << endl;
	cout << "  | " << game.Two.Privat_card[0].Suit << " | " << game.Two.Privat_card[1].Suit << " |" << endl;
	cout << "  +-------------+" << endl;
	Print_chips(game.Two);
	Print_bet(game);
}

void Sort_card(Playing_card* arm, int size) // ���������� ������� ��� ����������
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

int Senior_card(Game_table& game)  // ������� ����� 
{
	Sort_card(game.One.arm, 2);
	Sort_card(game.Two.arm, 2);

	if (game.One.arm[1].sort > game.Two.arm[1].sort)
	{
		cout << "���� ������� ����� ������� : ������ !" << endl;
		return Win;
	}
	else if (game.One.arm[1].sort < game.Two.arm[1].sort)
	{
		cout << "���� ������� ����� ������ : �������� !" << endl;
		return Lose;
	}
	else if (game.One.arm[0].sort > game.Two.arm[0].sort)
	{
		cout << "���� ������� ����� ������� : ������ !" << endl;
		return Win;
	}
	else if (game.One.arm[0].sort < game.Two.arm[0].sort)
	{
		cout << "���� ������� ����� ������ : �������� !" << endl;
		return Lose;
	}
	else
	{
		cout << "����� !" << endl;
		return Draw;
	}
}


bool Pairs(Playing_card* arm, int size) // ����
{
	Sort_card(arm, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arm[i].sort == arm[j].sort)
			{

				return true;
			}
		}
	}
	return false;
}

bool Two_pairs(Playing_card* arm, int size) // 2 ���� 
{
	Sort_card(arm, size);
	int pairs_count = 0;
	bool pair_found[15] = { false };

	for (int i = 0; i < size; i++)
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

bool Set(Playing_card* arm, int size) // ���
{
	Sort_card(arm, size);
	int rank_counts[15] {0};

	for (int i = 0; i < size; ++i)
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

bool Straight(Playing_card* arm , int size)  // �����
{
	Sort_card(arm, size);
	for (int i = 0; i < size - 1; ++i)
	{
		if (arm[i + 1].sort - arm[i].sort != 1)
		{
			return false;
		}
	}

	return true;
}


bool Flush(Playing_card* arm, int size) // ����
{
	Sort_card(arm, size);
	int count = 1;
	for (int i = 0; i < size - 1; ++i)
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

bool Four_of_a_kind(Playing_card* arm , int size) // ����
{
	Sort_card(arm, size);
	int rank_counts[15] {0};
	for (int i = 0; i < size; ++i)
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

bool FullHouse(Playing_card* arm, int size) // �������
{
	Sort_card(arm, size);
	int rank_counts[15] {0};

	for (int i = 0; i < size; ++i)
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

bool StraightFlush(Playing_card* arm, int size) // �����-����
{
	Sort_card(arm, size);
	int count = 1;
	for (int i = 0; i < size - 1; ++i)
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

bool Royal_flush(Playing_card* arm, int size) // ����-�����
{
	Sort_card(arm, size);
	if (size < 5)
	{
		return false;
	}
	if (arm[0].sort == 10 && arm[1].sort == 11 && arm[2].sort == 12 && arm[3].sort == 13 && arm[4].sort == 14 &&
		arm[0].su_vel == arm[1].su_vel && arm[1].su_vel == arm[2].su_vel && arm[2].su_vel == arm[3].su_vel && arm[3].su_vel == arm[4].su_vel)
	{

		return true;
	}

	return false;
}

void P_Check_combo(Playing_card* arm, int size)
{

	if (Royal_flush(arm,size))
	{
		cout << "���������� : ���� �����!" << endl;

	}
	else if (StraightFlush(arm, size))
	{
		cout << "���������� : ����� ����!" << endl;

	}
	else if (Four_of_a_kind(arm, size))
	{
		cout << "���������� : ����!" << endl;

	}
	else if (FullHouse(arm, size))
	{
		cout << "���������� : ���� ����!" << endl;

	}
	else if (Flush(arm, size))
	{
		cout << "���������� : ����!" << endl;

	}
	else if (Straight(arm, size))
	{
		cout << "���������� : �����!" << endl;
	}
	else if (Set(arm, size))
	{
		cout << "���������� : ���!" << endl;

	}
	else if (Two_pairs(arm, size))
	{
		cout << "���������� : ��� ����!" << endl;
	}
	else if (Pairs(arm, size))
	{
		cout << "���������� : ����!" << endl;
	}

}

void Start_Check_combo(Playing_card* arm, int size)
{
    if (Two_pairs(arm, size))
	{
		cout << "���������� : ��� ����!" << endl;
	}
	else if (Pairs(arm, size))
	{
		cout << "���������� : ����!" << endl;
	}
}

int Start_Combo_val(Playing_card* arm, int size)
{
	int val{};
	
	if (Two_pairs(arm, size))
	{
		val = 2;
	}
	else if (Pairs(arm, size))
	{
		val = 1;
	}

	return val;
}

int Combo_val(Playing_card* arm, int size)
{
	int val{};
	if (Royal_flush(arm, size))
	{
		val = 9;
	}
	else if (StraightFlush(arm, size))
	{
		val = 8;
	}
	else if (Four_of_a_kind(arm, size))
	{
		val = 7;
	}
	else if (FullHouse(arm, size))
	{
		val = 6;
	}
	else if (Flush(arm, size))
	{
		val = 5;
	}
	else if (Straight(arm, size))
	{
		val = 4;
	}
	else if (Set(arm, size))
	{
		val = 3;
	}
	else if (Two_pairs(arm, size))
	{
		val = 2;
	}
	else if (Pairs(arm, size))
	{
		val = 1;
	}

	return val;
}

int Win_loss(Game_table& game, Playing_card* arm, Playing_card* arm1, int size)
{
	int val_p1{};
	int val_p2{};
	if (size == 2)
	{
		int val_p1 = Start_Combo_val(arm, size);
		int val_p2 = Start_Combo_val(arm1, size);
	}
	else
	{
		int val_p1 = Combo_val(arm, size);
		int val_p2 = Combo_val(arm1, size);
	}

	if (val_p1 == val_p2)
	{
		int vel= Senior_card(game);
		if (vel == 0)
		{
			return Lose;
		}
		else if (vel == 1)
		{
			return Win;
		}
		else if (vel == 2)
		{
			return Draw;
		}
		
		
	}
	else if (val_p1 > val_p2)
	{
		cout << "���� ���������� ������� : ������ !" << endl;

		return Win;
	}
	else
	{
		cout << "���� ���������� ������ : �������� !" << endl;
		
		return Lose;
	}
}

void Swap_bet(Game_table& game, Player & ply1,Player & ply2, int size)
{
	int resul = Win_loss(game, ply1.Privat_card,ply2.Privat_card,2);
	if (resul==Draw)
	{
		cout << "����� ! ����� � ���������� " << game.bet << " ����� ����������� ����� �������� !" << endl;;
		ply1.chips += (game.bet / 2);
		ply2.chips += (game.bet / 2);
		game.bet = 0;
	}
	else if (resul == Win)
	{
		cout << "������ ! ����� � ������ : " << ply1.name << " �������� " << game.bet << " �����";
		ply1.chips += game.bet;
		game.bet = 0;
    }
	else if (resul == Lose)
	{
		cout << "��������� ! ����� � ������ : " << ply2.name << " �������� " << game.bet << " �����";
		ply2.chips += game.bet;
		game.bet = 0;
	}
}

int Bet (Game_table& game, Player & ply)
{
	int bet_f{};
	int choise{};
	cout << "�������� ������ : " << endl;
	cout << "1. 10 �����" << endl;
	cout << "2. 25 �����" << endl;
	cout << "3. 50 �����" << endl;
	cin >> choise;
	switch (choise)
	{

	case 1:
	{
		if (ply.chips > 10)
		{
			bet_f = 10;
			ply.chips -= bet_f;
			game.bet += bet_f;
			cout << "����� " << ply.name << " ������ ������ " << bet_f << " �����" << endl;
		}
		else
		{
			cout << "� ��� ������������ ����� :(" << endl;
			return -1;
		}
	} break;

	case 2:

	{
		if (ply.chips > 25)
		{
			bet_f = 25;
			ply.chips -= bet_f;
			game.bet += bet_f;
			cout << "����� " << ply.name << " ������ ������ " << bet_f << " �����" << endl;
		}
		else
		{
			cout << "� ��� ������������ ����� :(" << endl;
			return -1;
		}
	} break;

	case 3:

	{
		if (ply.chips > 50)
		{
			bet_f = 50;
			ply.chips -= bet_f;
			game.bet += bet_f;
			cout << "����� " << ply.name << " ������ ������ " << bet_f << " �����" << endl;
		}
		else
		{
			cout << "� ��� ������������ ����� :(" << endl;
			return -1;
		}
	}

	
	}
	return bet_f;
}


void Print_chips( Player& ply)
{	
	cout << "+--------------------+" << endl;
	cout << "| � ��� : " << ply.chips << " �����"<<"  |" << endl;
	cout << "+--------------------+" << endl;
}

void Print_bet(Game_table& game)
{
	cout << "+--------------------+" << endl;
	cout << "| ������ : " << game.bet << " �����" << "  |" << endl;
	cout << "+--------------------+" << endl;
}


void Phaise_1_ply1(Game_table& game) // ����� ����
{
	 
	int choise{};

	Print_Arm1(game);
	Start_Check_combo(game.One.arm,2);
	
	cout << "+--------------------+"<<endl;
	cout << "| ���� ������� :     |" << endl;
	cout << "| 1. ������� ������. |" << endl;
	cout << "| 2. ����� �� ����.  |" << endl;
	cout << "+--------------------+" << endl;
	cin >> choise;
	switch (choise)
	{
	
	case 1:
	{
		system("cls");
		bet = Bet(game, game.One);
		system("pause");
		system("cls");
		Phaise_1_ply2(game);
	} break;

	case 2:
	{
		cout << "����� : " << endl;
	} break;


	default:
	{
		cout << "������ �����, ���������� ��� ���" << endl;
	}
	break;
	}

}

void Phaise_1_ply2(Game_table& game ) // 2 ����� ������� 
{
	int choise{};
    Print_Arm2(game);
	Start_Check_combo(game.Two.arm ,2);
	
	cout << "+--------------------+" << endl;
	cout << "| ���� ������� :     |" << endl;
	cout << "| 1. �������� ������.|" << endl;
	cout << "| 2. �������� ������.|" << endl;
	cout << "| 3. ���             |" << endl; 
	cout << "+--------------------+" << endl;
	cin >> choise;
	switch (choise)
	{

	case 1:
	{
		game.Two.chips -= bet;
		game.bet += bet;
		system("pause");
		system("cls");
		Phaise_2_ply1(game);
	} break;

	case 2:
	{
	    bet += 15;
		system("pause");
		system("cls");
    } break;

	case 3:
	{
		system("cls");
		cout << "�� ��������� :(" << endl;
		game.One.chips += game.bet;
		cout << "����� 1 �������� : " << game.bet << " �����" << endl;;
		system("pause");
		system("cls");
		game.bet=0;
		Phaise_1_ply1(game);
	
	} break;


	default:
	{
		cout << "������ �����, ���������� ��� ���" << endl;
	}
	break;
	}
}

void Phaise_2_ply1(Game_table& game) // 1 ����� ������� � ������ ���������� 2 ������
{
	int choise{};
	Print_Arm1(game);
	Start_Check_combo(game.One.arm, 2);
	cout << "--------------------" << endl;
	cout << " ���� ������� : " << endl;
	cout << " 1.������� �����. " << endl;
	cout << " 2.�������� ������." << endl;
	cout << " 3.������� �� ���." << endl;
	cout << " 4.���" << endl;
	cout << "--------------------" << endl;
	cin >> choise;
	switch (choise)
	{

	case 1:
	{   
		system("cls");
		Swap_bet(game, game.One, game.Two, 2);
		system("pause");
		system("cls");
		Phaise_1_ply1(game);
		
	} break;

	case 2:
	{
		system("pause");
		system("cls");

	} break;

	case 3:
	{
		
		system("pause");
		system("cls");
	} break;

	case 4:
	{
		system("cls");
		cout << "�� ��������� :(" << endl;
		game.Two.chips += game.bet;
		cout << "����� 2 �������� : " << game.bet << " �����" << endl;;
		Phaise_1_ply1(game);
		system("pause");
		system("cls");
	} break;


	default:
	{
		cout << "������ �����, ���������� ��� ���" << endl;
	}
	break;
	}

}

void Phaise_2_1_ply1(Game_table& game) // 1 ����� �������� � ������ �������� 2 ������ 
{
	int choise{};
	Print_Arm1(game);
	Start_Check_combo(game.One.arm, 2);
	cout << "--------------------" << endl;
	cout << "���� ������� : " << endl;
	cout << " 1.�������� ������" << endl;
	cout << " 1.������� �����. " << endl;
	cout << " 2.�������� ������." << endl;
	cout << " 3.������� �� ���." << endl;
	cout << " 4.���" << endl;
	cout << "--------------------" << endl;
	cin >> choise;
	switch (choise)
	{

	case 1:
	{
		system("cls");
		Swap_bet(game, game.One, game.Two, 2);
		system("pause");
		system("cls");
		Phaise_1_ply1(game);

	} break;

	case 2:
	{
		system("pause");
		system("cls");

	} break;

	case 3:
	{

		system("pause");
		system("cls");
	} break;

	case 4:
	{
		system("cls");
		cout << "�� ��������� :(" << endl;
		game.Two.chips += game.bet;
		cout << "����� 2 �������� : " << game.bet << " �����" << endl;;
		Phaise_1_ply1(game);
		system("pause");
		system("cls");
	} break;


	default:
	{
		cout << "������ �����, ���������� ��� ���" << endl;
	}
	break;
	}

}