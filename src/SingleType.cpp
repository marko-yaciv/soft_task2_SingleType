#include "SingleType.h"
#include "type.h"

int squareRoot(int val){
    if(val < 0) throw std::bad_exception();
    return (int)sqrt(val);
}

std::ostream &operator<< (std::ostream &out, const SingleType& value) {
    switch (value.currentType) {
        case SingleType::Types::Bool: out << value.Variable.boolT; break;
        case SingleType::Types::Char: out << value.Variable.charT; break;
        case SingleType::Types::Char32: out << value.Variable.char32T; break;
        case SingleType::Types::Int: out << value.Variable.intT; break;
        case SingleType::Types::Int64: out << value.Variable.int64T; break;
        case SingleType::Types::uInt64: out << value.Variable.uint64T; break;
        case SingleType::Types::Float: out << value.Variable.floatT; break;
        case SingleType::Types::Double: out << value.Variable.doubleT; break;
        case SingleType::Types::lDouble: out << value.Variable.ldoubleT; break;
    }
    return out;
}


SingleType::SingleType(bool val) noexcept{
    Variable.boolT = val;
    currentType = Types::Bool;
}

SingleType::SingleType(char val)noexcept{
    Variable.charT = val;
    currentType = Types::Char;
}

SingleType::SingleType(char32_t val) noexcept{
    Variable.char32T = val;
    currentType = Types::Char32;
}

SingleType::SingleType(int val) noexcept{
    Variable.intT = val;
    currentType = Types::Int;
}

SingleType::SingleType(int64_t val) noexcept{
    Variable.int64T = val;
    currentType = Types::Int64;
}

SingleType::SingleType(uint64_t val) noexcept{
    Variable.uint64T = val;
    currentType = Types::uInt64;
}

SingleType::SingleType(float val) noexcept{
    Variable.floatT = val;
    currentType = Types::Float;
}

SingleType::SingleType(double val) noexcept{
    Variable.doubleT = val;
    currentType = Types::Double;
}

SingleType::SingleType(long double val) noexcept{
    Variable.ldoubleT = val;
    currentType = Types::lDouble;
}

SingleType::SingleType(const SingleType &other) noexcept{
    Variable = other.Variable;
    currentType = other.currentType;
}

SingleType::SingleType(SingleType &&other)  noexcept{
    Variable = other.Variable;
    currentType = other.currentType;
}


bool SingleType::toBool() const {
    if(currentType != Types::Bool) throw std::bad_cast();
    return Variable.boolT;
}

char SingleType::toChar() const {
    if(currentType != Types::Char) throw std::bad_cast();
    return Variable.charT;
}

char32_t SingleType::toChar32() const {
    if(currentType != Types::Char32) throw std::bad_cast();
    return Variable.char32T;
}

int SingleType::toInt() const {
    if(currentType != Types::Int) throw std::bad_cast();
    return Variable.intT;
}

int64_t SingleType::toInt64() const {
    if(currentType != Types::Int64) throw std::bad_cast();
    return Variable.int64T;
}

uint64_t SingleType::touInt64() const {
    if(currentType != Types::uInt64) throw std::bad_cast();
    return Variable.uint64T;
}

float SingleType::toFloat() const {
    if(currentType != Types::Float) throw std::bad_cast();
    return Variable.floatT;
}

double SingleType::toDouble() const {
    if(currentType != Types::Double) throw std::bad_cast();
    return Variable.doubleT;
}

long double SingleType::tolDouble() const {
    if(currentType != Types::lDouble) throw std::bad_cast();
    return Variable.ldoubleT;
}


SingleType &SingleType::operator = (bool val) noexcept{
    Variable.boolT = val;
    currentType = Types::Bool;
    return *this;
}

SingleType& SingleType::operator = (char val)noexcept{
    Variable.charT = val;
    currentType = Types::Char;
    return *this;
}

SingleType& SingleType::operator = (char32_t val)noexcept{
    Variable.char32T = val;
    currentType = Types::Char32;
    return *this;
}

SingleType& SingleType::operator = (int val)noexcept{
    Variable.intT = val;
    currentType = Types::Int;
    return *this;
}

SingleType& SingleType::operator = (int64_t val)noexcept{
    Variable.int64T = val;
    currentType = Types::Int64;
    return *this;
}

SingleType& SingleType::operator = (uint64_t val)noexcept{
    Variable.uint64T = val;
    currentType = Types::uInt64;
    return *this;
}

SingleType& SingleType::operator = (float val)noexcept{
    Variable.floatT = val;
    currentType = Types::Float;
    return *this;
}

SingleType& SingleType::operator = (double val)noexcept{
    Variable.doubleT = val;
    currentType = Types::Double;
    return *this;
}
SingleType& SingleType::operator = (long double val)noexcept{
    Variable.ldoubleT = val;
    currentType = Types::lDouble;
    return *this;
}

std::string SingleType::getType() const {

    switch (this->currentType) {
        case SingleType::Types::Bool:    return type(Variable.boolT);
        case SingleType::Types::Char:    return type(Variable.charT);
        case SingleType::Types::Char32:  return type(Variable.char32T);
        case SingleType::Types::Int:     return type(Variable.intT);
        case SingleType::Types::Int64:   return type(Variable.int64T);
        case SingleType::Types::uInt64:  return type(Variable.uint64T);
        case SingleType::Types::Float:   return type(Variable.floatT);
        case SingleType::Types::Double:  return type(Variable.doubleT);
        case SingleType::Types::lDouble: return type(Variable.ldoubleT);
    }
    return "none";
}

void SingleType::swap(SingleType &val2) {
    auto tmp = *this;

    Variable = val2.Variable;
    currentType = val2.currentType;

    val2.Variable = tmp.Variable;
    val2.currentType = tmp.currentType;
}

SingleType &SingleType::operator=(const SingleType &other) noexcept = default;

SingleType &SingleType::operator=(SingleType &&other) noexcept = default;
