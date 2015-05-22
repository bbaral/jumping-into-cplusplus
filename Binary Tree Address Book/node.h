#include <string>

using namespace std;

struct Node{
	string name;
	string email;
	Node *p_left;
	Node *p_right;
};

enum Sort{
	ASC = 1,
	DESC = -1
};

Node* insert(Node *p_tree, string name, string email);
Node* remove(Node *p_tree, string name);
Node* findMaxNode(Node *p_tree);
Node* removeMaxNode(Node *p_tree, string name);
Node* find(Node *p_tree, string name);
int count(Node *p_tree);
void printTree(Node *p_tree, Sort sortDir);
void printNode(Node* p_node);
void destroyTree(Node *p_tree);