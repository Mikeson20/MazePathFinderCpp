/*
	Agent_Stack.cpp
	Mainly used to store the main path that the agent has taken.
	NOTE: Need to check incudes to see if they are really needed.
	@author Michael Henderson
	@version 1.0
*/
#include "Agent_Stack.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;

Agent_Stack::Agent_Stack()
{
    stack_top = NULL;
}

Agent_Stack::~Agent_Stack()
{
    deleteStack();
}


void Agent_Stack::push(int xC,int yC)
{
    Stack_Node * newNode;
    newNode = new Stack_Node;
    newNode->xP = xC;
    newNode->yP = yC;
    newNode->link = stack_top;
    stack_top = newNode;
}

void Agent_Stack::pop()
{
    Stack_Node * temp;
    if (stack_top != NULL){
        temp = stack_top;
        stack_top = stack_top->link;
        delete temp;
    }
}


Stack_Node* Agent_Stack::top()
{
    assert(stack_top != NULL);
  //  if(stack_top == NULL){
  //      return NULL;
  //  }
  //  else{
         return stack_top;
   // }
}

 int Agent_Stack::searchPathStack(int xS, int yS)
 {
    Stack_Node * current;
	int inStack = 0;
	current = stack_top;

	while( current != NULL )
	{
		if( (current -> xP == xS) && (current -> yP == yS) )
		{
			inStack = 1;
			break;
		}
		current = current -> link;
	}
	return inStack;
 }

int Agent_Stack::isEmptyStack()
{
    if(stack_top == NULL){
        return 1;
    }else{
        return (stack_top == NULL);
    }

}

void Agent_Stack::deleteStack()
{
    Stack_Node * temp;
    while(stack_top != NULL){
        temp = stack_top;
        stack_top = stack_top->link;
        delete temp;
    }
    stack_top = NULL;
}

void Agent_Stack::initializeStack()
{
    deleteStack();
}

void Agent_Stack::printStack()
{
    Stack_Node * current;

	current = stack_top;
    cout << "Current Path" << endl;
	while(current != NULL)
	{
		cout << "( xP: " << current -> xP << ", yP: " << current -> yP << " ), ";
		current = current -> link;
	}
    cout << endl;
}
