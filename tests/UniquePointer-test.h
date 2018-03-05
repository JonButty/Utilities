//
//  UniquePointer-test.hpp
//  Utilities-Test
//
//  Created by Jonathan Butt on 3/3/18.
//

#ifndef QUARK_UNIQUE_POINTER_TEST
#define QUARK_UNIQUE_POINTER_TEST

#define UNIQUE_POINTER_TESTS UniquePointerTests

#include "UniquePointer.h"

#include <gtest/gtest.h>

TEST(UNIQUE_POINTER_TESTS, Construction)
{
    UniquePointer<int> ptr(1);
    EXPECT_EQ(*ptr,1);
}

TEST(UNIQUE_POINTER_TESTS, Assignment1)
{
    UniquePointer<int> ptr(1);
    ptr = 42;
    EXPECT_EQ(*ptr,42);
}

TEST(UNIQUE_POINTER_TESTS, Assignment2)
{
    UniquePointer<int> ptr0(1);
    UniquePointer<int> ptr1(2);
    ptr0 = ptr1;
    ptr1 = 3;
    EXPECT_EQ(*ptr0,2);
    EXPECT_EQ(*ptr1,3);
}

TEST(UNIQUE_POINTER_TESTS, CopyConstructor)
{
    UniquePointer<int> ptr0(1);
    UniquePointer<int> ptr1(ptr0);
    ptr1 = 3;
    EXPECT_EQ(*ptr0,1);
    EXPECT_EQ(*ptr1,3);
}

#endif /* QUARK_UNIQUE_POINTER_TEST */
