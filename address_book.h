#include "node.h"

class AddressBook{
	public:
		AddressBook() :p_root(NULL) {}
		AddressBook(Node* node) :p_root(node) {}
		~AddressBook();
		void insert(const std::string &name, const std::string &email);
		void remove(const std::string &name);
		bool find(const std::string &name);
		void update(const std::string &name, const std::string &email);
		int size();
		void print(const Sort &sortDir);

	private:
		Node *p_root;

		Node* getRoot();
		void setRoot(Node *const node);
};