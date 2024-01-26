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
#include <sstream>
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
        cout << "Set is empty\n";
        return;
    }
    
    while (ptr != NULL && ptr->item != x)
    {
        prevPtr = ptr;
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        if (ptr == head)
            head = ptr->next;
        else
            prevPtr->next = ptr->next;

        delete ptr;
    }   
}

//==================================================
// contains
// This specifies whether a Set contains the 
// given element
// Parameters: item of type T
// Return value: true/false
//==================================================
template <class T>
bool    Set<T>::contains    (const T &x) const
{
    Node *ptr = head;

    if (ptr == NULL)
        return false;

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
bool     Set<T>::operator==   ( const Set<T> &other_set ) const
{
    if (cardinality() != other_set.cardinality())
        return false;

    Node *ptr = head;

    while (ptr != NULL)
    {
        if (!other_set.contains(ptr->item))
            return false;
        ptr = ptr->next;
    }
    
    return true;
}

//==================================================
// operator<=
// This indicates whether a Set is the subset of the 
// another one
// Parameters: reference call to Set
// Return value: true/false
//==================================================
template <class T>
bool     Set<T>::operator<=   ( const Set<T> &other_set ) const
{
    if (other_set.cardinality() == 0)
        return false;
    
    if (cardinality() > other_set.cardinality())
        return false;
    
    Node *ptr = head;

    while (ptr != NULL)
    {
        if (!other_set.contains(ptr->item))
            return false;
        ptr = ptr->next;
    }

    return true;
}
//==================================================
// operator+
// Create a set containing the union of two sets
// Parameters: reference call to Set
// Return value: a Set object
//==================================================
template <class T>
Set<T>     Set<T>::operator+   ( const Set<T> &other_set ) const
{
    Set<T> set_union;
    Node *ptr = head;

    while (ptr != NULL)
    {
        set_union.insert(ptr->item);
        ptr = ptr->next;
    }

    ptr = other_set.head;

    while (ptr != NULL)
    {
        if (!set_union.contains(ptr->item))
            set_union.insert(ptr->item);
        ptr = ptr->next;
    }

    return set_union;
}

//==================================================
// operator&
// Create a set containing the interections of two sets
// Parameters: reference call to Set
// Return value: a Set object
//==================================================
template <class T>
Set<T>   Set<T>::operator&      ( const Set<T> &other_set ) const
{
    Set<T> intersection;
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (other_set.contains(ptr->item)){
            intersection.insert(ptr->item);
        }
        ptr = ptr->next;
    }
    return intersection;
}

//==================================================
// operator-
// Create a set containing the differences between two sets
// Parameters: reference call to Set
// Return value: true/false
//==================================================

template <class T>
Set<T>    Set<T>::operator-   ( const Set<T> &other_set ) const
{
    Set<T> difference;
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (!other_set.contains(ptr->item)){
            difference.insert(ptr->item);
        }
        ptr = ptr->next;
    }
    return difference;
}


//==================================================
// to_string
// Converts Set object to c++ string type.
// Parameters: none
// Return value: string with the elements in set 
// separated by a single space and starting at the head
//==================================================
// template <class T>
// string      Set<T>::to_string       ( void ) const
// {
//     string result = "";
//     Node* ptr = head;

//     if (ptr == NULL){
//     return result;
//     }

//     while (ptr != NULL)
//     {
//         result += ptr->item;

//         if (ptr->next != NULL)
//             result += " ";
//         ptr = ptr->next;
//     }

//     return result;
// }

template <class T>
string      Set<T>::to_string       ( void ) const
{
    stringstream result;
	Node *ptr = head;

	while ( ptr != NULL )
	{
        if (ptr->next)
        {
            result << ptr->item << " ";
        }
		else
        {
            result << ptr->item;
        }
		ptr = ptr -> next;
	}

    return result.str();
}
