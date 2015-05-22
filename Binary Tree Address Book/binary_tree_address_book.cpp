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

#include <iostream>
#include "node.h"

using namespace std;

void printOptions();

int main(){
	cout << "Welcome to my simple C++ Address Book Program.\n\n\n";
	cout << "This is a simple command line utility for managing contacts and their emails.\n\n";
	cout << "You can add, remove, find, and update your contacts.\n";
	cout << "Also, you can print out your entire list of contacts so you can see who you have stored.\n\n";

	printOptions();

	cout << "\nWhat would you like to do now? ";
	char control;
	cin >> control;

	Node *p_tree = NULL;

	while (control != 'Q'){
		//let user insert new entry
		if (control == 'I'){
			string name;
			string email;
			cout << "\nEnter a name: ";
			cin.ignore();
			getline(cin, name, '\n');
			cout << "Enter an email: ";
			getline(cin, email, '\n');
			p_tree = insert(p_tree, name, email);
			cout << name << " inserted into address book.\n\n";
		}
		//let user remove an entry
		else if (control == 'R'){
			string name;
			cout << "Who would you like to remove? ";
			cin.ignore();
			getline(cin, name, '\n');
			p_tree = remove(p_tree, name);
		}
		//let user update an entry
		else if (control == 'U'){
			string name;
			cout << "Who do you want to update? ";
			cin.ignore();
			getline(cin, name, '\n');
			Node *p_node = find(p_tree, name);
			if (p_node != NULL){
				cout << name << " found!\n";
				cout << "Who do you want to set their email to? ";
				string email;
				cin >> email;
				p_node->email = email;
				cout << name << " updated!\n";
				printNode(p_node);
			}
		}
		//let user find an entry
		else if (control == 'F'){
			string name;
			cout << "Who do you want to find? ";
			cin.ignore();
			getline(cin, name, '\n');
			Node *p_node = find(p_tree, name);
			if (p_node != NULL){
				cout << name << " found!\n";
				cout << "Here are their details:\n";
				printNode(p_node);
			}
		}
		//let user print their entries
		else if (control == 'P'){
			if (p_tree == NULL){
				cout << "There are no entries. Try adding one by using the 'I' option.\n";
			}
			else{
				cout << "Enter 'A' for ascending or 'D' for descending sorting: ";
				char sortControl;
				cin >> sortControl;

				Sort sortDir;
				if (sortControl == 'A'){
					sortDir = Sort::ASC;
				}
				else if (sortControl == 'D'){
					sortDir = Sort::DESC;
				}
				else{
					cout << "\nNot a valid sort entry, defaulting to ascending.\n";
					sortDir = Sort::ASC;
				}

				printTree(p_tree, sortDir);
			}
		}
		//let the user print their options again
		else if (control == 'O'){
			cout << '\n';
			printOptions();
		}
		else{
			cout << "Sorry, that is not a valid option. Please try again.";
		}

		int contactCount = count(p_tree);
		if (contactCount == 0){
			cout << "You have no contacts.\n";
		}
		else if (contactCount == 1){
			cout << "You have 1 contact.\n";
		}
		else{
			cout << "You have " << contactCount << " contacts.\n";
		}

		cout << "\nWhat would you like to do now ('O' for options)? ";
		cin >> control;
	}

	destroyTree(p_tree);
}

void printOptions(){
	cout << "------\n";
	cout << "Options:\n";
	cout << "'I' to insert a contact\n";
	cout << "'R' to remove a contact\n";
	cout << "'U' to update a contact\n";
	cout << "'F' to find a contact\n";
	cout << "'P' to print your contacts\n";
	cout << "'O' to see available options\n";
	cout << "'Q' to quit\n";
	cout << "------\n";
}