/**
	Maze.cpp
	Contains every thing to do with maze / map. No special comments.
	@author Michael Henderson
	@version 1.0
*/
#include "Maze.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Maze::Maze()
{
    allocate_outside = 0;
    row = 0;
}

Maze::~Maze()
{
    //dtor
    int i;
    for(i = 0; i < xM; i++) {
            free(outside[i]);
        }
    free(outside);
}

int Maze::getMazeSize_X(){
    return xM;
}

int Maze::getMazeSize_Y(){
    return yM;
}

void Maze::setMaze_EndPosition_X( int x ){
    endPoint_X = x;
}

void Maze::setMaze_EndPosition_Y( int y ){
    endPoint_Y = y;
}

int Maze::getMaze_EndPosition_X(){
    return endPoint_X;
}

int Maze::getMaze_EndPosition_Y(){
    return endPoint_Y;
}

int Maze::checkMapPosition(int x, int y){
     if( ( x >= 0 && y >= 0 ) &&  ( x < getMazeSize_X() && y < getMazeSize_Y() )  ){
        if(  outside[y][x] == 1 ){
            return 1;
        }else{
            return 0;
        }
    }else{
        cout << "Error CheckPosition: OUT OF BOUNDS" << endl;
        //system("PAUSE");
        return 0;
    }
}

void Maze::remaze(char oldMaze[], char newMaze[]){
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

void Maze::loadMaze(char maze[]){
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
}

void Maze::storeMazeData(int data[], int dataSize){
        int y, i, c = 0;
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


 void Maze::displayMazeOnly(){
     int i, j;
    //Displaying selected maze.
    cout << "@-";
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
        cout << rpc << "-";
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
 }


void Maze::displayMazeOnly( int classifiedAs, int x, int y ){
     int i, j;
     char cP;                   //Classified Position Marker.
     if( classifiedAs == 0 ){
        cP = 'A';                 //Agent Position.
     }else{
         cP = 'X';                //End Position.
     }
    //Displaying selected maze.
    cout << "@-";
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
        cout << rpc << "-";
        rpc++;
        for(j = 0; j < yM;j++){

            if(outside[i][j] == 1){
                if( j == x && i == y ){
                    cout << cP;
                }else{
                    cout << " ";
                }

            }else{
                cout << outside[i][j];
            }
        }
        cout << endl;
    }
}


void Maze::displayMazeOnly(int sX, int sY, int eX, int eY){
     int i, j;
     char sP = 'A'; // Agent start point.
     char eP = 'X'; // End Point.


    //Displaying selected maze.
    cout << "@-";
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
        cout << rpc << "-";
        rpc++;
        for(j = 0; j < yM;j++){

            if(outside[i][j] == 1){
                if( j == sX && i == sY ){
                    cout << sP;
                }else if( j == eX && i == eY ){
                    cout << eP;
                }else{
                    cout << " ";
                }

            }else{
                cout << outside[i][j];
            }
        }
        cout << endl;
    }
}
