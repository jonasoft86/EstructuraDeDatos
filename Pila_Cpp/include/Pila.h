#ifndef PILA_H
#define PILA_H

#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

class Pila
{
    public:
        Pila();
        ~Pila();
        void insertar(int dato);
        void buscarDato(int dato);
        void eliminar();
        void eliminarDato(int dato);
        void modificarDato(int dato);
        void imprimir();
        bool estaVacia();
    private:
        Nodo *primero;

};

#endif // PILA_H
