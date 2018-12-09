#include <iostream>
#include "No.h"
using namespace std;

int main()
{
    No<int>* n = new No<int>(4);
    n->inserir(3);
    n->inserir(3);
    n->inserir(3);


    if (n->esta_cheio())
        cout << "f...";
    cout << *n << endl;
    return 0;
}
