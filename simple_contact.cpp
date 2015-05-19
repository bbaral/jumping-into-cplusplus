/*
Simple Contact Struct

Written By: Stephen Merendino
Date: May 12, 2015

A simple program to try structs out. Simple contact reader that reads in a single contact and prints it back out.

Problem Source: 
Learning with C++
Alex Alain
Chapter 11, Practice Problem 1 (page 129)

TODO:
-None
*/

#include <iostream>;
#include <string>;

using namespace std;

struct Contact
{
	string name;
	string address;
	string phone_number;
};

void printContact(Contact contact);

int main()
{
	Contact contact;

	cout << "Welcome to your contact center!" << endl;
	cout << "This application can only hold one contact while you are running it." << endl;

	cout << "Please enter the name for your contact: " << endl;
	getline(cin, contact.name, '\n');

	cout << "Please enter the address for your contact: " << endl;
	getline(cin, contact.address, '\n');

	cout << "Please enter the phone number for your contact: " << endl;
	getline(cin, contact.phone_number, '\n');

	cout << "Congratulations, you have now used up your one contact! Here it is:" << endl;
	printContact(contact);

	cin.get();
}

void printContact(Contact contact)
{
	cout << "Name: " << contact.name << endl;
	cout << "Address: " << contact.address << endl;
	cout << "Phone Number: " << contact.phone_number << endl;
}