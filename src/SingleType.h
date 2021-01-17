//
// Created by user on 04.01.2021.
//

#ifndef TASK_2_SINGLETYPE_SINGLETYPE_H
#define TASK_2_SINGLETYPE_SINGLETYPE_H

#include <typeinfo>
#include <iostream>
#include <memory>
#include <cmath>

/*This macro function will return
 value of enum <Types> as char* */
#define CASE_TYPE(datatype) case datatype: return #datatype; break;


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

    enum Types{
        Bool, Char, Char32, Int, Int64, uInt64, Float, Double, lDouble
    }currentType;

    /* function will throw exception if
     <currentType> is not equal to <type>*/
    void validateType(Types type) const;

    /*Function uses macro CASE_TYPE
     * to return type of kept value*/
    [[nodiscard]] const char * typeToString() const;
public:
    // constructors for each supported type
    SingleType();
    SingleType(bool val) noexcept;
    SingleType(char val) noexcept;
    SingleType(char32_t val) noexcept;
    SingleType(int val) noexcept;
    SingleType(int64_t val) noexcept;
    SingleType(uint64_t val) noexcept;
    SingleType(float val) noexcept;
    SingleType(double val) noexcept;
    SingleType(long double val) noexcept;
    SingleType(SingleType&& other) noexcept;
    SingleType(const SingleType& other) noexcept;

    ~SingleType() = default;

    /*nodiscard will show warning
     * when return type will not be used*/
    [[nodiscard]] bool toBool() const;
    [[nodiscard]] char toChar() const;
    [[nodiscard]] char32_t toChar32() const;
    [[nodiscard]] int toInt() const;
    [[nodiscard]] int64_t toInt64() const;
    [[nodiscard]] uint64_t touInt64() const;
    [[nodiscard]] float toFloat() const;
    [[nodiscard]] double toDouble() const;
    [[nodiscard]] long double tolDouble() const;

    // member function that returns type of variable as string object
    [[nodiscard]] std::string getType() const;

    //function to swap two objects of SingleType type;
    void swap(SingleType& val2);

    //assignment operators for each supported type
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

    //function for easy printing type by std::cout <<
    friend std::ostream &operator<< (std::ostream &out, const SingleType& value);
};


#endif //TASK_2_SINGLETYPE_SINGLETYPE_H
