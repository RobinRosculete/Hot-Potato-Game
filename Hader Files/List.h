#include"Node.h"
#ifndef  LIST_H
#define LIST_H

class List:public Node {
public:

	List() : head(nullptr), tail(nullptr) {}
	List(const List& listObj);
	~List() {makeEmpty(); }
	List& operator=(const List& rhs);

	//Precondition:None
	//Postcondition: return true if list is empty, else return false
	bool isEmpty()const { return (head == nullptr);}
   
	Node* newNode(int data);

	//Precondition: list has been initilized
	//Postcondition: If list has been initialized return the tail poilter else return nulptr
	Node* getTail()const { return this->tail; }

	//Precondition: list has been initilized
	//Postcondition: If list has been initialized return the head poilter else return nulptr
	Node* getHead() const { return this->head; }


	void createList(int numPlayers);
	void hotPotatoGame(int numPlayers, int numPasses);
	void makeEmpty();
	
	void setTail(Node* taill) { this->tail = taill;}//Post: set a value into the tail member pointer

	void setListHead(Node* head) { this->head = head;}//post: set a value into the head member pointer
private:
	Node* head;
	Node* tail;
};

#endif  LIST_H

