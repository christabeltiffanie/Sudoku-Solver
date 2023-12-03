#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//CONSTANT VARIABLES
const int ROWS = 9;
const int COLS = 9; //9x9 block
const int NUMOFQUADRANTS = 9;
/*
TopLeftQuad (0)
TopCenterQuad (1)
TopRightQuad (2)
MidLeftQuad (3)
MidCenterQuad (4)
MidRightQuad (5)
BotLeftQuad (6)
BotCenterQuad (7)
BotRightQuad (8)

Total 9 Quadrants
*/

//Scanned Bools
bool scannedTopLeftQuad = false;
bool scannedTopCenterQuad = false;
bool scannedTopRightQuad = false;
bool scannedMidLeftQuad = false;
bool scannedMidCenterQuad = false;
bool scannedMidRightQuad = false;
bool scannedBotLeftQuad = false;
bool scannedBotCenterQuad = false;
bool scannedBotRightQuad = false;

bool scannedRow1 = false;
bool scannedRow2 = false;
bool scannedRow3 = false;
bool scannedRow4 = false;
bool scannedRow5 = false;
bool scannedRow6 = false;
bool scannedRow7 = false;
bool scannedRow8 = false;
bool scannedRow9 = false;

bool scannedCol1 = false;
bool scannedCol2 = false;
bool scannedCol3 = false;
bool scannedCol4 = false;
bool scannedCol5 = false;
bool scannedCol6 = false;
bool scannedCol7 = false;
bool scannedCol8 = false;
bool scannedCol9 = false;

bool scannedTopQuads = false; 
bool scannedMidQuads = false;
bool scannedBotQuads = false;
bool scannedLeftQuads = false;
bool scannedCenterQuads = false;
bool scannedRightQuads = false;

bool scannedTopLeftQuadForSingleDigit = false;
bool scannedTopCenterQuadForSingleDigit = false;
bool scannedTopRightQuadForSingleDigit = false;
bool scannedMidLeftQuadForSingleDigit = false;
bool scannedMidCenterQuadForSingleDigit = false;
bool scannedMidRightQuadForSingleDigit = false;
bool scannedBotLeftQuadForSingleDigit = false;
bool scannedBotCenterQuadForSingleDigit = false;
bool scannedBotRightQuadForSingleDigit = false;

bool scannedTopCenterAndTopRightForSameDigit = false;
bool scannedTopLeftAndTopRightForSameDigit = false;
bool scannedTopLeftAndTopCenterForSameDigit = false;
bool scannedMidCenterAndMidRightForSameDigit = false;
bool scannedMidLeftandMidRightForSameDigit = false;
bool scannedMidLeftAndMidCenterForSameDigit = false;
bool scannedBotCenterAndBotRightForSameDigit = false;
bool scannedBotLeftAndBotRightForSameDigit = false; 
bool scannedBotLeftAndBotCenterForSameDigit = false;

bool scannedMidLeftandBotLeftForSameDigit = false;
bool scannedTopLeftAndBotLeftForSameDigit = false;
bool scannedTopLeftAndMidLeftForSameDigit = false; 
bool scannedMidCenterAndBotCenterForSameDigit = false; 
bool scannedTopCenterAndBotCenterForSameDigit = false; 
bool scannedTopCenterAndMidCenterForSameDigit = false; 
bool scannedMidRightAndBotRightForSameDigit = false; 
bool scannedTopRightAndBotRightForSameDigit = false; 
bool scannedTopRightAndMidRightForSameDigit = false;

bool scannedTopRow = false; 
bool scannedMidRow = false; 
bool scannedBotRow = false; 

bool scannedLeftCol = false; 
bool scannedCenterCol = false; 
bool scannedRightCol = false; 

//Puzzle (given)
int puzzleInt[ROWS][COLS]{
	{5,3,4,0,7,0,9,1,2},
	{6,0,0,1,9,5,0,0,8},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,4},
	{2,8,7,4,1,9,0,0,5},
	{3,4,5,0,8,0,0,7,9}
};
//0 = Blanks

//Cross Hatch Array - responsible for eliminating the rows/cols to input the numbers.
int arrCrossHatch[ROWS][COLS] = {
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1}
};

//Temp Quadrant Arrays
int crossHatchQuad[3][3] = {
	{1,1,1},
	{1,1,1},
	{1,1,1}
};

