#include <iostream>
#include "SingleType.h"
template<class T>
SingleType foo(T val){
    return SingleType(val);
}

int main() {

    SingleType val1('a');
    SingleType val2 = 'f';
    std::cout << "Value 1: "<< val1 <<" Type: " << val1.getType() <<  "\t"
              << "Value 2: " << val2  <<" Type: "  << val2.getType() << "\n";

    SingleType val3 = val2;
    val2 = 10.25345345;
    std::cout << "Value 2: "<< val2 << " Type: " << val2.getType() << "\t"
              << "Value 3: "<< val3 << " Type: " << val3.getType() << std::endl;
    SingleType val4 = foo(20.546);
    std::cout<< "Value 4: "<< val4 <<" Type: "<< val4.getType() << std::endl;

    val1.swap(val4);
    std::cout << "Swapped Value 1 and Value 4:\t"<<
                "Value 1: "<< val1 <<" Type: " << val1.getType() <<  "  |  " <<
                "Value 4: "<< val4 <<" Type: " << val4.getType() << std::endl;
    try{
        auto a = val2.toDouble();
        std::cout<< "Casted variable from Value 2: " << a <<std::endl;
        auto b = val1.toInt();
        std::cout<< "Casted variable from Value 1: " << b <<std::endl;
    }catch(std::bad_cast& ex){
        std::cout<<ex.what();
        return 1;
    }

    return 0;
}
