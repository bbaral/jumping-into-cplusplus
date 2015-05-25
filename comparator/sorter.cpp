/*
Comparator Interface

Written By: Stephen Merendino
Date: May 25, 2015

Provide another implementation of your sort function, 
this time taking an interface called Comparator, 
which has a method compare(const string& lhs, const string& rhs) 
that follows similar rules to the previous compare method: 
return 0 if the two values are the same, 1 if lhs > rhs or -1 
if lhs < rhs. 

Write two different classes to do comparison: one that does 
a case-insensitive comparison and one that sorts in reverse alphabetical order.

Problem Source:
Learning with C++
Alex Alain
Chapter 26, Practice Problem 2 (page 302)

TODO:
-None
*/

#ifndef COMPARATOR_H
#define COMPARATOR_H
#include "comparator.h"
#endif
#ifndef REVERSE_ALPHABETICAL_H
#define REVERSE_ALPHABETICAL_H
#include "reverse_alphabetical.h"
#endif
#ifndef CASE_INSENSITIVE_H
#define CASE_INSENSITIVE_H
#include "case_insensitive.h"
#endif
#include <string>
#include <vector>
#include <iostream>

void sort(std::vector<std::string> &collection, Comparator &comparator);
void print(std::vector<std::string> &collection);

int main(){
	std::vector<std::string> collection = { "Stephen", "Sarah", "Wat", "testing", "WAT", "Duke", "wat" };
	std::cout << "Unsorted:\n";
	print(collection);
	std::cout << std::endl;

	sort(collection, ReverseAlphabetical());
	std::cout << "Reverse Alphabetical:\n";
	print(collection);
	std::cout << std::endl;

	collection = { "Stephen", "Sarah", "Wat", "testing", "WAT", "Duke", "wat" };
	sort(collection, CaseInsensitive());
	std::cout << "Case Insensitive:\n";
	print(collection);

	std::cin.get();
}

void sort(std::vector<std::string> &collection, Comparator &comparator){
	for (size_t i = 0, end = collection.size(); i < end; i++){
		int smallest = i;
		for (size_t j = i; j < end; j++){
			if (comparator.compare(collection[j], collection[smallest]) == -1){
				smallest = j;
			}
		}
		if (smallest != i){
			std::string temp = collection[i];
			collection[i] = collection[smallest];
			collection[smallest] = temp;
		}
	}
}

void print(std::vector<std::string> &collection){
	for (std::vector<std::string>::iterator outerIt = collection.begin(), end = collection.end();
		outerIt != end;
		outerIt++){
		std::cout << *outerIt << std::endl;
	}
}