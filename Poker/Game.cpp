#include "Game.h"

int bet{}; // ���������� ������

enum Result { Lose, Win, Draw }; // ��� ����������� ������, ��������� , � ������ 

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

void Preparing_game(Deck& deck, Player& one, Player& two, Game_table& game) // ���������� � ���� 
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
		one.arm[i]= game.Play_deck[index];
		two.arm[i]= game.Play_deck[index];
		++index;
	}
	game.One = one;
	game.Two = two;

}

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
	cout << " ---���� ������ "<<game.One.name<<"---" << endl;
	cout << "    +------+------+" << endl;
	cout << "    |  " << game.One.arm[0].Card << "  |  " << game.One.arm[1].Card << "  |" << endl;
	cout << "    | " << game.One.arm[0].Suit << " | " << game.One.arm[1].Suit << " |" << endl;
	cout << "    +------+------+" << endl;
	Print_chips(game.One);
	Print_bet(game);
}

void Print_Arm2(Game_table& game) // ����� ���� 2 ������ 
{
	cout << " ---���� ������ " << game.Two.name << "---" << endl;
	cout << "    +-------------+" << endl;
	cout << "    |  " << game.Two.arm[0].Card << "  |  " << game.Two.arm[1].Card << "  |" << endl;
	cout << "    | " << game.Two.arm[0].Suit << " | " << game.Two.arm[1].Suit << " |" << endl;
	cout << "    +-------------+" << endl;
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

void Old_arr(Playing_card* arm1, Playing_card* arm2, int size) // ������� ������� ��� ���������� � ������������ �������� 
{
	for (int i{}; i < size; ++i)
	{
		arm1[i] = arm2[i];
	}
}

int Senior_card(Game_table& game, Player& ply1, Player& ply2)  // ������� ����� 
{
	Sort_card(game.One.arm, 2);
	Sort_card(game.Two.arm, 2);

	if (ply1.arm[1].sort == ply2.arm[1].sort)
	{
		if (ply1.arm[0].sort == ply2.arm[0].sort)
		{
			return Draw;
		}
		else if (ply1.arm[0].sort > ply2.arm[0].sort)
		{
			
			return Win;
		}
		else
		{
			
			return Lose;
		}
	}
	else if (ply1.arm[1].sort > ply2.arm[1].sort)
	{
		
		return Win;
	}
	else
	{
		
	    return Lose;
	}
}


bool Pairs(Player ply, int size) // ����
{
	Sort_card(ply.Privat_card, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ply.Privat_card[i].sort == ply.Privat_card[j].sort)
			{
				Old_arr(ply.Privat_card, ply.arm,size);
				return true;
			}
		}
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool Two_pairs(Player ply, int size) // 2 ��� 3 ���� 
{
	Sort_card(ply.Privat_card, size);
	int pairs_count = 0;
	bool pair_found[15] = { false };

	for (int i = 0; i < size; i++)
	{
		if (pair_found[ply.Privat_card[i].sort])
		{
			pairs_count++;
		}
		else
		{
			pair_found[ply.Privat_card[i].sort] = true;
		}
	}

	if (pairs_count == 2 || pairs_count == 3)
	{
		Old_arr(ply.Privat_card, ply.arm, size);
		return true;
	}
	else
	{
		Old_arr(ply.Privat_card, ply.arm, size);
		return false;
	}
}

bool Set(Player ply, int size) // ���
{
	Sort_card(ply.Privat_card, size);
	int rank_counts[15]{ 0 };

	for (int i = 0; i < size; ++i)
	{
		rank_counts[ply.Privat_card[i].sort]++;
	}

	for (int i = 0; i < 15; ++i)
	{
		if (rank_counts[i] == 3)
		{
			Old_arr(ply.Privat_card, ply.arm, size);
			return true;
		}
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool Straight(Player ply, int size)  // �����
{
	Sort_card(ply.Privat_card, size);
	for (int i = 0; i < size - 1; ++i)
	{
		if (ply.Privat_card[i + 1].sort - ply.Privat_card[i].sort != 1)
		{
			Old_arr(ply.Privat_card, ply.arm, size);
			return false;
		}
	}

	Old_arr(ply.Privat_card, ply.arm, size);
	return true;
}


bool Flush(Player ply, int size) // ����
{
	Sort_card(ply.Privat_card, size);
	int count = 1;
	for (int i = 0; i < size - 1; ++i)
	{
		if (ply.Privat_card[i].su_vel == ply.Privat_card[i + 1].su_vel)
		{
			count++;
			if (count == 5)
			{
				Old_arr(ply.Privat_card, ply.arm, size);
				return true;
			}
		}
		else
		{
			count = 1;
		}
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool Four_of_a_kind(Player ply, int size) // ����
{
	Sort_card(ply.Privat_card, size);
	int rank_counts[15]{ 0 };
	for (int i = 0; i < size; ++i)
	{
		rank_counts[ply.Privat_card[i].sort]++;
	}

	for (int i = 0; i < 15; ++i)
	{
		if (rank_counts[i] == 4)
		{
			Old_arr(ply.Privat_card, ply.arm, size);
			return true;
		}
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool FullHouse(Player ply, int size) // �������
{
	Sort_card(ply.Privat_card, size);
	int rank_counts[15]{ 0 };

	for (int i = 0; i < size; ++i)
	{
		rank_counts[ply.Privat_card[i].sort]++;
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
		Old_arr(ply.Privat_card, ply.arm, size);
		return true;
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool StraightFlush(Player ply, int size) // �����-����
{
	Sort_card(ply.Privat_card, size);
	int count = 1;
	for (int i = 0; i < size - 1; ++i)
	{
		if (ply.Privat_card[i].su_vel == ply.Privat_card[i + 1].su_vel && ply.Privat_card[i + 1].sort - ply.Privat_card[i].sort == 1)
		{
			count++;
			if (count == 5)
			{
				Old_arr(ply.Privat_card, ply.arm, size);
				return true;
			}
		}
		else
		{
			count = 1;
		}
	}
	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

bool Royal_flush(Player ply, int size) // ����-�����
{
	Sort_card(ply.Privat_card, size);
	if (size < 5)
	{
		return false;
	}
	if (ply.Privat_card[0].sort == 10 && ply.Privat_card[1].sort == 11 && ply.Privat_card[2].sort == 12 && ply.Privat_card[3].sort == 13 && ply.Privat_card[4].sort == 14 &&
		ply.Privat_card[0].su_vel == ply.Privat_card[1].su_vel && ply.Privat_card[1].su_vel == ply.Privat_card[2].su_vel && ply.Privat_card[2].su_vel == ply.Privat_card[3].su_vel && ply.Privat_card[3].su_vel == ply.Privat_card[4].su_vel)
	{
		Old_arr(ply.Privat_card, ply.arm, size);
		return true;
	}

	Old_arr(ply.Privat_card, ply.arm, size);
	return false;
}

void P_Check_combo(Player ply, int size) // ������ ����� �������
{

	if (Royal_flush(ply,size))
	{
		cout << "���������� : ���� �����!" << endl;

	}
	else if (StraightFlush(ply, size))
	{
		cout << "���������� : ����� ����!" << endl;

	}
	else if (Four_of_a_kind(ply, size))
	{
		cout << "���������� : ����!" << endl;

	}
	else if (FullHouse(ply, size))
	{
		cout << "���������� : ���� ����!" << endl;

	}
	else if (Flush(ply, size))
	{
		cout << "���������� : ����!" << endl;

	}
	else if (Straight(ply, size))
	{
		cout << "���������� : �����!" << endl;
	}
	else if (Set(ply, size))
	{
		cout << "���������� : ���!" << endl;

	}
	else if (Two_pairs(ply, size))
	{
		cout << "���������� : ��� ����!" << endl;
	}
	else if (Pairs(ply, size))
	{
		cout << "���������� : ����!" << endl;
	}

}

void Start_Check_combo(Player ply, int size) // ������ ����� �� ���� 
{
	if (Two_pairs(ply, size))
	{
		cout << "���������� : ��� ����!" << endl;
	}
	else if (Pairs(ply, size))
	{
		cout << "���������� : ����!" << endl;
	}
}

int Start_Combo_val(Player ply, int size) // ������� ������� ���� ���������� �� ������ 
{
	int val{};

	if (Two_pairs(ply, size))
	{
		val = 2;
	}
	else if (Pairs(ply, size))
	{
		val = 1;
	}

	return val;
}

int Combo_val(Player ply, int size) // ������ ���� ����������
{
	int val{};
	if (Royal_flush(ply, size))
	{
		val = 9;
	}
	else if (StraightFlush(ply, size))
	{
		val = 8;
	}
	else if (Four_of_a_kind(ply, size))
	{
		val = 7;
	}
	else if (FullHouse(ply, size))
	{
		val = 6;
	}
	else if (Flush(ply, size))
	{
		val = 5;
	}
	else if (Straight(ply, size))
	{
		val = 4;
	}
	else if (Set(ply, size))
	{
		val = 3;
	}
	else if (Two_pairs(ply, size))
	{
		val = 2;
	}
	else if (Pairs(ply, size))
	{
		val = 1;
	}

	return val;
}

int Win_loss(Game_table& game, Player& ply1, Player& ply2, int size) // ����������� ����������
{
	int val_p1{};
	int val_p2{};
	if (size == 2)
	{
		 val_p1 = Start_Combo_val(ply1, size);
		 val_p2 = Start_Combo_val(ply2, size);
	}
	else
	{
		 val_p1 = Combo_val(ply1, size);
		 val_p2 = Combo_val(ply2, size);
	}

	if (val_p1 == val_p2)
	{
		int vel = Senior_card(game, ply1, ply2);
		if (vel == 0)
		{
			cout <<"������� ����� ������ "<<ply1.name << " ������" << endl;
			return Lose;
		}
		else if (vel == 1)
		{
			cout << "������� ����� ������ " << ply1.name << " �������" << endl;
			return Win;
		}
		else if (vel == 2)
		{
			return Draw;
		}
	}
	else if (val_p1 > val_p2)
	{
		
		return Win;
	}
	else
	{
		
		return Lose;
	}
}

void Swap_bet(Game_table& game, Player& ply1, Player& ply2, int size) // ������������� ������ 
{
	int resul = Win_loss(game, ply1, ply2, 2);
	if (resul == Draw)
	{
		cout << "����� ! ����� � ���������� " << game.bet << " ����� ����������� ����� �������� !" << endl;;
		ply1.chips += (game.bet / 2);
		ply2.chips += (game.bet / 2);
		game.bet = 0;
	}
	else if (resul == Win)
	{
		cout << "������  ������ � ������ : " << ply1.name << " �� �������� " << game.bet << " �����" << endl;
		ply1.chips += game.bet;
		game.bet = 0;
	}
	else if (resul == Lose)
	{
		cout << "������  ������ � ������ : " << ply2.name << " �� �������� " << game.bet << " �����" << endl;
		ply2.chips += game.bet;
		game.bet = 0;
	}
}

void Bet(Game_table& game, Player& ply) // ������ 
{
	
	int choise{};
	Print_chips(ply);
	cout << "+-------------------+" << endl;
	cout << "| �������� ������ : |" << endl;
	cout << "| 1. 10 �����       |" << endl;
	cout << "| 2. 25 �����       |" << endl;
	cout << "| 3. 50 �����       |" << endl;
	cout << "+-------------------+" << endl;
	cout << "����� : ";
	cin >> choise;
	switch (choise)
	{

	case 1:
	{
		if (ply.chips > 10)
		{
			bet = 10;
			ply.chips -= bet;
			game.bet += bet;
			system("cls");
			cout << endl;
			cout << "����� " << ply.name << " ������ ������ " << bet << " �����" << endl;
			cout << endl;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}

	} break;

	case 2:

	{
		if (ply.chips > 25)
		{
			bet = 25;
			ply.chips -= bet;
			game.bet += bet;
			system("cls");
			cout << endl;
			cout << "����� " << ply.name << " ������ ������ " << bet << " �����" << endl;
			cout << endl;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}

	} break;

	case 3:

	{
		if (ply.chips > 50)
		{
			bet = 50;
			ply.chips -= bet;
			game.bet += bet;
			system("cls");
			cout << endl;
			cout << "����� " << ply.name << " ������ ������ " << bet << " �����" << endl;
			cout << endl;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}
	} break;

	default :
	{
		system("cls");
		Bet(game, ply);
	} break;
	
}
}


void Print_chips(Player& ply) // ������ ����� ������
{
	cout << "+--------------------+" << endl;
	cout << "| � ��� : " << ply.chips << " �����" << "  |" << endl;
	cout << "+--------------------+" << endl;
}

void Print_bet(Game_table& game) // ������ ����� �� �����
{
	cout << "+--------------------+" << endl;
	cout << "| ������ : " << game.bet << " �����" << "  |" << endl;
	cout << "+--------------------+" << endl;
}

void Eq_bet(Game_table& game, Player& ply, int  bet) // ���������� ������
{
	if (ply.chips >= bet)
	{
		ply.chips -= bet;
		game.bet += bet;
		cout << "���� ������ ����������� !" << endl;
	}
	else
	{
		system("cls");
		Low_bat(game, ply);
	}
}

void Low_bat(Game_table& game, Player& ply) // ��������� ������� �����
{
	int vl{};
	cout << "� ��� �������� " << ply.chips << " ����� ��������� �� ?" << endl;
	cout << "    +---------+" << endl;
	cout << "    | 1. ��.  |" << endl;
	cout << "    | 2. ���. |" << endl;
	cout << "    +---------+" << endl;
	cout << " ���� ������� : ";
	cin >> vl;
	switch (vl)
	{
	case 1:
	{
		system("cls");
		bet = ply.chips;
		game.bet += ply.chips;
		ply.chips = 0;
	} break;

	case 2:
	{
		system("cls");
		return;

	} break;

	default:
	{
		system("cls");
		Low_bat(game, ply);
	} break;
		
	}

}

void Up_bet(Game_table& game, Player& ply) // ��������� ������
{
	int vl{};
	Print_bet();
	Print_chips(ply);
	cout << "+---------------------------+" << endl;
	cout << "| 1. ��������� �� 15 �����. |" << endl;
	cout << "| 2. ��������� �� 20 �����. |" << endl;
	cout << "| 3. ��������� �� 25 �����. |" << endl;
    cout << "+---------------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> vl;

	switch (vl)
	{
	case 1:
	{
		if (ply.chips >= bet + 15)
		{
			bet += 15;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}
		
	} break;

	case 2:
	{
		if (ply.chips >= bet + 20)
		{
			bet += 20;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}
	} break;

	case 3:
	{
		if (ply.chips >= bet + 25)
		{
			bet += 25;
		}
		else
		{
			system("cls");
			cout << "� ��� ������������ ����� " << endl;
			system("pause");
			system("cls");
			Low_bat(game, ply);
		}
	} break;

	

	default:
	{
		system("cls");
		Up_bet(game, ply);
	} break;

	}
	ply.chips -= bet;
	game.bet += bet;
	system("cls");
	cout << endl;
	cout << "������ ���� �������� �� " << bet << " �����" <<endl ; 
	cout << endl;
}

void Pas_bet(Game_table& game, Player& ply) // ��� ������
{
	ply.chips += game.bet;
	game.bet = 0;
	bet = 0;
	cout << "�������� , ����� �������� ����� " << ply.name << endl;
}

void Print_bet()
{
	cout << "���������� ������ : " << bet << endl;
}



void Coin_flip(Game_table& game, Deck &stack) // ������� ������� � ����������� ���� 
{
	bet = 0;
	Game_over(game, stack);
	Shuffle_card(stack);
	Preparing_game(stack, game.One, game.Two, game);

	bool val = rand() % 2;

	if (val)
	{
		cout << endl;
		cout << "� ����� ������������ ����� " << game.One.name << endl;
		cout << endl;
		system("pause");
		system("cls");
		Start_p1(game, stack);
	}
	else
	{
		cout << endl;
		cout << "� ����� ������������ ����� " << game.Two.name << endl;
		cout << endl;
		system("pause");
		system("cls");
		Start_p2(game, stack);
	}
}

void Game_over(Game_table& game, Deck& stack) // �������� �� ��������
{
	if (game.One.chips == 0)
	{
		
		cout << "+----------------------------------------+" << endl;
		cout << "| � ��� ���������� ����� , �� ��������� !|" << endl;
		cout << "+----------------------------------------+" << endl;
		system("pause");
		game.One.chips = 1000;
		game.Two.chips = 1000;
		Menu(game, stack);
	
	}

	if (game.Two.chips == 0)
	{
		cout << "+----------------------------------------+"<<endl;
		cout << "| � ��� ���������� ����� , �� ��������� !|" << endl;
		cout << "+----------------------------------------+"<<endl;
		system("pause");
		game.One.chips = 1000;
		game.Two.chips = 1000;
		Menu(game, stack);
	}
}

void Print_rules() // �������
{
	cout << "������� ���� � ���� ������ \"�����\" " << endl;
	cout << endl;
	cout << "1. ������ ��� ������� ������������ ��������� ������� " << endl;
	cout << "2. �� ������ ���� �� ������ ������� ������ ��� ��������� ���� �������� ������" << endl;
	cout << "3. ����� ����������� ������ ����� �� ������� , ���� ��������� � ����� ����     (�� ��������� ����� ���������� ����� ���������� )" << endl;
	cout << "4. ��� ������������� ���-�� ����� ��� ����������� ��� ��������� ������ , �� ������ ��������� ���� ���������� �����" << endl;
	cout << "5. � ��� �� ������ ����� ���� ����������� ��������� , ����� ����� ��� ����� �� ������ �������� ��� �������� " << endl;
	cout << "6. ����� ����� ��� ���������� ������� ����� ��� �������� ������� ������ , �����  ����� ����������� ��� ����������(�����  �� ��������� � ������ �������)" << endl;
	cout << endl;
	cout << " ���������� ����" << endl;
	cout << endl;
	cout << "1. ������� ����� - ���� � ��� ���������� ���������� � ����������, �� ��������� ����� � ����� ������� ������ �� �����" << endl;
	cout << "2. ���� - ��� ���������� ����� ������ ����� �� �����" << endl;
	cout << "3. ��� ���� - ��� ���� �� ����� " << endl;
	cout << "4. ��� - ��� ���������� ����� �� ����� " << endl;
	cout << "5. ����� - ������������������ �� 5 ���� ������ �� ����� " << endl;
	cout << "6. ���� - ���� ���� ����� ����� �� ����� " << endl;
	cout << "7. ���� ���� - ��� � ���� �� �����" << endl;
	cout << "8. ���� - ������ ����� ������ ����� �� �����" << endl;
	cout << "9. ����� ���� - ������������������ �� 5  ���� ����� ����� �� �����" << endl;
	cout << "10. ���� ����� - ������������������ ����� ����� �� 10 �� ���� �� ����� " << endl;

	system("pause");
	system("cls");
	return;
}



void Menu(Game_table& game, Deck& stack) // ����
{
	int choise{};
	do
	{
		cout << "\t\t\t\t\t  +-----------------+" << endl;
		cout << "\t\t\t\t\t  |1. ������ ����   |" << endl;
		cout << "\t\t\t\t\t  |2. ������� ����  |" << endl;
		cout << "\t\t\t\t\t  |3. ����� �� ���� |" << endl;
		cout << "\t\t\t\t\t  +-----------------+" << endl;
		cout << "\t\t\t\t\t   ���� ������� : ";
		cin >> choise;

		switch (choise)
		{

		case 1:
		{
			system("cls");
			Coin_flip(game, stack);
		} break;

		case 2:
		{
			system("cls");
			Print_rules();
		} break;

		case 3:
		{
			return;
		} break;

		default:
		{
			system("cls");
			Menu(game, stack);
        } break;
		}
	} while (choise != 3);
}

void Start_p1(Game_table& game, Deck& stack)  // ������ ������ ������� ������ ������ ����
{
	int p1{};
	Print_Arm1(game);
	Start_Check_combo(game.One, 2);
	Print_bet();
	cout << "+--------------------+" << endl;
	cout << "| 1. ������� ������. |" << endl;
	cout << "| 2. ���.            |" << endl;
	cout << "+--------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Bet(game, game.One);
		system("pause");
		system("cls");
		Start2_p2(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default :
	{
		system("cls");
		Start_p1(game, stack);
	}
	
	}
}

void Start2_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Print_Arm1(game);
	Start_Check_combo(game.One, 2);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.One,bet);
		system("pause");
		system("cls");
		Erl_p2(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Start2_p2(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game,stack);
	} break;

	default:
	{
		system("cls");
		Start2_p1(game, stack);
	}

	}
}

void Start_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Print_Arm2(game);
	Start_Check_combo(game.Two, 2);
	Print_bet();
	cout << "+--------------------+" << endl;
	cout << "| 1. ������� ������. |" << endl;
	cout << "| 2. ���.            |" << endl;
	cout << "+--------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Bet(game, game.Two);
		system("pause");
		system("cls");
		Start2_p1(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Start_p2(game, stack);
	}
	

	}
}

void Start2_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Print_Arm2(game);
	Start_Check_combo(game.Two, 2);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.Two, bet);
		system("pause");
		system("cls");
		Erl_p1(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Start2_p1(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Start2_p2(game, stack);
	}

	}
}

void Erl_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 5);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Erl2_p2(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Erl_WL_p1(game,stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Erl_pas_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl_p1(game, stack);
	}

	}

}

void Erl_WL_p1(Game_table& game, Deck& stack)
{
	
	int val{};

	cout << "������ ������ : " << game.Two.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.Two, game.One, 5);
		Swap_bet(game, game.Two, game.One, 5);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
    } break;

	case 2:
	{
		system("cls");
		Erl_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl_WL_p1(game, stack);
	}
	
	}
}

