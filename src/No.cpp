#ifndef NO_CPP
#define NO_CPP

#include "No.h"

template <class T>
No<T>::No(int n){
    if (n < 2)
        throw std::invalid_argument("N deve ser maior ou igual a 2");
    this->n = n;
    infos = new T[n-1];
    filhos = new No<T>*[n];

    for (int i=0; i<n; i++){
        if (i != n)
            infos[i] = NULL;
        filhos[i] = NULL;
    }
}

template <class T>
T No<T>::info(int i){
    if (i > n-1 || i < 0)
        throw std::invalid_argument("Indice fora do tamanho");

    return infos[i];
}

template <class T>
T No<T>::primeira_info(){
    return infos[0];
}

template <class T>
T No<T>::ultima_info(){
    return infos[n-2];
}

template <class T>
void No<T>::setInfo(int pos, T info){
    if (pos > n-1 || pos < 0)
        throw std::invalid_argument("Indice fora do tamanho");

    infos[pos] = info;
    ordenar();
}

template <class T>
void No<T>::remover_info(T info){
    int i = indice_de(info);
    if (i == -1)
        throw std::invalid_argument("Informacao nao existente para excluir");
    infos[i] = NULL;
    ordenar();
}

template <class T>
void No<T>::inserir(T info){
    for (int i=0; i<n-1; i++){

        if (infos[i] == NULL){
            infos[i] = info;
            break;
        }

        if (i == n-2)
            throw std::invalid_argument("Noh esta cheio");
    }
    ordenar();
}

template <class T>
No<T>* No<T>::filho(int i){
    if (i > n || i < 0)
        throw std::invalid_argument("Indice fora do tamanho");
    return filhos[i];
}

template <class T>
void No<T>::setFilho(int pos, No<T>* filho){
    if (pos > n || pos < 0)
       throw std::invalid_argument("Indice fora do tamanho");

    filhos[pos] = filho;
}

template <class T>
No<T>* No<T>::primeiro_filho(){
    return filhos[0];
}

template <class T>
No<T>* No<T>::ultimo_filho(){
    return filhos[n-1];
}

template <class T>
int No<T>::esta_cheio(){

    int ret = 0;
    for (int i = 0; i < n - 1; i++)
        if (infos[i] != NULL)
        {
           ret++;
        }

    return ret == n-1;
}

template <class T>
void No<T>::ordenar(){

    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n-1; j++)
            if (infos[i] > infos[j])
            {
                int aux = infos[i];
                infos[i] = infos[j];
                infos[j] = aux;
            }

}


template <class T>
int No<T>::eh_folha(){
    for (int i=0; i<n; i++)
        if (filhos[i] != NULL)
            return 0;
    return 1;
}

template <class T>
int No<T>::indice_de(T info){
    for (int i=0; i<n-1; i++)
        if (infos[i] == info)
            return i;
    return -1;
}

template <class T>
int No<T>::quantas_infos(){
    int ret = 0;
    for (int i=0; i<n-1; i++)
        if (infos[i] != NULL)
            ret++;
    return ret;
}


template <class T>
No<T>::~No()
{
    delete []infos;

    for (int i=0; i<n; i++)
        if (filhos[i] != NULL)
            delete filhos[i];
    delete []filhos;
}



#endif