int quadrantTopLeft[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantTopCenter[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantTopRight[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantMidLeft[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantMidCenter[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantMidRight[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantBotLeft[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantBotCenter[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int quadrantBotRight[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

enum quadrantLocation 
{
	TOPLEFTQUAD, TOPCENTERQUAD, TOPRIGHTQUAD,
	MIDLEFTQUAD, MIDCENTERQUAD, MIDRIGHTQUAD,
	BOTLEFTQUAD, BOTCENTERQUAD, BOTRIGHTQUAD
};

enum rowLocation {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8, ROW9};
enum colLocation {COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8, COL9};
 
int numsUsedArr[9] = { 0,0,0,0,0,0,0,0,0 };

//Functions:
void displaySudokuPuzzle(); //display the contents of the array
bool foundIntInQuadrant(int keyToSearch, int quadrantID);
bool foundIntInRow(int keyToSearch, int rowIndex);
bool foundIntInCol(int keyToSearch, int colIndex);
bool isPuzzleComplete();
int rowIndexOfKeyInQuadrant(int key, int quadrantID);
int colIndexofKeyQuadrant(int key, int quadrantID);
void createCrossHatchedQuadrant(int key, int quadrantToBeCrossHatchedID);
bool doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable();
void fillInSingleRemainingSquareInQuad(int quadrantToFillID);
void fillInFreeCrossHatchedSquareInQuad(int key, int quadrantToFillID);
void fillInQuadrants();
void setScannedFlagsToFalse();
void updatePuzzleInts();
bool isASingleZeroInThisQuad(int quadrantID);
bool isASingleZeroInThisRow(int rowIndex);
bool isASingleZeroInThisCol(int colIndex);
int colIndexOfKeyInThisRow(int key, int rowIndex);
int rowIndexOfKeyInThisCol(int key, int colIndex);
int whatSingleNumIsMissingInThisRow(int rowIndex);
int whatSingleNumIsMissingInThisCol(int colIndex);
void fillInSingleSquareInRow(int rowIndex);
void fillInSingleSquareInCol(int colIndex);
int findAvailableColInCrossHatchQuad();
int findAvailablRowInCrossHatchQuad();

int main() 
{
	//Declarations:
	int rowQuadrant = 0;
	int colQuadrant = 0;
	int numBeingInvestigated = 1; 
	int numOfEmptySquares = 0;
	int numNotBeingUsed = 0;
	bool puzzleSolved = false; 
	bool isOneSquareLeft = false;

	//Display the Sudoku Puzzle: 
	cout << "Original Sudoku Puzzle" << endl;
	cout << "*******************" << endl;
	displaySudokuPuzzle();

	//Solve the puzzle
	rowQuadrant = 1; 
	colQuadrant = 1; 
	fillInQuadrants();

	while (puzzleSolved == false)
	{
		//Check every numbed from 1-9 to see if two quadrants have it. 
		int intCnt = 1;
		int cntCycles = 0;
		bool haveCycledThroughAllRowsAndCols = false;

		while (intCnt < 10)
		{
			if (intCnt == 1)
				cout <<  "";
			else if (intCnt == 2)
				cout <<  "";
			else if (intCnt == 3)
				cout <<  "";
			else if (intCnt == 4)
				cout <<  "";
			else if (intCnt == 5)
				cout <<  "";
			else if (intCnt == 6)
				cout <<  "";
			else if (intCnt == 7)
				cout <<  "";
			else if (intCnt == 8)
				cout <<  "";
			else if (intCnt == 9)
				cout <<  "";

			//scan all individual rows
			if (scannedRow1 == false)
			{
				scannedRow1 = true; 
				if (isASingleZeroInThisRow(ROW1) == true)
					fillInSingleSquareInRow(ROW1);
			}
			else if (scannedRow2 == false)
			{
				scannedRow2 = true;
				if (isASingleZeroInThisRow(ROW2) == true)
					fillInSingleSquareInRow(ROW2);
			}
			else if (scannedRow3 == false)
			{
				scannedRow3 = true;
				if (isASingleZeroInThisRow(ROW3) == true)
					fillInSingleSquareInRow(ROW3);
			}
			else if (scannedRow4 == false)
			{
				scannedRow4 = true;
				if (isASingleZeroInThisRow(ROW4) == true)
					fillInSingleSquareInRow(ROW4);
			}
			else if (scannedRow5 == false)
			{
				scannedRow5 = true;
				if (isASingleZeroInThisRow(ROW5) == true)
					fillInSingleSquareInRow(ROW5);
			}
			else if (scannedRow6 == false)
			{
				scannedRow6 = true;
				if (isASingleZeroInThisRow(ROW6) == true)
					fillInSingleSquareInRow(ROW6);
			}
			else if (scannedRow7 == false)
			{
				scannedRow7 = true;
				if (isASingleZeroInThisRow(ROW7) == true)
					fillInSingleSquareInRow(ROW7);
			}
			else if (scannedRow8 == false)
			{
				scannedRow8 = true;
				if (isASingleZeroInThisRow(ROW8) == true)
					fillInSingleSquareInRow(ROW8);
			}
			else if (scannedRow9 == false)
			{
				scannedRow9 = true;
				if (isASingleZeroInThisRow(ROW9) == true)
					fillInSingleSquareInRow(ROW9);
			}

			//Scan all Individual Columns
			else if (scannedCol1 == false)
			{
				scannedCol1 = true;
				if (isASingleZeroInThisCol(COL1) == true)
					fillInSingleSquareInCol(COL1);
			}
			else if (scannedCol2 == false)
			{
				scannedCol2 = true;
				if (isASingleZeroInThisCol(COL2) == true)
					fillInSingleSquareInCol(COL2);
			}
			else if (scannedCol3 == false)
			{
				scannedCol3 = true;
				if (isASingleZeroInThisCol(COL3) == true)
					fillInSingleSquareInCol(COL3);
			}
			else if (scannedCol4 == false)
			{
				scannedCol4 = true;
				if (isASingleZeroInThisCol(COL4) == true)
					fillInSingleSquareInCol(COL4);
			}
			else if (scannedCol5 == false)
			{
				scannedCol5 = true;
				if (isASingleZeroInThisCol(COL5) == true)
					fillInSingleSquareInCol(COL5);
			}
			else if (scannedCol6 == false)
			{
				scannedCol6 = true;
				if (isASingleZeroInThisCol(COL6) == true)
					fillInSingleSquareInCol(COL6);
			}
			else if (scannedCol7 == false)
			{
				scannedCol7 = true;
				if (isASingleZeroInThisCol(COL7) == true)
					fillInSingleSquareInCol(COL7);
			}
			else if (scannedCol8 == false)
			{
				scannedCol8 = true;
				if (isASingleZeroInThisCol(COL8) == true)
					fillInSingleSquareInCol(COL8);
			}
			else if (scannedCol9 == false)
			{
				scannedCol9 = true;
				if (isASingleZeroInThisCol(COL9) == true)
					fillInSingleSquareInCol(COL9);
			}

			//Scann all quadrants for a single missing number
			else if (scannedTopLeftQuadForSingleDigit == false) 
			{
				scannedTopLeftQuadForSingleDigit = true; 
				if (isASingleZeroInThisQuad(TOPLEFTQUAD) == true) 
				{
					fillInSingleRemainingSquareInQuad(TOPLEFTQUAD);
				}
			}
			else if (scannedTopCenterQuadForSingleDigit == false)
			{
				scannedTopCenterQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(TOPCENTERQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(TOPCENTERQUAD);
				}
			}
			else if (scannedTopRightQuadForSingleDigit == false)
			{
				scannedTopRightQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(TOPRIGHTQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(TOPRIGHTQUAD);
				}
			}
			else if (scannedMidLeftQuadForSingleDigit == false)
			{
				scannedMidLeftQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(MIDLEFTQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(MIDLEFTQUAD);
				}
			}
			else if (scannedMidCenterQuadForSingleDigit == false)
			{
				scannedMidCenterQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(MIDCENTERQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(MIDCENTERQUAD);
				}
			}
			else if (scannedMidRightQuadForSingleDigit == false)
			{
				scannedMidRightQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(MIDRIGHTQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(MIDRIGHTQUAD);
				}
			}
			else if (scannedBotLeftQuadForSingleDigit == false)
			{
				scannedBotLeftQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(BOTLEFTQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(BOTLEFTQUAD);
				}
			}
			else if (scannedBotCenterQuadForSingleDigit == false)
			{
				scannedBotCenterQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(BOTCENTERQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(BOTCENTERQUAD);
				}
			}
			else if (scannedBotRightQuadForSingleDigit == false)
			{
				scannedBotRightQuadForSingleDigit = true;
				if (isASingleZeroInThisQuad(BOTRIGHTQUAD) == true)
				{
					fillInSingleRemainingSquareInQuad(BOTRIGHTQUAD);
				}
			}
			
			//Scan all row quadrants for the same number in each quadrant
			else if (scannedTopQuads == false) 
			{
				scannedTopQuads = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, TOPCENTERQUAD) && foundIntInQuadrant(intCnt, TOPRIGHTQUAD))
				{
					//Do nothing
				}
			}
			else if (scannedMidQuads == false)
			{
				scannedMidQuads = true;
				if (foundIntInQuadrant(intCnt, MIDLEFTQUAD) && foundIntInQuadrant(intCnt, MIDCENTERQUAD) && foundIntInQuadrant(intCnt, MIDRIGHTQUAD))
				{
					//Do nothing
				}
			}
			else if (scannedBotQuads == false)
			{
				scannedBotQuads = true;
				if (foundIntInQuadrant(intCnt, BOTLEFTQUAD) && foundIntInQuadrant(intCnt, BOTCENTERQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD))
				{
					//Do nothing
				}
			}

			//Scan all Col quads for the same number in each quadrant
			else if (scannedLeftCol == false)
			{
				scannedLeftCol = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, MIDLEFTQUAD) && foundIntInQuadrant(intCnt, BOTLEFTQUAD))
				{
					//Do Nothing
				}
			}
			else if (scannedCenterCol == false)
			{
				scannedCenterCol = true;
				if (foundIntInQuadrant(intCnt, TOPCENTERQUAD) && foundIntInQuadrant(intCnt, MIDCENTERQUAD) && foundIntInQuadrant(intCnt, BOTCENTERQUAD))
				{
					//Do Nothing
				}
			}
			else if (scannedRightCol == false)
			{
				scannedRightCol = true;
				if (foundIntInQuadrant(intCnt, TOPRIGHTQUAD) && foundIntInQuadrant(intCnt, MIDRIGHTQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD))
				{
					//Do Nothing
				}
			}

			//Scan top horizontal quadrants
			else if (scannedTopCenterAndTopRightForSameDigit == false)
			{
				scannedTopCenterAndTopRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPCENTERQUAD) && foundIntInQuadrant(intCnt, TOPRIGHTQUAD) && (foundIntInQuadrant(intCnt, TOPLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPLEFTQUAD);
					}
				}
			}
			else if (scannedTopLeftAndTopRightForSameDigit == false)
			{
				scannedTopLeftAndTopRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, TOPRIGHTQUAD) && (foundIntInQuadrant(intCnt, TOPCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPCENTERQUAD);
					}
				}
			}
			else if (scannedTopLeftAndTopCenterForSameDigit == false)
			{
				scannedTopLeftAndTopCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, TOPCENTERQUAD) && (foundIntInQuadrant(intCnt, TOPRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPRIGHTQUAD);
					}
				}
			}

			//Scan middle horizontal quadrants for same number in two quadrants
			else if (scannedMidCenterAndMidRightForSameDigit == false)
			{
				scannedMidCenterAndMidRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDCENTERQUAD) && foundIntInQuadrant(intCnt, MIDRIGHTQUAD) && (foundIntInQuadrant(intCnt, MIDLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDLEFTQUAD);
					}
				}
			}
			else if (scannedMidLeftandMidRightForSameDigit == false)
			{
				scannedMidLeftandMidRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDLEFTQUAD) && foundIntInQuadrant(intCnt, MIDRIGHTQUAD) && (foundIntInQuadrant(intCnt, MIDCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDCENTERQUAD);
					}
				}
			}
			else if (scannedMidLeftAndMidCenterForSameDigit == false)
			{
				scannedMidLeftAndMidCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDLEFTQUAD) && foundIntInQuadrant(intCnt, MIDCENTERQUAD) && (foundIntInQuadrant(intCnt, MIDRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDRIGHTQUAD);
					}
				}
			}
			
			//Scan all bottom horizontal quadrants
			else if (scannedBotCenterAndBotRightForSameDigit == false)
			{
				scannedBotCenterAndBotRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, BOTCENTERQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD) && (foundIntInQuadrant(intCnt, BOTLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTLEFTQUAD);
					}
				}
			}
			else if (scannedBotLeftAndBotRightForSameDigit == false)
			{
				scannedBotLeftAndBotRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, BOTLEFTQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD) && (foundIntInQuadrant(intCnt, BOTCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTCENTERQUAD);
					}
				}
			}
			else if (scannedBotLeftAndBotCenterForSameDigit == false)
			{
				scannedBotLeftAndBotCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, BOTLEFTQUAD) && foundIntInQuadrant(intCnt, BOTCENTERQUAD) && (foundIntInQuadrant(intCnt, BOTRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTRIGHTQUAD);
					}
				}
			}
			//Scan all left vertical quadrants
			else if (scannedMidLeftandBotLeftForSameDigit == false)
			{
				scannedMidLeftandBotLeftForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDLEFTQUAD) && foundIntInQuadrant(intCnt, BOTLEFTQUAD) && (foundIntInQuadrant(intCnt, TOPLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPLEFTQUAD);
					}
				}
			}
			else if (scannedTopLeftAndBotLeftForSameDigit == false)
			{
				scannedTopLeftAndBotLeftForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, BOTLEFTQUAD) && (foundIntInQuadrant(intCnt, MIDLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDLEFTQUAD);
					}
				}
			}
			else if (scannedTopLeftAndMidLeftForSameDigit == false)
			{
				scannedTopLeftAndMidLeftForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPLEFTQUAD) && foundIntInQuadrant(intCnt, MIDLEFTQUAD) && (foundIntInQuadrant(intCnt, BOTLEFTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTLEFTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTLEFTQUAD);
					}
				}
			}
			//Scan all center vertical quads
			else if (scannedMidCenterAndBotCenterForSameDigit == false)
			{
				scannedMidCenterAndBotCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDCENTERQUAD) && foundIntInQuadrant(intCnt, BOTCENTERQUAD) && (foundIntInQuadrant(intCnt, TOPCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPCENTERQUAD);
					}
				}
			}
			else if (scannedTopCenterAndBotCenterForSameDigit == false)
			{
				scannedTopCenterAndBotCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPCENTERQUAD) && foundIntInQuadrant(intCnt, BOTCENTERQUAD) && (foundIntInQuadrant(intCnt, MIDCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDCENTERQUAD);
					}
				}
			}
			else if (scannedTopCenterAndMidCenterForSameDigit == false)
			{
				scannedTopCenterAndMidCenterForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPCENTERQUAD) && foundIntInQuadrant(intCnt, MIDCENTERQUAD) && (foundIntInQuadrant(intCnt, BOTCENTERQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTCENTERQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTCENTERQUAD);
					}
				}
			}
			//Scan All Right Vertical Quads
			else if (scannedMidRightAndBotRightForSameDigit == false)
			{
				scannedMidRightAndBotRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, MIDRIGHTQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD) && (foundIntInQuadrant(intCnt, TOPRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, TOPRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, TOPRIGHTQUAD);
					}
				}
			}
			else if (scannedTopRightAndBotRightForSameDigit == false)
			{
				scannedTopRightAndBotRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPRIGHTQUAD) && foundIntInQuadrant(intCnt, BOTRIGHTQUAD) && (foundIntInQuadrant(intCnt, MIDRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, MIDRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, MIDRIGHTQUAD);
					}
				}
			}
			else if (scannedTopRightAndMidRightForSameDigit == false)
			{
				scannedTopRightAndMidRightForSameDigit = true;
				if (foundIntInQuadrant(intCnt, TOPRIGHTQUAD) && foundIntInQuadrant(intCnt, MIDRIGHTQUAD) && (foundIntInQuadrant(intCnt, BOTRIGHTQUAD) == false))
				{
					createCrossHatchedQuadrant(intCnt, BOTRIGHTQUAD);
					if (doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable() == true)
					{
						fillInFreeCrossHatchedSquareInQuad(intCnt, BOTRIGHTQUAD);
					}
				}
			}

			if (scannedRow1 == true
				&& scannedRow2 == true
				&& scannedRow3 == true
				&& scannedRow4 == true
				&& scannedRow5 == true
				&& scannedRow6 == true
				&& scannedRow7 == true
				&& scannedRow8 == true
				&& scannedRow9 == true
				&& scannedCol1 == true
				&& scannedCol2 == true
				&& scannedCol3 == true
				&& scannedCol4 == true
				&& scannedCol5 == true
				&& scannedCol6 == true
				&& scannedCol7 == true
				&& scannedCol8 == true
				&& scannedCol9 == true
				&& scannedTopLeftQuadForSingleDigit == true
				&& scannedTopCenterQuadForSingleDigit == true
				&& scannedTopRightQuadForSingleDigit == true
				&& scannedMidLeftQuadForSingleDigit == true
				&& scannedMidCenterQuadForSingleDigit == true
				&& scannedMidRightQuadForSingleDigit == true
				&& scannedBotLeftQuadForSingleDigit == true
				&& scannedBotCenterQuadForSingleDigit == true
				&& scannedBotRightQuadForSingleDigit == true
				&& scannedTopQuads == true
				&& scannedMidQuads == true
				&& scannedBotQuads == true
				&& scannedLeftCol == true
				&& scannedCenterCol == true
				&& scannedRightCol == true
				&& scannedTopCenterAndTopRightForSameDigit == true
				&& scannedTopLeftAndTopRightForSameDigit == true
				&& scannedTopLeftAndTopCenterForSameDigit == true
				&& scannedMidCenterAndMidRightForSameDigit == true
				&& scannedMidLeftandMidRightForSameDigit == true
				&& scannedMidLeftAndMidCenterForSameDigit == true
				&& scannedBotCenterAndBotRightForSameDigit == true
				&& scannedBotLeftAndBotRightForSameDigit == true
				&& scannedBotLeftAndBotCenterForSameDigit == true
				&& scannedMidLeftandBotLeftForSameDigit == true
				&& scannedTopLeftAndBotLeftForSameDigit == true
				&& scannedTopLeftAndMidLeftForSameDigit == true
				&& scannedMidCenterAndBotCenterForSameDigit == true
				&& scannedTopCenterAndBotCenterForSameDigit == true
				&& scannedTopCenterAndMidCenterForSameDigit == true
				&& scannedMidRightAndBotRightForSameDigit == true
				&& scannedTopRightAndBotRightForSameDigit == true
				&& scannedTopRightAndMidRightForSameDigit == true)
			{
				intCnt += 1;
				scannedRow1 = false;
				scannedRow2 = false;
				scannedRow3 = false;
				scannedRow4 = false;
				scannedRow5 = false;
				scannedRow6 = false;
				scannedRow7 = false;
				scannedRow8 = false;
				scannedRow9 = false;

				scannedCol1 = false;
				scannedCol2 = false;
				scannedCol3 = false;
				scannedCol4 = false;
				scannedCol5 = false;
				scannedCol6 = false;
				scannedCol7 = false;
				scannedCol8 = false;
				scannedCol9 = false;

				scannedTopLeftQuad = false;
				scannedTopCenterQuad = false;
				scannedTopRightQuad = false;
				scannedMidLeftQuad = false;
				scannedMidCenterQuad = false;
				scannedMidRightQuad = false;
				scannedBotLeftQuad = false;
				scannedBotCenterQuad = false;
				scannedBotRightQuad = false;

				scannedTopLeftQuadForSingleDigit = false;
				scannedTopCenterQuadForSingleDigit = false;
				scannedTopRightQuadForSingleDigit = false;
				scannedMidLeftQuadForSingleDigit = false;
				scannedMidCenterQuadForSingleDigit = false;
				scannedMidRightQuadForSingleDigit = false;
				scannedBotLeftQuadForSingleDigit = false;
				scannedBotCenterQuadForSingleDigit = false;
				scannedBotRightQuadForSingleDigit = false;

				scannedTopCenterAndTopRightForSameDigit = false;
				scannedTopLeftAndTopRightForSameDigit = false;
				scannedTopLeftAndTopCenterForSameDigit = false;
				scannedMidCenterAndMidRightForSameDigit = false;
				scannedMidLeftandMidRightForSameDigit = false;
				scannedMidLeftAndMidCenterForSameDigit = false;
				scannedBotCenterAndBotRightForSameDigit = false;
				scannedBotLeftAndBotRightForSameDigit = false;
				scannedBotLeftAndBotCenterForSameDigit = false;

				scannedMidLeftandBotLeftForSameDigit = false;
				scannedTopLeftAndBotLeftForSameDigit = false;
				scannedTopLeftAndMidLeftForSameDigit = false;
				scannedMidCenterAndBotCenterForSameDigit = false;
				scannedTopCenterAndBotCenterForSameDigit = false;
				scannedTopCenterAndMidCenterForSameDigit = false;
				scannedMidRightAndBotRightForSameDigit = false;
				scannedTopRightAndBotRightForSameDigit = false;
				scannedTopRightAndMidRightForSameDigit = false;

				scannedLeftQuads = false;
				scannedCenterQuads = false;
				scannedBotQuads = false;

				scannedTopRow = false;
				scannedMidRow = false;
				scannedBotRow = false;

				scannedLeftCol = false;
				scannedCenterCol = false;
				scannedRightCol = false;
			}//end of if
		}//end of while(intCnt <10)
		
		//Check if puzzle if solved
		if (isPuzzleComplete() == true)
		{
			puzzleSolved = true;
		}
		else
			puzzleSolved = false;
	}//while(puzzleSolved == false)

	//Display solved Puzzle
	cout << endl;
	cout << "Solved puzzle: " << endl;
	cout << "*******************" << endl;
	displaySudokuPuzzle();

	return 0;
}

