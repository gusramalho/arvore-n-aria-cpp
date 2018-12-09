#ifndef NO_H
#define NO_H
#include <iostream>

using namespace std;
template <class T>
class No
{
    public:
        No(int n);
        ~No();

        T info(int i);
        int indice_de(T info);
        void inserir(T info);
        void setInfo(int pos, T info);
        void remover_info(T info);
        T primeira_info();
        T ultima_info();
        int quantas_infos();

        No<T>* filho(int i);
        No<T>* primeiro_filho();
        No<T>* ultimo_filho();
        void setFilho(int pos, No<T>* filho);

        int esta_cheio();
        int eh_folha();


        friend ostream &operator<<(ostream& out, No<T>& no){
            out << "(";
            for (int i=0; i < no.n - 1; i++){
                if (no.infos[i] == NULL)
                    out << "null";
                else
                    out << no.infos[i];
                if (i != no.n-2)
                    out << ", ";
            }
            out << ")";
            return out;
        }

    protected:

    private:
        int n;
        T* infos;
        No<T>** filhos;
        void ordenar();


};
#include "../src/No.cpp"
#endif // NO_H
