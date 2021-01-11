#include "SingleType.h"

int squareRoot(int val){
    if(val < 0) throw std::bad_exception();
    return (int)sqrt(val);
}
