#pragma once
#include <string>
using std::string;

class Character
{
private:


public:
	int health;
	int minDamage;
	int maxDamage;
	string name;
	string attackName;
	
	// print character's info to the console
	void printCharacterInfo();


};

void textcolor(int color);

