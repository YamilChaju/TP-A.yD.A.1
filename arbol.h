#ifndef ARBOL_H
#define ARBOL_H
#include <map>
#include <IOSTREAM>
using namespace std;

class arbol
{
    public:
        arbol();
        virtual ~arbol();
        arbol(const map < string , int > & claves);
        string getClave();
        arbol(const arbol & actual , char lado);
    private:
        int cantclaves;
        int **proba;
        string **clave;
        struct nodoarbol
        {
            string clave;
            nodoarbol*menor; //PARA UN MEJOR FUNCIONAMIENTO DEL ARBOL, SE VA A REMPLAZAR POR ARBOLMENOR
            nodoarbol*mayor; //PARA UN MEJOR FUNCIONAMIENTO DEL ARBOL, SE VA A REMPLAZAR POR ARBOLMAYOR
        };
        nodoarbol *arbolBin;
        int sumamenores(int fila , int columna);
        int sumaprobabilidades(int fila , int columna);
        void crearArbol(nodoarbol*&arbol, int fila , int columna);
        void crearmatriz(const map<string,int> & claves);
};

#endif
