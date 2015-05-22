/*
Simple Needle and Haystack

Written By: Stephen Merendino
Date: May 21, 2015

Reads in two strings, a "Needle" and a "Haystack", and counts how many times the needle
appears in the haystack.

Problem Source:
Learning with C++
Alex Alain
Chapter 19, Practice Problem 1 (page 223)

TODO:
-None
*/

#include<string>;
#include<iostream>;

using namespace std;

int main(){
	string needle;
	string haystack;

	cout << "What is your needle? ";
	getline(cin, needle, '\n');

	cout << "What is your haystack? ";
	getline(cin, haystack, '\n');

	int numTimesFound = 0;

	for (int i = haystack.find(needle, 0); i != string::npos; i = haystack.find(needle, i)){
		numTimesFound++;
		i++;
	}

	cout << "Found it " << numTimesFound << " times.";
	cin.get();
}