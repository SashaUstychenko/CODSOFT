#pragma once
#pragma once
#include <iostream>
#include <random>

void task1()
{
	int from;
	int to;
	int user_num;
	char again;
	while (true)
	{
		std::cout << "add num from ";
		std::cin >> from;
		std::cout << "to ";
		std::cin >> to;
		system("cls");
		if (from > to)
		{
			std::cout << std::endl << "the second number cannot be less than the first and the first cannot be greater than the second" << std::endl;
		}
		else
		{
			break;
		}
	}
	std::mt19937 gen(static_cast<unsigned>(time(nullptr)));
	std::uniform_int_distribution<int> distribution;
	int rand_num = distribution(gen) % (to + 1 - from) + from;
	std::cout << std::endl << "Guess the number from " << from << " to " << to << std::endl;
	while (true)
	{
		while (true)
		{
			std::cin >> user_num;

			if (user_num<from || user_num>to)
			{
				std::cout << "incorrect number entered, you are out of range, enter in the range you entered" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (user_num == rand_num)
		{
			std::cout << "you guessed the number" << std::endl;

			std::cout << std::endl << "Want to play again: y/n" << std::endl;
			std::cin >> again;
			if (again == 'y' || again == 'Y')
			{
				system("cls");
				task1();
			}
			else
			{
				std::cout << "Thanks for playing" << std::endl;
				break;
			}
		}
		else if (user_num < rand_num)
		{
			std::cout << "your number is less than the specified one" << std::endl;
		}
		else
		{
			std::cout << "your number is greater than the specified one" << std::endl;
		}
	}
}