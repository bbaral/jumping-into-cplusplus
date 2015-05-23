#ifndef IOSTREAM_INC
#define IOSTREAM_INC
#include <iostream>
#endif
#include "node.h"

Node::~Node(){
	delete this->p_left;
	delete this->p_right;
}

std::string Node::getName(){
	return this->name;
}

std::string Node::getEmail(){
	return this->email;
}

Node* Node::getLeftChild(){
	return this->p_left;
}

Node* Node::getRightChild(){
	return this->p_right;
}

void Node::setName(const std::string &newName){
	this->name = newName;
}

void Node::setEmail(const std::string &newEmail){
	this->email = newEmail;
}

void Node::setLeftChild(Node *const p_node){
	this->p_left = p_node;
}

void Node::setRightChild(Node *const p_node){
	this->p_right = p_node;
}

void Node::insertChildNode(Node *const p_node){
	if (p_node->getName() == this->getName()){
		std::cout << p_node->getName() << " already exists.\n";
	}
	else if (p_node->getName() < this->getName()){
		if (getLeftChild() == NULL){
			setLeftChild(p_node);
		}
		else{
			getLeftChild()->insertChildNode(p_node);
		}
	}
	else{
		if (getRightChild() == NULL){
			setRightChild(p_node);
		}
		else{
			getRightChild()->insertChildNode(p_node);
		}
	}
}

Node* Node::remove(const std::string &name){
	//The end of the tree has been reached and the node was never found.
	if (getName() != name && getLeftChild() == NULL && getRightChild() == NULL){
		std::cout << "Could not find that contact to remove.\n";
		return this;
	}

	if (getName() == name){
		if (getLeftChild() == NULL && getRightChild() == NULL){
			delete this;
			std::cout << "Successfully removed " << name << ".\n";
			return NULL;
		}
		else if (getLeftChild() != NULL && getRightChild() != NULL){
			Node *largestChildNode = findLargestChildNode();
			removeLargestChildNode(largestChildNode->getName());
			largestChildNode->setLeftChild(getLeftChild());
			largestChildNode->setRightChild(getRightChild());
			delete this;
			std::cout << "Successfully removed " << name << ".\n";
			return largestChildNode;
		}
		else if (getLeftChild() != NULL){
			Node* leftChildTree = getLeftChild();
			delete this;
			std::cout << "Successfully removed " << name << ".\n";
			return leftChildTree;
		}
		else if (getRightChild() != NULL){
			Node* rightChildTree = getRightChild();
			delete this;
			std::cout << "Successfully removed " << name << ".\n";
			return rightChildTree;
		}
	}
	else if (name < getName()){
		setLeftChild(getLeftChild()->remove(name));
	}
	else {
		setRightChild(getRightChild()->remove(name));
	}
}

Node* Node::findLargestChildNode(){
	if (getRightChild() == NULL){
		return this;
	}

	return getRightChild()->findLargestChildNode();
}

Node* Node::removeLargestChildNode(const std::string &name){
	if (getName() == name){
		if (getLeftChild() == NULL){//we arleady know the maxnode has no right subtree, so we only check the left
			return NULL;
		}
		else{
			return getLeftChild();//set parent pointer to the max node's left tree.
		}
	}
	else{
		setRightChild(getRightChild()->removeLargestChildNode(name));//keep traversing the right branches until we find the provided name.
	}

	return this;
}

Node* Node::find(const std::string &name){
	if (getName() != name && getLeftChild() == NULL && getRightChild() == NULL){
		return NULL;
	}

	if (getName() == name){
		return this;
	}
	else if (name < getName()){
		return getLeftChild()->find(name);
	}
	else{
		return getRightChild()->find(name);
	}
}

int Node::size(){
	int leftTreeSize = 0;
	int rightTreeSize = 0;

	if (getLeftChild() != NULL){
		leftTreeSize = getLeftChild()->size();
	}

	if (getRightChild() != NULL){
		rightTreeSize = getRightChild()->size();
	}
	return 1 + leftTreeSize + rightTreeSize;
}

void Node::printTree(const Sort &sortDir){
	if (getLeftChild() == NULL && getRightChild() == NULL){
		printNode();
		return;
	}

	if (sortDir == Sort::ASC){
		if (getLeftChild() != NULL){
			getLeftChild()->printTree(sortDir);
		}
		printNode();
		if (getRightChild() != NULL){
			getRightChild()->printTree(sortDir);
		}
	}
	else{
		if (getRightChild() != NULL){
			getRightChild()->printTree(sortDir);
		}
		printNode();
		if (getLeftChild() != NULL){
			getLeftChild()->printTree(sortDir);
		}
	}
}

void Node::printNode(){
	std::cout << '\n';
	std::cout << "Name: " << name;
	std::cout << '\n';
	std::cout << "Email: " << email;
	std::cout << '\n';
}