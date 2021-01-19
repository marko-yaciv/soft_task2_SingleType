#include "SingleType.h"

//--------constructors---------
SingleType::SingleType() {
    currentType = Types::Bool;
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

//----------convert functions---------
bool SingleType::toBool() const {
    validateType(Types::Bool);
    return Variable.boolT;
}

char SingleType::toChar() const {
    validateType(Types::Char);
    return Variable.charT;
}

char32_t SingleType::toChar32() const {
    validateType(Types::Char32);
    return Variable.char32T;
}

int SingleType::toInt() const {
    validateType(Types::Int);
    return Variable.intT;
}

int64_t SingleType::toInt64() const {
    validateType(Types::Int64);
    return Variable.int64T;
}

uint64_t SingleType::touInt64() const {
    validateType(Types::uInt64);
    return Variable.uint64T;
}

float SingleType::toFloat() const {
    validateType(Types::Float);
    return Variable.floatT;
}

double SingleType::toDouble() const {
    validateType(Types::Double);
    return Variable.doubleT;
}

long double SingleType::tolDouble() const {
    validateType(Types::lDouble);
    return Variable.ldoubleT;
}

//--------assignment operators-------------
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
SingleType& SingleType::operator = (long double val) noexcept{
    Variable.ldoubleT = val;
    currentType = Types::lDouble;
    return *this;
}
SingleType &SingleType::operator=(const SingleType &other) noexcept = default;

SingleType &SingleType::operator=(SingleType &&other) noexcept = default;


std::string SingleType::getType() const{
    return std::string(typeToString()).substr(7);
}

void SingleType::swap(SingleType &val2){
    auto tmp = *this;

    Variable = val2.Variable;
    currentType = val2.currentType;

    val2.Variable = tmp.Variable;
    val2.currentType = tmp.currentType;
}

/*Private functions*/
const char * SingleType::typeToString() const{
    switch (currentType){
        CASE_TYPE(Types::Bool)
        CASE_TYPE(Types::Char)
        CASE_TYPE(Types::Char32)
        CASE_TYPE(Types::Int)
        CASE_TYPE(Types::Int64)
        CASE_TYPE(Types::uInt64)
        CASE_TYPE(Types::Float)
        CASE_TYPE(Types::Double)
        CASE_TYPE(Types::lDouble)
    }
    return "none";
}

void SingleType::validateType(Types type) const{
    if(currentType != type){
        throw std::bad_cast();
    }
}

std::ostream &operator<< (std::ostream &out, const SingleType& value) {
    switch (value.currentType) {
        case Types::Bool: out << value.Variable.boolT; break;
        case Types::Char: out << value.Variable.charT; break;
        case Types::Char32: out << value.Variable.char32T; break;
        case Types::Int: out << value.Variable.intT; break;
        case Types::Int64: out << value.Variable.int64T; break;
        case Types::uInt64: out << value.Variable.uint64T; break;
        case Types::Float: out << value.Variable.floatT; break;
        case Types::Double: out << value.Variable.doubleT; break;
        case Types::lDouble: out << value.Variable.ldoubleT; break;
    }
    return out;
}
