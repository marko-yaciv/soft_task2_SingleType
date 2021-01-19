#include "gtest/gtest.h"
#include "../../src/SingleType.h"


TEST(asssignmentOperator, boolType){
    SingleType variable;
    variable = false;
    EXPECT_EQ(variable.getType(),"Bool");
}
TEST(asssignmentOperator, charType){
    SingleType variable;
    variable = 'a';
    EXPECT_EQ(variable.getType(),"Char");
}
TEST(asssignmentOperator, Char32Type){
    SingleType variable;
    variable = static_cast<char32_t >('d');
    EXPECT_EQ(variable.getType(),"Char32");
}
TEST(asssignmentOperator, intType){
    SingleType variable;
    variable = 5;
    EXPECT_EQ(variable.getType(),"Int");
}
TEST(asssignmentOperator, int64Type){
    SingleType variable;
    variable = 7365836538573568364ll;
    EXPECT_EQ(variable.getType(),"Int64");
}
TEST(asssignmentOperator, uint64Type){
    SingleType variable;
    variable = 9998284672648624237ull;
    EXPECT_EQ(variable.getType(),"uInt64");
}
TEST(asssignmentOperator, floatType){
    SingleType variable;
    variable = 10.324f;
    EXPECT_EQ(variable.getType(),"Float");
}
TEST(asssignmentOperator, doubleType){
    SingleType variable;
    variable = 10.234424;
    EXPECT_EQ(variable.getType(),"Double");
}
TEST(asssignmentOperator, ldoubleType){
    SingleType variable;
    variable = 10.6346345234223432423424243242424l;
    EXPECT_EQ(variable.getType(),"lDouble");
}

TEST(convertToStdType, boolT)
{
    SingleType value(false);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, charT)
{
    SingleType value('f');
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, char32T)
{
    SingleType value(static_cast<char32_t>('f'));
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, intT)
{
    SingleType value(5);
    EXPECT_THROW(value.toDouble(),std::bad_cast);
}
TEST(convertToStdType, int64T)
{
    SingleType value(4234324242424234LL);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, uint64T)
{
    SingleType value(7348536485678346583ULL);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, floatT)
{
    SingleType value(10.342f);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, doubleT)
{
    SingleType value(10.74534534535);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}
TEST(convertToStdType, ldoubleT)
{
    SingleType value(10.298492739472397423984792L);
    EXPECT_THROW(value.toInt(),std::bad_cast);
}