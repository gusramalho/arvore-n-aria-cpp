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
        raiz->inserir(info);

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
                pos = n-1;

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
            No<T>* novo = new No<T>(n);
            novo->inserir(info);
            anterior->setFilho(pos, novo);

        }else if (!atual->esta_cheio()){
            atual->inserir(info);
        }
    }
}


template <class T>
void ArvoreNaria<T>::remover(T info){
    No<T>* atual = raiz;
    No<T>* anterior = NULL;
    int pos = -1;

    while(atual->indice_de(info) == -1 && atual != NULL){
        anterior = atual;
        if (info < atual->primeira_info()){
            atual = atual->primeiro_filho();
            pos = 0;
        }
        else if (info > atual->ultima_info()){
            atual = atual->ultimo_filho();
            pos = n - 1;
        }
        else

            for (int i=0; i<n-2; i++)
                if(info > atual->info(i) && info < atual->info(i+1)){
                      atual = atual->filho(i+1);
                      pos = i+1;
                      break;
                }
    }

    if (atual == NULL)
        return;


    if (atual->eh_folha()){
        if (atual->quantas_infos() == 1){
            delete atual;
            if (anterior != NULL)
                anterior->setFilho(pos, NULL);
            else
                raiz = NULL;
        }else{
            atual->remover_info(info);
        }
    }else{
        int i = atual->indice_de(info);
        No<T>* esquerda = atual->filho(i);
        No<T>* direita = atual->filho(i+1);

        if (!esquerda && !direita){

            for (int j=0; j<i; j++)
                if (atual->filho(j) != NULL){
                    int maior = maior_info(atual->filho(j));
                    remover(maior);
                    atual->setInfo(i, maior);
                }

            for (int j = n-1; j > i; j--)
                if (atual->filho(j) != NULL){
                    int menor = menor_info(atual->filho(j));
                    remover(menor);
                    atual->setInfo(i, menor);
                }

        } else if (esquerda) {

            int maior = maior_info(esquerda);
            remover(maior);
            atual->setInfo(i, maior);

        } else if (direita) {

            int menor = menor_info(direita);
            remover(menor);
            atual->setInfo(i, menor);
        }
    }

}


template <class T>
T ArvoreNaria<T>::menor_info(No<T>* ptr){
    No<T>* atual = ptr;
    while(atual->filho(0) != NULL)
        atual = atual->filho(0);

    for (int i=0; i<n-1; i++)
        if (atual->info(i) != NULL)
            return atual->info(i);

    return NULL;
}

template <class T>
T ArvoreNaria<T>::maior_info(No<T>* ptr){
    No<T>* atual = ptr;
    while (atual->filho(n-1) != NULL)
         atual = atual->filho(n-1);

    for (int i=n-2; i >= 0; i--)
        if (atual->info(i) != NULL)
            return atual->info(i);

    return NULL;
}


#endif // ARVORENARIA_CPP
