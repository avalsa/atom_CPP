//
// Created by svuatoslav on 3/2/17.
//
#ifndef HOMEWORK_2_ARRAY_H
#define HOMEWORK_2_ARRAY_H

#include <cstdint>
#include <cstring>
#include <cmath>
#include "ArrayPointer.h"
#include "ArrayPointerBool.h"
#include "Collection.h"
#include "Iterator.h"
#include "Utils.h"


template <typename T>
class Array:Collection<T>
{
private:
    int current_;
    ArrayPointer<T> * pointer_;

public:
    Iterator<T> begin();
    Iterator<T> end();

    explicit Array(size_t capacity);
    Array(const Array<T>&);
    ~Array();
    T& operator[](size_t position) const;
    T& At(size_t position) const;
    const Array<T>& operator=(const Array<T>&);//inc value of pointer
    Array<T>& clone() const; //deep copy of object
    bool ok() const;
    void dump(std::ostream& out,size_t displacement = 0) const;
    size_t capacity() const;
    T& operator*() const;
    Array<T>& operator+(int) const;
    Array<T>& operator-(int) const;
    Array<T>& operator++();
    Array<T>& operator--();
    Array<T>& operator+=(int);
    Array<T>& operator-=(int);
};


template <typename T>
Array<T>::Array(size_t capacity):current_(0), pointer_(new ArrayPointer<T>(capacity))
{
    INFO(*this);
}

template <typename T>
Array<T>::Array(const Array<T>& that):current_(0), pointer_(that.pointer_)
{
    that.pointer_->link();
    INFO(*this);
}

template <typename T>
Array<T>::~Array()
{
    INFO(*this);
    if (pointer_->dislink()) delete pointer_;
}

template <typename T>
T& Array<T>::operator[](size_t position) const
{
    INFO(*this);
    return (*pointer_)[position];
}

template <typename T>
T& Array<T>::At(size_t position) const
{
    INFO(*this);
    return pointer_->At(position);
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array& that)
{
    INFO(*this);
    Array swapper(that);
    std::swap(*this, swapper);
    INFO(*this);
    return *this;
}

template <typename T>
Array<T>& Array<T>::clone() const
{
    INFO(*this);
    Array<T> * ret = new Array<T>(0);
    ret->pointer_ = new ArrayPointer<T>(*this->pointer_);
    return *ret;
}

template <typename T>
bool Array<T>::ok() const
{
    return pointer_->ok();
}

template <typename T>
void Array<T>::dump(std::ostream& out,size_t displacement) const
{
    char *tabs = utils::getPadding('\t',displacement);

    out<<tabs<<"Array("<<(ok()?"OK":"ERROR")<<") @ "<<(void*)this<<'\n';
    out<<tabs<<"{\n";
    out<<tabs<<"\tcurrent: "<<current_<<'\n';
    out<<tabs<<"\tpointer:\n";
    pointer_->dump(out,displacement+2);
    out<<tabs<<"}\n";

    delete [] tabs;
}

template <typename T>
size_t Array<T>::capacity() const
{
    INFO(*this);
    return pointer_->capacity();
}

template <typename T>
T& Array<T>::operator*() const
{
    INFO(*this);
    if (current_ < 0) throw std::out_of_range("minus is not allow");
    return (*pointer_)[current_];
}

template <typename T>
Array<T>& Array<T>::operator+(int value) const
{
    INFO(*this);
    Array<T> * ret = new Array<T>(*this);
    ret->current_ += value;
    return *ret;
}

template <typename T>
Array<T>& Array<T>::operator-(int value) const
{
    INFO(*this);
    Array<T> * ret = new Array<T>(*this);
    ret->current_ -= value;
    return *ret;
}

template <typename T>
Array<T>& Array<T>::operator++()
{
    INFO(*this);
    INFO(*this);
    current_++;
    INFO(*this);
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator--()
{
    INFO(*this);
    current_--;
    INFO(*this);
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator+=(int value)
{
    INFO(*this);
    current_+=value;
    INFO(*this);
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(int value)
{
    INFO(*this);
    current_-=value;
    INFO(*this);
    return *this;
}

template <typename T>
Iterator<T> Array<T>::begin()
{
    INFO(*this);
    return Iterator<T>(this,0);
}

template <typename T>
Iterator<T> Array<T>::end()
{
    INFO(*this);
    return Iterator<T>(this,capacity());
}
//
//
//
//
//
//
//
//template <typename T>
//class Iterator {
//public:
//
//private:
//
//
//
//};

#endif //HOMEWORK_2_ARRAY_H