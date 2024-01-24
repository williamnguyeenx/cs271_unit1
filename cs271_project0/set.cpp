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
// to_string
// Converts ListLinked object to c++ string type.
// Parameters: none
// Return value: string of the form "n/d" where
// n is the numerator and d is the denominator.
//==================================================

template <class T>
string   Set<T>::to_string    ( void ) const
{
    string result = "[";
    Node* ptr = head;

    while (ptr != NULL)
    {
        result += std::to_string(ptr->item);
        ptr = ptr->next;

        if (ptr != NULL)
            result += " ,";
    }

    result += "]";
    return result;
}