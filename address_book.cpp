#ifndef IOSTREAM_INC
#define IOSTREAM_INC
#include <iostream>
#endif
#include "address_book.h"

AddressBook::~AddressBook(){
	delete p_root;
}

void AddressBook::insert(const std::string &name, const std::string &email){
	if (getRoot() == NULL){
		Node *node = new Node(name, email);
		setRoot(node);
		return;
	}

	Node *node = new Node(name, email);
	getRoot()->insertChildNode(node);
	std::cout << name << " has been inserted.\n";
}

void AddressBook::remove(const std::string &name){
	if (getRoot() == NULL){
		std::cout << "Your address book is empty.\n";
		return;
	}

	setRoot(getRoot()->remove(name));
}

bool AddressBook::find(const std::string &name){
	Node *node = getRoot()->find(name);
	if (node == NULL){
		std::cout << "Sorry, couldn't find " << name << " in your address book.\n";
		return false;
	}
	else{
		std::cout << name << " found!\n";
		node->printNode();
		return true;
	}
}

void AddressBook::update(const std::string &name, const std::string &email){
	Node *node = getRoot()->find(name);
	if (node != NULL){
		node->setEmail(email);
		std::cout << "Updated " << name << "'s emails to " << email << ".\n";
	}
}

int AddressBook::size(){
	if (getRoot() == NULL){
		return 0;
	}

	return getRoot()->size();
}

void AddressBook::print(const Sort &sortDir){
	if (getRoot() == NULL){
		std::cout << "You have no contacts.\n";
		return;
	}

	getRoot()->printTree(sortDir);
}

Node* AddressBook::getRoot(){
	return p_root;
}

void AddressBook::setRoot(Node *const node){
	p_root = node;
}