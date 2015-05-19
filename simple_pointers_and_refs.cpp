/*
Simple Pointers and References program.

Written By: Stephen Merendino
Date: May 12, 2015

Simple program for trying out points and references that reads in a few values and spits them back out.
Decided not to use the std namespace just as an excercise in practice.

Problem Source: 
Learning with C++
Alex Alain
Chapter 13, Practice Problem 1 (page 147)

TODO:
-Add back in the std namespace, its needed badly.
*/

#include <iostream>;
#include <string>;

void initializeWithPointers(std::string *firstName, std::string *lastName);
void initializeWithReferences(std::string &firstname, std::string &lastName);
void printNames(std::string firstName, std::string lastName);

int main()
{
	std::string firstName;
	std::string lastName;

	std::cout << "Names using pointers" << std::endl;
	initializeWithPointers(&firstName, &lastName);
	std::cout << std::endl;
	printNames(firstName, lastName);
	std::cout << std::endl;

	std::cout << "Names using references" << std::endl;
	initializeWithReferences(firstName, lastName);
	std::cout << std::endl;
	printNames(firstName, lastName);
	std::cout << std::endl;

	std::cin.get();
}

void initializeWithPointers(std::string *firstName, std::string *lastName)
{
	std::cout << "Enter the first name: " << std::endl;
	getline(std::cin, *firstName, '\n');

	std::cout << "Enter the last name: " << std::endl;
	getline(std::cin, *lastName, '\n');
}

void initializeWithReferences(std::string &firstName, std::string &lastName)
{
	std::cout << "Enter the first name: " << std::endl;
	getline(std::cin, firstName, '\n');

	std::cout << "Enter the last name: " << std::endl;
	getline(std::cin, lastName, '\n');
}

void printNames(std::string firstName, std::string lastName)
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
}