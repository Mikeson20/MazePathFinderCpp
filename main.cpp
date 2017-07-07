/**
	main.cpp
	Core, utilize functions to make program operable.
	BUGS:
	@author Michael Henderson
	@version 2.0
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "windows.h"

#include "Menu.h"
#include "Maze.h"
#include "Agent.h"

using namespace std;


int main()
{
    char * m;
    int inC;
    Menu menu;
    Maze maze;
    Agent agent;

    m = menu.chooseMaze();
    cout << "Maze Chosen: " << m << endl;

    //system("PAUSE");

    maze.loadMaze(m);

    //system("PAUSE");

    //Displaying selected maze.
    maze.displayMazeOnly();

    int asp[2];//[2]; //Agent start position ( 0: X, 1: Y ).
    int * agentStartPosition = menu.chooseStartPosition(asp, maze.getMazeSize_X(), maze.getMazeSize_Y() );
    cout << "Chosen Start Position" << endl;
    //cout << "X: " << asp[0] << " | Y: " << asp[1] << endl;

    agent.setAgentStartPosition_X(asp[0]);
    agent.setAgentStartPosition_Y(asp[1]);

    //system("PAUSE");

    //Displaying selected maze showing start position.
    maze.displayMazeOnly(0, asp[0], asp[1]);

    //system("PAUSE");

    int aep[2];//[2]; //Agent end position ( 0: X, 1: Y ).
    int * agentEndPosition = menu.chooseEndPosition( asp, aep, maze.getMazeSize_X(), maze.getMazeSize_Y() );
    cout << "Chosen End Position" << endl;
    //cout << "X: " << aep[0] << " | Y: " << aep[1] << endl;
    maze.setMaze_EndPosition_X(aep[0]);
    maze.setMaze_EndPosition_Y(aep[1]);
    //system("PAUSE");

    //Displaying selected maze showing start and position.
    maze.displayMazeOnly(asp[0], asp[1], aep[0], aep[1]);
    cout << "Maze Chosen: " << m << endl;
    cout << "Start Position@ X: " << asp[0] << " | Y: " << asp[1] << endl;
    cout << "End Position@ X: " << aep[0] << " | Y: " << aep[1] << endl;
    cin >> inC;
    //system("PAUSE");

    agent.updateAgentPosition(asp[0],asp[1]);


    //MAIN DISPLAY THREAD....
    //ENGINE CLASS ??????....
    int x, y;
    int stop = 0;
    while(stop == 0){
        for( x = 0; x < maze.getMazeSize_X(); x++ ){
            for( y = 0; y < maze.getMazeSize_Y(); y++ ){
                if( ( y == agent.getAgentPosition_X() ) && ( x == agent.getAgentPosition_Y() ) ){
                    cout << "A";
                    if( ( y == maze.getMaze_EndPosition_X() ) && ( x == maze.getMaze_EndPosition_Y() ) ){
                        stop = 1;
                    }
                }else{
                    if(maze.outside[x][y] == 1){
                        //To leave a marker so path can be seen.
                        if( agent.searchAgentPath( y,x ) == 1 ){
                            cout << "*";
                        }else if( y == maze.getMaze_EndPosition_X() && x == maze.getMaze_EndPosition_Y() ){
                            cout << "X";
                        }else{
                            cout << " ";
                        }
                    }else{
                        cout << maze.outside[x][y];
                    }
                }
            }
            cout << endl;
        }

       // system("PAUSE");
        if(stop == 0){
            agent.moveAgent( maze );
            //shut it down as path stack is empty catch crash??????
            //NOT UPDATED

         if(agent.checkIfPathEmtpy() == 1){
                cout << "Agent path stack is empty\nAbout to stop may crash if not enter: 1 | or continue enter: 0" << endl;
                cin >> inC;
                stop = inC;
            }else if( ( agent.getAgentPosition_X() == agent.getAgentStartPosition_X() ) && ( agent.getAgentPosition_Y() == agent.getAgentStartPosition_Y() ) ){
                cout << "At start point.\nAbout to stop may crash if not enter: 1 | or continue enter: 0" << endl;
                cin >> inC;
                stop = inC;
            }else{
                Sleep(40);
                system("cls");
            }
        }
        else{
            cout << "End Point Reached" << endl;
        }
    }
    //Memory Clean up
    delete m;
    return 0;
}




