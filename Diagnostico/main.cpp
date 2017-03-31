#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Deportista{
    string nombre;
    string pais;
    string deporte;
    int numMedallas;
};

string minuscula(string p)
{
   std::transform(p.begin(), p.end(), p.begin(), ::tolower);
   return p;
}

int main()
{
    string nombre,pais,deporte;
    Deportista deportista[4];
    string paisesMatch[4];
    string paisBuscar;

    //Punto1
    for(int i=0;i<4;i++)
    {
        nombre = "";
        pais = "";
        deporte = "";

        cout<<"\n";
        cout<<"--- Deportista Numero "<<i+1<<" ---";
        cout<<"\n";
        cout<<"\nNombre: ";
        cin>>nombre;
        deportista[i].nombre = minuscula(nombre);
        cout<<"\nPais: ";
        cin>>pais;
        deportista[i].pais = minuscula(pais);
        cout<<"\nDeporte: ";
        cin>>deporte;
        deportista[i].deporte = minuscula(deporte);
        cout<<"\nNumero medallas: ";
        cin>>deportista[i].numMedallas;
    }

    string nombreMayor;
    int mayor = deportista[0].numMedallas;

    for(int i=0;i<4;i++)
    {
        if(deportista[i].numMedallas>mayor)
        {
            mayor = deportista[i].numMedallas;
            nombreMayor = deportista[i].nombre;
        }

        if(mayor==deportista[0].numMedallas)
        {
            nombreMayor = deportista[0].nombre;
        }
    }

    cout<<"\n";
    cout<<"El deportista con mas medallas es: "<<nombreMayor;

    cout<<"\n\n";
    cout<<"Ingrese nombre de un pais: ";
    cin>>paisBuscar;
    paisBuscar = minuscula(paisBuscar);

    //Punto3 - Match
    for(int i=0;i<4;i++)
    {
        if(deportista[i].pais.compare(paisBuscar)==0)
        {
            paisesMatch[i] = deportista[i].deporte;
        }
    }

    cout<<"\n";
    cout<<"--- Deportes que se practican en "<<paisBuscar<<"---";

    //imprimir deportes
    for(int i=0;i<4;i++)
    {
        cout<<"\n";
        cout<<paisesMatch[i];
    }
    cout<<"\n";


    return 0;
}
