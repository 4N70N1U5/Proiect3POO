#ifndef Repository_H
#define Repository_H

#include <vector>

template <class T>
class Repository
{
protected:
    std::vector<T*> elemente;
};

#endif
