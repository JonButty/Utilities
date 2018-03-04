//
//  main.cpp
//  Utilities
//
//  Created by Jonathan Butt on 3/1/18.
//

#include "gtest/gtest.h"
#include "UniquePointer.h"
#include <iostream>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SimpleTest, UniquePointerTest) {
    std::cout << "Test0" << std::endl;
    UniquePointer<int> ptr(1);
    
    EXPECT_EQ(*ptr,1);
}
