#include "array.hpp"
#include <iostream>

using std::cout;
using std::endl;

Array::Array(const int &size) : arraySize(size){
    this->array = new int[size];
}

Array::~Array() {
    delete [] this->array;
}

int Array::operator[](int i) {
    if (i < 0)
        i = this->arraySize - i;

    return *(this->array+i);
}

int Array::add(int item) {
    if (size >= arraySize)
        return 0;

    this->array[size] = item;

    this->size++;

    return 1;
}

int Array::index(int item) {
    for (int i = 0; i < size; ++i) {
        if (this->array[i] == item)
            return i;
    }

    return -1;
}

int Array::insert(int item, int i) {
    if (i >= this->arraySize)
        return 0;
    if (this->size >= this->arraySize)
        return 0;

    for (int j = this->arraySize-1; j != i-1; --j) {
        if (j == i) {
            this->array[j] = item;
        } else
            this->array[j] = this->array[j-1];
    }
    this->size++;

    if (i == this->arraySize-1)
        this->size = i+1;

    return 1;
}

int Array::pop(int index) {
    if (index >= this->size)
        return 0;
    if (this->size >= this->arraySize)
        return 0;

    int i;

    for (i = index; i < this->size; ++i) {
        this->array[i] = this->array[i+1];
    }
    this->array[i+1] = 0;

    this->size--;
    return 1;
}

int Array::remove(int item) {
    int index = this->index(item);

    if (index < 0)
        return 0;

    return pop(index);
}

ostream &operator<<(ostream &out, const Array &myArray) {
    int Size = (myArray.size == 0 ?
            myArray.arraySize:
            myArray.size);

    out << "{";

    for (int i = 0; i < Size; ++i) {
        out << myArray.getArray()[i];
        if (i == Size -1)
            out << "}";
        else
            out << ", ";
    }

    return out;
}
