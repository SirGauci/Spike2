// GridWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Grid.h"
#include "Player.h"

int main()
{
	Grid* grid = new Grid();
	Player* p = new Player(*grid);
	char command;
	// Game loop
	do
	{
		std::cout << "Enter directon: ";
		std::cin >> command;
		command = tolower(command);
		if (command == 'e' || command == 's' || command == 'w' || command == 'n')
		{
			p->Move(command);
		}
		else if (command == 'q')
		{
			std::cout << "Goodbye!";
		}
		else
		{
			std::cout << "Invalid command\n";
		}
	} while ((p->GetCell() != 'D' && p->GetCell() != 'G') && command != 'q');
	// End game
	if (p->GetCell() == 'D')
	{
		std::cout << "Arrrrgh.... you've fallen down a pit.\nYOU HAVE DIED!\nThanks for playing. Maybe next time.";
	}
	else if (command != 'q')
	{
		std::cout << "Wow... you've discovered a large chest filled with GOLD coins\nYOU WIN!\nThanks for playing. There probably won't be a next time.";
	}
	std::cin >> command;
	return 0;
}

