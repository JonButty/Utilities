//
//  Singleton-test.h
//  Utilities-Test
//
//  Created by Jonathan Butt on 3/5/18.
//
#ifndef QUARK_SINGLETON_TEST
#define QUARK_SINGLETON_TEST

#define SINGLETON_TESTS SingletonTests

#include "Singleton.h"

#include <gtest/gtest.h>

class TestSingletonClass : public Singleton<TestSingletonClass>
{
public:
    int GetIntVal() const
    {
        return _intVal;
    }
    void SetIntVal(int v)
    {
        _intVal = v;
    }
private:
    int _intVal;
};

TEST(SINGLETON_TESTS, GetValue)
{
    TestSingletonClass::getInstance().SetIntVal(5);
    EXPECT_EQ(TestSingletonClass::getInstance().GetIntVal(),5);
}

TEST(SINGLETON_TESTS, MultipleInstances)
{
    TestSingletonClass::getInstance().SetIntVal(5);
    TestSingletonClass s;
    s.SetIntVal(10);
    EXPECT_EQ(s.GetIntVal(),10);
}
#endif
