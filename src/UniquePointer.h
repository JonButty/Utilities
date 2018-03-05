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
    }
    
    UniquePointer(const UniquePointer<T>& v)
    {
        data = new T(*(v.data));
    }
    ~UniquePointer()
    {
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

#endif
