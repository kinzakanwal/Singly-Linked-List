#include "pch.h"
#include <iostream>
using namespace std;
#include "dsa lab2.cpp"

class List
{
	Node *headNode;
	Node *currentNode;
	Node *lastCurrentNode;
	int size;

public:
	List()
	{
		headNode=0;
		currentNode=0;
	    lastCurrentNode=0;
	    size=0;
	}
	void insert(int n)
	{
		if(currentNode!=0)
		{
			if (currentNode->getNxtNode() == 0)
			{
				Node *newNode = new Node();
				lastCurrentNode = currentNode;
				currentNode->setNxtNode(newNode);
				currentNode = newNode;
				currentNode->setValue(n);
				currentNode->setNxtNode(0);
				size++; 
				display();
			}
			else
			{
				Node *newNode = new Node();
				newNode->setNxtNode(currentNode->getNxtNode());
				currentNode->setNxtNode(newNode);
				lastCurrentNode = currentNode;
				currentNode = newNode;
				currentNode->setValue(n);
				size++;
				display();
			}
		}
		else
		{
			Node *newNode = new Node();
			headNode = newNode;
			currentNode = headNode;
			currentNode->setValue(n);
			currentNode->setNxtNode(0);
			size++;
			display();
		}
	}
	void start()
	{
		lastCurrentNode = 0;
		currentNode = headNode;
	}
	void move()
	{
		lastCurrentNode = currentNode;
		currentNode = currentNode->getNxtNode();

	}
	int get()
	{
		return currentNode->getValue();
	}
	int getSize()
	{
		return size;
	}

	void InsertAtBegin(int p)
	{
		if (currentNode != 0)
		{
			Node *newNode = new Node();
			start();
			newNode->setNxtNode(headNode);
			headNode = newNode;
			currentNode = headNode;
			currentNode->setValue(p);
			size++;
			display();
		}
		else
		{
			Node *newNode = new Node();
			headNode = newNode;
			currentNode = headNode;
			currentNode->setValue(p);
			currentNode->setNxtNode(0);
			size++;
			display();
		}
	}

	void InsertAtEnd(int q)
	{
		if (currentNode != 0)
		{
			Node *newNode = new Node();
			start();
			while(currentNode->getNxtNode() != 0)
			{
				move();
			}
			lastCurrentNode = currentNode;
			currentNode->setNxtNode(newNode);
			currentNode = newNode;
			currentNode->setNxtNode(0);
			currentNode->setValue(q);
			size++;
			display();
		}
		else
		{
			Node *newNode = new Node();
			headNode = newNode;
			currentNode = headNode;
			currentNode->setValue(q);
			currentNode->setNxtNode(0);
			size++;
			display();
		}
	}

	void update(int v)
	{
		cout <<"The size of our list at this time is: " << size<<endl;
		int index;
		cout << "enter the index of the list where u want to update the value: ";
		cin >> index;
		start();
		for (int i = 1; i < index; i++)
		{
			move();
		}
		currentNode->setValue(v);
		cout << "After upadating the list at index " << index << " is:" << endl;
		display();
	}

	void display()
	{
		start();
		if (currentNode != 0)
		{
			cout << "List is:" << endl;
			cout << get() << endl;
			while (currentNode->getNxtNode() != 0)
			{
				move();
				cout << get() << endl;
			}
			cout << "size of the list is: " << getSize() <<endl << endl;
		}
		else
		{
			cout << "list is empty" << endl;
		}
	}
	
	bool search()
	{
		int num;
		cout << "enter the number u want to search: ";
		cin >> num;
		start();
		for (int i = 1; i < size; i++)
		{
			int n = get();
			if (num == n)
			{
				cout << "value find at node " << i << endl;
				return 1;
				break;
			}
			else
			{
				move();
			}
		}
		return 0;
		
	}

	void sum()
	{
		int add=0;
		start();
		
		while (currentNode != 0)
		{
			add = get() + add;
			move();
		}
		cout << "sum of all the values in the list is: " << add <<endl << endl;
	}

	void InsertAt(int x, int n)
	{
		start();
		Node *newNode = new Node();
		newNode->setValue(n);
		for (int i = 1; i < (x - 1); i++)
		{
			move();
		}
		newNode->setNxtNode(currentNode->getNxtNode());
		currentNode->setNxtNode(newNode);
		currentNode = newNode;
		size++;
	}

	/*bool insertAfter(int x, int n)
	{
		Node *temp = headNode;
		Node *newNode = new Node();
		newNode->setValue(n);
		while (temp)
		{
			if (temp->getValue() == x)
			{
				newNode->setNxtNode(temp->getNxtNode());
				temp->setNxtNode(newNode);
				size++;
				return 1;
			}
			temp = temp->getNxtNode();
		}*/
	void DeleteFirst()//Done
	{
		if (headNode == 0)
		{
			cout << "List is empty " << endl;
		}
		else
		{
			cout << "list is not empty so, deleting 1st node" << endl;
			Node* ptr = headNode;
			start();
			currentNode = currentNode->getNxtNode();
			headNode = currentNode;
			ptr->setNxtNode(0);
			delete ptr;
			size--;
			display();
		}

	}
	void DeleteLast()
	{
		start();
		for (int i = 2; i < size; i++)
		{
			move();
		}
		Node* ptr = currentNode->getNxtNode();
		currentNode->setNxtNode(0);
		delete ptr;
		size--;
		display();
	}
	void DeleteAt(int p)
	{
		start();
		if (headNode == 0)
		{
			cout << "List is empty " << endl;
		}
		else
		{
			if (p == 1)
			{
				DeleteFirst();
			}
			else
			{
				if (p == size)
				{
					DeleteLast();
				}
				else
				{
					if (p > size)
					{
						cout << "Element not found at the entered position" << endl;
					}
					else
					{
						for (int i = 1; i < p; ++i)
						{
							move();
						}
						Node* ptr = currentNode;
						lastCurrentNode->setNxtNode(ptr->getNxtNode());
						currentNode = currentNode->getNxtNode();
						ptr->setNxtNode(0);
						delete ptr;
						size--;
						display();
					}
				}
			}

		}

	}
		
	

};
