#pragma once
#include "Character.h"

bool HeroesAlive(Character * Heroes, size_t arrSize);

bool EnemiesAlive(Character * Monsters, size_t arrSize);

int randRange(int low, int high);

void sortDescending(Character * list, size_t arrSize);

void ClearScreen();