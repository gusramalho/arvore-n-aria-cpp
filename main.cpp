#include <iostream>
#include "No.h"
using namespace std;

int main()
{
    No<int>* n = new No<int>(4);
    n->setInfo(3);
    n->setInfo(4);
    n->setInfo(8);


    cout << *n << endl;
    return 0;
}
