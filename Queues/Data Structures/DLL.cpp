#include "DLL.h"

// default constructor
DLinkedList::DLinkedList() {
	header = new DLLNode;               // create sentinels
	trailer = new DLLNode;
	header->next = trailer;           // have them point to each other
	trailer->prev = header;
}

// destructor
DLinkedList::~DLinkedList() {
	while (!empty()) removeFront();     // remove all but sentinels
	delete header;                      // remove the sentinels
	delete trailer;
}

// checks DLL empty status
bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

// get front element
const ArrivalTime& DLinkedList::front() const
{
	return header->next->aTime;
}

// append to DLL
void DLinkedList::addFront(const ArrivalTime& arrival, const FileSize& size)
{
	add(header->next, arrival, size);
}

// prepend to DLL
void DLinkedList::addBack(const ArrivalTime& arrival, const FileSize& size)
{
	add(trailer, arrival, size);
}

// pop DLL
void DLinkedList::removeFront()
{
	remove(header->next);
}

// remove last element of DLL
void DLinkedList::removeBack()
{
	remove(trailer->prev);
}

// inserts new node before v in DLL
void DLinkedList::add(DLLNode* v, const ArrivalTime& arrival, const FileSize& size) {
	DLLNode* u = new DLLNode;       // create a new node and assign members
	u->aTime = arrival;
	u->fSize = size;
	u->next = v;		// place u in between v
	u->prev = v->prev;	// and v->prev
	v->prev->next = u;
	v->prev = u;
}

// remove node v from DLL
void DLinkedList::remove(DLLNode* v) {     // remove node v
	DLLNode* u = v->prev;                  // predecessor
	DLLNode* w = v->next;                  // successor
	u->next = w;                         // unlink v from list
	w->prev = u;
	delete v;
}