void displaySudokuPuzzle()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << "|";
			if (puzzleInt[i][j] == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << puzzleInt[i][j] << " ";
			}

			if (puzzleInt[i][j + 1] == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << puzzleInt[i][j + 1] << " ";
			}
			if (puzzleInt[i][j + 2] == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << puzzleInt[i][j + 2];
			}

		} //j loop

		cout << "|" << endl;

		if (i == 2 || i == 5 || i == 8) //draw below after drawing 3 rows
		{
			cout << "*******************" << endl;
		}

	} //i loop
}

bool foundIntInQuadrant(int keyToSearch, int quadrantID) //Finding if the number exists in the quadrant
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3;  j++)
		{
			if (quadrantID == TOPLEFTQUAD)
			{
				if (quadrantTopLeft[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == TOPCENTERQUAD)
			{
				if (quadrantTopCenter[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == TOPRIGHTQUAD)
			{
				if (quadrantTopRight[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == MIDLEFTQUAD)
			{
				if (quadrantMidLeft[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == MIDCENTERQUAD)
			{
				if (quadrantMidCenter[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == MIDRIGHTQUAD)
			{
				if (quadrantMidRight[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == BOTLEFTQUAD)
			{
				if (quadrantBotLeft[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == BOTCENTERQUAD)
			{
				if (quadrantBotCenter[i][j] == keyToSearch)
					return true;
			}
			else if (quadrantID == BOTRIGHTQUAD)
			{
				if (quadrantBotRight[i][j] == keyToSearch)
					return true;
			}
		}
	}
	return false;
}

bool foundIntInRow(int keyToSearch, int rowIndex)
{
	for (int col = 0; col < COLS; col++)
	{
		if (puzzleInt[rowIndex][col] == keyToSearch)
			return true;
	}
	return false;
}

bool foundIntInCol(int keyToSearch, int colIndex)
{
	for (int row = 0; row < ROWS; row++)
	{
		if (puzzleInt[row][colIndex] == keyToSearch)
			return true;
	}
	return false;
}

bool isPuzzleComplete() 
{
	//Check all rows:
	for(int row = 0; row < ROWS; row++)
	{
		for (int key = 1; key <= 9; key++)
		{
			if (foundIntInRow(key, row) == false)
				return false;
		}
	}

	//Check all cols:
	for (int col = 0; col < COLS; col++)
	{
		for (int key = 1; key <= 9; key++)
		{
			if (foundIntInCol(key, col) == false)
				return false;
		}
	}
	return true;
}

int rowIndexOfKeyInQuadrant(int key, int quadrantID)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantID == TOPLEFTQUAD)
			{
				if (quadrantTopLeft[row][col] == key)
					return row;
			}
			else if (quadrantID == TOPCENTERQUAD)
			{
				if (quadrantTopCenter[row][col] == key)
					return row;
			}
			else if (quadrantID == TOPRIGHTQUAD)
			{
				if (quadrantTopRight[row][col] == key)
					return row;
			}
			else if (quadrantID == MIDLEFTQUAD)
			{
				if (quadrantMidLeft[row][col] == key)
					return row;
			}
			else if (quadrantID == MIDCENTERQUAD)
			{
				if (quadrantMidCenter[row][col] == key)
					return row;
			}
			else if (quadrantID == MIDRIGHTQUAD)
			{
				if (quadrantMidRight[row][col] == key)
					return row;
			}
			else if (quadrantID == BOTLEFTQUAD)
			{
				if (quadrantBotLeft[row][col] == key)
					return row;
			}
			else if (quadrantID == BOTCENTERQUAD)
			{
				if (quadrantBotCenter[row][col] == key)
					return row;
			}
			else if (quadrantID == BOTRIGHTQUAD)
			{
				if (quadrantBotRight[row][col] == key)
					return row;
			}
		}
	}
	return -1; //if key is not found. 
}

int colIndexofKeyQuadrant(int key, int quadrantID)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantID == TOPLEFTQUAD)
			{
				if (quadrantTopLeft[row][col] == key)
					return col;
			}
			else if (quadrantID == TOPCENTERQUAD)
			{
				if (quadrantTopCenter[row][col] == key)
					return col;
			}
			else if (quadrantID == TOPRIGHTQUAD)
			{
				if (quadrantTopRight[row][col] == key)
					return col;
			}
			else if (quadrantID == MIDLEFTQUAD)
			{
				if (quadrantMidLeft[row][col] == key)
					return col;
			}
			else if (quadrantID == MIDCENTERQUAD)
			{
				if (quadrantMidCenter[row][col] == key)
					return row;
			}
			else if (quadrantID == MIDRIGHTQUAD)
			{
				if (quadrantMidRight[row][col] == key)
					return col;
			}
			else if (quadrantID == BOTLEFTQUAD)
			{
				if (quadrantBotLeft[row][col] == key)
					return col;
			}
			else if (quadrantID == BOTCENTERQUAD)
			{
				if (quadrantBotCenter[row][col] == key)
					return col;
			}
			else if (quadrantID == BOTRIGHTQUAD)
			{
				if (quadrantBotRight[row][col] == key)
					return col;
			}
		}
	}
	return -1; //if key is not found. 
}

void createCrossHatchedQuadrant(int key, int quadrantToBeCrossHatchedID)
{
	//reset the crossHatchQuadrant
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			crossHatchQuad[row][col] = 1; //Every square with a 1 can be filled- filling the array with 1.
		}
	}	

	//go through the quadrant and cross hatch any square that has the number in that location
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantToBeCrossHatchedID == TOPLEFTQUAD)
			{
				if (quadrantTopLeft[row][col] > 0)
					crossHatchQuad[row][col] = 0; 
				//Placing a 0 in that position. 
			}
			else if (quadrantToBeCrossHatchedID == TOPCENTERQUAD)
			{
				if (quadrantTopCenter[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == TOPRIGHTQUAD)
			{
				if (quadrantTopRight[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == MIDLEFTQUAD)
			{
				if (quadrantMidLeft[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == MIDCENTERQUAD)
			{
				if (quadrantMidCenter[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == MIDRIGHTQUAD)
			{
				if (quadrantMidRight[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == BOTLEFTQUAD)
			{
				if (quadrantBotLeft[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == BOTCENTERQUAD)
			{
				if (quadrantBotCenter[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
			else if (quadrantToBeCrossHatchedID == BOTRIGHTQUAD)
			{
				if (quadrantBotRight[row][col] > 0)
					crossHatchQuad[row][col] = 0;
			}
		}
	}

	//Based on the numBeingInvestigated-  cross hatch any row and col with that number: 
	if (quadrantToBeCrossHatchedID == TOPLEFTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][2] = 0;
		}

		if (rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][2] = 0;
		}		

		if (colIndexofKeyQuadrant(key, MIDLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
		}

		if (colIndexofKeyQuadrant(key, BOTLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == TOPCENTERQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPRIGHTQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, MIDCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, BOTCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == TOPRIGHTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, TOPCENTERQUAD)][2] = 0;
		}

		if (colIndexofKeyQuadrant(key, MIDRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, BOTRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == MIDLEFTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, BOTLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTLEFTQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == MIDCENTERQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDRIGHTQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, BOTCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTCENTERQUAD)] = 0;
		}

	}
	else if (quadrantToBeCrossHatchedID == MIDRIGHTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, MIDCENTERQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, BOTRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, BOTRIGHTQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == BOTLEFTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPLEFTQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, MIDLEFTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDLEFTQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == BOTCENTERQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTRIGHTQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPCENTERQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, MIDCENTERQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDCENTERQUAD)] = 0;
		}
	}
	else if (quadrantToBeCrossHatchedID == BOTRIGHTQUAD)
	{
		if (rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTLEFTQUAD)][2] = 0;
		}
		if (rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD) != -1)
		{
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][0] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][1] = 0;
			crossHatchQuad[rowIndexOfKeyInQuadrant(key, BOTCENTERQUAD)][2] = 0;
		}
		if (colIndexofKeyQuadrant(key, TOPRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, TOPRIGHTQUAD)] = 0;
		}
		if (colIndexofKeyQuadrant(key, MIDRIGHTQUAD) != -1)
		{
			crossHatchQuad[0][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
			crossHatchQuad[1][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
			crossHatchQuad[2][colIndexofKeyQuadrant(key, MIDRIGHTQUAD)] = 0;
		}
	}
}

bool doesTheCrossHatchQuadrantHaveOnlyOneSpaceAvailable()
{
	int numOfEmptySquares = 0;
	//determine how many squares are empty
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (crossHatchQuad[row][col] == 1) //every square with 1, it can be filled
				numOfEmptySquares += 1;
		}
	}
	//return the appropriate answer
	if (numOfEmptySquares == 1)
		return true;
	else
		return false;
}

void fillInSingleRemainingSquareInQuad(int quadrantToFillID)
{
	//Create a temp quadrant to store the value of the quadrantToFillID
	const int ZERO = 0;
	int tempQuad[3][3];
	int numsAvailability[] = { 1,1,1,1,1,1,1,1,1 };
	int missingIntInQuad;

	//Fill in the temp quadrant
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantToFillID == TOPLEFTQUAD)
				tempQuad[row][col] = quadrantTopLeft[row][col];
			else if (quadrantToFillID == TOPCENTERQUAD)
				tempQuad[row][col] = quadrantTopCenter[row][col];
			else if (quadrantToFillID == TOPRIGHTQUAD)
				tempQuad[row][col] = quadrantTopRight[row][col];
			else if (quadrantToFillID == MIDLEFTQUAD)
				tempQuad[row][col] = quadrantMidLeft[row][col];
			else if (quadrantToFillID == MIDCENTERQUAD)
				tempQuad[row][col] = quadrantMidCenter[row][col];
			else if (quadrantToFillID == MIDRIGHTQUAD)
				tempQuad[row][col] = quadrantMidRight[row][col];
			else if (quadrantToFillID == BOTLEFTQUAD)
				tempQuad[row][col] = quadrantBotLeft[row][col];
			else if (quadrantToFillID == BOTCENTERQUAD)
				tempQuad[row][col] = quadrantBotCenter[row][col];
			else if (quadrantToFillID == BOTRIGHTQUAD)
				tempQuad[row][col] = quadrantBotRight[row][col];
		}
	}

	//Evaluate the avilability of all integers
	for (int myInts = 1; myInts < 10; myInts++)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				if (tempQuad[row][col] == myInts)
					numsAvailability[myInts - 1] = 0;
				//0=not available, 1= available
			}
		}
	}

	//assign the value for the missing integer
	for (int i = 0; i < 9; i++)
	{
		if (numsAvailability[i] == 1)
			missingIntInQuad = i + 1;
	}

	//Find the single square that is empty(i.e. equal to zero) and assign it the key value
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (tempQuad[row][col] == 0) //empty square
				tempQuad[row][col] = missingIntInQuad;
		}
	}

	//Update the destination quadrant with the tempQuad updated values
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantToFillID == TOPLEFTQUAD)
				quadrantTopLeft[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == TOPCENTERQUAD)
				quadrantTopCenter[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == TOPRIGHTQUAD)
				quadrantTopRight[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == MIDLEFTQUAD)
				quadrantMidLeft[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == MIDCENTERQUAD)
				quadrantMidCenter[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == MIDRIGHTQUAD)
				quadrantMidRight[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == BOTLEFTQUAD)
				quadrantBotLeft[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == BOTCENTERQUAD)
				quadrantBotCenter[row][col] = tempQuad[row][col];
			else if (quadrantToFillID == BOTRIGHTQUAD)
				quadrantBotRight[row][col] = tempQuad[row][col];
		}
	}

	//Update the main puzzleInts array with the new quadrant updates values
	updatePuzzleInts();
	fillInQuadrants();
	setScannedFlagsToFalse();
}

