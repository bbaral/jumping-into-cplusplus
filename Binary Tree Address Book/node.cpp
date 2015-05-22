#include <iostream>
#include "node.h"

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