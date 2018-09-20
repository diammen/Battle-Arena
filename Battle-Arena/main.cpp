#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Character.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std::chrono_literals;
using namespace std::this_thread;

Character Hero = { 100, 10, 30, "Hero", "Fimbul Lance" };
Character Heroine = { 100, 10, 30, "Heroine", "Moldrak Thunder" };

int main()
{
	bool gameOver = false;

	while (!gameOver)
	{
		if (Hero.health == 0 & Heroine.health == 0)
		{
			gameOver = true;
		}
	}
}