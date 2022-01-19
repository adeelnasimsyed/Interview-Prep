#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

class Warrior{
private:
	int health;
	int attackStrength;
	int blockStrength;
	string name;

public:

	Warrior(string name, int health, int attackStrength, int blockStrength)
	{
		this->name = name;
		this->health = health;
		this->attackStrength = attackStrength; 
		this->blockStrength = blockStrength;
	}

	/*Warrior()
	{

	}*/

	string getName()
	{
		return this->name;
	}

	int getHealth()
	{
		return this->health;
	}

	int Attack()
	{
		return rand() % this->attackStrength + 1;
	}

	int Block()
	{
		return rand() % this->blockStrength;
	}

	bool isDead()
	{
		if (this->health == 0)
			return true;
		else
			return false;
	}

	void Hit(int damage)
	{
		this->health = this->health - damage;

		if (this->health < 0)
		{
			this->health = 0;
		}
	}


};

class Battle{

public:

	static void getAttackResult(Warrior& player1, Warrior& player2)
	{
		int damage = player1.Attack() - player2.Block();

		if (damage < 0)
			damage = 0;


		cout << player1.getName() << " attacks " << player2.getName() <<
		" and deals " << damage << " damage\n";

		player2.Hit(damage);
		

		cout << player2.getName() << " is down to " << player2.getHealth() <<
		" health\n";

	}

	static void StartFight(Warrior& player1, Warrior& player2)
	{
		Warrior players[2] = {player1, player2};		
	/*	players[0] = player1;
		players[1] = player2;*/
		int attacker = 1, defender = 0;
		int i = 0;

		while(1)
		{
			attacker = !attacker;
			defender = !attacker;

			getAttackResult(players[attacker], players[defender]);

			if (players[defender].isDead())
			{
				cout << players[defender].getName() << " has died and "
					 << players[attacker].getName() << " is victorious\n";
				return;
			}
		}

	}


};


int main()
{
	
	srand(time(NULL));
	Warrior thor("Thor", 100, 30, 15);
	Warrior hulk("Hulk", 135, 30, 10);
	Battle::StartFight(thor, hulk);

	return 0;

}