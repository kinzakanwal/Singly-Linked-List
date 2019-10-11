#include"pch.h"
#include<iostream>
#include"List.cpp"
using namespace std;
int main()
{
	List myLinkList;
	myLinkList.insert(100);
	myLinkList.insert(150);
	myLinkList.insert(32);
	myLinkList.insert(56);
	myLinkList.InsertAtBegin(14);
	
	myLinkList.update(36);
	
	if (myLinkList.search())
	{
		cout<<"Element found" << endl << endl;
	}
	else
	{
		cout << "Element not found "<<endl << endl;
	}

	myLinkList.sum();

	cout << "After deleting the first node: " << endl;
	myLinkList.DeleteFirst();
	myLinkList.InsertAtEnd(25);

	cout << "After deleting the last node: " << endl;
	myLinkList.DeleteLast();
	
	cout << "After deleting the node at given position: " << endl;
	myLinkList.DeleteAt(4);
	
/*	myLinkList.InsertAt(3, 890);
	cout << endl << "Now my linked list is: " << endl;
	myLinkList.display();
*/
	/*myLinkList.insertAfter(150, 90);
	cout << endl << "Now my linked list is: " << endl;
	myLinkList.display();*/
	return 0;
}
