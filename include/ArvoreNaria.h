#ifndef ARVORENARIA_H
#define ARVORENARIA_H
#include "No.h"
#include <iostream>

template <class T>
class ArvoreNaria
{
    public:
        ArvoreNaria(int n);

        void add(T info);
        void remover();




    protected:

    private:
        No<T>* raiz;
        int n;

};

#include "../src/ArvoreNaria.cpp"
#endif // ARVORENARIA_H
