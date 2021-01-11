#include <iostream>
#include "SingleType.h"

int main() {
    SingleType<int> integer = 10;
    SingleType<int> integer2(integer);
    SingleType<double> floatpoint = 15.23;

    std::cout << integer << "\t" << floatpoint << "\t" << integer2 << std::endl;

    integer2 = 15;
    SingleType<double> f2 = std::move(floatpoint);
    std::cout << integer << "\t" << integer2 << "\t" << f2 << std::endl;

    integer2.swap(integer);
    std::cout << integer << "\t" << "\t" << integer2 <<  std::endl;

    std::cout<< "Type of double is: "<<f2.getType()<<std::endl;
    return 0;
}
