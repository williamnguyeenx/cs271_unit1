//========================================================
// William Nguyen, Cheryl Nguyen
// test_set.cpp
// January 2024
// This file contains the test cases for the
// Set class.
//========================================================

#include <iostream>
#include "set.h"

void test_insert() {
    //int
    try {
        Set<int> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
    // float
    try {
        Set<float> s;
        s.insert(0.5);
        string set_str = s.to_string();
        if (s.to_string() != "0.5") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2.4);
        s.insert(-1.2);
        set_str = s.to_string();
        if (s.to_string() != "-1.2 2.4 0.5") {
            cout << "Incorrect insert result. Expected -1.2 2.4 0.5 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
    //char
    try {
        Set<char> s;
        s.insert('a');
        s.insert('c');
        s.insert('b');
        string set_str = s.to_string();
        if (set_str != "b c a") {
            cout << "Incorrect insert result for char. Expected b c a but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting char into set : " << e.what() << endl;
    }

    //string
    try {
        Set<string> s;
        s.insert("professor");
        s.insert("stacy");
        s.insert("data");
        string set_str = s.to_string();
        if (set_str != "data stacy professor") {
            cout << "Incorrect insert result for string. Expected data stacy professor but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting string into set : " << e.what() << endl;
    }
}

void test_remove() {
    //int
    try {
        Set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        string set_str = s.to_string();
        if (s.to_string() != "4 3 2 1") {
            cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << endl;
        }
        s.remove(3);
        set_str = s.to_string();
        if(s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
    //float
     try {
        Set<float> s;
        s.insert(1.5);
        s.insert(2.3);
        s.insert(-0.7);
        s.remove(2.3);
        string set_str = s.to_string();
        if (set_str != "-0.7 1.5") {
            cout << "Incorrect insert result for float. Expected -0.7 1.5 but got : " << set_str << endl;
        }
        s.remove(1.5);
        set_str = s.to_string();
        if (set_str != "-0.7") {
            cout << "Incorrect insert result for float. Expected -0.7 but got: " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting float into set : " << e.what() << endl;
    }

    //char
    try {
        Set<char> s;
        s.insert('x');
        s.insert('y');
        s.insert('z');
        s.remove('y');
        string set_str = s.to_string();
        if (set_str != "z x") {
            cout << "Incorrect remove result for char. Expected z x but got : " << set_str << endl;
        }
        s.remove('z');
        set_str = s.to_string();
        if (set_str != "x") {
            cout << "Incorrect remove result for char. Expected x but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing char from set : " << e.what() << endl;
    }

    //string
    try {
        Set<string> s;
        s.insert("orange");
        s.insert("grape");
        s.insert("lemon");
        s.remove("grape");
        string set_str = s.to_string();
        if (set_str != "lemon orange") {
            cout << "Incorrect remove result for string. Expected lemon orange but got : " << set_str << endl;
        }
        s.remove("lemon");
        s.remove("orange");
        set_str = s.to_string();
        if (set_str != "") {
            cout << "Incorrect remove result for string. Expected empty string but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing string from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    //int
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
    //float
    try {
        Set<float> s;
        float c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6.3);
        s.insert(5.9);
        s.insert(4.2);
        s.insert(2.0);
        c = s.cardinality();
        if(c != 4) {
            cout << "Incorrect cardinality. Expected 4 but got : " << c << endl;
        }
        s.remove(4.2);
        s.remove(2.0);
        c = s.cardinality();
        if(c != 2) {
            cout << "Incorrect cardinality. Expected 2 but got : " << c << endl;
        }
        s.insert(9.6);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
    //char
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert('a');
        s.insert('b');
        s.insert('c');
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
        s.remove('c');
        c = s.cardinality();
        if(c != 2) {
            cout << "Incorrect cardinality. Expected 2 but got : " << c << endl;
        }
        s.insert('d');
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    //int
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1);
        s.insert(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
    //float
    try {
        Set<float> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1.5);
        s.insert(2.7);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(2.7);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1.5);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
    //char
    try {
        Set<char> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert('a');
        s.insert('b');
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove('b');
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove('a');
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
    //string
    try {
        Set<string> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert("empty");
        s.insert("set");
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove("set");
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove("empty");
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    //int
    try {
        Set<int> s;
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in set : " << e.what() << endl;
    }
    //float
    try {
        Set<float> s;
        if(s.contains(6.6)) {
            cout << "Incorrectly identified 6.6 as in the set " << s.to_string() << endl;
        }
        s.insert(1.6);
        s.insert(2.8);
        if(s.contains(6.6)) {
            cout << "Correctly identified 2.8 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(1.6)) {
            cout << "Incorrectly identified 1.6 as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in set : " << e.what() << endl;
    }

    //char
    try {
        Set<char> s;
        if(s.contains('a')) {
            cout << "Incorrectly identified a as in the set " << s.to_string() << endl;
        }
        s.insert('b');
        s.insert('c');
        if(!s.contains('c')) {
            cout << "Incorrectly identified c as NOT in the set " << s.to_string() << endl;
        }
        if(s.contains('x')) {
            cout << "Incorrectly identified x as in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if string contained in set : " << e.what() << endl;
    }
    //string
    try {
        Set<string> s;
        if(s.contains("will")) {
            cout << "Incorrectly identified will as in the set " << s.to_string() << endl;
        }
        s.insert("apple");
        s.insert("banana");
        if(!s.contains("apple")) {
            cout << "Incorrectly identified 'apple' as NOT in the set " << s.to_string() << endl;
        }
        if(s.contains("cherry")) {
            cout << "Incorrectly identified 'cherry' as in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if string contained in set : " << e.what() << endl;
    }
}

void test_equality() {
    //int
    try {
        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(1);
        t.insert(2);
        t.insert(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
    //float
    try {
        Set<float> s;
        Set<float> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        s.insert(3.3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(1.1);
        t.insert(2.2);
        t.insert(3.3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3.3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
    //char
    try {
        Set<char> s;
        Set<char> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert('a');
        s.insert('b');
        s.insert('c');
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert('a');
        t.insert('b');
        t.insert('c');
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove('b');
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
    //string
    try {
        Set<string> s;
        Set<string> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert("Who");
        s.insert("What");
        s.insert("How");
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert("Who");
        t.insert("What");
        t.insert("How");
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove("Who");
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(11);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }

        s.remove(3);
        s.remove(7);
        s.remove(11);
        if (!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(2);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        t.insert(6);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "1 2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s-t).to_string();
        if(set_str != "1 2") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> S;
    // TO-DO: generate large set
    for (int i = 0; i < 10000; ++i) 
    {
        S.insert(rand() % 10000);  // Insert random numbers or i for sequential numbers
    }
    Set<int> T;
    // TO-DO: generate large set
    for (int i = 0; i < 10000; ++i) 
    {
        T.insert(rand() % 10000);  // Insert random numbers or i for sequential numbers
    }
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
