#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente; 
};

class Cola {
	public:
		Cola(); 
		~Cola(); 
		void insertar(int dato); 
		void eliminar(); 
		void imprimir(); 
		bool esVacia(); 
	private:
	  	Nodo *primero;
	  	Nodo *ultimo;
};

Cola::Cola()
{
	primero = NULL;
	ultimo = NULL;
}

Cola::~Cola() 
{
	while (!esVacia()) {
		eliminar();
	}
}


void Cola::insertar(int dato)
{
	Nodo *nuevo = new Nodo();
    nuevo->dato = dato;
	nuevo->siguiente = NULL;

	if(primero == NULL)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
	}
}

void Cola::eliminar()
{
	 if(esVacia())
	 {
	 	cout<<"Cola esta vacia\n";
	 }
	 else
	 {
		 if(primero == ultimo)
		 {
		  	delete primero;
		  	primero = ultimo = NULL;
		 }
		 else
		 {
			Nodo *aux = primero;
			primero = primero->siguiente;
			delete aux;
		 }
	}
}

void Cola::imprimir()
{
    Nodo *actual = new Nodo();
    actual = primero;

    cout<<"(primero)->";
    if(esVacia())
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
        cout<<"(ultimo)";
        cout<<"\n\n";
    }
}

bool Cola::esVacia()
{
	 if(primero == NULL && ultimo == NULL)
	 	return true;
	 else
	 	return false;
}

int main() 
{
	Cola *cola = new Cola();
	cola->insertar(5);
	cola->insertar(10);
	cola->insertar(15);
	cola->insertar(20);
	
	cola->imprimir();
	
	cola->eliminar();
	
	cola->imprimir();
	
	return 0;
}