void fillInFreeCrossHatchedSquareInQuad(int key, int quadrantToFillID)
{
	//Fill in appropriate quadrant with the key value
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (crossHatchQuad[row][col] == 1)
			{
				if (quadrantToFillID == TOPLEFTQUAD)
					quadrantTopLeft[row][col] = key;
				else if (quadrantToFillID == TOPCENTERQUAD)
					quadrantTopCenter[row][col] = key;
				else if (quadrantToFillID == TOPRIGHTQUAD)
					quadrantTopRight[row][col] = key;
				
				else if (quadrantToFillID == MIDLEFTQUAD)
					quadrantMidLeft[row][col] = key;
				else if (quadrantToFillID == MIDCENTERQUAD)
					quadrantMidCenter[row][col] = key;
				else if (quadrantToFillID == MIDRIGHTQUAD)
					quadrantMidRight[row][col] = key;
				
				else if (quadrantToFillID == BOTLEFTQUAD)
					quadrantBotLeft[row][col] = key;
				else if (quadrantToFillID == BOTCENTERQUAD)
					quadrantBotCenter[row][col] = key;
				else if (quadrantToFillID == BOTRIGHTQUAD)
					quadrantBotCenter[row][col] = key;
			}
		}
	}

	//Update the puzzleInts array based on the newly updated quadrant
	updatePuzzleInts();
	fillInQuadrants();
	setScannedFlagsToFalse();
}

