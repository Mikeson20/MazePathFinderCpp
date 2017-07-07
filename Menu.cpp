/**
	Menu.cpp
	Menu display and content
	@author Michael Henderson
	@version 1.0
*/
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

char * Menu::chooseMaze(){
    int menuClose = 0;
    int inC;
    do{
        cout << "Choose Maze" << endl;
        cout << "Maze 1 enter: 1" << endl;
        cout << "Maze 2 enter: 2" << endl;
        cout << "Maze 3 enter: 3" << endl;
        cout << "S: ";
        cin >> inC;
        if(inC == 1){
            menuClose = 1;
            //m = "Maze/maze01.txt";
            //return "Maze/maze01.txt";
            return "maze01.txt";
        }else if(inC == 2){
            menuClose = 1;
            //m = "Maze/maze02.txt";
            //return "Maze/maze02.txt";
            return "maze02.txt";
        }else if(inC == 3){
            //menuClose = 1;
            //m = "Maze/maze03.txt";
            //return "Maze/maze03.txt";
            return "maze03.txt";
        }else{
            cout << "*** Bad Selection ***" << endl;
        }
    }while(menuClose == 0);
    //return mazeIs;
}

int * Menu::chooseStartPosition( int *sp, int size_X, int size_Y ){
    int menuClose = 0;
    int inC;

    do{
        cout << "Choose Start Position. NOTE: add a 1 if > first 9" << endl;
        cout << "X: ";
        cin >> inC;
        sp[0] = inC;
        cout << "Y: ";
        cin >> inC;
        sp[1] = inC;
        if( (sp[0] < 0) || (sp[0] > size_X) || (sp[1] < 0) || (sp[1] > size_Y) ){
            cout << "*** Bad Selection ***" << endl;
            cout << "*** Out of Bounds ***" << endl;
        }else{
            menuClose = 1;
        }
    }while(menuClose == 0);
    return sp;
}

int * Menu::chooseEndPosition( int *sp, int *ep, int size_X, int size_Y ){
    int menuClose = 0;
    int inC;

    do{
        cout << "Choose End Position. NOTE: add a 1 if > first 9" << endl;
        cout << "X: ";
        cin >> inC;
        ep[0] = inC;
        cout << "Y: ";
        cin >> inC;
        ep[1] = inC;

        if( (ep[0] < 0) || (ep[0] > size_X) || (ep[1] < 0) || (ep[1] > size_Y) ){
            cout << "*** Bad Selection ***" << endl;
            cout << "*** Out of Bounds ***" << endl;
        }else if( ep[0] == sp[0] && ep[1] == sp[1] ){
            cout << "*** Bad Selection ***" << endl;
            cout << "End points same as start points." << endl;
        }else{
            menuClose = 1;
        }
    }while(menuClose == 0);
    return sp;
}
