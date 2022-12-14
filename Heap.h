//
// Created by Khoa on 02/12/2022.
//

#ifndef DSALAB_HEAP_H
#define DSALAB_HEAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

/*
 * Implementation of Heap
 *
 * A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
 * Its implementation:
 * Node[i]
 * Parent: [(i - 1) / 2]
 * Left: i * 2 + 1
 * Right: i * 2 + 2
 * HeapUp(): O(logN)
 * HeapDown(): O(logN)
 * Build a Heap -> O(N) not O(logN)
 * Insert a Node: O(logN)
 * Pop: O(logN)
 *
 * Detail Implementation in lab5.cpp
 * */
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);

    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};


#endif //DSALAB_HEAP_H
