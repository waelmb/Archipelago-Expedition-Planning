/*
*	proj6.h
*	A header file for a program for Archipelago Expedition Planning
*
****************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>

// Global variables
static bool debugMode;

// Classes and structs
/*
class MyFNode
{
 private:
 	FILE* fName;
 	MyFNode* next;
  
 public:
	//Default constructor
	MyFNode()
	{
  
	}
	
	//Constructor

	
	//Accessors
	FILE* getFile() {
		return fName;
	}
	
	MyFNode* getNext() {
		return next;
	}
	
	
	//Modifiers
	void setFile(FILE* newFile) {
		fName = newFile;
	}
	
	void setNext(MyFNode* newNode) {
		next = newNode;
	}
  
};
*/

class MyLNode
{
 private:
  int elem;
  MyLNode* next;
  
 public:
  MyLNode (int v1);
  MyLNode (int v1, MyLNode* n);
  
  void setElem (int e);
  int getElem ();
  void setNext (MyLNode* n);
  MyLNode* getNext();
};

// the list class for the linked list
//  This contains all of the operations and data for the
//  list as a whole
//  This class relies heavily on the MyLNode class
class MyList
{
 private:
  MyLNode* head;
  void copyNode (MyLNode* pNode);  
  
 public:
  MyList();              // default constructor
  MyList(const MyList&); // copy constructor
  ~MyList();             // destructor   

  void show();
  void insert (int v1);
  void remove (int v1);
  void removeAll ();
  void makeCopy (const MyList& p);

  MyList& operator= ( const MyList& p);
  bool edgeExists (int v1);
  int getListLength();
  int getNthValue(int n);
};

class Island
{
 private:
 MyList list;
 bool isVisited;
  
 public:
  Island();
  //~Island();             // destructor 
  void showList();
  void add(int val);
  bool edgeExist(int val);
  void remove(int val);
  void removeAll();
  int getListLength();
  int getNthValue(int n);
  bool getIsVisited();
  void setIsVisited(bool val);
};