void Erl_pas_p1(Game_table& game, Deck &stack)
{
	int val{};
	cout << "������ ������ : " << game.Two.name << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� �������� ������ , �� �������� ? |" << endl;
	cout << "|                  1. ��                               |" << endl;
	cout << "|                  2. ���                              |" << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Mid_p2(game, stack);
		
	} break;

	case 2:
	{
		system("cls");
		Erl_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl_pas_p1(game, stack);
	}

	}
}

void Erl2_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 5);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.One, bet);
		system("pause");
		system("cls");
		Mid_p2(game, stack);
		
	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Erl2_p2(game, stack);

	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl2_p1(game, stack);
	}

	

	}

}
   
void Erl_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 5);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Erl2_p1(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Erl_WL_p2(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Erl_pas_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl_p2(game, stack);
	}

	}

}

void Erl_WL_p2(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.One.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.One, game.Two, 5);
		Swap_bet(game, game.One, game.Two, 5);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Erl_p2(game, stack);
	} break;
	default:
	{
		system("cls");
		Erl_WL_p2(game, stack);
	}

	}
}

void Erl_pas_p2(Game_table& game, Deck &stack)
{
	int val{};
	cout << "������ ������ : " << game.One.name << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� �������� ������ , �� �������� ? |" << endl;
	cout << "|                  1. ��                               |" << endl;
	cout << "|                  2. ���                              |" << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Mid_p1(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Erl_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl_pas_p2(game, stack);
	}

	}
}

