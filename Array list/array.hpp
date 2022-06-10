#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using std::ostream;

class Array{
// out
friend ostream &operator<<(ostream &, const Array &);
private:
    int *array;
    int size = 0;
    int arraySize;
public:
    Array(const int &);
    ~Array();

    // getters
    int *getArray() const {return this->array;}
    int getSize() const {return this->size;}
    int operator[](int i);

    // setters
    int add(int);
    int insert(int, int);
    int remove(int);
    int pop(int);
    int index(int);
};

#endif