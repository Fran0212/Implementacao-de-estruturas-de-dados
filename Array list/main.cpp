#include <iostream>
#include "array.hpp"

int main(){
    Array arr(5);

    arr.add(1);
    arr.add(1);
    arr.add(1);
    arr.add(1);
    arr.pop(3);
    arr.insert(2, 1);
    arr.remove(2);
    std::cout << arr << std::endl;
    return 0;
}