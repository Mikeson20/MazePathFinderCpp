/*
	Agent_Stack.h
	Mainly used to store the main path that the agent has taken.
	@author Michael Henderson
	@version 1.0
*/
#ifndef AGENT_STACK_H
#define AGENT_STACK_H

typedef struct Stack_Node{
    int xP;     //x position
    int yP;     //y position
    Stack_Node * link;
    }Stack_Node;

class Agent_Stack
{
    public:
        /*
            Constructor
            @author Michael Henderson
            @version 1.0
        */
        Agent_Stack();

        /*
            Deconstructor
            @author Michael Henderson
            @version 1.0
        */
        virtual ~Agent_Stack();

        /*
            Puts a new node on top of stack.
            @param int x position
            @param int y position
            @author Michael Henderson
            @version 1.0
        */
        void push(int,int);

         /*
            Removes node on top of stack.
            @param int x position
            @param int y position
            @author Michael Henderson
            @version 1.0
        */
        void pop();

        /*
            Returns top node so agent can move back to previous position.
            @return Stack_Node  x position, y position
            @author Michael Henderson
            @version 1.0
        */
        Stack_Node * top();

        /*
            Is empty Stack Duh
            @return int 1-true, 0-false
            @author Michael Henderson
            @version 1.0
        */
        int isEmptyStack();

        /*
            Simple search to see if agent has been at that position on current path.
            Mainly used to print path on console.
            NOTE: Needs quicker search...
            @return int 1-true, 0-false
            @author Michael Henderson
            @version 1.0
        */
        int searchPathStack(int, int);

        /*
            Delete's Stack Duh
            @author Michael Henderson
            @version 1.0
        */
        void deleteStack();

        /*
            Calls deleteStack()
            @author Michael Henderson
            @version 1.0
        */
        void initializeStack();

        /*
            Prints stack contents to console.
            @author Michael Henderson
            @version 1.0
        */
        void printStack();
    protected:
    private:
        Stack_Node * stack_top;
};

#endif // AGENT_STACK_H
