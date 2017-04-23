#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente; 
};

class Pila {
	public:
		Pila(); 
		~Pila(); 
		void insertar(int dato); 
		void eliminar(); 
		void imprimir(); 
		bool esVacia(); 
	private:
	  	Nodo *primero; 
};

Pila::Pila()
{
	primero = NULL;
}

Pila::~Pila() 
{
	while (!esVacia()) {
		eliminar();
	}
}

void Pila::insertar(int dato) 
{
	Nodo *nuevo = new Nodo;
	nuevo->dato = dato;
	nuevo->siguiente = primero; 
              
  	primero = nuevo; 
}

void Pila::eliminar() 
{
	if (!esVacia()) 
	{
		Nodo *aux = primero;                 
		primero = primero->siguiente;    
		                   
		delete aux;           
	} 
	else 
	{
		cout<<"Pila vacia!";
		exit(1);
	}
}

bool Pila::esVacia() 
{
	return (primero == NULL);
}

void Pila::imprimir() 
{
	cout<<"(Primero)";
	if (esVacia()) 
	{
		cout<<"Pila vacia";
	} 
	else 
	{
		Nodo *actual = primero;
		while (actual != NULL) 
		{
			cout<<"->"<<actual->dato;
		  	actual = actual->siguiente;
		}
		cout<<"\n\n";
	}
}

int main() 
{
	Pila *pila = new Pila();
	pila->insertar(5);
	pila->insertar(10);
	pila->insertar(15);
	pila->insertar(20);
	
	pila->imprimir();
	
	pila->eliminar();
	
	pila->imprimir();
	
	return 0;
}
