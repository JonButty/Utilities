//
//  Singleton.h
//  Utilities
//
//  Created by Jonathan Butt on 3/4/18.
//
#ifndef QUARK_SINGLETON
#define QUARK_SINGLETON

#include <cstdlib>

template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T    instance;
        return instance;
    }
    Singleton() {}
    virtual ~Singleton() {}
private:

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    Singleton(Singleton<T> const&)               = delete;
    void operator=(Singleton<T> const&)  = delete;
};

#endif
