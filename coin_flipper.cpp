/*
Coin Flipper

Written By: Stephen Merendino
Date: May 6, 2015

Simple program that lets a user flip a coin as many
times as they want and see the results.

Problem Source: 
Learning with C++
Alex Alain
Chapter 8, Practice Problem 1 (page 104)

TODO:
-None
*/

#include <iostream>;
#include <cstdlib>;
#include <ctime>;
#include <string>;

using namespace std;

int main()
{
	srand(time(NULL));

	int numCoinFlips;
	int numHeads = 0;
	int numTails = 0;

	cout << "How many coin flips do you want to do?" << endl;
	cin >> numCoinFlips;

	for (int i = 0; i < numCoinFlips; i++)
	{
		if (rand() % 2 == 0)
		{
			cout << "Heads!";
			numHeads++;
		}
		else
		{
			cout << "\tTails!";
			numTails++;
		}

		cout << endl;
	}

	cout << endl << " --- Final Tally! ---" << endl;

	cout << "Number of Heads: " << numHeads << endl;
	cout << "Number of Tails: " << numTails << endl;

	if (numHeads == numTails)
	{
		cout << "Whoa! You rolled the same amount!" << endl;
	}
	else if (numHeads > numTails)
	{
		cout << "Heads wins!" << endl;
	}
	else if (numHeads < numTails)
	{
		cout << "Tails wins!" << endl;
	}

	cin.ignore();
	cin.get();
}