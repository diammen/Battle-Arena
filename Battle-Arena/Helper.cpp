#pragma once
#include "Character.h"

bool HeroesAlive(Character * Heroes, size_t arrSize)
{
	int counter = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (Heroes[i].health <= 0)
			counter++;
	}

	if (counter != arrSize)
		return true;
	else
		return false;
}

bool EnemiesAlive(Character * Monsters, size_t arrSize)
{
	int counter = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		if (Monsters[i].health <= 0)
			counter++;
	}

	if (counter != arrSize)
		return true;
	else
		return false;
}

int randRange(int low, int high)
{
	return rand() % (high - low) + low;
}

void sortDescending(Character * list, size_t arrSize)
{
	Character temp;

	for (int i = 1; i < arrSize; ++i)
	{
		if (list[i - 1].health < list[i].health)
		{
			temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = temp;
		}
	}
}