//========================================================
// William Nguyen, Cheryl Nguyen
// set.cpp
// January 2024
// This file contains the class methods for the
// Set class.
//========================================================

#include "set.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//-----------------
// define Set class
//-----------------

//======================
// default constructor
// Creates a new empty Set
// Parameter: none
// Return Value: none
//=======================
template <class T> 
    Set<T>::Set   (void)
{
    head = NULL;
}

//======================
// copy constructor
// Creates a new Set object that is a copy
// of the parameter.
// Parameter: Set reference to other_set
// Return Value: none
//=======================
template <class T>
    Set<T>::Set        ( const Set<T> &other_set )
{
    if (other_set.head == NULL)
        head = NULL;
    else
    {
        head = new Node;
        head->item = other_set.head->item;
        head->next = NULL;

        Node* newNode = head;
        Node* ptr = other_set.head->next;

        while (ptr != NULL)
        {
            newNode->next = new Node;
            newNode = newNode->next;
            newNode->item = ptr->item;
            ptr = ptr->next;
        }
        newNode->next = NULL;
    }
}

//==================================================
// destructor
// This deletes the dynamic
// memory allocation for this class.
// Parameter: None
// Return Value: None
//==================================================
template <class T>
    Set<T>::~Set        ( void )
{
    Node* nextTemp; // ptr to node that we will delete
    Node* ptr = head;

    while (ptr != NULL)
    {
        nextTemp = ptr;
        ptr = ptr->next;
        delete nextTemp;
    }

    head = NULL;
}

//==================================================
// assignment operator
// first destructor, then copy constructor
// Parameters: Linked Set reference to mySet
// Return value: a Linked Set object
//==================================================
template <class T>
Set<T>     Set<T>::operator=   ( const Set<T> &other_set )
{
    if (this != &other_set)
    {
        Node* nextTemp;
        Node* ptr = head;

        while (ptr != NULL) 
        {
            nextTemp = ptr->next;
            delete ptr; // Delete the current node
            ptr = nextTemp; 
        }

        if (other_set.head == NULL)
            head = NULL;
        else
        {
            head = new Node;
            head->item = other_set.head->item;
            head->next = NULL;

            Node* newNode = head;
            Node* ptr = other_set.head->next;

            while (ptr != NULL)
            {
                newNode->next = new Node;
                newNode = newNode->next;
                newNode->item = ptr->item;
                newNode->next = NULL;

                ptr = ptr->next;
            }
        }
    }

    return *this;
}

//==================================================
// cardinality
// This returns the number of items in the list
// Parameters: none
// Return value: int count
//==================================================
template <class T>
int     Set<T>::cardinality     ( void ) const
{
	Node *ptr = head;
	int count = 0;
	
	while ( ptr != NULL )
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

//==================================================
// empty
// This returns true if the list is empty,
// false otherwise
// Parameters: none
// Return value: True or False
//==================================================
template <class T>
bool    Set<T>::empty    ( void ) const
{
    return (head == NULL);
}

//==================================================
// insert
// This inserts a new value at the beginning of Set
// Parameters: reference call to item 
// Return value: none
//==================================================
template <class T>
void Set<T>::insert ( const T &x )
{
    Node *ptr = head;

    Node *qtr = new Node;
    qtr->item = x;

    if (ptr == NULL) 
    {
        head = qtr;
        qtr->next = NULL;
    }

    else
    {
        qtr->next = ptr;
        head = qtr;
    }
}

//==================================================
// remove
// This removes an item in Set
// Parameters: reference call to item 
// Return value: none
//==================================================
template <class T>
void Set<T>::remove ( const T &x )
{
    Node *prevPtr = NULL;
    Node *ptr = head;

    if (ptr == NULL)
    {
        cout << "Set is empty" << endl;
    }
    
    while (ptr != NULL && ptr->item != x){
        prevPtr = ptr;
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        if (ptr == head)
        {
            head = ptr->next;
        }
        else
        {
            prevPtr->next = ptr;
        }
    }
    if (ptr == NULL)
    {
        ptr = prevPtr;
    }
    
    delete ptr;
}

//==================================================
// contains
// This specifies whether a Set contains the 
// given element
// Parameters: item of type T
// Return value: true/false
//==================================================
template <class T>
bool    Set<T>::contains    (const T &x)
{
    Node *ptr = head;

    if (ptr == NULL)
    {
        cout << "Set is empty\n";
    }

    while (ptr != NULL)
    {
        if (ptr->item == x)
            return true;
        ptr = ptr->next;
    }

    return false;

}

//==================================================
// operator==
// This indicates whether a Set contains the 
// same elements as another one
// Parameters: reference call to Set
// Return value: true/false
//==================================================
template <class T>
bool     Set<T>::operator==   ( const Set<T> &other_set )
{
    if (cardinality != other_set.cardinality)
        return false;

    Node *ptr = head;
    Node *qtr = other_set.head;

    if (ptr == NULL || qtr == NULL)
        cout << "Set is empty\n";

    while (ptr != NULL)
    {
        if (!other_set.contains(ptr->item))
            return false;
        ptr = ptr->next;
    }
    
    return true;
}