#pragma once
#include <iostream>

void task2()
{
	int a;
	int b;
	char operation;
	char again;

	std::cout << "calc" << std::endl;
	std::cout << "enter the first number " << std::endl;
	std::cin >> a;
	std::cout << "enter the second number " << std::endl;
	std::cin >> b;
	std::cout << "enter the operatio \n + \n - \n * \n /" << std::endl;

	while (true)
	{
		std::cin >> operation;
		if (std::isdigit(operation)) {
			std::cout << "You entered a digit" << std::endl;
		}
		else
		{
			break;
		}
	}
	switch (operation)
	{
	case '+':
		std::cout << "you have decided to add" << std::endl;
		std::cout << "execution result : " << a + b << std::endl;
		break;
	case '-':
		std::cout << "you have decided to subtract" << std::endl;
		std::cout << "execution result : " << a - b << std::endl;
		break;
	case '*':
		std::cout << "you have decided to add multiply" << std::endl;
		std::cout << "execution result : " << a * b << std::endl;
		break;
	case '/':
		std::cout << "you have decided to division" << std::endl;
		std::cout << "execution result : " << a / b << std::endl;
		break;
	default:
		std::cout << "incorrectly selected character for an arithmetic operation" << std::endl;
		break;
	}
	std::cout << std::endl << "Want to use the calculator again: y/n" << std::endl;
	std::cin >> again;
	if (again == 'y' || again == 'Y')
	{
		system("cls");
		task2();
	}
	else
	{
		std::cout << "Thanks" << std::endl;
	}

}