#include <iostream>
#include <stdlib.h>
#include "Pila.h"

using namespace std;

int main()
{
    int opcion = 0;
    int dato;
    Pila *pila = new Pila();

    do
    {
        system("cls");
        cout<<"\n |---------------------------------|";
        cout<<"\n |            *Pila*               |";
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

                pila->insertar(dato);
                system("pause");

            break;

            case 2:
                cout<<"\n Ingrese dato a buscar: ";
                cin>>dato;
                pila->buscarDato(dato);
                system("pause");
            break;

            case 3:
                cout<<"\n Ingrese dato a modificar: ";
                cin>>dato;
                pila->modificarDato(dato);
                system("pause");
            break;

            case 4:
                int opcEliminar;
                cout<<"\n 1. Eliminar primer dato de la pila";
                cout<<"\n 2. Eliminar dato de la pila";
                cout<<"\n opcion: ";
                cin>>opcEliminar;

                if(opcEliminar==1)
                {
                    pila->eliminar();
                }
                if(opcEliminar==2)
                {
                    cout<<"\n Ingrese dato a eliminar: ";
                    cin>>dato;
                    pila->eliminarDato(dato);
                }
                system("pause");
            break;

            case 5:
                cout<<"\n\n Elementos de la Pila \n";
                pila->imprimir();
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
