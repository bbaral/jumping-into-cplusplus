/*
Towers of Hanoi

Written By: Stephen Merendino
Date: May 18, 2015

Recursive solution to the famous Towers of Hanoi problem. I used basic
structs and arrays to get this done.

Problem Source: 
Learning with C++
Alex Alain
Chapter 16, Practice Problem 5 (page 185)

TODO:
-Use vectors instead of arrays.
-Print out the towers after each move.
-Add a graphical screen that shows the user each move and lets them step through each move
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Disk
{
	int size;
};

struct Tower
{
	int num;
	stack<Disk> disks;
};

void move(int numDisks, Tower &toTower, Tower &fromTower, Tower &spareTower);
void printTowers(Tower *p_towers);

//Towers of Hanoi always uses 3 towers.
const int numTowers = 3;

int main()
{
	//Get input from user for how many disks to simulate
	cout << "How many disks do you want to simulate? ";
	int numDisks;
	cin >> numDisks;

	//Init towers
	Tower *p_towers = new Tower[numTowers];
	for (int i = 0; i < numTowers; i++)
	{
		Tower tower;
		tower.num = i + 1;
		p_towers[i] = tower;
	}

	//Init disks
	Disk *p_disks = new Disk[numDisks];
	for (int i = 0; i < numDisks; i++)
	{
		Disk disk;
		disk.size = i + 1;
		p_disks[i] = disk;
	}

	//Add disks in order of biggest to smallest onto the first tower
	for (int i = numDisks - 1; i >= 0; i--)
	{
		p_towers[0].disks.push(p_disks[i]);
	}

	move(numDisks, p_towers[0], p_towers[2], p_towers[1]);
	printTowers(p_towers);

	cin.ignore();
	cin.get();
}

void move(int numDisks, Tower &fromTower, Tower &toTower, Tower &spareTower)
{
	//moving one disk is trivial, this is our base case
	if (numDisks == 1)
	{
		Disk disk = fromTower.disks.top();
		cout << "Moving Disk " << disk.size << " from Tower " << fromTower.num << " to Tower " << toTower.num << endl;
		fromTower.disks.pop();
		toTower.disks.push(disk);
	}
	else
	{
		//move all of the disks on top of the disk to the spare
		move(numDisks - 1, fromTower, spareTower, toTower);

		//move the single disk left (base case)
		move(1, fromTower, toTower, spareTower);

		//move all of the disks from the spare back onto the bottom disk
		move(numDisks - 1, spareTower, toTower, fromTower);
	}
}

void printTowers(Tower *p_towers)
{
	cout << "---------------------------" << endl;
	int maxDisksOnOneTower = 0;

	for (int i = 0; i < numTowers; i++)
	{
		int curNumDisks = p_towers[i].disks.size();
		if (curNumDisks > maxDisksOnOneTower)
		{
			maxDisksOnOneTower = curNumDisks;
		}
	}

	for (int i = maxDisksOnOneTower; i > 0; i--)
	{
		for (int j = 0; j < numTowers; j++)
		{
			if (p_towers[j].disks.size() >= i)
			{
				Disk disk = p_towers[j].disks.top();
				cout << "|" << disk.size << "|\t";
				p_towers[j].disks.pop();
			}
			else
			{
				cout << "| |\t";
			}
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}