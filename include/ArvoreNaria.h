#ifndef ARVORENARIA_H
#define ARVORENARIA_H
#include "No.h"
#include <iostream>

template <class T>
class ArvoreNaria
{
    public:
        ArvoreNaria();

    protected:

    private:
        No<T>* raiz;

};

#include "../src/ArvoreNaria.cpp"
#endif // ARVORENARIA_H