void fillInQuadrants()
{
	for (int row = 0; row < ROWS - 6; row++)
	{
		for (int col = 0; col < COLS - 6; col++)
		{
			quadrantTopLeft[row][col] = puzzleInt[row][col];
			quadrantTopCenter[row][col] = puzzleInt[row][col + 3];
			quadrantTopRight[row][col] = puzzleInt[row][col + 6];
			
			quadrantMidLeft[row][col] = puzzleInt[row + 3][col];
			quadrantMidCenter[row][col] = puzzleInt[row + 3][col + 3];
			quadrantMidRight[row][col] = puzzleInt[row + 3][col + 6];
			
			quadrantBotLeft[row][col] = puzzleInt[row + 6][col];
			quadrantBotCenter[row][col] = puzzleInt[row + 6][col + 3];
			quadrantBotRight[row][col] = puzzleInt[row + 6][col + 6];
		}
	}
	setScannedFlagsToFalse();
}

void updatePuzzleInts()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			puzzleInt[row][col] = quadrantTopLeft[row][col];
			puzzleInt[row][col + 3] = quadrantTopCenter[row][col];
			puzzleInt[row][col + 6] = quadrantTopRight[row][col];

			puzzleInt[row + 3][col] = quadrantMidLeft[row][col];
			puzzleInt[row + 3][col + 3] = quadrantMidCenter[row][col];
			puzzleInt[row + 3][col + 6] = quadrantMidRight[row][col];

			puzzleInt[row + 6][col] = quadrantBotLeft[row][col];
			puzzleInt[row + 6][col + 3] = quadrantBotCenter[row][col];
			puzzleInt[row + 6][col + 6] = quadrantBotRight[row][col];
		}
	}

	system("cls");
	displaySudokuPuzzle();
}

