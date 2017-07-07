/**
	Agent.cpp
	Contains nearly every thing to do with agent. No special comments.
	@author Michael Henderson
	@version 1.0
*/
#include "Agent.h"
#include "Agent_Visited.h"
#include "Agent_Stack.h"
#include "Maze.h"

#include <stdlib.h>
#include <iostream> //cout and endl;
using namespace std;

Agent::Agent()
{
    //ctor
}

Agent::~Agent()
{
    //dtor
    delete check_top;
}

void Agent::setAgentPosition_X(int x){
    agent_X = x;
}

void Agent::setAgentPosition_Y(int y){
    agent_Y = y;
}

int Agent::getAgentPosition_X(){
    return agent_X;
}

int Agent::getAgentPosition_Y(){
    return agent_Y;
}

void Agent::setAgentStartPosition_X(int x){
   startPoint_X = x;
}

void Agent::setAgentStartPosition_Y(int y){
   startPoint_Y = y;
}

int Agent::getAgentStartPosition_X(){
    return startPoint_X;
}

int Agent::getAgentStartPosition_Y(){
    return startPoint_Y;
}

void Agent::setAgentEndPosition_X(int x){
   endPoint_X = x;
}

void Agent::setAgentEndPosition_Y(int y){
   endPoint_Y = y;
}

int Agent::getAgentEndPosition_X(){
    return endPoint_X;
}

int Agent::getAgentEndPosition_Y(){
    return endPoint_Y;
}

//will update agent stack agentPath and agent visited av
void Agent::updateAgentPosition( int x,int y ){
    setAgentPosition_X( x );
    setAgentPosition_Y( y );
    agentsPath.push( x, y );
    av.insertFirst( x, y ) ;
}

int Agent::searchAgentPath( int x, int y ){
    return agentsPath.searchPathStack(x,y);
}

int Agent::checkIfPathEmtpy(){
    return agentsPath.isEmptyStack();
}

void Agent::moveAgent( Maze &maze1 ){
    //Maze mazeMap
    //000 north -Y,  left -X, right +X
    //0X0 same   ,  left -X, right +X
    //000 south +Y,  left -X, right +X

    int xtp, ytp;
    int xT = getAgentPosition_X();
    int yT = getAgentPosition_Y();
    int r;
    int noMove = 0; //Cannot (Dead End) move go to previous till can move.


    //Go North ???
    if(maze1.checkMapPosition( xT, yT-1 ) == 1){
        r = av.searchLinkedList(xT, yT-1);
        //cout << "Visited: xT: " << xT << " yT-1: " << yT-1 << " r: " << r << endl;
        if( r != 1 )
        {
            setAgentPosition_Y( yT-1 );
            av.insertFirst( xT, yT-1 );
            agentsPath.push( xT, yT-1 );
            goto moving;
        }
        else{
            noMove = 1;
        }
    }

    //Go east ???
    if(maze1.checkMapPosition( xT+1, yT ) == 1){
        r =av.searchLinkedList(xT+1, yT);
        //cout << "Visited: xT+1: " << xT+1 << " yT: " << yT << " r: " << r << endl;
        if( r != 1 )
        {
            setAgentPosition_X( xT+1 );
            av.insertFirst( xT+1, yT );
            agentsPath.push( xT+1, yT );
            goto moving;
        }
        else{
            noMove = 1;
        }
    }

    //Go west ???
    if(maze1.checkMapPosition( xT-1, yT ) == 1){
        r = av.searchLinkedList(xT-1, yT);
        //cout << "Visited: xT-1: " << xT-1 << " yT: " << yT << " r: " << r << endl;
        if( r != 1)
        {
            setAgentPosition_X( xT-1 );
            av.insertFirst( xT-1, yT );
            agentsPath.push( xT-1, yT );
            goto moving;
        }
        else{
            noMove = 1;
        }
    }

    //Go south ???
    if(maze1.checkMapPosition( xT, yT+1 ) == 1){
        r = av.searchLinkedList(xT, yT+1);
        //cout << "Visited: xT: " << xT << " yT+1: " << yT+1 << " r: " << r << endl;
        if( r != 1)
        {
            setAgentPosition_Y( yT+1 );
            av.insertFirst(xT, yT+1 );
            agentsPath.push(xT, yT+1 );
            goto moving;
        }
        else{
            noMove = 1;
        }
    }

    if(noMove == 1){
        if(agentsPath.isEmptyStack() != 1){
            agentsPath.pop();
            if(agentsPath.isEmptyStack() != 1){
                check_top = agentsPath.top();
                xtp = check_top->xP;
                ytp = check_top->yP;
                //cout << "Checking Top: " << xtp << " : " << ytp << endl;
                agent_X = xtp;
                agent_Y = ytp;
            }else{              //RESET POSITION
                agent_X = startPoint_X;
                agent_Y = startPoint_Y;
            }

        }
    }

    moving:;
}
