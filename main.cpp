#include <iostream>
#include "ArvoreNaria.h"
using namespace std;

int main()
{
    ArvoreNaria<int>* arv = new ArvoreNaria<int>(4);

    arv->add(30);
    arv->add(20);
    arv->add(40);
    arv->add(50);
    arv->add(60);
    arv->add(70);
    arv->add(24);
    arv->add(10);
    arv->add(34);
    cout << *arv<< endl;
    return 0;
}
