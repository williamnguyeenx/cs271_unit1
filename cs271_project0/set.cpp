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
        head = new Node;                            //create new head pointer
        head->item = other_set.head->item;          //copy head pointer
        head->next = NULL;                          //set to NULL to ready for copying the rest of the linked list

        Node* newNode = head;
        Node* ptr = other_set.head->next;

        while (ptr != NULL)
        {
            newNode->next = new Node;               // create new node
            newNode = newNode->next;                // copy the data from list's nodes to be copied
            newNode->item = ptr->item;
            ptr = ptr->next;                        // traverse the existing list
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
    Node* nextTemp;                                 // ptr to node that we will delete
    Node* ptr = head;

    while (ptr != NULL)
    {
        nextTemp = ptr;
        ptr = ptr->next;                            // traverse the list                  
        delete nextTemp;                            // deleting nodes
    }

    head = NULL;                                    //set head pointer to NULL to deallocate the list to be deleted
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
// Pre-condition: a Set object exists
// Post-condition: Element inserted as a Node at 
// the start of the Set object
//==================================================
template <class T>
void Set<T>::insert     ( const T &x )
{
    Node *ptr = head;                   // pointer to access the list

    Node *qtr = new Node;               // a new node to hold the value of the element to be inserted
    qtr->item = x;                      // get the element's value

    if (ptr == NULL)                    // check if list is empty
    {
        head = qtr;                     // list's head pointer points to the new node
        qtr->next = NULL;               // new node doesn't point to other node for it is the only node in the list
    }
    else
    {
        qtr->next = ptr;                // new node points to the former first node of the list
        head = qtr;                     // list's head pointer points to the new node
    }
}

//==================================================
// remove
// This removes an item in Set
// Parameters: reference call to item 
// Return value: none
// Pre-condition: a Set object exists
// Post-condition: input item removed from
// the list/Set object
//==================================================
template <class T>
void Set<T>::remove     ( const T &x )
{
    Node *prevPtr = NULL;                       // pointer to remove the item
    Node *ptr = head;                           // pointer to access the list's nodes

    if (ptr == NULL)                            // check if list is empty
    {
        cout << "Set is empty\n";
        return;
    }
    
    while (ptr != NULL && ptr->item != x)       // traverse through the list to find the item
    {
        prevPtr = ptr;                          // points to the current node the ptr is at
        ptr = ptr->next;                        // go to the next node
    }

    if (ptr != NULL)                            // check if the item is found
    {
        if (ptr == head)                        // if the item is found at the start of the list
            head = ptr->next;                   // unlink the item
        else
            prevPtr->next = ptr->next;          // unlink the item

        delete ptr;                             // remove/deallocate the item 
    }   
}

//==================================================
// contains
// This specifies whether a Set contains the 
// given item
// Parameters: item of type T
// Return value: true/false
// Pre-condition: a Set object exists
// Post-condition: return true if item is found
// in list, otherwise false
//==================================================
template <class T>
bool    Set<T>::contains    (const T &x) const
{
    Node *ptr = head;

    if (ptr == NULL)                            //check if list is empty
        return false;

    while (ptr != NULL)                         //traverse to find the item
    {
        if (ptr->item == x)                     //if item is found, return true
            return true;
        ptr = ptr->next;
    }

    return false;                               //item not found, return false
}

//==================================================
// operator==
// This indicates whether a Set contains the 
// same elements as another one
// Parameters: reference call to Set
// Return value: true/false
// Pre-condition: exists two Set objects of
// the same data type
// Post-condition: return true if two Set objects
// equivalent, otherwise return false
//==================================================
template <class T>
bool     Set<T>::operator==   ( const Set<T> &other_set ) const
{
    if (cardinality() != other_set.cardinality())       //check if the cardinality of two sets are equal
        return false;

    Node *ptr = head;

    while (ptr != NULL)                                 //traverse through one of the sets
    {
        if (!other_set.contains(ptr->item))             //use contains() method to compare the items of two sets
            return false;
        ptr = ptr->next;
    }
    
    return true;                                        //passed the check, two sets that are to be checked are equal
}

//==================================================
// operator<=
// This indicates whether a Set is the subset of the 
// other one
// Parameters: reference call to Set
// Return value: true/false
// Pre-condition: exists two Set objects
// Post-condition: return true if a set is the 
// subset of the other one, otherwise return false
//==================================================
template <class T>
bool     Set<T>::operator<=   ( const Set<T> &other_set ) const
{
    if (cardinality() == 0)
        return true;

    if (cardinality() !=0 && other_set.cardinality() == 0)      // check if the supposedly subset is empty or not with the other one is empty
        return false;
    
    if (cardinality() > other_set.cardinality())                // check if the subset's cardinality is larger than cardinality of the set that possibly contains the subset
        return false;
    
    Node *ptr = head;

    while (ptr != NULL)                                         //traverse through the potential subset
    {
        if (!other_set.contains(ptr->item))                     //use contains() to traverse the other set and check if the subset's items are present in the other set
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
// Pre-condition:
//==================================================
template <class T>
Set<T>      Set<T>::operator+   ( const Set<T> &other_set ) const
{
    Set<T> set_union;
    Node *ptr = other_set.head;

    while (ptr != NULL)
    {
        set_union.insert(ptr->item);
        ptr = ptr->next;
    }

    ptr = head;

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
Set<T>      Set<T>::operator&      ( const Set<T> &other_set ) const
{
    Set<T> intersection;
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (other_set.contains(ptr->item))
            intersection.insert(ptr->item);
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
Set<T>      Set<T>::operator-       ( const Set<T> &other_set ) const
{
    Set<T> difference;
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (!other_set.contains(ptr->item))
            difference.insert(ptr->item);
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
template <class T>
string      Set<T>::to_string       ( void ) const
{
    stringstream result;
	Node *ptr = head;

	while ( ptr != NULL )
	{
        if (ptr->next)
            result << ptr->item << " ";
		else
            result << ptr->item;
		ptr = ptr -> next;
	}

    return result.str();
}
