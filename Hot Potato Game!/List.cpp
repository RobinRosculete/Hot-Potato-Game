#include<iostream>
#include"List.h"
#include "Node.h"
using namespace std;

//Function purpose to creat a new player(Node) 
//Preconsdition:none
//Postcondition: if there is sufiicent memory a new node has been created and function will return it
//else bad_alloc is thrown and error meassage is printed to the screen, nullptr is returned in this case
Node* List::newNode(int data) {

	Node* tempNewNode = nullptr;
		tempNewNode = new Node;
		tempNewNode->setPlayerNumber(data);
		return tempNewNode;
	
}//end newPlayernode function

//Function purpose to create a circulare linked list, the size of the num of players!
//Precondition:None
//Postcondition:List is initialized,to the size of the number of players
void List::createList(int listSize) {
	for (int x = 1; x <= listSize; ++x) {
		if (isEmpty()) {
			head = newNode(x);
			tail = head;
		}
		else {
			tail->setNext(newNode(x));
			tail = tail->getNext();
		}
	}tail->setNext(head);
}//end creatList Function!

//Function purpose to remove each player(Node form the linked List) at a specific number of passes
//Precondition:List has been initialized and it is not empty
//Postcondition:Each element was removed and printed to the screen in the order of the passses, 
//the last node(player )isprinted to the screen, all memory is freed.
void List::hotPotatoGame(int numPlayers, int numPasses) {
	while (numPlayers!=1)
	{
		for (int x = 0; x < numPasses; ++x)
		{
			tail=head;
			head = head->getNext();
		}
		cout << "Player #" << head->getPlayerNumber()  << " was eliminated" << endl;
		tail->setNext(head->getNext());

	    delete head;
		head = tail->getNext();
		--numPlayers;		
	}		
	cout <<"\n*The Winer is Player #" << head->getPlayerNumber() << endl;
	makeEmpty();//Freeing remaining memory

}//End function removeFromList

//Function purpose to empty the linked list;
//Precondition: none
//Postcondition: List is empty, all memory is freed
void List::makeEmpty() {
	Node* tempPtr = nullptr;
	if (head != nullptr) {
		tail->setNext(nullptr);
	
		while (head != nullptr) {
			tempPtr = head;
			head = head->getNext();
			delete tempPtr;
			//tempPtr = nullptr;
		}
	}
	head = nullptr;
}//end make empty Function

//Function purpose to overload operator "=", to be able to perform a deep copy 
List& List::operator=(const List& rhs) {
	this->head = rhs.head;
	this->tail = rhs.tail;
	return*this;
}//end copy assigment operator funciton

List::List(const List& listObj) {
	this->head = listObj.head;
	this->tail = listObj.tail;
}
