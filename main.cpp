#include <iostream>
#include <string.h>
#include "Graphe.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout<<argc<<endl;
    string arg;
    for(int i=0; i<argc ; i++)
    {
        arg.assign(argv[i]);
        cout<<i<<":"<<arg<<endl;
    }


    return 0;
}