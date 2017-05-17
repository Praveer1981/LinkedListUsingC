// delete_it.cpp : Defines the entry point for the console application.
// Example to inset data into a linked list

#include "stdafx.h"
#include <iostream>


struct Node{
	Node* _next;
	int   _data;
};
// global head pointer
Node* _head;

Node* _createNode( int data )
{
	Node* temp = new Node;
	temp->_data = data;
	temp->_next = NULL;

	return temp;
}

void _insertNode( int data )
{

	// create node
	Node* newNode = _createNode( data );

	// head points to NULL, there is no data in linked list
	if( _head == NULL )
	{
		_head = newNode;
		return;
	}
	newNode->_next = _head;
	_head = newNode;
}

void _printData()
{
	printf("*************************Data in the linked list *************************\n");
	Node* tempNode = _head;
	while ( tempNode )
	{
		printf("%d	", tempNode->_data );
		tempNode = tempNode->_next;
	}
	printf("\n");
}

void _insertDataAtASpecifcPosition(int data, int pos)
{
	Node* newNode = _createNode(data);
	// if head is null - there is no data in the linked list
	if (_head == NULL)
	{
		_head = newNode;
		return;
	}
	// if its a first position
	if (pos==1)
	{
		newNode->_next = _head;
		_head = newNode;
		return;

	}
	Node* tempNewNode = _head;
	for (int i = 0; i < pos-2; i++)
	{
		tempNewNode = tempNewNode->_next;
	}
	newNode->_next = tempNewNode->_next;
	tempNewNode->_next = newNode;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_head = NULL;
	// there are many ways to give input to the application
	// I have choosen the simplest way for demonstration

	_insertNode(3);
	_insertNode(5);
	_insertNode(7);
	_insertNode(9);
	_printData();
	// Make sure that the position is between[1,n]
	_insertDataAtASpecifcPosition(4,1);
	_printData();
	return 0;

}

