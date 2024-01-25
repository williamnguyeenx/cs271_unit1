//========================================================
// William Nguyen, Cheryl Nguyen
// set.h
// January 2024
// This file contains the Set class declaration.  
//========================================================
#include <iostream>
#include <string>

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
                Set		( const Set<T> &other_set );
                ~Set            ( void );
Set<T>		operator=	( const Set<T> &other_set );
void            insert          ( const T &x );
void            remove          ( const T &x );
int             cardinality     ( void ) const;
bool            empty           ( void ) const;
bool            contains        ( const T &x );
bool            operator==      ( const Set<T> &other_set ) const;
bool            operator<=      ( const Set<T> &other_set ) const;
Set<T>          operator+       ( const Set<T> &other_set ) const;
Set<T>          operator&       ( const Set<T> &other_set ) const;
Set<T>          operator-       ( const Set<T> &other_set ) const;
string          to_string       ( void ) const;

friend ostream & operator<< ( ostream &os, Set<T> &other_set )
{
	Node *ptr = other_set.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}

};

#include "set.cpp"
#endif