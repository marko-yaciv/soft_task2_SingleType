//
// Created by user on 04.01.2021.
//

#ifndef TASK_2_SINGLETYPE_SINGLETYPE_H
#define TASK_2_SINGLETYPE_SINGLETYPE_H

#include <typeinfo>
#include <iostream>
#include <memory>

template<class Type> class SingleType;
template<class T> std::ostream &operator<< (std::ostream &out, const SingleType<T>& value) {
    out << *value.variable;
    return out;
}

template<class Type>
class SingleType {
    std::shared_ptr<Type> variable;
public:
    // constructors
    SingleType();
    SingleType(Type& val);
    SingleType(Type&& val);
    SingleType(const SingleType& other) noexcept;
    SingleType(SingleType&& other) noexcept ;

    //destructor
    ~SingleType();

    // member function that returns type of variable as std::type_info object
    const char* getType() const;
    void swap(SingleType& val2);

    bool operator >  (const SingleType& other) const;
    bool operator >= (const SingleType& other) const;
    bool operator <  (const SingleType& other) const;
    bool operator <= (const SingleType& other) const;
    bool operator == (const SingleType& other) const;

    SingleType& operator = (const SingleType& other) noexcept;
    SingleType& operator = (SingleType&& other) noexcept;
    SingleType& operator = (const Type& val) noexcept;
    SingleType& operator = (Type&& val) noexcept;


    friend std::ostream &operator<< <>(std::ostream &out, const SingleType& value);
};

template<class Type>
SingleType<Type>::SingleType() {
    variable = std::make_shared<Type>(nullptr);
}

template<class Type>
SingleType<Type>::SingleType(Type &val) {
    variable = std::make_shared<Type>(val);
}

template<class Type>
SingleType<Type>::SingleType(Type &&val) {
    variable = std::make_shared<Type>(std::move(val));
}

template<class Type>
SingleType<Type>::SingleType(const SingleType &other) noexcept {
    variable = other.variable;
}

template<class Type>
SingleType<Type>::SingleType(SingleType &&other) noexcept {
    variable = std::move(other.variable);
}

template<class Type>
SingleType<Type>::~SingleType() {

}

template<class Type>
const char* SingleType<Type>::getType() const {
    return typeid(*variable).name();
}

template<class Type>
void SingleType<Type>::swap(SingleType &val2) {
    auto tmp = *this;
    *this = val2;
    val2 = tmp;
}

template<class Type>
bool SingleType<Type>::operator>(const SingleType &other) const {
    return *variable > *other.variable;
}

template<class Type>
bool SingleType<Type>::operator>=(const SingleType &other) const {
    return *variable >= *other.variable;
}

template<class Type>
bool SingleType<Type>::operator<(const SingleType &other) const {
    return *variable < *other.variable;
}

template<class Type>
bool SingleType<Type>::operator<=(const SingleType &other) const {
    return *variable <= *other.variable;
}

template<class Type>
bool SingleType<Type>::operator==(const SingleType &other) const {
    return *variable == *other.variable;
}

template<class Type>
SingleType<Type> &SingleType<Type>::operator=(const SingleType &other) noexcept {
    variable = other.variable;
    return *this;
}

template<class Type>
SingleType<Type> &SingleType<Type>::operator=(SingleType &&other) noexcept {
    variable = std::move(other.variable);
    return *this;
}

template<class Type>
SingleType<Type> &SingleType<Type>::operator=(const Type &val) noexcept {
    variable = std::make_shared<Type>(val);
    return *this;
}

template<class Type>
SingleType<Type> &SingleType<Type>::operator=(Type &&val) noexcept {
    variable = std::make_shared<Type>(std::move(val));
    return *this;
}


#endif //TASK_2_SINGLETYPE_SINGLETYPE_H
