//
// Created by user on 09.01.2021.
//

#ifndef TASK2_SINGLETYPE_TYPE_H
#define TASK2_SINGLETYPE_TYPE_H


#include <string>
#include <typeinfo>

std::string demangle(const char* name);

template <class T>
std::string type(const T& t) {

    return demangle(typeid(t).name());
}

#endif //TASK2_SINGLETYPE_TYPE_H
