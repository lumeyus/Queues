#include <iostream>
#include <string>
#include <iomanip>

typedef double ArrivalTime;        // arrival time
typedef int    FileSize;           // file size

class DNode {                      // doubly linked list node
public:
	ArrivalTime aTime;             // node element value
	FileSize    fSize;             // file size
	DNode* prev;                   // previous node in list
	DNode* next;                   // next node in list
	friend class DLinkedList;      // allow DLinkedList access
};

class DLinkedList {             // doubly linked list
public:
	DLinkedList();              // constructor
	~DLinkedList();             // destructor
	bool empty() const;             // is list empty?
	const ArrivalTime& front() const;          // get front element
	//const Elem& back() const;           // get back element
	//const WaitingTime& front() const;     
	void addFront(const ArrivalTime& arrival, const FileSize& size);        // add to front of list
	void addBack(const ArrivalTime& arrival, const FileSize& size);         // add to back of list
	void removeFront();             // remove from front
	void removeBack();              // remove from back
	//void displayViaAge();
	//void displayViaName();
public:                  // local type definitions
	DNode* header;              // list sentinels
	DNode* trailer;
protected:                    // local utilities
	void add(DNode* v, const ArrivalTime& arrival, const FileSize& size);       // insert new node before v
	void remove(DNode* v);          // remove node v
};

double myrand();