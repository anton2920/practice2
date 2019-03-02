#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

void game();
void computerVsPlayer();
void getUserInput(int* player_coins, char* coins);
void playerVsPlayer();

void game()
{
	srand(time(nullptr));
	std::cout
		<< "Hello! Welcome to my simple game.\n"
		<< "The rules of the game:\n"
		<< "In a row, there are 25 coins.\nFor a turn,"
		<< " it is allowed to takes one or two adjacent coins.\n"
		<< "The one, who has nothing to takes, loses.\n\n\n";

	int user_choice;
	do
	{
		std::cout << "Select mode of the game:\n"
			<< "1 - Computer Vs Player\n"
			<< "2 - Player1 vs Player2\n";
		std::cin >> user_choice;
	} while (user_choice != 1 && user_choice != 2);

	std::cout << "\n\n";
	if (user_choice == 1)
		computerVsPlayer();
	else
		playerVsPlayer();
}

void getUserInput(int* player_coins, char* coins)
{
	bool adjacent_coins(false);
	for (int i = 1; i < 25; ++i)
		if (coins[i] == '*' && coins[i - 1] == '*')
		{
			adjacent_coins = true;
			break;
		}
	do
	{
		if (adjacent_coins)
		{
			std::cout << "Enter the amount of coins you want to takes(1 or 2): ";
			std::cin >> player_coins[0];

			if (std::cin.fail())
			{
				std::cout << "Invalid input!\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else if (player_coins[0] < 1 || player_coins[0] > 2)
				std::cout << "You can only takes one or two coins.\n";
		}
		else
		{
			std::cout << "No adjacent coins in a row.\n"
				<< "Enter number of coin: ";
			std::cin >> player_coins[1];
			player_coins[0] = 0;
			if (std::cin.fail())
			{
				std::cout << "Invalid input!\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else if (player_coins[1] < 1 || player_coins[1] > 25 || coins[player_coins[1] - 1] == ' ')
				std::cout << "Wrong input.\n";
			else
			{
				player_coins[0] = 1;
			}
		}

	} while (player_coins[0] != 1 && player_coins[0] != 2);

	if (adjacent_coins)
	{

		if (player_coins[0] % 2 == 0)
		{
			bool correct(false);
			do
			{
				std::cout << "Enter number of 2 adjacent coins: ";
				std::cin >> player_coins[1] >> player_coins[2];
				if (player_coins[1] <= 25 && player_coins[1] >= 1 &&
					player_coins[2] <= 25 && player_coins[2] >= 1 &&
					player_coins[1] != player_coins[2] &&
					coins[player_coins[1] - 1] == '*' && coins[player_coins[2] - 1] == '*' &&
					std::abs(player_coins[1] - player_coins[2]) == 1)
				{
					correct = true;
				}
			} while (!correct);
		}
		else
		{
			bool correct(false);
			do
			{
				std::cout << "Enter number of coin: ";
				std::cin >> player_coins[1];
				if (player_coins[1] <= 25 && player_coins[1] >= 1 && coins[player_coins[1] - 1] == '*')
					correct = true;
			} while (!correct);
		}
	}
}

void drawCoins(char* coins)
{
	std::cout << '\n';
	int count = 1;
	for (int i = 1; i <= 25; ++i)
	{
		if (count < 10)
			std::cout << "  " << count;
		else
			std::cout << ' ' << count;
		count++;
	}
	std::cout << '\n';
	for (int i = 0; i < 75; ++i)
		std::cout << '-';
	std::cout << '\n';
	for (int i = 0; i < 25; ++i)
		std::cout << "  " << coins[i];
	std::cout << "\n\n";

}

void computerVsPlayer()
{
	int step(0);
	int amount_of_coins(25);

	// Toss a coin to decide who goes first.
	// 0 - computer, 1 - player.
	int roll = rand() % 2;

	// [0] - amount of coins; [1], [2] - position in a row.
	int player_coins[3] = { -1,-1,-1 };

	char coins[25];
	for (auto& c : coins)
		c = '*';

	if (roll == 0)
	{
		std::cout << "Computer goes first!\n";
		while (amount_of_coins)
		{
			std::cout << "Step #" << ++step << ": \n";
			if (amount_of_coins == 25)
			{
				std::cout << "Computer takes coin #13\n";
				std::cout << "Coins left: " << --amount_of_coins << '\n';
				coins[12] = ' ';
			}
			else
			{
				if (player_coins[0] % 2)
				{
					// 1 coin:
					std::cout << "Computer takes coin # " << 26 - player_coins[1] << '\n';
					std::cout << "Coins left: " << --amount_of_coins << '\n';
					coins[26 - player_coins[1] - 1] = ' ';
				}
				else
				{
					// 2 coins:
					std::cout << "Computer takes coins #" << 26 - player_coins[1]
						<< " and #" << 26 - player_coins[2] << "\n";
					amount_of_coins -= 2;
					std::cout << "Coins left: " << amount_of_coins << '\n';
					coins[26 - player_coins[1] - 1] = ' ';
					coins[26 - player_coins[2] - 1] = ' ';
				}
			}

			if (amount_of_coins == 0)
			{
				std::cout << "Computer Won!\n";
				return;
			}
			drawCoins(coins);

			getUserInput(player_coins, coins);

			if (player_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player takes coin #" << player_coins[1] << "\n";
				coins[player_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player takes coins #" << player_coins[1]
					<< " and #" << player_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player_coins[1] - 1] = ' ';
				coins[player_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player Won!\n";
				return;
			}
		}

	}
	else
	{
		std::cout << "Player goes first!\n";
		while (amount_of_coins > 0)
		{
			std::cout << "Step #" << ++step << ": \n";
			getUserInput(player_coins, coins);
			if (player_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player takes coin #" << player_coins[1] << "\n";
				coins[player_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player takes coins #" << player_coins[1]
					<< " and #" << player_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player_coins[1] - 1] = ' ';
				coins[player_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player Won!\n";
				return;
			}

			// [0] - amount of coins; [1],[2] - number of coins.
			int computer_coins[3] = { -1,-1,1 };

			for (int i = 0; i < 24; ++i)
			{
				if (coins[i] == '*' && coins[i + 1] == '*')
				{
					computer_coins[0] = 2;
					computer_coins[1] = i + 1;
					computer_coins[2] = i + 2;
					break;
				}
				else if (coins[i] == '*')
				{
					computer_coins[0] = 1;
					computer_coins[1] = i + 1;
				}

			}

			if (computer_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Computer takes coin #" << computer_coins[1] << "\n";
				std::cout << "Coins left: " << --amount_of_coins << '\n';
				coins[computer_coins[1] - 1] = ' ';
			}
			else
			{
				// 2 coins:
				std::cout << "Computer takes coins #" << computer_coins[1]
					<< " and #" << computer_coins[2] << " \n";
				amount_of_coins -= 2;
				std::cout << "Coins left: " << amount_of_coins << '\n';
				coins[computer_coins[1] - 1] = ' ';
				coins[computer_coins[2] - 1] = ' ';
			}

			drawCoins(coins);
			if (amount_of_coins == 0)
			{
				std::cout << "Computer Won!\n";
				return;
			}
		}
	}

}

void playerVsPlayer()
{
	int step(0);
	int amount_of_coins(25);

	// Toss a coin to decide who goes first.
	// 0 - computer, 1 - player.
	int roll = rand() % 2;

	// [0] - amount of coins; [1], [2] - position in a row.
	int player1_coins[3] = { -1,-1,-1 };
	int player2_coins[3] = { -1,-1,-1 };

	char coins[25];
	for (auto& c : coins)
		c = '*';

	if (roll == 0)
	{
		std::cout << "Player1 goes first.\n";
		while (amount_of_coins > 0)
		{
			std::cout << "Step #" << ++step << ": \n";
			std::cout << "Player1 turn!\n";
			getUserInput(player1_coins, coins);
			if (player1_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player1 takes coin #" << player1_coins[1] << "\n";
				coins[player1_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player1 takes coins #" << player1_coins[1]
					<< " and #" << player1_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player1_coins[1] - 1] = ' ';
				coins[player1_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player1 Won!\n";
				return;
			}

			std::cout << "Player2 turn!\n";
			getUserInput(player2_coins, coins);
			if (player2_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player2 takes coin #" << player2_coins[1] << "\n";
				coins[player2_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player2 takes coins #" << player2_coins[1]
					<< " and #" << player2_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player2_coins[1] - 1] = ' ';
				coins[player2_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player2 Won!\n";
				return;
			}


		}
	}
	else
	{
		std::cout << "Player2 goes first.\n";
		while (amount_of_coins > 0)
		{
			std::cout << "Step #" << ++step << ": \n";

			std::cout << "Player2 turn!\n";

			getUserInput(player2_coins, coins);
			if (player2_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player2 takes coin #" << player2_coins[1] << "\n";
				coins[player2_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player2 takes coins #" << player2_coins[1]
					<< " and #" << player2_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player2_coins[1] - 1] = ' ';
				coins[player2_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player2 Won!\n";
				return;
			}


			std::cout << "Player1 turn!\n";
			getUserInput(player1_coins, coins);
			if (player1_coins[0] % 2)
			{
				// 1 coin:
				std::cout << "Player1 takes coin #" << player1_coins[1] << "\n";
				coins[player1_coins[1] - 1] = ' ';
				std::cout << "Coins left: " << --amount_of_coins << '\n';
			}
			else
			{
				// 2 coins:
				std::cout << "Player1 takes coins #" << player1_coins[1]
					<< " and #" << player1_coins[2] << "\n";
				amount_of_coins -= 2;
				coins[player1_coins[1] - 1] = ' ';
				coins[player1_coins[2] - 1] = ' ';
				std::cout << "Coins left: " << amount_of_coins << '\n';
			}

			drawCoins(coins);

			if (amount_of_coins == 0)
			{
				std::cout << "Player1 Won!\n";
				return;
			}


		}
	}
}


int main()
{
	game();

	////At the request of Anton.
	//system("pause");
	return 0;
}
