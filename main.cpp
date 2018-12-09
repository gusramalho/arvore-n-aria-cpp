#include <iostream>
#include "ArvoreNaria.h"
using namespace std;

int main()
{
    ArvoreNaria<int>* arv = new ArvoreNaria<int>(3);

    arv->add(30);
    arv->add(20);
    arv->add(40);
    arv->add(50);
    arv->add(70);
    arv->add(80);
    arv->add(90);
    arv->add(100);
    arv->add(35);
    arv->remover(20);




    cout << *arv<< endl;
    return 0;
}
