/*
	Agent_Visited.h
	A linked list that stores all the positions the agent has been.
	@author Michael Henderson
	@version 1.0
*/
#ifndef AGENT_VISITED_H
#define AGENT_VISITED_H

using namespace std;

typedef struct Node{
    int xV;     //x position
    int yV;     //y position
    Node * next;
}Node;

class Agent_Visited
{
    public:
        /*
            Constructor
            @author Michael Henderson
            @version 1.0
        */
        Agent_Visited();

        /*
            Deconstructor
            @author Michael Henderson
            @version 1.0
        */
        virtual ~Agent_Visited();

        /*
            Inserts a node at front of linked list.
            @param int x position
            @param int y position
            @author Michael Henderson
            @version 1.0
        */
        void insertFirst(int, int);

        /*
            Simple search to see if agent has visited position.
            NOTE: Needs quicker search...
            @return int 1-true, 0-false
            @author Michael Henderson
            @version 1.0
        */
        int searchLinkedList(int, int);

        /*
            Delete's visited linked list stored data duh.
            @author Michael Henderson
            @version 1.0
        */
        void deleteVisitedList();

        /*
            Calls deleteVisitedList().
            @author Michael Henderson
            @version 1.0
        */
        void initialzeVisitedList();

        /*
            Prints list contents to console.
            @author Michael Henderson
            @version 1.0
        */
        void printAVList();

    protected:

    private:
        Node * head;
        Node * tail;
};

#endif // AGENT_VISITED_H
