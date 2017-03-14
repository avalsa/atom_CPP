//
// Created by svuatoslav on 3/14/17.
//

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <cassert>
#include <iostream>

#define ERROR_LOG

#define ERROR_STREAM std::cerr
#define LOG_STREAM std::cout

#ifdef FULL_LOG

#define INFO( object )          \
if(!(object).ok())              \
{                               \
    (object).dump(ERROR_STREAM);\
    assert(!"Object is OK");    \
}                               \
else                            \
{                               \
    (object).dump(LOG_STREAM);  \
}

#else
#ifdef ERROR_LOG

#define INFO( object )          \
if(!(object).ok())              \
{                               \
    (object).dump(ERROR_STREAM);\
    assert(!"Object is ok");    \
}

#else
#define INFO( object )
#endif
#endif

namespace utils
{
    char* getPadding(char symbol, int amount)
    {
        char* padding;
        padding = new char[amount+1];
        for(int i = 0;i<amount;i++) padding[i]=symbol;
        padding[amount]=0;
        return padding;
    }
}

#endif //ARRAY_UTILS_H
