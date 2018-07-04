/*#pragma once
#include "Node.h"
#include<stdexcept>
#include<sstream>
template<class T>
class LinkedList
{
public:
	LinkedList() {};
	~LinkedList() {
		clear();
	};
	node<T>* head = NULL;
	bool check(T value)
	{
		node<T>* check;
		check = head;
		while (check != NULL)
		{
			if (check->itemtype != value)
			{
				check = check->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	void insertHead(T value)
	{
		node<T>* temp;
		temp = head;
		if (head == NULL)
		{
			node<T>* newnode = new node<T>;
			head = newnode;
			head->itemtype = value;
		}
		else if (check(value) == true)
		{
			node<T>* newnode = new node<T>;
			head = newnode;
			head->itemtype = value;
			head->next = temp;
			temp->previous = head;
		}

	}
	void insertTail(T value)
	{
		node<T>* temp;
		temp = head;
		node<T>*cur;
		cur = head;
		if (check(value) == true)
		{
			if (head == NULL)
			{
				node<T>* newnode = new node<T>;
				newnode->itemtype = value;
				head = newnode;
			}
			else
			{
				while (temp != NULL)
				{
					cur = temp;
					temp = temp->next;
				}
				node<T>* newnode = new node<T>;
				newnode->itemtype = value;
				cur->next = newnode;
				newnode->previous = cur;
			}
		}
	}
	void insertAfter(T value, T insertionNode)
	{
		node<T>* temp;
		temp = head;
		if (check(value) == true && check(insertionNode) == false)
		{
			while (temp->itemtype != insertionNode)
			{
				temp = temp->next;
			}
			node<T>* newnode = new node<T>;
			newnode->itemtype = value;
			if (temp->next != NULL)
			{
				newnode->next = temp->next;
				temp->next->previous = newnode;
				temp->next = newnode;
				newnode->previous = temp;
			}
			else
			{
				temp->next = newnode;
				newnode->previous = temp;
			}
		}
	}
	void remove(T value)
	{
		node<T>* temp;
		temp = head;
		if (check(value) == false)
		{
			while (temp->itemtype != value)
			{
				temp = temp->next;
			}
			node<T>*cur = temp->next;
			node<T>*pre = temp->previous;
			if (pre == NULL&&cur == NULL)
			{
				delete temp;
				head = NULL;
			}
			else if (pre == NULL)
			{
				cur->previous = NULL;
				delete temp;
				head = cur;
			}
			else if (cur == NULL)
			{
				pre->next = NULL;
				delete temp;
			}
			else
			{
				pre->next = cur;
				cur->previous = pre;
				delete temp;
			}

		}
	}
	void clear()
	{
		node<T>* temp;
		temp = head;
		node<T>* cur;
		cur = head;
		while (temp != NULL)
		{
			cur = temp;
			temp = temp->next;
			delete cur;
		}
		head = NULL;
	}
	T at(int index)
	{
		node<T>*temp;
		temp = head;
		if (size() == 0 || index<0)
		{
			throw out_of_range("");
			return NULL;
		}
		if (index + 1>size())
		{
			throw out_of_range("");
			return NULL;
		}
		for (int i = 0; i < index; i++)
		{
			//see if i need
			if (temp->next == NULL)
			{
				throw out_of_range("");
				return NULL;
			}

			else
			{
				temp = temp->next;
			}

		}
		return temp->itemtype;
	}
	int size()
	{
		node<T>* temp;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}
	string printList()
	{
		node<T>*temp;
		string result;
		string y;
		temp = head;
		for (int i = 0; i < size(); i++)
		{
			stringstream ss;
			ss << temp->itemtype;
			result = ss.str();
			if (i == (size() - 1))
			{
				y += result;
			}
			else
			{
				y += result + " ";
			}
			temp = temp->next;

		}
		return y;
	}
	T gettail()
	{
		node<T>*temp;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->itemtype;
	}
	T getprevious(T data)
	{
		node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->itemtype == data)
			{
				return temp->previous->itemtype;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
};*/
