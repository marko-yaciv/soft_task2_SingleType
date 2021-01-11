#include "gtest/gtest.h"
#include "../../src/SingleType.h"

TEST(firstTest, test1){
    EXPECT_EQ(4, squareRoot(16));
    ASSERT_ANY_THROW(squareRoot(-5));
}
