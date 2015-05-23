/*
Address Book

Written By: Stephen Merendino
Date: May 20, 2015

A simple map implemented using a binary tree that holds an
address book. The map uses the person's name as the key and
their email as the value. User can add email addresses, remove
email addresses, update email addresses, and find email addresses.
Program also cleans up its memory when it shuts down.

Problem Source:
Learning with C++
Alex Alain
Chapter 17, Practice Problem 6 (page 204)

TODO:
-Clean up the output spacing a tad bit.
*/

#ifndef IOSTREAM_INC
#define IOSTREAM_INC
#include <iostream>
#endif
#ifndef STRING_INC
#define STRING_INC
#include <string>
#endif
#include "address_book.h"

void printOptions();

int main(){
	std::cout << "Welcome to my simple C++ Address Book Program.\n\n\n";
	std::cout << "This is a simple command line utility for managing contacts and their emails.\n\n";
	std::cout << "You can add, remove, find, and update your contacts.\n";
	std::cout << "Also, you can print out your entire list of contacts so you can see who you have stored.\n\n";

	printOptions();

	std::cout << "\nWhat would you like to do now? ";
	char control;
	std::cin >> control;

	AddressBook addressBook;

	while (control != 'Q'){
		//let user insert new entry
		if (control == 'I'){
			std::string name;
			std::string email;
			std::cout << "\nEnter a name: ";
			std::cin.ignore();
			getline(std::cin, name, '\n');
			std::cout << "Enter an email: ";
			getline(std::cin, email, '\n');
			addressBook.insert(name, email);
		}
		//let user remove an entry
		else if (control == 'R'){
			std::string name;
			std::cout << "Who would you like to remove? ";
			std::cin.ignore();
			getline(std::cin, name, '\n');
			addressBook.remove(name);
		}
		//let user update an entry
		else if (control == 'U'){
			std::string name;
			std::cout << "Who do you want to update? ";
			std::cin.ignore();
			getline(std::cin, name, '\n');
			bool found = addressBook.find(name);
			if (found){
				std::cout << name << " found!\n";
				std::cout << "What should their email be? ";
				std::string email;
				std::cin >> email;
				addressBook.update(name, email);
			}
		}
		//let user find an entry
		else if (control == 'F'){
			std::string name;
			std::cout << "Who do you want to find? ";
			std::cin.ignore();
			getline(std::cin, name, '\n');
			addressBook.find(name);
		}
		//let user print their entries
		else if (control == 'P'){
			std::cout << "Enter 'A' for ascending or 'D' for descending sorting: ";
			char sortControl;
			std::cin >> sortControl;

			Sort sortDir;
			if (sortControl == 'A'){
				sortDir = Sort::ASC;
			}
			else if (sortControl == 'D'){
				sortDir = Sort::DESC;
			}
			else{
				std::cout << "\nNot a valid sort entry, defaulting to ascending.\n";
				sortDir = Sort::ASC;
			}

			addressBook.print(sortDir);
		}
		//let the user print their options again
		else if (control == 'O'){
			std::cout << '\n';
			printOptions();
		}
		else{
			std::cout << "Sorry, that is not a valid option. Please try again.";
		}

		int contactCount = addressBook.size();
		if (contactCount == 0){
			std::cout << "You have no contacts.\n";
		}
		else if (contactCount == 1){
			std::cout << "You have 1 contact.\n";
		}
		else{
			std::cout << "You have " << contactCount << " contacts.\n";
		}

		std::cout << "\nWhat would you like to do now ('O' for options)? ";
		std::cin >> control;
	}
}

void printOptions(){
	std::cout << "------\n";
	std::cout << "Options:\n";
	std::cout << "'I' to insert a contact\n";
	std::cout << "'R' to remove a contact\n";
	std::cout << "'U' to update a contact\n";
	std::cout << "'F' to find a contact\n";
	std::cout << "'P' to print your contacts\n";
	std::cout << "'O' to see available options\n";
	std::cout << "'Q' to quit\n";
	std::cout << "------\n";
}