#include "gtest/gtest.h"
#include "../../src/SingleType.h"
#include "customTypeForTest.h"
TEST(standartTypesTests, constructTest){
    SingleType<int> integer(8);
    SingleType<long double> lDouble = 15.284729347249242L;

    ASSERT_EQ(integer.getValue(),8);
    ASSERT_DOUBLE_EQ(lDouble.getValue(),15.284729347249242L);
}

TEST(standartTypesTests, correctType){
    SingleType<int> integer(8);
    SingleType<long double> lDouble = 15.284729347249242L;

    ASSERT_EQ(integer.getType(), typeid(8).name());
    ASSERT_EQ(lDouble.getType(), typeid(15.284729347249242L).name());
}

TEST(standartTypesTests, assingTest){
    SingleType<int> integer(8);
    SingleType<long double> lDouble = 15.284729347249242L;
    int number = 20;

    integer = number;
    lDouble = 20.2323L;
    auto lDouble2 = lDouble;

    EXPECT_EQ(integer.getValue(), number);
    EXPECT_DOUBLE_EQ(lDouble.getValue(), 20.2323L);

    EXPECT_DOUBLE_EQ(lDouble2.getValue(),lDouble.getValue());
    EXPECT_EQ(lDouble2.getType(), lDouble.getType());
}

TEST(standartTypesTests, compareTest) {
    SingleType<int> integer(8);
    SingleType<long double> lDouble = 15.284729347249242L;
    int iNumber = 20;
    SingleType<long double> dNumber = 30.09088L;
    EXPECT_FALSE(integer == iNumber);
    EXPECT_TRUE(integer <= iNumber);
    EXPECT_TRUE(integer < iNumber);

    EXPECT_TRUE(dNumber >= lDouble);
    EXPECT_TRUE(dNumber > lDouble);
}

TEST(standartTypesTests, swapTest) {
    SingleType<int> integer(8);
    SingleType<int> integer2 = 28;

    EXPECT_LT(integer,integer2);

    integer.swap(integer2);

    EXPECT_GT(integer,integer2);
}


TEST(customTypeTest, initialiseTest){
    SingleType<MyClass> val{MyClass(5,10.6)};

    EXPECT_EQ(val.getType(), typeid(MyClass).name());
}
