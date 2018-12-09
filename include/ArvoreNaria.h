#ifndef ARVORENARIA_H
#define ARVORENARIA_H
#include "No.h"
#include <iostream>
#include <queue>
#include<math.h>
template <class T>
class ArvoreNaria
{
    public:
        ArvoreNaria(int n);

        void add(T info);
        void remover();

        friend ostream &operator<<(ostream& out, ArvoreNaria<T>& arvore){


           std::queue<No<T>* > fila = std::queue<No<T>* >();
           fila.push(arvore.raiz);
           int cont = 0;
           int cont_nulls = 0;
           int nvl = 1;


            while (!fila.empty()){

                No<T> *atual = fila.front();
                out << *atual;
                fila.pop();

                for (int i=0; i<arvore.n; i++){
                    if (atual->filho(i) != NULL){
                        fila.push(atual->filho(i));
                        cont++;
                    }else{
                        cont_nulls++;

                    }

                }

                if (cont + cont_nulls == (int)pow(arvore.n, nvl)){
                    out << endl;
                    cont_nulls *= arvore.n;
                    nvl++;
                    cont = 0;

                }


            }

            return out;
        }

        No<T>* raiz;

    protected:

    private:

        int n;

};

#include "../src/ArvoreNaria.cpp"
#endif // ARVORENARIA_H
