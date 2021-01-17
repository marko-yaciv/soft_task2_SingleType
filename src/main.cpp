#include <iostream>
#include <vector>
#include "SingleType.h"
#include "Helper.h"
enum Options {
    Exit,
    AddNewElement,
    ChangeElement,
    OutputElement,
    Swap,
    GetType
};
int main() {

    bool condition{true};
    std::string choice{};
    int option{0};
    Helper service;

    while (condition) {
        std::cout << "1 - Add new element to a vector\n" \
                     "2 - Change a value\n" \
                     "3 - Output a value\n" \
                     "4 - Swap two values\n" \
                     "5 - Get a type of an element \n" \
                     "0 - Exit\n";

        std::cout << "Please, enter your choice: ";
        getline(std::cin, choice);
        try {
            option = std::stoi(choice);
        }catch (std::invalid_argument& ex){
            std::cout<< ex.what() << std::endl;
            continue;
        }
        switch (option) {
            case Options::AddNewElement: service.addNewElement(); break;
            case Options::ChangeElement: service.changeElement(); break;
            case Options::OutputElement: service.outputElement(); break;
            case Options::Swap: service.swapElements(); break;
            case Options::GetType: service.getType(); break;
            case Options::Exit: condition = false;
            default: continue;
        }
    }

    return 0;
}
