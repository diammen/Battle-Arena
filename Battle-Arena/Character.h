#pragma once
#include <string>
using std::string;

class Character
{
private:


public:
	int health;
	int maxHealth;
	int minDamage;
	int maxDamage;
	string name;
	string attackName;
	bool isAlive = true;
	
	// print character's info to the console
	void printCharacterInfo();
	void takeDamage(int damage);


};

void textcolor(int color);

