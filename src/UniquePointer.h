#ifndef QUARK_UNIQUE_POINTER
#define QUARK_UNIQUE_POINTER

#include <iostream>
#include <typeinfo>

template <typename T>
class UniquePointer
{
public:
    UniquePointer(T v)
    {
        data = new T (v);
        std::cout << "Allocated " << typeid(T).name() <<
        " at " << data <<
        " with value " << v << std::endl;
    }
    
    UniquePointer(const UniquePointer<T>& v)
    {
        data = new T(*(v.data));
        std::cout << "Allocated " << typeid(T).name() <<
        " at " << data <<
        " with value " << v << std::endl;
    }
    ~UniquePointer()
    {
        std::cout << "Deallocated " << typeid(T).name() <<
        " at " << data <<
        " with value " << *data << std::endl;
        delete data;
    }
    
    T& operator=(const T& v)
    {
        *data = v;
        return *data;
    }
    
    UniquePointer<T>& operator=(const UniquePointer<T>& v)
    {
        *data = *v.data;
        return *this;
    }
    
    T& operator*() const
    {
        return *data;
    }
    
    T& operator->() const
    {
        return *data;
    }
    
private:
    T* data;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const UniquePointer<T>& v)
{
    return out << *v;
}

template <typename T>
std::istream &operator>>( std::istream& input, UniquePointer<T>& v )
{
    input >> *v;
    return input;
}

void test0()
{
    std::cout << "Test0" << std::endl;
    UniquePointer<int> ptr(1);
    ptr = 42;
}

void test1()
{
    std::cout << "Test1" << std::endl;
    UniquePointer<int> ptr0(1);
    UniquePointer<int> ptr1(2);
    ptr0 = ptr1;
    ptr1 = 3;
}

void test2()
{
    std::cout << "Test2" << std::endl;
    UniquePointer<int> ptr0(1);
    UniquePointer<int> ptr1(ptr0);
    ptr1 = 3;
}

#endif