bool isASingleZeroInThisQuad(int quadrantID)
{
	//A single zero in the quadrant means there is only one square that is missing a value
	int numOfEmptySquares = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (quadrantID == TOPLEFTQUAD)
			{
				if (quadrantTopLeft[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == TOPCENTERQUAD)
			{
				if (quadrantTopCenter[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == TOPRIGHTQUAD)
			{
				if (quadrantTopRight[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == MIDLEFTQUAD)
			{
				if (quadrantMidLeft[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == MIDCENTERQUAD)
			{
				if (quadrantMidCenter[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == MIDRIGHTQUAD)
			{
				if (quadrantMidRight[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == BOTLEFTQUAD)
			{
				if (quadrantBotLeft[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == BOTCENTERQUAD)
			{
				if (quadrantBotCenter[row][col] == 0)
					numOfEmptySquares += 1;
			}
			else if (quadrantID == BOTRIGHTQUAD)
			{
				if (quadrantBotRight[row][col] == 0)
					numOfEmptySquares += 1;
			}
		}
	}
	if (numOfEmptySquares == 1)
		return true;
	else
		return false;
}

bool isASingleZeroInThisRow(int rowIndex)
{
	//A single zero in this row means there is only one square missing a value in the row
	int numOfEmptySquares = 0;
	for (int col = 0; col < COLS; col++)
	{
		if (puzzleInt[rowIndex][col] == 0)
			numOfEmptySquares += 1;
	}
	if (numOfEmptySquares == 1)
		return true;
	else
		return false;
}

bool isASingleZeroInThisCol(int colIndex)
{
	//A single zero in this col means there is only one square missing a value in the row
	int numOfEmptySquares = 0;
	for (int row = 0; row < ROWS; row++)
	{
		if (puzzleInt[row][colIndex] == 0)
			numOfEmptySquares += 1;
	}

	if (numOfEmptySquares == 1)
		return true;
	else
		return false;
}

int colIndexOfKeyInThisRow(int key, int rowIndex)
{
	for (int col = 0; col < COLS; col++)
	{
		if (puzzleInt[rowIndex][col] == key)
		{
			return col;
		}
	}
	return -1;
}

int rowIndexOfKeyInThisCol(int key, int colIndex)
{
	for (int row = 0; row < COLS; row++)
	{
		if (puzzleInt[row][colIndex] == key)
		{
			return row;
		}
	}
	return -1;
}

int whatSingleNumIsMissingInThisRow(int rowIndex)
{
	for (int col = 0; col < COLS; col++)
	{
		if (puzzleInt[rowIndex][col] == 0)
		{
			return (col + 1);
		}
	}
	return -1;
}

int whatSingleNumIsMissingInThisCol(int colIndex)
{
	for (int row = 0; row < ROWS; row++)
	{
		if (puzzleInt[colIndex][row] == 0)
		{
			return (row + 1);
		}
	}
	return -1;
}

void fillInSingleSquareInRow(int rowIndex)
{
	const int ZERO = 0;
	int colIndex;
	int missingIntInTheRow;
	int availability[] = { 1,1,1,1,1,1,1,1,1 };

	//Evaluate the availability of all integers
	for (int myInts = 1; myInts < 10; myInts++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (puzzleInt[rowIndex][i] == myInts)
				availability[myInts - 1] = 0;
		}
	}
	//Determine the value of the missing integer
	for (int i = 0; i < 9; i++)
	{
		if (availability[i] == 1)
			missingIntInTheRow = i + 1;
	}

	//Fill in the known missing integer
	colIndex = colIndexOfKeyInThisRow(ZERO, rowIndex);
	puzzleInt[rowIndex][colIndex] = missingIntInTheRow; 
	fillInQuadrants();
	setScannedFlagsToFalse();
}

void fillInSingleSquareInCol(int colIndex)
{
	const int ZERO = 0;
	int rowIndex;
	int missingIntInTheCol;
	int availability[] = { 1,1,1,1,1,1,1,1,1 };

	//Evaluate the availability of all integers
	for (int myInts = 1; myInts < 10; myInts++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (puzzleInt[i][colIndex] == myInts)
				availability[myInts - 1] = 0;
		}
	}
	//Determine the value of the missing integer
	for (int i = 0; i < 9; i++)
	{
		if (availability[i] == 1)
			missingIntInTheCol = i + 1;
	}

	//Fill in the known missing integer
	rowIndex = rowIndexOfKeyInThisCol(ZERO, colIndex);
	puzzleInt[rowIndex][colIndex] = missingIntInTheCol;
	fillInQuadrants();
	setScannedFlagsToFalse();
}

int findAvailableColInCrossHatchQuad()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (crossHatchQuad[row][col] == 1)
				return col;
		}
	}
	return -1;
}

int findAvailablRowInCrossHatchQuad()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (crossHatchQuad[row][col] == 1)
				return row;
		}
	}
	return -1;
}


void setScannedFlagsToFalse()
{
	scannedRow1 = false; 
	scannedRow2 = false;
	scannedRow3 = false;
	scannedRow4 = false;
	scannedRow5 = false;
	scannedRow6 = false;
	scannedRow7 = false;
	scannedRow8 = false;
	scannedRow9 = false;

	scannedCol1 = false; 
	scannedCol2 = false;
	scannedCol3 = false;
	scannedCol4 = false;
	scannedCol5 = false;
	scannedCol6 = false;
	scannedCol7 = false;
	scannedCol8 = false;
	scannedCol9 = false;

	scannedTopLeftQuad = false;
	scannedTopCenterQuad = false;
	scannedTopRightQuad = false;
	scannedMidLeftQuad = false;
	scannedMidCenterQuad = false;
	scannedMidRightQuad = false;
	scannedBotLeftQuad = false;
	scannedBotCenterQuad = false;
	scannedBotRightQuad = false;

	scannedTopLeftQuadForSingleDigit = false;
	scannedTopCenterQuadForSingleDigit = false;
	scannedTopRightQuadForSingleDigit = false;
	scannedMidLeftQuadForSingleDigit = false;
	scannedMidCenterQuadForSingleDigit = false;
	scannedMidRightQuadForSingleDigit = false;
	scannedBotLeftQuadForSingleDigit = false;
	scannedBotCenterQuadForSingleDigit = false;
	scannedBotRightQuadForSingleDigit = false;

	scannedTopCenterAndTopRightForSameDigit = false;
	scannedTopLeftAndTopRightForSameDigit = false;
	scannedTopLeftAndTopCenterForSameDigit = false;
	scannedMidCenterAndMidRightForSameDigit = false;
	scannedMidLeftandMidRightForSameDigit = false;
	scannedMidLeftAndMidCenterForSameDigit = false;
	scannedBotCenterAndBotRightForSameDigit = false;
	scannedBotLeftAndBotRightForSameDigit = false;
	scannedBotLeftAndBotCenterForSameDigit = false;

	scannedMidLeftandBotLeftForSameDigit = false;
	scannedTopLeftAndBotLeftForSameDigit = false;
	scannedTopLeftAndMidLeftForSameDigit = false;
	scannedMidCenterAndBotCenterForSameDigit = false;
	scannedTopCenterAndBotCenterForSameDigit = false;
	scannedTopCenterAndMidCenterForSameDigit = false;
	scannedMidRightAndBotRightForSameDigit = false;
	scannedTopRightAndBotRightForSameDigit = false;
	scannedTopRightAndMidRightForSameDigit = false;

	scannedLeftQuads = false;
	scannedCenterQuads = false;
	scannedBotQuads = false;

	scannedLeftQuads = false;
	scannedCenterQuads = false;
	scannedBotQuads = false;

	scannedTopRow = false;
	scannedMidRow = false;
	scannedBotRow = false;

	scannedLeftCol = false;
	scannedCenterCol = false;
	scannedRightCol = false;
}


