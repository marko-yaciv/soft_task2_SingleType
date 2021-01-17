//
// Created by Marko on 17.01.2021.
//

#include "Helper.h"

Helper::Helper() {
    elements = {};
}

Helper::~Helper() {

}

//----public functions--------
void Helper::addNewElement() {
    try {
        Types type = chooseType();
        std::string value = getValue();
        SingleType anyTypeValue;
        assignValue(anyTypeValue, type, value);
        elements.push_back(anyTypeValue);
    }
    catch (std::bad_cast& err) {
        std::cerr << err.what();
    }
    waiter();
}

void Helper::changeElement() {
    try {
        int index = getIndex(elements.size());

        Types type = chooseType();
        std::string value = getValue();
        assignValue(elements[index], type, value);
    }
    catch(std::bad_cast& err) {
        std::cerr << err.what() << std::endl;
    }
    catch(std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void Helper::outputElement() {
    try {
        int index = getIndex(elements.size());

        std::cout << elements[index] << std:: endl;
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void Helper::swapElements() {
    try {
        int index1 = getIndex(elements.size());
        int index2 = getIndex(elements.size());

        swap(elements[index1], elements[index2]);
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void Helper::getType() {
    try {
        int index = getIndex(elements.size());
        std::cout << elements[index].getType() << std::endl;
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

//----Private functions---------
Types Helper::chooseType() {
    std::cout << "1 - Bool\n" \
                 "2 - char\n" \
                 "3 - char32\n" \
                 "4 - int\n" \
                 "5 - long long\n" \
                 "6 - unsigned long long\n" \
                 "7 - float\n" \
                 "8 - double\n" \
                 "9 - long double\n"\
                 "Please choose a type of value: ";

    std::string choice;
    getline(std::cin, choice);

    return static_cast<Types>(std::stoi(choice) - 1);
}

std::string Helper::getValue() {
    std::cout << "Please enter a value: ";
    std::string value{};
    getline(std::cin, value);

    return value;
}

void Helper::assignValue(SingleType& anyType, Types type, const std::string& value) {
    switch (type) {
        case Types::Bool:
            anyType = static_cast<bool>(stoi(value));
            break;
        case Types::Char:
            anyType = static_cast<char>(stoi(value));
            break;
        case Types::Char32:
            anyType = static_cast<char32_t>(stoi(value));
            break;
        case Types::Int:
            anyType = stoi(value);
            break;
        case Types::Int64:
            anyType = stoll(value);
            break;
        case Types::uInt64:
            anyType = stoull(value);
            break;
        case Types::Float:
            anyType = stof(value);
            break;
        case Types::Double:
            anyType = stod(value);
            break;
        case Types::lDouble:
            anyType = stold(value);
            break;
    }
}

int Helper::getIndex(int size) {
    std::cout << "There are " << size << " elements in vector\n";
    std::cout << "Please, enter an index of an element: ";
    std::string stringIndex;
    getline(std::cin, stringIndex);
    int index = stoi(stringIndex);

    if (index < 0 || index > size - 1) {
        throw std::out_of_range("Out of elements range");
    }

    return index;
}

void Helper::waiter() {
    std::cout << "Press Enter to continue\n";
    getchar();
}

void Helper::swap(SingleType& a, SingleType& b) {
    a.swap(b);
}

