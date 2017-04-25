// 5- Reverse a linked list - ReverseLinkedList.cpp 
//

#include "stdafx.h"
#include <stdio.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

 void Insert(  int value )
 {
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;
	
	 if (head == NULL )
	 {
		 head =temp;
	 }
	 else
	 {
		 Node* temp1 = new Node;
		 temp1->data = temp->data;
		 temp1->next = head;
		 head = temp1;		
	 }
 }

 void PrintNode( )
 {
	 Node* tempNode =head;
	 while (tempNode != NULL)
	 {
		 printf("%d  ",tempNode->data);
		 tempNode = tempNode->next;
	 }
 }

 void Reverse(){
	 Node *current,*Prev,*Next;

	 current = head;
	 Prev = NULL;

	 while ( current != NULL)
	 {
		 Next = current->next;
		 current->next =  Prev;
		 Prev = current;
		 current = Next;
	 }
	 head = Prev;
 }

int _tmain(int argc, _TCHAR* argv[])
{
	head = NULL;
	Insert(3);
	Insert(8);
	Insert(7);
	Insert(1);
	Insert(4);
	Insert(6);

	PrintNode();
	printf("\nReverse the link list\n");
	Reverse();
	PrintNode( );
	return 0;
}

