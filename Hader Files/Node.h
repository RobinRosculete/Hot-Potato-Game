#ifndef NODE_H
#define  NODE_H
#include<iostream>
#include<string>
using std::string;
class Node {
public:
	Node() :playerNumber(0), next(nullptr) {}


	void setPlayerNumber(int data) { this->playerNumber = data;}//Function purpose: To set a value in the playerNumber member variable
	void setNext(Node* next) { this->next = next; }//Function puporse:To set a value to the next member pointer
	
	//Precondition:A node is initialized
	//Postcondition:The nodes next pointer is returned
	Node* getNext()const { return this->next; }

	//Precondition:A node is initialized
	//Postcondition:The players data is returned
	int getPlayerNumber()const { return this->playerNumber; }
private:
	int playerNumber;
	Node* next;
	
};
#endif NODE_H