void Erl2_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 5);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.Two, bet);
		system("pause");
		system("cls");
		Mid_p1(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Erl2_p1(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Erl2_p2(game, stack);
	}



	}

}

void Mid_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table_t_2(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 6);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Mid2_p2(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Mid_WL_p1(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Mid_pas_p1(game, stack);
		
	} break;

	default:
	{
		system("cls");
		Mid_p1(game, stack);
	}

	}
}

void Mid_WL_p1(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.Two.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.Two, game.One, 6);
		Swap_bet(game, game.Two, game.One, 6);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Mid_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid_WL_p1(game, stack);
	}

	}
}

void Mid_pas_p1(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.Two.name << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� �������� ������ , �� �������� ? |" << endl;
	cout << "|                  1. ��                               |" << endl;
	cout << "|                  2. ���                              |" << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Lt_p2(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Mid_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid_pas_p1(game, stack);
	}

	}
}

void Mid2_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table_t_2(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 6);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.One, bet);
		system("pause");
		system("cls");
		Lt_p2(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Mid2_p2(game, stack);

	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid2_p1(game, stack);
	}



	}

}

void Mid_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table_t_2(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 6);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Mid2_p1(game, stack);
		
	} break;

	case 2:
	{
		system("cls");
		Mid_WL_p2(game, stack);
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Mid_pas_p2(game, stack);
		
	} break;

	default:
	{
		system("cls");
		Mid_p2(game, stack);
	}

	}
}

