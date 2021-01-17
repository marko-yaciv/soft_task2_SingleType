//
// Created by Marko on 17.01.2021.
//

#ifndef TASK2_SINGLETYPE_HELPER_H
#define TASK2_SINGLETYPE_HELPER_H
#include <vector>
#include "SingleType.h"

class Helper{
    std::vector<SingleType> elements;
private:
//prints message that work is completed
    void waiter();

//Allows user to choose type from a given list
    Types chooseType();

//assign <anyType> variable of type <type> with value <value>
    void assignValue(SingleType& anyType, Types type,const std::string& value);

//allows user to type a value and returns it
    std::string getValue();

/*asks user to type index and returns it.
 If index is incorrect, throws std::out_of_range*/
    int getIndex(int size);

//swaps two variables of type SingleType
    void swap(SingleType& a, SingleType& b);
public:
    Helper();
    ~Helper();

// Create a new element of type "AnyType" and then adds it to the vector
    void addNewElement();

// Change an element which exists in vector
    void changeElement();

// Output an element of a particular type
    void outputElement();

// Swap two values which exists in a vector
    void swapElements();

// Output a type of an element in a vector
    void getType();
};




#endif //TASK2_SINGLETYPE_HELPER_H
