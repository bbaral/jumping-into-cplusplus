/*
High Score Vector

Written By: Stephen Merendino
Date: May 21, 2015

A program that uses a vector to implement a high score list
for a game.

Problem Source:
Learning with C++
Alex Alain
Chapter 18, Practice Problem 2 (page 214)

TODO:
-Clean up the output spacing a tad bit.
*/

#include <vector>;
#include <string>;
#include <iostream>;

using namespace std;

void printOptions();

int main(){
	vector<int> scores(10);

	cout << "Simple Vector based high score list.\n\n";

	printOptions();

	char control;
	cout << "What would you like to do? ";
	cin >> control;

	while (control != 'Q'){
		if (control == 'I'){
			int newScore;
			cout << "Enter new score: ";
			cin.ignore();
			cin >> newScore;
			int insertIndex;
			vector<int>::iterator it = scores.begin();
			for (vector<int>::iterator it = scores.begin(); it != scores.end(); ++it){
				if (newScore > *it){
					scores.insert(it, newScore);
					break;
				}
			}
		}
		else if (control == 'P'){
			vector<int>::iterator it = scores.begin();
			while (it != scores.end()){
				cout << *it << "\n";
				it++;
			}
		}

		cout << "What would you like to do now ('O' for options)? ";
		cin >> control;
	}
}

void printOptions(){
	cout << "------\n";
	cout << "Options:\n";
	cout << "'I' to insert a score\n";
	cout << "'P' to print your contacts\n";
	cout << "'Q' to quit\n";
	cout << "------\n";
}