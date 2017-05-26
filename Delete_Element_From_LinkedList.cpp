// DeleteElement.cpp : Defines the entry point for the console application.
// Example to delete data from linked list

#include "stdafx.h"
#include <iostream>

using namespace std;

// there is another program to insert element in the linked list
struct Node{
	Node* _link;
	int _data;
};

Node* _head;

Node* _createNode(int data)
{
	Node* newNode = new Node;

	newNode->_data = data;
	newNode->_link = NULL;

	return newNode;
}

void _insertNode(int data )
{
	Node* newNode = _createNode(data);
	// check the node inthe linked list
	if (_head==NULL) // for the very first nmode head will be NULL
	{
		_head = newNode;
		return ;
	}
	newNode->_link = _head;
	_head = newNode;
}

void _printData()
{
	Node* tempNode = _head;

	while (tempNode)
	{
		std::cout<<tempNode->_data<<"\t";
		tempNode = tempNode->_link;
	}
	std::cout<<"\n";
}

// delete node from the nth position
void _deleteDataFrom_nth_Position(int pos)
{
	if (_head==NULL)
	{
		std::cout<<"There is no element in the linked list"<<std::endl;
	}
	// if its a first element
	Node* tempNode = _head;
	if (pos==1)
	{
		_head = tempNode->_link;
		return;
	}
	
	for (int i = 0; i < pos - 2 ; i++)
	{
		tempNode = tempNode->_link;
	}
	Node* temp = tempNode->_link;
	tempNode->_link = temp->_link;
}

int _tmain(int argc, _TCHAR* argv[])
{

	// initialize head;
	_head = NULL;

	_insertNode(95);
	_insertNode(5);
	_insertNode(15);
	_insertNode(52);
	_insertNode(25);
	_insertNode(35);
	_insertNode(45);
	_insertNode(55);

	_printData();


	_deleteDataFrom_nth_Position(4);
	_printData();

	return 0;

}

