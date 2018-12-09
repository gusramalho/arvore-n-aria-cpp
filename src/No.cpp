#ifndef NO_CPP
#define NO_CPP

#include "No.h"

template <class T>
No<T>::No(int n){

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
    return infos[n-1];
}

template <class T>
void No<T>::setInfo(int pos, T info){
    if (pos > n-1 || pos < 0)
        throw std::invalid_argument("Indice fora do tamanho");

    infos[pos] = info;
}

template <class T>
void No<T>::setInfo(T info){
    for (int i=0; i<n-1; i++){
        if (infos[i] == NULL){
            infos[i] = info;
            break;
        }
        if (i == n-2)
            throw std::invalid_argument("Noh esta cheio");
    }
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
    return filhos[n];
}


#endif
