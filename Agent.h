/**
	Agent.h
	Contains nearly every thing to do with agent. No special comments.
	@author Michael Henderson
	@version 1.0
*/
#ifndef AGENT_H
#define AGENT_H
#include "Maze.h"
#include "Agent_Visited.h"
#include "Agent_Stack.h"

class Agent
{
    public:
        /**
        Constructor Empty.
        @author Michael Henderson
        @version 1.0
        */
        Agent();

        /**
        Deconstructor - memory deletes check_top.
        @author Michael Henderson
        @version 1.0
        */
        virtual ~Agent();

                /**
        Sets agents start X position: startPoint_X.
        @author Michael Henderson
        @version 1.0
        @param int: X position.
        */
        void setAgentStartPosition_X(int);

        /**
        Sets agents start Y position: startPoint_Y.
        @author Michael Henderson
        @version 1.0
        @param int: Y position.
        */
        void setAgentStartPosition_Y(int);

        /**
        Gets agents start X position.
        @author Michael Henderson
        @version 1.0
        @return int: startPoint_X position.
        */
        int getAgentStartPosition_X();

        /**
        Gets agents start X position.
        @author Michael Henderson
        @version 1.0
        @return int: startPoint_Y position.
        */
        int getAgentStartPosition_Y();

        /**
        Sets agents current X position.
        @author Michael Henderson
        @version 1.0
        @param int: agent_X position.
        */
        void setAgentPosition_X(int);

        /**
        Sets agents current Y position.
        @author Michael Henderson
        @version 1.0
        @param int: agent_Y position.
        */
        void setAgentPosition_Y(int);

        /**
        Gets agents current X position.
        @author Michael Henderson
        @version 1.0
        @return int: agent_X position.
        */
        int getAgentPosition_X();

        /**
        Gets agents current X position.
        @author Michael Henderson
        @version 1.0
        @return int: agent_Y position.
        */
        int getAgentPosition_Y();

        /**
        Sets agents end position.
        @author Michael Henderson
        @version 1.0
        @param int: X position.
        */
        void setAgentEndPosition_X(int);

        /**
        Sets agents end position.
        @author Michael Henderson
        @version 1.0
        @param int: Y position.
        */
        void setAgentEndPosition_Y(int);

        /**
        Gets agents end position.
        @author Michael Henderson
        @version 1.0
        @return int: X position.
        */
        int getAgentEndPosition_X();

        /**
        Gets agents end position.
        @author Michael Henderson
        @version 1.0
        @return int: Y position.
        */
        int getAgentEndPosition_Y();


        /**
        Updates agents position and adds it to agent stack agentPath and agent visited av.
        @author Michael Henderson
        @version 1.0
        @param int: X position.
        @param int: Y position.
        */
        void updateAgentPosition(int,int);

        /**
        Basic control of agents movement.
        TODO: Improve
        @author Michael Henderson
        @version 1.0
        @param Maze maze
        */
        void moveAgent( Maze& );

        /**
        Um calls agentsPath.searchPathStack(x,y)
        @see Agent_Stack agentsPath agentsPath.searchPathStack(x,y)
        @author Michael Henderson
        @version 1.0
        @param int: X position.
        @param int: Y position.
        */
        int searchAgentPath( int, int );

        /**
        Tempory Um calls agentsPath.isEmptyStack();
        @see Agent_Stack int isEmptyStack();
        @author Michael Henderson
        @version 1.0
        @param int: 1 - true, 0 - false.
        */
        int checkIfPathEmtpy();

    protected:

    private:
        int agent_X;            //The X coordinate of agent's position.
        int agent_Y;            //The Y coordinate of agent's position.
        int startPoint_X;       //The X coordinate of agent's start position.
        int startPoint_Y;       //The Y coordinate of agent's start position.
        int endPoint_X;         //The X coordinate of agent's stopped position.
        int endPoint_Y;         //The Y coordinate of agent's stopped position.
        Agent_Visited av;       //Places the agent has visited
        Agent_Stack agentsPath; //The current path of the agent.
        Stack_Node * check_top; //To access data before popping.
};

#endif // AGENT_H
