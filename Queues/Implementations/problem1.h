/*
	problem1.h - Luis Ibanez - 3/6/2020
	-----------------------------------
	Contains the Double Linked List and respective Node class declarations.
	Also contains declaration of the myrand() function to produce a random value for
	the arrival routine.  
	Used to simulate the Geo/Geo/1, Geo/D/1, and Geo/X/1 queues as defined by problem 1 of homework 3.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <time.h>

// define queue types
enum queues
{
	geogeo1,
	geoD1,
	geoX1,
};

#define NUM_SIM_POINTS 12
#define SIM_TIME 1e8
#define M 5

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
	// default constructor
	DLinkedList();         

	// destructor
	~DLinkedList();             

	// checks DLL empty status
	bool empty() const;          

	// get front element
	const ArrivalTime& front() const;       

	// append to DLL
	void addFront(const ArrivalTime& arrival, const FileSize& size);    

	// prepend to DLL
	void addBack(const ArrivalTime& arrival, const FileSize& size);

	// pop DLL
	void removeFront();           

	// remove last element of DLL
	void removeBack();   

	// local type definitions:
	// list sentinels
	DNode* header;              
	DNode* trailer;

protected:                    
	// local utilities:
	// insert new node before v in DLL
	void add(DNode* v, const ArrivalTime& arrival, const FileSize& size);    

	// remove node v from DLL
	void remove(DNode* v);          
};

// used to generate random double value
double myrand();

// run the desired queueing simulation, problem 1
void runProblem1(int queue_type);