#include "Cola.h"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

Cola::~Cola()
{
    cout<<"Cola destruida";
}

void Cola::insertar(int dato)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = dato;

    if(primero==NULL)
    {
        primero = nuevo;
        primero->siguiente = NULL;
        ultimo = primero;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
    cout<<"\n Nodo Ingresado";
    cout<<"\n\n";
}

void Cola::buscarDato(int dato)
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

void Cola::eliminar()
{
    if(!estaVacia())
    {
        Nodo *anteriorPrimero = new Nodo();
        anteriorPrimero = primero;

        primero = anteriorPrimero->siguiente;

        delete anteriorPrimero;
        cout<<"\n\n Nodo fue eliminado";
    }
    else{
        cout<<"\n La pila esta vacia \n\n";
    }
}

void Cola::eliminarDato(int dato)
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

void Cola::modificarDato(int dato)
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

bool Cola::estaVacia()
{
    return (primero == NULL);
}

void Cola::imprimir()
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
