//
// Created by user on 04.01.2021.
//

#ifndef TASK_2_SINGLETYPE_SINGLETYPE_H
#define TASK_2_SINGLETYPE_SINGLETYPE_H

#include <typeinfo>
#include <iostream>
#include <memory>
#include <cmath>


class SingleType {
    union {
        bool boolT;
        char charT;
        char32_t char32T;
        int intT;
        int64_t int64T;
        uint64_t uint64T;
        float floatT;
        double doubleT;
        long double ldoubleT;
    }Variable{};

    const static enum Types{
        Bool, Char, Char32, Int, Int64, uInt64, Float, Double, lDouble
    }Types;

    int currentType{};
public:
    // constructors
    SingleType() = default;
    SingleType(bool val) noexcept;
    SingleType(char val) noexcept;
    SingleType(char32_t val) noexcept;
    SingleType(int val) noexcept;
    SingleType(int64_t val) noexcept;
    SingleType(uint64_t val) noexcept;
    SingleType(float val) noexcept;
    SingleType(double val) noexcept;
    SingleType(long double val) noexcept;

    SingleType(const SingleType& other) noexcept;
    SingleType(SingleType&& other) noexcept;
    //destructor
    ~SingleType() = default;

    [[nodiscard]] bool toBool() const;
    [[nodiscard]] char toChar() const;
    [[nodiscard]] char32_t toChar32() const;
    [[nodiscard]] int toInt() const;
    [[nodiscard]] int64_t toInt64() const;
    [[nodiscard]] uint64_t touInt64() const;
    [[nodiscard]] float toFloat() const;
    [[nodiscard]] double toDouble() const;
    [[nodiscard]] long double tolDouble() const;

    // member function that returns type of variable as std::type_info object
    [[nodiscard]] std::string getType() const;
    void swap(SingleType& val2);


    SingleType& operator = (bool val)  noexcept;
    SingleType& operator = (char val) noexcept;
    SingleType& operator = (char32_t val) noexcept;
    SingleType& operator = (int val) noexcept;
    SingleType& operator = (int64_t val) noexcept;
    SingleType& operator = (uint64_t val) noexcept;
    SingleType& operator = (float val) noexcept;
    SingleType& operator = (double val) noexcept;
    SingleType& operator = (long double val) noexcept;

    SingleType& operator = (const SingleType& other) noexcept;
    SingleType& operator = (SingleType&& other) noexcept;
    friend std::ostream &operator<< (std::ostream &out, const SingleType& value);
};

int squareRoot(int val);

#endif //TASK_2_SINGLETYPE_SINGLETYPE_H
