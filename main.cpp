/*
	main.cpp
	Has read file maze is in, loads it to 2D dynamic memory, menu's,
	basic agent movement.
	BUGS: Seems to crash at end, going out of bounds somewhere.
	@author Michael Henderson
	@version 1.0
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "windows.h"
//#include <array>

#include "Agent_Visited.h"
#include "Agent_Stack.h"

using namespace std;

Agent_Visited av;
Agent_Stack agentsPath;
Stack_Node * check_top;

int agent_X;
int agent_Y;
int startPoint_X;
int startPoint_Y;
int **outside;
int allocate_outside = 0;
int row = 0;
int xM;
int yM;
void remaze(char [], char[]);
void loadMaze(char []);
void storeMazeData(int [],int);
int length(char []);
void moveAgent();

void arrayTest();

int main()
{

    int inC, i, j;
    int menuClose = 0;
    char * m;
    do{
        cout << "Choose Maze" << endl;
        cout << "Maze 1 enter: 1" << endl;
        cout << "Maze 2 enter: 2" << endl;
        cin >> inC;
        if(inC == 1){
            m = "maze01.txt";
            menuClose = 1;
        }else if(inC == 2){
            m = "maze02.txt";
            menuClose = 1;
        }else{
            cout << "Bad Selection" << endl;
        }
    }while(menuClose == 0);

    loadMaze(m);
    cout << "@";
    int rpc = 0; //position count
    for(i = 0; i < xM; i++){
        if(rpc > 9){
            rpc = 0;
        }
        cout << rpc;
        rpc++;
    }
    cout << endl;
    rpc = 0;
    for(i = 0; i < xM; i++){
        if(rpc > 9){
            rpc = 0;
        }
        cout << rpc;
        rpc++;
        for(j = 0; j < yM;j++){

            if(outside[i][j] == 1){
                cout << " ";
            }else{
                cout << outside[i][j];
            }
        }
        cout << endl;
    }

    menuClose = 0;
    do{
        cout << "Choose Start Position. NOTE: add a 1 if > first 9" << endl;
        cout << "X: ";
        cin >> inC;
        agent_X = inC;
        startPoint_X = inC;
        cout << "Y: ";
        cin >> inC;
        agent_Y = inC;
        startPoint_Y = inC;
        if( (agent_X < 0) || (agent_X > xM) || (agent_Y < 0) || (agent_Y > yM) ){
            cout << "Bad Selection" << endl;
        }else{
            menuClose = 1;
        }
    }while(menuClose == 0);

    ///////////////////////////////////////////////////////////////////
    agentsPath.push(agent_X, agent_Y);
    av.insertFirst(agent_X, agent_Y);


    int x, y;

    int stop = 0;
    while(stop == 0){
       // av.printAVList();

    //cout << "##############################################" << endl;
        for(x = 0; x < xM;x++){
            for(y = 0; y < yM;y++){
                if( (x == agent_X) && (y == agent_Y) ){
                    cout << "A";
                }else{
                    if(outside[x][y] == 1){
                        //To leave a marker so path can be seen.
                        if(agentsPath.searchPathStack(x,y) == 1){
                            cout << "-";
                        }else{
                            cout << " ";
                        }
                    }else{
                        cout << outside[x][y];
                    }
                }
            }
            cout << endl;
        }

        //moveAgent(agentBeen);
        moveAgent();
        //shut it down as path stack is empty catch crash??????
        if(agentsPath.isEmptyStack() == 1){
            cout << "About to stop may crash if not enter: 1 | or continue enter: 0" << endl;
            cin >> inC;
            stop = inC;
        }else if(agent_X == startPoint_X && agent_Y == startPoint_Y){
            cout << "About to stop may crash if not enter: 1 | or continue enter: 0" << endl;
            cin >> inC;
            stop = inC;
        }else{
            Sleep(20);
            system("cls");
        }
    }
    //Memory Clean up
    delete m;
    delete check_top;
    for(i = 0; i < xM; i++) {
            free(outside[i]);
        }
    free(outside);
    ////////////////////////////////////////////////////////////////

    return 0;
}

void remaze(char oldMaze[], char newMaze[]){
    char letter = ' ';

    FILE * infile;
    FILE * outfile;

    infile = fopen(oldMaze,"r");
    outfile = fopen(newMaze,"w");

    if(infile == NULL || outfile == NULL){
            perror("Open file");
    }else{
        do
        {
            letter =  fgetc(infile);
            if(letter == '0'){

                cout << " ";
                //letter = ' ';
                fputc(' ', outfile);
            }else if(letter == '#'){
                cout << letter;
                fputc(letter, outfile);
            }else{
                if(letter == '\n'){
                    cout << endl;
                    fputc('\n', outfile);
                }
            }
        }while(letter != EOF);

        fclose(infile);
        fclose(outfile);
    }
}

void loadMaze(char maze[]){

    int buffer[256];
    int counter = 0;
    char letter = ' ';


    FILE * infile;

    infile = fopen(maze,"r");

    if(infile == NULL){
            perror("Open file");
    }else{
        do
        {
            letter =  fgetc(infile);
            if(letter == ' '){
                buffer[counter] = 1;
                counter++;
                //cout << " ";
            }else if(letter == '#'){
                buffer[counter] = 0;
                counter++;
                //cout << letter;
            }else{
                if(letter == '\n' || letter == EOF){
                    //cout << endl;
                    //buffer[counter] = '\0';
                    //cout << buffer << endl;

                    storeMazeData(buffer,counter);
                    counter = 0;
                }
            }
        }while(letter != EOF);

        fclose(infile);
    }
    ///////////////////////////////////////////////////////////////////////
}


//maze has to be square..........
void storeMazeData(int data[], int dataSize){
    int x, y, i, c = 0;
    xM = dataSize; //length(data);   //size(data);//sizeof(data[0]);
    yM = xM;
    //cout << "storeMazeData xM: " << xM << " yM: " << yM << endl;

    //Allocate memory for maze;
    if(allocate_outside == 0){
        outside = (int **)malloc(xM * sizeof(int*));
        for(i = 0; i < yM; i++) {
            outside[i] = (int *)malloc( yM * sizeof(int));
        }
        allocate_outside = 1;
        cout << "MEMORY ALLOCATED" << endl;
    }


    for(y = 0; y < yM; y++){
        outside[row][y] = data[c];
        c++;
    }

    row++;
}

int length(char data[]){
    int ds = 0;

    while( data[ds] != NULL ){
        ds++;
    }
   // cout << "LENGTH: " << ds << endl;
    return ds;
}



void moveAgent(){
    int xtp, ytp;
    int xT = agent_X;
    int yT = agent_Y;
    int r;
    int noMove = 0; //Cannot (Dead End) move go to previous till can move.
    //000 north -,  left -, right +
    //0X0 same   ,  left -, right +
    //000 south +,  left -, right +

    //while(moveable == 0){

    //}


    if( (outside[xT-1][yT] == 1) && (xT-1 >= 0) ){       //can go north
        r = av.searchLinkedList(xT-1, yT);
        //cout << "Visited: xT-1: " << xT-1 << " yT: " << yT << " r: " << r << endl;
        if( r != 1 )
        {
            agent_X--;
            av.insertFirst(xT-1, yT);
            agentsPath.push(xT-1, yT);
            goto moving;
        }
        else{
            noMove = 1;
        }
    }
    if( (outside[xT][yT+1] == 1) && (yT+1 <= yM) ){  //can go east
        r =av.searchLinkedList(xT, yT+1);
        //cout << "Visited: xT: " << xT << " yT+1: " << yT+1 << " r: " << r << endl;
        if( r != 1 )
        {
            agent_Y++;
            av.insertFirst(xT, yT+1);
            agentsPath.push(xT, yT+1);
            goto moving;
        }
        else{
            noMove = 1;
        }
    }
    if( (outside[xT][yT-1] == 1) && (yT+1 >= 0) ){   //can go west
        r = av.searchLinkedList(xT, yT-1);
        //cout << "Visited: xT: " << xT << " yT-1: " << yT-1 << " r: " << r << endl;
        if( r != 1)
        {
            agent_Y--;
            av.insertFirst(xT, yT-1);
            agentsPath.push(xT, yT-1);
            goto moving;
        }
        else{
            noMove = 1;
        }
    }
    if( (outside[xT+1][yT] == 1) && (xT-1 <= xM)  ){ //can go south
        r = av.searchLinkedList(xT+1, yT);
        //cout << "Visited: xT+1: " << xT+1 << " yT: " << yT<< " r: " << r << endl;
        if( r != 1)
        {
            agent_X++;
            av.insertFirst(xT+1, yT);
            agentsPath.push(xT+1, yT);
            goto moving;
        }
        else{
            noMove = 1;
        }
    }

    if(noMove == 1){
        agentsPath.pop();
        check_top = agentsPath.top();
        xtp = check_top->xP;
        ytp = check_top->yP;
        //cout << "Checking Top: " << xtp << " : " << ytp << endl;
        agent_X = xtp;
        agent_Y = ytp;
    }

    moving:;
}

