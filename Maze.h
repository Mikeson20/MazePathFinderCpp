/**
	Maze.h
	Contains every thing to do with maze / map. No special comments.
	@author Michael Henderson
	@version 1.0
*/
#ifndef MAZE_H
#define MAZE_H


class Maze
{
    public:
        /**
        Constructor allocate_outside = 0; row = 0;
        @author Michael Henderson
        @version 1.0
        */
        Maze();

        /**
        Deconstructor free's "outside - really to rename" memory.
        @author Michael Henderson
        @version 1.0
        */
        virtual ~Maze();

        /**
        Was used to reproccess a maze text file/s.
        @author Michael Henderson
        @version 1.0
        @param char[] Name of maze text file.
        @param char[] Name of the new maze text file.
        */
        void remaze(char [], char[]);

        /**
        Opens the text file containing the maze, reads it and passes in onto
        storeMazeData(int [],int);
        @author Michael Henderson
        @version 1.0
        @param char[] Name of maze text file.
        */
        void loadMaze(char []);

        /**
        Allocates memory and stores the data one row at a time that is read
        from file and maybe console.
        @author Michael Henderson
        @version 1.0
        @param int[] data - The row of data to be stored.
        @param int  dataSize.
        */
        void storeMazeData(int [],int);

        /**
        Prints maze to console.
        @author Michael Henderson
        @version 1.0
        */
        void displayMazeOnly();

        /**
        Overloaded to show maze, agent "A" start point or end "X" point.
        TODO: Check to see if position on maze wall.
        TODO: X and Y seem to be wrong way around.
        @author Michael Henderson
        @version 1.0
        @param int: 0 - Agent, 1 - End point.
        @param int: X coordinate.
        @param int: Y coordinate.
        */
        void displayMazeOnly(int, int, int);

        /**
        Overloaded to show maze, agent "A" start point and end "X" point.
        TODO: Check to see if position on maze wall.
        TODO: X and Y seem to be wrong way around.
        @author Michael Henderson
        @version 1.0
        @param int* To store start position.
        @param int: X start - position Agent
        @param int: Y start - position Agent
        @param int: X end - position Target
        @param int: Y end - position Target
        */
        void displayMazeOnly(int, int, int, int);

        /**
        Checks whether the coordinates are "valid", out of bounds and not an
        object( "object" expanded later maybe :-).
        @author Michael Henderson
        @version 1.0
        @param int  X position
        @param int  Y position
        @return int 1 - go, 0 - no go
        */
        int checkMapPosition(int, int);

        /**
        Gets the maximum X coordinate / width of maze.
        @author Michael Henderson
        @version 1.0
        @return int xM
        */
        int getMazeSize_X();

        /**
        Gets the maximum Y coordinate / width of maze.
        @author Michael Henderson
        @version 1.0
        @return int yM
        */
        int getMazeSize_Y();

        /**
        Sets the X coordinate of maze to target/find/tressure.
        @author Michael Henderson
        @version 1.0
        @param int X position
        */
        void setMaze_EndPosition_X(int);

        /**
        Sets the Y coordinate of maze to target/find/tressure.
        @author Michael Henderson
        @version 1.0
        @param int Y position
        */
        void setMaze_EndPosition_Y(int);

        /**
        Gets the X coordinate of maze to target/find/tressure.
        @author Michael Henderson
        @version 1.0
        @return int* endPoint_X
        */
        int getMaze_EndPosition_X();

        /**
        Gets the Y coordinate of maze to target/find/tressure.
        @author Michael Henderson
        @version 1.0
        @return int* endPoint_Y
        */
        int getMaze_EndPosition_Y();

        int **outside;              //The storage for the maze. Could be private, though should be protected..
    protected:

    private:

        int allocate_outside;   //To store if memory was allocated for the maze.
        int row;                //To keep track which row is to be inserted into storage / memory.
        int xM;                     //The largest X coordinate of maze.
        int yM;                     //The largest Y coordinate of maze.
        int endPoint_X;             //The X coordinate of maze to target/find/tressure.
        int endPoint_Y;             //The Y coordinate of maze to target/find/tressure.
};

#endif // MAZE_H
