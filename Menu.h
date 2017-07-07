/**
	Menu.h
	Menu display and content
	@author Michael Henderson
	@version 1.0
*/
#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();

         /**
        Selection of available mazes.
        @author Michael Henderson
        @version 1.0
        */
        char * chooseMaze();

        /**
        Menu to enter start position in maze.
        TODO: Check to see if position on maze wall.
        TODO: X and Y seem to be wrong way around.
        @author Michael Henderson
        @version 1.0
        @param int* To store start position.
        @param int  X position
        @param int  Y position
        @return int* start position
        */
        int * chooseStartPosition( int*, int, int );

        /**
        Menu to enter end position in maze.
        TODO: Check to see if position on maze wall.
        TODO: X and Y seem to be wrong way around.
        @author Michael Henderson
        @version 1.0
        @param int* Start position.
        @param int* To store end position
        @param int  X position
        @param int  Y position
        @return int* end position
        @author Michael Henderson
        @version 1.0
        */
        int * chooseEndPosition( int*, int*, int, int );

    protected:

    private:
};

#endif // MENU_H