void Mid_WL_p2(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.One.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.One, game.Two, 6);
		Swap_bet(game, game.One, game.Two, 6);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Mid_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid_WL_p2(game, stack);
	}

	}
}

void Mid_pas_p2(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.One.name << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� �������� ������ , �� �������� ? |" << endl;
	cout << "|                  1. ��                               |" << endl;
	cout << "|                  2. ���                              |" << endl;
	cout << "+------------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Lt_p1(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Mid_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid_pas_p2(game, stack);
	}

	}
}

void Mid2_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table_t_2(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 6);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.Two, bet);
		system("pause");
		system("cls");
		Lt_p1(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Mid2_p1(game, stack);

	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Mid2_p2(game, stack);
	}



	}

}

void Lt_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table_t_3(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 7);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Lt2_p2(game, stack);
		
	} break;

	case 2:
	{
		system("cls");
		Lt_WL_p1(game, stack);
		
	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Lt_WL_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt_p1(game, stack);
	}

	}
}

void Lt_WL_p1(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.Two.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.Two, game.One, 7);
		Swap_bet(game, game.Two, game.One, 7);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Lt_p1(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt_WL_p1(game, stack);
	}

	}
}

void Lt2_p1(Game_table& game, Deck& stack)
{
	int p1{};
	Table_t_3(game);
	Print_Arm1(game);
	P_Check_combo(game.One, 7);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p1;
	switch (p1)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.One, bet);
		system("pause");
		system("cls");
		Win_loss(game, game.One, game.Two, 7);
		Swap_bet(game, game.One, game.Two, 7);
		system("pause");
		system("cls");
		Coin_flip(game, stack);

		
	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.One);
		system("pause");
		system("cls");
		Lt2_p2(game, stack);
		

	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.Two);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt2_p1(game, stack);
	}



	}
}

