//========================================================
// William Nguyen, Cheryl Nguyen
// January 2024
// set.h
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
        Set();
        ~Set();
        void insert(const T x);
        void remove(const T x);
        int cardinality();
        bool empty();
        bool contains(const T x);
        void operator==(const T &other_set);
        void operator<=(const T &other_set);
        Set<T> operator+(const T &other_set);
        Set<T> operator&(const T &other_set);
        Set<T> operator-(const T &other_set);
        string to_string();
};

#include "set.cpp"
#endif