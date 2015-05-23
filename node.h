#ifndef STRING_INC
#define STRING_INC
#include <string>
#endif

enum Sort{
	ASC = 1,
	DESC = -1
};

class Node{
	public:
		Node(const std::string name, const std::string email)
			:name(name),
			email(email),
			p_left(NULL),
			p_right(NULL)
			{}
		~Node();
		std::string getName();
		std::string getEmail();
		Node* getLeftChild();
		Node* getRightChild();
		void setName(const std::string &newName);
		void setEmail(const std::string &newEmail);
		void setLeftChild(Node *const p_node);
		void setRightChild(Node *const p_node);
		void insertChildNode(Node *const p_node);
		Node* remove(const std::string &name);
		Node* find(const std::string &name);
		int size();
		void printTree(const Sort &sortDir);
		void printNode();

	private:
		std::string name;
		std::string email;
		Node *p_left;
		Node *p_right;

		Node* findLargestChildNode();
		Node* removeLargestChildNode(const std::string &name);

		//Copying is disabled, because nodes should not be copied
		//since they are part of a larger structure.
		Node(const Node &otherNode){};
		Node& operator=(const Node &otherNode);
};