/*
*	Island.cpp
*	Functions for a program for Archipelago Expedition Planning
*
****************************************/
#include "proj6.h"

//MyLNode methods
MyLNode::MyLNode (int v1)
{
  elem = v1;
  next = NULL;
}
  
MyLNode::MyLNode (int v1, MyLNode* n)
{
  elem = v1;
  next = n;
}

void MyLNode::setElem (int e)
{
  elem = e;
}

int MyLNode::getElem ()
{
  return elem;
}

void MyLNode::setNext (MyLNode* n)
{
  next = n;
}

MyLNode* MyLNode::getNext()
{
  return next;
}



//  Methods for the MyList class
MyList::MyList()
{
  head = NULL;
}

MyList::MyList ( const MyList &p)   //LINE 95
{
 //head = p.head;    // This code does Shallow Copy
 makeCopy (p);       // This code does a Deep Copy
}

// Code to make a copy of a list - doing a Deep Copy
//   This code uses the recursive method of copyNode()
//   copyNode() should be private since it is intended to only
//   be called by makeCopy()
void MyList::makeCopy ( const MyList &p)
{
 head = NULL;
 copyNode (p.head);
} 
 
void MyList::copyNode (MyLNode* pNode)
{
  if (pNode != NULL)
  {
    copyNode ( pNode->getNext() );

    // insert nodes at the front of the list while returning
    //   from the recursive calls  (adds values to the front
    //   in reverse order - this copies the list on O(n) time
    head = new MyLNode ( pNode->getElem(), head );
  }
}

// method to print out all of the values in the list
void MyList::show()
{
  MyLNode* tmp = head;
  
  while ( tmp != NULL )
  {
    printf ("%d, ", tmp->getElem() );
    tmp = tmp->getNext();
  }
  printf ("\n");
}

void MyList::insert (int v1)
{
  MyLNode* tmp = new MyLNode (v1);
  
  // this code just inserts the node at the beginning of the list
  //tmp->setNext (head);
  //head = tmp;

  // the following code insert the node in increasing order in the list
  MyLNode* curr = head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getElem() < v1 ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  // set the next pointer in the new node to point to curr
  tmp->setNext ( curr );

  if ( prev == NULL ) // v1 becomes the in first/head node in list
    head = tmp;
  else
    prev->setNext( tmp );
}


void MyList::remove (int v1)
{
  MyLNode* curr = head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getElem() != v1 ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  if ( curr == NULL ) // v1 does not exist in list
    return;

  if ( prev == NULL ) // v1 is in first/head node in list
  {
    head = curr->getNext();
    delete curr;
  }
  else
  {
    prev->setNext( curr->getNext() );
    delete curr;
  }
}

  

void MyList::removeAll ()
{
  MyLNode* tmp = head;
  
  while ( tmp != NULL )
  {
    MyLNode* tmp2 = tmp;
    tmp = tmp->getNext();
    delete tmp2;
  }
  head = NULL;
}

MyList::~MyList()
{
  // doing a show() so we can see when the destructor is called
  printf ("In Destructor: ");

  // Note that removeAll() does same operation as required by destructor
  removeAll();
}

// the overloaded assignment operator
//
MyList& MyList::operator= (const MyList& p)
{
 if ( this == &p )   // both operands are the same
   return *this;     //   do nothing, just return

 removeAll();        // Deallocate the existing list

 makeCopy (p);       // Do a deep copy

 return *this;       // allow for "cascading assignments":  a = b = c;
}


bool MyList::edgeExists (int v1) {
	MyLNode* tmp = head;
	bool isFound = false;
	
	while ( tmp != NULL )
	{
		if(tmp->getElem() == v1) {
			isFound = true;
			break;
		}
		tmp = tmp->getNext();
	}
	
	return isFound;
}

int MyList::getListLength() {
  MyLNode* tmp = head;
  int n = 0;
  
  while ( tmp != NULL )
  {
    n++;
    tmp = tmp->getNext();
  }
  
  return n;
}

int MyList::getNthValue(int n) {
  MyLNode* tmp = head;
  
  for(int i = 0; i < n; i++)
  {
    tmp = tmp->getNext();
  }
  
  return tmp->getElem();	
}

Island::Island()
{
  
}

/*Island::~Island() {
	delete this;
}*/
  
//Constructor

//Accessors
void Island::showList() {
  list.show();
}
  
  
//Modifiers
//calls the add function to add a node to the list
void Island::add(int val) {
list.insert(val);
}
  
//calls the remove function to remove a node from the list
bool Island::edgeExist(int val) {
	return list.edgeExists(val);
}

void Island::remove(int val) {
	list.remove(val);
}

void Island::removeAll() {
	list.removeAll();
}

int Island::getListLength() {
	return list.getListLength();
}

int Island::getNthValue(int n) {
	return list.getNthValue(n);
}

bool Island::getIsVisited() {
	return isVisited;
}

void Island::setIsVisited(bool val) {
	isVisited = val;
}
