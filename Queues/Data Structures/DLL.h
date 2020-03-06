/* 
	DLL.h - Luis Ibanez - 3/6/2020
	------------------------------
	Contains the Doubly-Linked List and respective Node class declarations.
*/

// define queue types
enum queues
{
	geogeo1,
	geoD1,
	geoX1,
	geogeokk,
	geoDkk,
	geoXkk,
};

typedef double ArrivalTime;        // arrival time
typedef int    FileSize;           // file size

// doubly linked list node class
class DLLNode {                      
public:
	ArrivalTime aTime;             // node element value
	FileSize    fSize;             // file size
	DLLNode* prev;                   // previous node in list
	DLLNode* next;                   // next node in list
	friend class DLinkedList;      // allow access to DLinkedList
};

// doubly linked list class
class DLinkedList {             
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
	DLLNode* header;
	DLLNode* trailer;

protected:
	// local utilities:
	// insert new node before v in DLL
	void add(DLLNode* v, const ArrivalTime& arrival, const FileSize& size);

	// remove node v from DLL
	void remove(DLLNode* v);
};