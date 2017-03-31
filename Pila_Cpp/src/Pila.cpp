#include "Pila.h"

Pila::Pila()
{
    primero = NULL;
}

Pila::~Pila()
{
    cout<<"Pila destruida";
}

void Pila::insertar(int dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = primero;
    primero = nuevo;
}

void Pila::buscarDato(int dato)
{
    Nodo *actual = primero;

    bool encontrado = false;

    if(!estaVacia())
    {
        while(actual!=NULL && encontrado!= true)
        {
            if(actual->dato == dato)
            {
                cout<<"\n Nodo con el dato "<<dato<<" fue encontrado \n\n";
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if(encontrado==false)
        {
            cout<<"\n\n No existe dato en la pila";
        }

    }
    else{
        cout<<"\n La pila esta vacia \n\n";
    }
}

void Pila::eliminar()
{
    if(!estaVacia())
    {
        Nodo *anteriorPrimero = new Nodo();
        anteriorPrimero = primero;

        primero = anteriorPrimero->siguiente;

        delete anteriorPrimero;
    }
    else{
        cout<<"\n La pila esta vacia \n\n";
    }

}

void Pila::eliminarDato(int dato)
{
    Nodo *actual = primero;
    Nodo *anterior = new Nodo();
    anterior = NULL;

    bool encontrado = false;

    if(!estaVacia())
    {
        while(actual!=NULL && encontrado!= true)
        {
            if(actual->dato == dato)
            {
                if(actual==primero)
                {
                    primero = primero->siguiente;
                }
                else
                {
                    anterior->siguiente = actual->siguiente;
                }
                cout<<"\n\n Nodo con el dato "<<dato<<" fue eliminado";
                encontrado = true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        if(encontrado==false)
        {
            cout<<"\n\n No existe dato en la pila";
        }

    }
    else{
        cout<<"\n La pila esta vacia \n\n";
    }
    cout<<"\n\n";
}

void Pila::modificarDato(int dato)
{
    Nodo *actual = primero;
    bool encontrado = false;

    if(!estaVacia())
    {
        while(actual!=NULL && encontrado!= true)
        {
            if(actual->dato == dato)
            {
                cout<<"\n Nodo con el dato "<<dato<<" fue encontrado \n\n";
                cout<<"\n Ingrese nuevo dato para este nodo: ";
                cin>>actual->dato;
                encontrado = true;
            }
            actual = actual->siguiente;
            cout<<"\n\n Dato modificado";
        }
        if(encontrado==false)
        {
            cout<<"\n\n No existe dato en la pila";
        }
    }
    else{
        cout<<"\n La pila esta vacia \n\n";
    }
    cout<<"\n\n";
}

bool Pila::estaVacia()
{
    return (primero == NULL);
}

void Pila::imprimir()
{
    Nodo *actual = new Nodo();
    actual = primero;

    if(estaVacia())
    {
        cout<<"\n La pila esta vacia \n\n";
    }
    else
    {
        while(actual!=NULL)
        {
            cout<<actual->dato<<"->";
            actual = actual->siguiente;
        }
        cout<<"\n\n";
    }
}
