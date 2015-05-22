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

#include <iostream>;
#include <string>;

using namespace std;

enum Sort{
	ASC = 1,
	DESC = -1
};

struct Node{
	string name;
	string email;
	Node *p_left;
	Node *p_right;
};

void printOptions();
Node* insert(Node *p_tree, string name, string email);
Node* remove(Node *p_tree, string name);
Node* findMaxNode(Node *p_tree);
Node* removeMaxNode(Node *p_tree, string name);
Node* find(Node *p_tree, string name);
int count(Node *p_tree);
void printTree(Node *p_tree, Sort sortDir);
void printNode(Node* p_node);
void destroyTree(Node *p_tree);

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

Node* insert(Node *p_tree, string name, string email){
	if (p_tree == NULL){
		Node *node = new Node;
		node->name = name;
		node->email = email;
		node->p_left = NULL;
		node->p_right = NULL;
		return node;
	}

	if (name < p_tree->name){
		p_tree->p_left = insert(p_tree->p_left, name, email);
	}
	else{
		p_tree->p_right = insert(p_tree->p_right, name, email);
	}

	return p_tree;
}

Node* remove(Node *p_tree, string name){
	if (p_tree == NULL){
		cout << "Could not find that contact to remove.\n";
		return NULL;
	}

	if (name == p_tree->name){
		if (p_tree->p_left == NULL && p_tree->p_right == NULL){
			delete p_tree;
			cout << "Successfully removed " << name << ".\n";
			return NULL;
		}
		else if (p_tree->p_left != NULL && p_tree->p_right != NULL){
			Node *maxNode = findMaxNode(p_tree);
			p_tree = removeMaxNode(p_tree, maxNode->name);
			maxNode->p_left = p_tree->p_left;
			maxNode->p_right = p_tree->p_right;
			delete p_tree;
			cout << "Successfully removed " << name << ".\n";
			return maxNode;
		}
		else if (p_tree->p_left != NULL){
			Node* leftTree = p_tree->p_left;
			delete p_tree;
			cout << "Successfully removed " << name << ".\n";
			return leftTree;
		}
		else if (p_tree->p_right != NULL){
			Node* rightTree = p_tree->p_right;
			delete p_tree;
			cout << "Successfully removed " << name << ".\n";
			return rightTree;
		}

	}
	else if (name < p_tree->name){
		p_tree->p_left = remove(p_tree->p_left, name);
		return p_tree;
	}
	else {
		p_tree->p_right = remove(p_tree->p_right, name);
		return p_tree;
	}
}

//Go down the right branches from the tree until you hit a dead end.
//This will give you the biggest node under the tree.
Node* findMaxNode(Node *p_tree){
	if (p_tree->p_right == NULL){
		return p_tree;
	}

	findMaxNode(p_tree->p_right);
}

Node* removeMaxNode(Node *p_tree, string name){
	if (p_tree == NULL){
		return NULL;
	}

	if (p_tree->name == name){
		if (p_tree->p_left == NULL){//we arleady know the maxnode has no right subtree, so we only check the left
			return NULL;
		}
		else{
			return p_tree->p_left;//set parent pointer to the max node's left tree.
		}
	}
	else{
		removeMaxNode(p_tree->p_right, name);//keep traversing the right branches until we find the provided name.
	}

	return p_tree;
}

Node* find(Node *p_tree, string name){
	if (p_tree == NULL){
		cout << "Sorry, couldn't find " << name << " in your address book.\n";
		return NULL;
	}

	if (p_tree->name == name){
		return p_tree;
	}

	if (name < p_tree->name){
		return find(p_tree->p_left, name);
	}
	else{
		return find(p_tree->p_right, name);
	}
}

int count(Node *p_tree){
	if (p_tree == NULL){
		return 0;
	}

	return 1 + count(p_tree->p_left) + count(p_tree->p_right);
}

void destroyTree(Node *p_tree){
	if (p_tree == NULL){
		return;
	}

	destroyTree(p_tree->p_right);
	destroyTree(p_tree->p_left);
	delete p_tree;
}

void printTree(Node *p_tree, Sort sortDir){
	if (p_tree == NULL){
		return;
	}

	if (p_tree->p_left == NULL && p_tree->p_right == NULL){
		printNode(p_tree);
		return;
	}

	if (sortDir == Sort::ASC){
		printTree(p_tree->p_left, sortDir);
		printNode(p_tree);
		printTree(p_tree->p_right, sortDir);
	}
	else{
		printTree(p_tree->p_right, sortDir);
		printNode(p_tree);
		printTree(p_tree->p_left, sortDir);
	}
}

void printNode(Node *p_node){
	if (p_node == NULL){
		return;
	}

	cout << '\n';
	cout << p_node->name;
	cout << '\n';
	cout << p_node->email;
	cout << '\n';
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
