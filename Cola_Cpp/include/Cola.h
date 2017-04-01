#ifndef COLA_H
#define COLA_H


#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

class Cola
{
    public:
        Cola();
        ~Cola();
        void insertar(int dato);
        void buscarDato(int dato);
        void eliminar();
        void eliminarDato(int dato);
        void modificarDato(int dato);
        void imprimir();
        bool estaVacia();
    private:
        Nodo *primero, *ultimo;

};

#endif // COLA_H
