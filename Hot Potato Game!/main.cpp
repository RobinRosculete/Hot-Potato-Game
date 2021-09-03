#include"main.h"
using namespace std;

int main()
{
	List listObj;
	int numPasses = 0;
	int numPlayers = 0;

	char playAgain = 'y';
	
	while (!(playAgain == 'n' || playAgain == 'N')) {

		printMenu(numPlayers, numPasses);
		try {

			listObj.createList(numPlayers);
			listObj.hotPotatoGame(numPlayers, numPasses);
		}
		catch (bad_alloc& ex) {

			cout << "Error!Failed to allocate memory: Exception: " << ex.what() << endl;
		}
		listObj.makeEmpty();
		cout << "\nWant To Play again? Yes press 'Y' No press 'N'" << endl;
		cin >> playAgain;
	}
}

//Function purpose to print menu, and ask user for num passes and num players
//Precondition:nmPlayers and numPasses are initialized
//Postcondition:Correct values are stored and returned in both numPlayers and numPasses
void printMenu(int& numpalyers, int& numPasses)
{
	cout << "\n\t\t*** Hot Potato Game ***"
		"\nPlease enter the number of players(positive numbers greater than 2 only): " << endl;
	while (!(cin >> numpalyers) || numpalyers < 2)
	{
		cout << "There was an error with your input please enter a positive number greate than 2! " << endl;
		cin.clear();
		cin.ignore(2000, '\n');
	}

	cout << "\n\nPlease enter number of passes(positive numbers only): " << endl;
	while (!(cin >> numPasses) || numPasses < 0) {
		cout << "There was an error with your input please enter a positive number ! " << endl;
		cin.clear();
		cin.ignore(2000, '\n');
	}

}//end menu function



//1.Test with wrong input
/*
                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
fd
There was an error with your input please enter a positive number greate than 2!
we
There was an error with your input please enter a positive number greate than 2!
$
There was an error with your input please enter a positive number greate than 2!
-1
There was an error with your input please enter a positive number greate than 2!
0
There was an error with your input please enter a positive number greate than 2!
1
There was an error with your input please enter a positive number greate than 2!
5


Please enter number of passes(positive numbers only):
fd
There was an error with your input please enter a positive number !
-1
There was an error with your input please enter a positive number !
%
There was an error with your input please enter a positive number !
1
Player #2 was eliminated
Player #4 was eliminated
Player #1 was eliminated
Player #5 was eliminated

*The Winer is Player #3

Want To Play again? Yes press 'Y' No press 'N'

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
There was an error with your input please enter a positive number greate than 2!
C:\Users\Robin\Desktop\Scoala\Anul 2\SEM #2\CS 136\LABS\LAB 5.1\Debug\LAB 5.1.exe (process 22156) exited with code -1073741510.
Press any key to close this window . . .
*/




//2.Testing with correct input!
/*
                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
5


Please enter number of passes(positive numbers only):
3
Player #4 was eliminated
Player #3 was eliminated
Player #5 was eliminated
Player #2 was eliminated

*The Winer is Player #1

Want To Play again? Yes press 'Y' No press 'N'
y

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
5


Please enter number of passes(positive numbers only):
0
Player #1 was eliminated
Player #2 was eliminated
Player #3 was eliminated
Player #4 was eliminated

*The Winer is Player #5

Want To Play again? Yes press 'Y' No press 'N'
y

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
5


Please enter number of passes(positive numbers only):
1
Player #2 was eliminated
Player #4 was eliminated
Player #1 was eliminated
Player #5 was eliminated

*The Winer is Player #3

Want To Play again? Yes press 'Y' No press 'N'
y

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
9


Please enter number of passes(positive numbers only):
7
Player #8 was eliminated
Player #7 was eliminated
Player #9 was eliminated
Player #2 was eliminated
Player #5 was eliminated
Player #4 was eliminated
Player #1 was eliminated
Player #6 was eliminated

*The Winer is Player #3

Want To Play again? Yes press 'Y' No press 'N'
y

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
10


Please enter number of passes(positive numbers only):
2
Player #3 was eliminated
Player #6 was eliminated
Player #9 was eliminated
Player #2 was eliminated
Player #7 was eliminated
Player #1 was eliminated
Player #8 was eliminated
Player #5 was eliminated
Player #10 was eliminated

*The Winer is Player #4

Want To Play again? Yes press 'Y' No press 'N'
10

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
There was an error with your input please enter a positive number greate than 2!
0
There was an error with your input please enter a positive number greate than 2!
10


Please enter number of passes(positive numbers only):
0
Player #1 was eliminated
Player #2 was eliminated
Player #3 was eliminated
Player #4 was eliminated
Player #5 was eliminated
Player #6 was eliminated
Player #7 was eliminated
Player #8 was eliminated
Player #9 was eliminated

*The Winer is Player #10

Want To Play again? Yes press 'Y' No press 'N'
y

                *** Hot Potato Game ***
Please enter the number of players(positive numbers greater than 2 only):
12


Please enter number of passes(positive numbers only):
6
Player #7 was eliminated
Player #2 was eliminated
Player #10 was eliminated
Player #6 was eliminated
Player #4 was eliminated
Player #3 was eliminated
Player #5 was eliminated
Player #9 was eliminated
Player #1 was eliminated
Player #8 was eliminated
Player #11 was eliminated

*The Winer is Player #12

Want To Play again? Yes press 'Y' No press 'N'
*/

