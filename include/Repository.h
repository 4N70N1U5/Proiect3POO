#ifndef Repository_H
#define Repository_H

#include <vector>

template <class T>
class Repository
{
public:
    void AdaugaElement(T* element)
    {
        this->elemente.push_back(element);
    }
    void StergeElement(T* element)
    {
        typename std::vector<T*>::iterator it;
        for (it = this->elemente.begin(); it != this->elemente.end(); it++)
        {
            if (*it == element)
            {
                this->elemente.erase(it);
                break;
            }
        }
    }
    void StergeElement(int pozitie)
    {
        this->elemente.erase(this->elemente.begin() + pozitie);
    }
protected:
    std::vector<T*> elemente;
};

#endif
