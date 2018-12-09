#ifndef ARVORENARIA_CPP
#define ARVORENARIA_CPP


#include "ArvoreNaria.h"

template <class T>
ArvoreNaria<T>::ArvoreNaria(int n)
{
    this->n = n;
    raiz = NULL;
}

template <class T>
void ArvoreNaria<T>::add(T info){
    if (raiz == NULL){
        raiz = new No<T>(n);
        raiz->setInfo(info);

    }else{

        No<T>* anterior = NULL;
        No<T>* atual = raiz;
        int pos = -1;

        while (atual != NULL && atual->esta_cheio()){
            anterior = atual;

            if (info < atual->primeira_info()){
                atual = atual->primeiro_filho();
                pos = 0;

            }else if (info > atual->ultima_info()){
                atual = atual->ultimo_filho();
                pos = n;

            }else{

                for (int i=0; i<n-2; i++)
                    if(info > atual->info(i) && info < atual->info(i+1)){
                          atual = atual->filho(i+1);
                          pos = i+1;
                          break;
                    }
            }
        }

        if (atual == NULL){
            atual = new No<T>(n);
            atual->setInfo(info);
            anterior->setFilho(pos, atual);

        }else if (!atual->esta_cheio()){
            atual->inserir(info);
        }
    }


}
#endif // ARVORENARIA_CPP
