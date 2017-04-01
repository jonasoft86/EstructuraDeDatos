#include <iostream>
#include <stdlib.h>
#include "Cola.h"

using namespace std;

int main()
{
    int opcion = 0;
    int dato;
    Cola *cola = new Cola();

    do
    {
        system("cls");
        cout<<"\n |---------------------------------|";
        cout<<"\n |            *Cola*               |";
        cout<<"\n |---------------------------------|";
        cout<<"\n |  1.Insertar   | 4. Eliminar     |";
        cout<<"\n |  2.Buscar     | 5. Mostrar      |";
        cout<<"\n |  3.Modificar  | 6. Salir        |";
        cout<<"\n |---------------------------------|\n\n";
        cout<<"Opcion [1-6]: ";

        //Validacion numeros
        while(!(cin>>opcion)) {
            cin.clear();
            cin.ignore(999,'\n');
            cout<<"Solo se aceptan numeros, intente otra vez...\n";
            cout<<"Opcion [1-6]: ";
        }


        switch(opcion)
        {
            case 1:
                cout<<"\n Ingrese dato: ";
                cin>>dato;
                cola->insertar(dato);
                system("pause");

            break;

            case 2:
                cout<<"\n Ingrese dato a buscar: ";
                cin>>dato;
                cola->buscarDato(dato);
                system("pause");
            break;

            case 3:
                cout<<"\n Ingrese dato a modificar: ";
                cin>>dato;
                cola->modificarDato(dato);
                system("pause");
            break;

            case 4:
                cola->eliminar();
                system("pause");
            break;

            case 5:
                cout<<"\n\n Elementos de la Cola \n";
                cola->imprimir();
                system("pause");
            break;

            case 6:
                cout<<"\n\n Salir \n";
            break;

            default:
                cout<<"\n\n Opcion no valida... \n";


        }
    }while(opcion!=6);

    cout<<"\n\n";
    return 0;
}
