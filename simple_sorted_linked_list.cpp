/*
Simple two-way sorted linked list.

Written By: Stephen Merendino
Date: May 13, 2015

This program builds a two-dimensional multiplication table 
with arbitrary sizes for the two dimensions.

Problem Source: 
Learning with C++
Alex Alain
Chapter 15, Practice Problem 2 (page 172)

TODO:
-None
*/

#include <iostream>;
#include <string>;

using namespace std;

struct ListNode
{
	ListNode *p_previousNode;
	string name;
	ListNode *p_nextNode;
};

ListNode* makeNewNode(string name);
ListNode* insertNewNode(ListNode *p_newNode, ListNode *p_list);
void printList(ListNode *p_list);

int main()
{
	ListNode *p_list = NULL;

	string control = "";
	while (control != "Q")
	{
		cout << "Enter in new name, 'P' to print what you have so far, or 'Q' to quit:" << endl;
		cin >> control;

		if (control == "Q")
		{
			continue;
		}
		else if (control == "P")
		{
			printList(p_list);
		}
		else
		{
			ListNode *p_newNode = makeNewNode(control);
			p_list = insertNewNode(p_newNode, p_list);
		}
	}
}

ListNode* makeNewNode(string name)
{
	ListNode *p_newNode = new ListNode;
	p_newNode->p_previousNode = NULL;
	p_newNode->name = name;
	p_newNode->p_nextNode = NULL;
	return p_newNode;
}

ListNode* insertNewNode(ListNode *p_newNode, ListNode *p_list)
{
	//If the list is null, then we start the list with the new node
	if (p_list == NULL)
	{
		p_list = p_newNode;
	}
	else
	{
		ListNode *p_currentNode = p_list; //get start of list

		bool sorted = false;
		while (sorted == false)
		{
			//we've found the item that is greater than the new node
			if (p_newNode->name.compare(p_currentNode->name) <= 0)
			{
				//first item in the list
				if (p_currentNode->p_previousNode == NULL)
				{
					p_newNode->p_nextNode = p_currentNode;
					p_currentNode->p_previousNode = p_newNode;
					p_list = p_newNode;//set the start of the list to our new node
					sorted = true;
				}
				//somewhere in the middle of the list
				else
				{
					ListNode *p_previousNode = p_currentNode->p_previousNode;
					p_previousNode->p_nextNode = p_newNode;
					p_currentNode->p_previousNode = p_newNode;
					p_newNode->p_previousNode = p_previousNode;
					p_newNode->p_nextNode = p_currentNode;
					sorted = true;
				}
			}
			//we didn't find it, and we are at the end of the list
			else if (p_currentNode->p_nextNode == NULL)
			{
				p_currentNode->p_nextNode = p_newNode;
				p_newNode->p_previousNode = p_currentNode;
				sorted = true;
			}

			//move to the next node to check it
			p_currentNode = p_currentNode->p_nextNode;
		}
	}

	return p_list;
}

void printList(ListNode *p_list)
{
	if (p_list == NULL)
	{
		cout << "There are no names in the list, try inserting one." << endl;
	}
	else
	{
		ListNode *currentNode = p_list;
		while (currentNode != NULL)
		{
			cout << currentNode->name << " -> ";
			currentNode = currentNode->p_nextNode;
		}
		cout << "NULL" << endl;
	}
}