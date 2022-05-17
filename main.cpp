#include <iostream>
#include "arbol.h"
#include <map>
#include <string>

using namespace std;

int main()
{
    string palabra;
    int numero=0;
    map<string, int> mymap;
    palabra="a";
    numero=22;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="al";
    numero=18;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="ama";
    numero=20;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="si";
    numero=25;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="eso";
    numero=5;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="sin";
    numero=2;
    mymap.insert (pair <string, int> (palabra , numero));
    palabra="su";
    numero=8;
    mymap.insert (pair <string, int> (palabra , numero));
    arbol a = arbol(mymap);
    cout << a.getClave();
}
