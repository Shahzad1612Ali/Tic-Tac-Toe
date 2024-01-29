#include<iostream>
#include<cstring>
using namespace std;

void main_Menu();
void initialize_Board();
void display_Board();
void game_Instructions();
void start_Game();
void player_1();
void player_2();
void check_Winner();
char game_Board[3][3];
char p1, p2;
int i, j;
void main()
{
	main_Menu();
	start_Game();
	system("pause");
}
void main_Menu() 
{
	int choice;
	cout << "Press 1 to Start the Game\n";
	cout << "Press 2 to See the Game Instructions\n";
	cout << "Press 3 to Exit the Game\n\n";
	cout << "---------------------------------\n\n";
	cout << "Enter Your Choice : ";
	cin >> choice;
	while (choice != 3)
	{
		if (choice == 1)
		{
			start_Game();
		}
		else if (choice == 2)
		{
			game_Instructions();
		}
	}
	exit(0);
}

void game_Instructions()
{
	cout << "This is a two Players Game.Both the Players\n";
	cout << "choose their one different character.They\n";
	cout << "choose position at game board at their turn.\n";
	cout << "They make a line of their own character which\n";
	cout << "may be straigt or diagonal.The player which\n";
	cout << "complete his line first, win the game \n\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n\n";
	main_Menu();

}

void initialize_Board()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game_Board[i][j] = '*';
		}
	}
	display_Board();
}
void display_Board()
{
	cout << "\n--------------------------\n";
	cout << "\tGAME BOARD";
	cout << "\n--------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<game_Board[i][j]<<"\t";
		}
		cout << endl;
	}
}

void start_Game() 
{
	cout << "-----------------------------------------\n";
	cout << "----Choose Your Specific Characters------\n";
	cout << "-----------------------------------------\n\n";
	cout << "Player 1 Choose his Character : ";
	cin >> p1;
	cout << "Player 2 Choose his Character : ";
	cin >> p2;
	initialize_Board();
	for (int i = 0; i < 4; i++)
	{
		player_1();
		player_2();
	}
	player_1();

}
void player_1()
{
	cout << "PLAYER 1 TURN \n";
	cout << "First Enter Index Value at which You Want to Place Your Character\n";
	cout << "Enter Row Subscript : ";
	cin >> i;
	cout << "Enter Column Subscript : ";
	cin >> j;
	game_Board[i][j] = p1;
	display_Board();
	check_Winner();
}

void player_2()
{
	cout << "PLAYER 2 TURN \n";
	cout << "First Enter Index Value at which You Want to Place Your Character\n";
	cout << "Enter Row Subscript : ";
	cin >> i;
	cout << "Enter Column Subscript : ";
	cin >> j;
	game_Board[i][j] = p2;
	display_Board();
	check_Winner();
}
void check_Winner()
{
	for (int i = 0; i < 3; i++)
	{
		//Loop 4 Checking Rows

		for (int j = 0; i < 3; i++)
		{
			if (game_Board[i][j] == game_Board[i][j + 1])
			{
				if (game_Board[i][j] == game_Board[i][j + 2])
				{
					if (game_Board[i][j] == p1)
					{
						cout << " GREAT! PLAYER 1 IS WINNER \n";
						cout << "GAME OVER";
						main_Menu();
					}
					else if (game_Board[i][j] == p2)
					{
						cout << " GREAT! PLAYER 2 IS WINNER \n";
						cout << "GAME OVER";
						main_Menu();
					}
				}
			}
		}
	}
	for (int j = 0; j < 3; j++)
	{
		//Loop 4 Checking Columns 4 Player 1
		for (int i = 0; i < 3; i++)
		{
			if (game_Board[i][j] == game_Board[i + 1][j])
			{
				if (game_Board[i][j] == game_Board[i + 2][j])
				{
					if (game_Board[i][j] == p1)
					{
						cout << " GREAT! PLAYER 1 IS WINNER \n";
						cout << "GAME OVER";
						main_Menu();
					}
					else if (game_Board[i][j] == p2)
					{
						cout << " GREAT! PLAYER 2 IS WINNER \n";
						cout << "GAME OVER";
						main_Menu();
					}
				}
			}
		}
	}

	//CHECKING DIAGONAL LIKE IN MATRIX Player 1
	if (game_Board[0][0] == game_Board[1][1])
	{
		if (game_Board[0][0] == game_Board[2][2])
		{
			if (game_Board[0][0] == p1)
			{
				cout << " GREAT! PLAYER 1 IS WINNER \n";
				cout << "GAME OVER";
				main_Menu();
			}
			else if (game_Board[0][0] == p2)
			{
				cout << " GREAT! PLAYER 2 IS WINNER \n";
				cout << "GAME OVER";
				main_Menu();
			}
		}
	}

	//CHECKING IN OTHER DIAGONAL 4 Player 1
	if (game_Board[0][2] == game_Board[1][1])
	{
		if (game_Board[1][1] == game_Board[2][0])
		{
			if (game_Board[1][1] == p1)
			{
				cout << " GREAT! PLAYER 1 IS WINNER \n";
				cout << "GAME OVER";
				main_Menu();
			}
			else if (game_Board[1][1] == p2)
			{
				cout << " GREAT! PLAYER 1 IS WINNER \n";
				cout << "GAME OVER";
				main_Menu();
			}
		}
	}
}