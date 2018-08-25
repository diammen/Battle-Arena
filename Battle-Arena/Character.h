#pragma once
#include <string>
using std::string;

class Character
{
public:

	int health;
	int minDamage;
	int maxDamage;
	string name;
	string attackName;

};

void textcolor(int color);