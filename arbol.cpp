#include "arbol.h"
#include <climits>
#include <map>
#include <IOSTREAM>
using namespace std;

arbol::arbol()
{

}

arbol::arbol(const arbol & actual , char lado) // Lo usamos para poder acceder a los hijos, lo vamos a cambiar
{
    if (actual.arbolBin != NULL)
    {
        if (lado == 'I')
            this->arbolBin = actual.arbolBin->menor;
        else
            this->arbolBin = actual.arbolBin->mayor;
    }
}



arbol::arbol(const map<string,int> & claves)
{
    crearmatriz(claves);
    crearArbol(arbolBin, 0 , cantclaves);
}

arbol::~arbol()
{

}

int arbol::sumaprobabilidades(int fila , int columna)
{
 int probabilidades=0;
	for (int k=fila;k<columna;k++)
		probabilidades+= proba[k][k+1];
return probabilidades;
}

int arbol::sumamenores(int fila , int columna)
{
	int menor=INT_MAX;
	for(int k=fila;k<columna;k++)
	{
		if(menor > proba[fila][k] + proba[k+1][columna] )
		{
			menor=proba[fila][k] + proba[k+1][columna];
			clave[fila][columna]=clave[k][k+1];
		}
	}
    return menor;
}

void arbol::crearmatriz(const map<string, int>& claves)
{
        cantclaves = claves.size();
        typename map<string, int>::const_iterator it = claves.begin();

        proba = new int*[cantclaves+1];
        clave = new string*[cantclaves+1];
        for(int i=0;i<=cantclaves;i++){
            proba[i] = new int [cantclaves+1];
            clave[i] = new string[cantclaves+1];
        }

        for(int i=0;i<=cantclaves;i++)
        {
            proba[i][i]=0;
            if (i<cantclaves && it != claves.end())
            {
                proba[i][i+1]= it->second;
                clave[i][i+1]=it->first;
                it++;
            }
        }
        for(int i=2;i<=cantclaves;i++)
        {
            for(int j=0;j<=cantclaves-i;j++)
            {
                proba[j][j+i]=sumaprobabilidades(j,j+i)+sumamenores(j,j+i);
            }
        }

}

void arbol::crearArbol(nodoarbol*&actual, int filas, int columnas)
{
	if(filas==columnas)
		actual=NULL;
	else
		{
		    int k=filas;
			while (k<=columnas)
			{
				if (clave [filas][columnas]==clave [k][k+1])
				{
                actual = new nodoarbol;
				actual->clave=clave[filas][columnas];
				crearArbol(actual->menor,filas,k);
				crearArbol(actual->mayor,k+1,columnas);
				k=columnas;
				}
				k++;
			}
		}
}

string arbol::getClave()
{
    if (arbolBin != NULL)
        return arbolBin->clave;
    else
        return "Vacio";
}
