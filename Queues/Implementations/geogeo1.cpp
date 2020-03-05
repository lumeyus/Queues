#include "GeoGeo1.h"
#include <math.h>
#include <time.h>
#include <iomanip>
#include <fstream>

#define NumofSimPoints 12
#define SimTime 1e8
#define M 10

double Seed = 7;

double myrand()
{
	double p;
	p = fmod(3125.0*Seed, 34359738337.0);
	Seed = p;
	p = p / 34359738337.0;
	return p;
}

// default constructor
DLinkedList::DLinkedList() {    
	header = new DNode;               // create sentinels
	trailer = new DNode;
	header->next = trailer;           // have them point to each other
	trailer->prev = header;
}

// destructor
DLinkedList::~DLinkedList() {           
	while (!empty()) removeFront();     // remove all but sentinels
	delete header;                      // remove the sentinels
	delete trailer;
}

// inserts new node before v
void DLinkedList::add(DNode* v, const ArrivalTime& arrival, const FileSize& size) {
	DNode* u = new DNode;       // create a new node and assign members
	u->aTime = arrival;
	u->fSize = size;
	u->next = v;		// place u in between v
	u->prev = v->prev;	// and v->prev
	v->prev->next = u;
	v->prev = u;
	//v->prev->next = v->prev = u;
}

void DLinkedList::addFront(const ArrivalTime& arrival, const FileSize& size)  // add to front of list
{
	add(header->next, arrival, size);
}

void DLinkedList::addBack(const ArrivalTime& arrival, const FileSize& size)   // add to back of list
{
	add(trailer, arrival, size);
}

void DLinkedList::remove(DNode* v) {     // remove node v
	DNode* u = v->prev;                  // predecessor
	DNode* w = v->next;                  // successor
	u->next = w;                         // unlink v from list
	w->prev = u;
	delete v;
}

void DLinkedList::removeFront()       // remove from font
{
	remove(header->next);
}

void DLinkedList::removeBack()        // remove from back
{
	remove(trailer->prev);
}


bool DLinkedList::empty() const        // is list empty?
{
	return (header->next == trailer);
}

const ArrivalTime& DLinkedList::front() const    // get front element
{
	return header->next->aTime;
}

/*const Elem& DLinkedList::back() const     // get back element
{
	return trailer->prev->elem;
}*/

/*void DLinkedList::displayViaAge() {                     //Displays person via age

	DNode*temp = header;

	while (temp != trailer)
	{

		//if(howold = age)
		cout << temp->elem << endl;
		temp = temp->next;
	}

	cout << temp->elem << endl;
}*/