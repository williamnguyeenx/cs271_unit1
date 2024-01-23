#include <iostream>
#include <string>

#ifndef SET.H
#define SET.H

template <class T>
class Set{
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
    private:
};

#include "set.cpp"
#endif