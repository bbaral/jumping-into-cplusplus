/*
High Score Binary File

Written By: Stephen Merendino
Date: May 25, 2015

A high score proram that inserts scores into the
correct file position using a binary file format. User can
print the file back out to the console to check its contents.

Problem Source:
Learning with C++
Alex Alain
Chapter 28, Practice Problem 1 (page 326)

TODO:
-None
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void printOptions();

int main(){
	const std::string filename = "highscores.bin";

	std::fstream f(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

	if (!f.is_open()){
		std::cout << "File Error. Check disk.\n";
		std::cin.get();
		return 0;
	}

	printOptions();
	std::cout << "What would you like to do now? ";
	char control;
	std::cin >> control;

	while (control != 'Q'){

		if (control == 'I'){
			int newScore;
			std::cout << "Enter new score: ";
			std::cin.ignore();
			std::cin >> newScore;

			//loop through what is in file so far
			//find the value that is lower than what was read in
			//insert the new value before that
			//rewrite the rest of values back out

			f.seekg(0, std::ios::beg); //set get back to start of file

			std::vector<int> scores; //to store the scores we are shifting
			std::streampos insertPos = f.tellg(); //will be the insert position for the new score
			int curScore;

			while (f.read(reinterpret_cast<char*>(&curScore), sizeof(curScore))){
				if (curScore < newScore){
					break;
				}
				insertPos = f.tellg();
			}

			if (f.fail() && !f.eof()){
				std::cout << "Something is wrong with the file.";
				std::cin.get();
			}

			f.clear();

			//return to pos where we are going to insert
			f.seekg(insertPos);
			//save the scores in the vector for later use
			while (f.read(reinterpret_cast<char*>(&curScore), sizeof(curScore))){
				scores.push_back(curScore);
			}

			f.clear();

			f.seekp(insertPos);
			f.write(reinterpret_cast<char*>(&newScore), sizeof(newScore));
			for (std::vector<int>::iterator itr = scores.begin(), end = scores.end(); itr != end; itr++){
				int score = *itr;
				f.write(reinterpret_cast<char*>(&score), sizeof(score));
			}

			f.clear();
		}
		else if (control == 'P'){
			std::cout << "\nScores:\n";
			f.seekg(0, std::ios::beg);
			int inScore;
			while (f.read(reinterpret_cast<char*>(&inScore), sizeof(inScore))){
				std::cout << inScore << std::endl;
			}
			if (!f.eof()){
				std::cout << "Error occured reading from file.\n";
				std::cin.get();
				return 0;
			}
			f.clear();
			std::cout << std::endl;
		}

		printOptions();
		std::cin >> control;
	}

	f.close();
}

void printOptions(){
	std::cout << "------\n";
	std::cout << "Options:\n";
	std::cout << "'I' to insert a high score\n";
	std::cout << "'P' to print your high scores\n";
	std::cout << "'O' to see available options\n";
	std::cout << "'Q' to quit\n";
	std::cout << "------\n";
}