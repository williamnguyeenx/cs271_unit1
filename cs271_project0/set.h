//========================================================
// William Nguyen, Cheryl Nguyen
// set.h
// January 2024
// This file contains the Set class declaration.  
//========================================================
#include <iostream>
#include <string>
using namespace std;

#ifndef SET_H
#define SET_H

template <class T>
class Set
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// the pointer for the linked list

public:
                Set             ( void );
                Set				( const Set<T> &other_set );
                ~Set            ( void );
Set<T>			operator=		( const Set<T> &other_set );
void            insert          ( const T &x );
void            remove          ( const T &x );
int             cardinality     ( void ) const;
bool            empty           ( void ) const;
bool            contains        ( const T &x ) const;
bool            operator==      ( const Set<T> &other_set ) const;
bool            operator<=      ( const Set<T> &other_set ) const;
Set<T>          operator+       ( const Set<T> &other_set ) const;
Set<T>          operator&       ( const Set<T> &other_set ) const;
Set<T>          operator-       ( const Set<T> &other_set ) const;
string          to_string       ( void ) const;

// ==========================================================================================
// Overloads the << operator to provide a way to print the Set contents to an output stream.
// This function is declared as a friend within the Set class so it can access private members of Set.
// Parameters:
// - os: A reference to the ostream object where the Set elements will be sent (e.g., std::cout)
// - other_set: A constant reference to the Set object to be printed
// Return Value: A reference to the ostream object to allow chaining of << operator calls
// ==========================================================================================
friend ostream & operator<< ( ostream &os, Set<T> &other_set )
{
	// access the head pointer of the Set to traverse the elements
	Node *ptr = other_set.head;
	os << "{ ";

	// Traverse the linked list until the end is reached
	while ( ptr != NULL )
	{
		// If the current node is not the last, append the item followed by a comma and a space
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " "; // If it's the last element, append the item followed by a space (no comma)
		ptr = ptr->next;
	}
	os << "}";
	return os;	
}

};

#include "set.cpp"
#endif