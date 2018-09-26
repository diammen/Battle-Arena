#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <windows.h>
#include "Character.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std::chrono_literals;
using namespace std::this_thread;

void textcolor(int color)
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Character::printCharacterInfo()
{
	cout << name << endl;
	cout << "Health: " << health << "/" << maxHealth << endl;
	cout << "Attack: " << minDamage << "-" << maxDamage << endl;
}

void Character::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}