/*
	Agent_Visited.cpp
	A linked list that stores all the positions the agent has been.
	@author Michael Henderson
	@version 1.0
*/
#include "Agent_Visited.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Agent_Visited::Agent_Visited()
{
    head = NULL;
    tail = NULL;
}

Agent_Visited::~Agent_Visited()
{
    deleteVisitedList();
}

void Agent_Visited::insertFirst(int xA, int yA)
{
    Node * newNode;
	newNode = new Node;

	newNode -> xV = xA;
	newNode -> yV = yA;
	newNode -> next = head;
	head = newNode;
	//length++;

	if(tail == NULL)
	{
		tail = newNode;
	}
}

int Agent_Visited::searchLinkedList(int xF, int yF)
{
    Node * current;
	int inList = false;
	current = head;

	while( current != NULL )
	{
		if( (current -> xV == xF) && (current -> yV == yF) )
		{
			inList = true;
			break;
		}
		current = current -> next;
	}
	return inList;
}

void Agent_Visited::deleteVisitedList()
{
    Node * temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
}

void Agent_Visited::initialzeVisitedList()
{
    deleteVisitedList();
}

void Agent_Visited::printAVList(){
    Node * current;

	current = head;
    cout << "Visited" << endl;
	while(current != NULL)
	{
		cout << "( xV: " << current -> xV << ", yV: " << current->yV << " ), ";
		current = current -> next;
	}
    cout << endl;
}