void Lt_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table_t_3(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 7);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. ������� �����.   |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "| 4. �������� ������. |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Lt2_p1(game, stack);

	} break;

	case 2:
	{
		system("cls");
		Lt_WL_p2(game, stack);

	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 4:
	{
		system("cls");
		Lt_WL_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt_p2(game, stack);
	}

	}

}

void Lt_WL_p2(Game_table& game, Deck& stack)
{
	int val{};
	cout << "������ ������ : " << game.One.name << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "| ����� ���������� ��� ������� ����� , �� �������� ? |" << endl;
	cout << "|                  1. ��                             |" << endl;
	cout << "|                  2. ���                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "              ���� ������� : ";
	cin >> val;

	switch (val)
	{

	case 1:
	{
		system("cls");
		Win_loss(game, game.One, game.Two, 7);
		Swap_bet(game, game.One, game.Two, 7);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	case 2:
	{
		system("cls");
		Lt_p2(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt_WL_p2(game, stack);
	}

	}
}

void Lt2_p2(Game_table& game, Deck& stack)
{
	int p2{};
	Table_t_3(game);
	Print_Arm2(game);
	P_Check_combo(game.Two, 7);
	Print_bet();
	cout << "+---------------------+" << endl;
	cout << "| 1. �������� ������. |" << endl;
	cout << "| 2. �������� ������. |" << endl;
	cout << "| 3. ���.             |" << endl;
	cout << "+---------------------+" << endl;
	cout << "     ���� ������� : ";
	cin >> p2;
	switch (p2)
	{
	case 1:
	{
		system("cls");
		Eq_bet(game, game.Two, bet);
		system("pause");
		system("cls");
		Win_loss(game, game.Two, game.One, 7);
		Swap_bet(game, game.Two, game.One, 7);
		system("pause");
		system("cls");
		Coin_flip(game, stack);


	} break;

	case 2:
	{
		system("cls");
		Up_bet(game, game.Two);
		system("pause");
		system("cls");
		Lt2_p1(game, stack);


	} break;

	case 3:
	{
		system("cls");
		Pas_bet(game, game.One);
		system("pause");
		system("cls");
		Coin_flip(game, stack);
	} break;

	default:
	{
		system("cls");
		Lt2_p2(game, stack);
	}



	}

}