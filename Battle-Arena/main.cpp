#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Character.h"
#include "Helper.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std::chrono_literals;
using namespace std::this_thread;



int main()
{
	srand(time(NULL));

	int randomNum = 0;
	int randomDamage = 0;
	int roundCounter = 0;

	Character Heroes[] = { 
		{ 200, 200, 15, 35, "Hero", "Fimbul Lance"},
		{ 150, 150, 10, 40, "Heroine", "Heaven's Will"}
	};
	int heroTarget = 0;
	int heroGroupSize = 2;
	int deadHeroes = 0;

	Character Monsters[] = {
		{ 125, 125, 10, 30, "Orc Marauder", "Good ol' Axe" },
		{ 150, 150, 15, 25, "Demon", "Unholy Vice" },
		{ 75, 75, 10, 20, "Skeleton Knight", "Big Bone" }
	};
	int monsterTarget = 0;
	int monsterGroupSize = 3;
	int deadMonsters = 0;

	// if anyone is still alive
	while (HeroesAlive(Heroes, heroGroupSize) && EnemiesAlive(Monsters, monsterGroupSize))
	{
		roundCounter++;
		cout << "Round " << roundCounter << endl;
		cout << "-------" << endl;
		sleep_for(1s);
		// if heroes are still alive
		if (HeroesAlive(Heroes, heroGroupSize))
		{
			// each hero attacks a random target
			for (int i = 0; i < heroGroupSize; ++i)
			{
				// if hero is alive and there are monsters remaining, attack; otherwise go to next alive unit or don't attack
				if (EnemiesAlive(Monsters, monsterGroupSize && Heroes[i].isAlive))
				{
					randomNum = rand() % 2;
					randomDamage = randRange(Heroes[i].minDamage, Heroes[i].maxDamage);
					cout << Heroes[i].name << " uses " << Heroes[i].attackName << " for " << randomDamage << " damage" << endl;

					// if target monster is already dead, choose another target
					while (Monsters[randomNum].health == 0)
					{
						randomNum = rand() & 2;
						deadMonsters++;
						if (deadMonsters == 3) break;
					}
					Monsters[randomNum].takeDamage(randomDamage);
					// if target dies
					if (Monsters[randomNum].health == 0)
					{
						cout << Monsters[randomNum].name << " perishes" << endl;
						Monsters[randomNum].isAlive = false;
					}
					else
					{
						cout << Monsters[randomNum].name << " is left with " << Monsters[randomNum].health << " health" << endl;
					}
					// if every monster has perished after a hero attacks, exit the game loop
					if (deadMonsters == 3)
						break;
					else
						deadMonsters = 0;
				}
			}
		}
		// if monsters are still alive
		if (EnemiesAlive(Monsters, monsterGroupSize))
		{
			// each monster attacks a random target
			for (int i = 0; i < monsterGroupSize; ++i)
			{
				// if monster is alive, attack; otherwise go to next alive unit
				if (Monsters[i].isAlive && HeroesAlive(Heroes, heroGroupSize))
				{
					randomNum = rand() % 2;
					randomDamage = randRange(Monsters[i].minDamage, Monsters[i].maxDamage);
					cout << Monsters[i].name << " uses " << Monsters[i].attackName << " for " << randomDamage << " damage" << endl;

					while (Heroes[randomNum].health == 0)
					{
						randomNum = rand() % 2;
						deadHeroes++;
						if (deadHeroes == 2) break;
					}
					Heroes[randomNum].takeDamage(randomDamage);
					if (Heroes[randomNum].health == 0)
					{
						cout << Heroes[randomNum].name << " perishes" << endl;
						Heroes[randomNum].isAlive = false;
					}
					else
					{
						cout << Heroes[randomNum].name << " is left with " << Heroes[randomNum].health << " health" << endl;
					}
					// if every hero has perished after a monster attacks, exit the game loop
					if (deadHeroes == 2)
						break;
					else
						deadHeroes = 0;
				}
			}
		}
		sortDescending(Heroes, heroGroupSize);
		sortDescending(Monsters, monsterGroupSize);
		sleep_for(1s);

		// Explain current situation after round ends
		cout << endl;
		cout << "Round " << roundCounter << " is over." << endl;
		sleep_for(1s);
		cout << "Here are the current teams: " << endl;
		cout << endl;
		sleep_for(1s);

		cout << "Heroes" << endl;
		cout << "------" << endl;
		for (int i = 0; i < heroGroupSize; ++i)
		{
			Heroes[i].printCharacterInfo();
			cout << endl;
		}

		cout << "Monsters" << endl;
		cout << "--------" << endl;
		for (int i = 0; i < monsterGroupSize; ++i)
		{
			Monsters[i].printCharacterInfo();
			cout << endl;
		}
		sleep_for(3s);
		if (HeroesAlive(Heroes, heroGroupSize) && EnemiesAlive(Monsters, monsterGroupSize))
		{
			cout << "Beginning next round..." << endl;
			sleep_for(1s);
			ClearScreen();
		}
	}
	// if heroes are not alive, heroes lose
	if (!HeroesAlive(Heroes, heroGroupSize))
	{
		cout << "Monsters win!";
		sleep_for(1s);
	}
	else if (!EnemiesAlive(Monsters, monsterGroupSize))
	{
		cout << "Heroes win!" << endl;
		sleep_for(1s);
	}
}