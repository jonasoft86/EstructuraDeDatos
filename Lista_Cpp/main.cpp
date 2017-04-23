#include <iostream>

using namespace std;

struct Nodo
{
	 int dato;
	 Nodo *siguiente;
};

class Lista
{
    public:
        Lista();
        ~Lista();
        void insertarFrente(int dato);
        void insertarFinal(int dato);
        void eliminarFrente();
        void eliminarFinal();
        void eliminarDato(int dato);
        void modificarDato(int dato);
        void imprimir();
        void invertirLista();
        bool esVacia();
    private:
        Nodo *primero;
};

Lista::Lista()
{
    primero = NULL;
}

Lista::~Lista()
{
    cout<<"Lista destruida";
}

void Lista::insertarFrente(int dato)
{
	 Nodo *nuevo = new Nodo();
	 nuevo->dato = dato;
	 nuevo->siguiente = primero;
	 primero = nuevo;
}

void Lista::insertarFinal(int dato)
{
	Nodo *nuevo = new Nodo();
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	
	if(primero==NULL)
		primero = nuevo;
	else
	{
		Nodo *aux = primero;
		while(aux->siguiente != NULL)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
	}
}

void Lista::eliminarFrente(){

	if(primero == NULL)
	 	cout<<"Lista vacia\n";
	else
	{
		Nodo *aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

void Lista::eliminarFinal()
{
	Nodo *aux;
	aux = primero;
	
	if(primero == NULL)
	 	cout<<"Lista vacia\n";

	if(primero->siguiente == NULL)
	{
		primero = NULL;
		delete aux;
	}
	else
	{  
		Nodo *anterior;
		while(aux->siguiente!=NULL)
		{
			anterior = aux;
			aux = aux->siguiente;
		}
		anterior->siguiente = NULL;
		delete aux;
	}
}

void Lista::imprimir()
{
    Nodo *actual = new Nodo();
    actual = primero;

    if(esVacia())
    {
        cout<<"\n La lista esta vacia \n\n";
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

void Lista::invertirLista()
{
	Nodo *anterior = NULL;
	Nodo *siguiente = NULL;
	Nodo *actual = primero;

	while(actual!=NULL)
	{
		siguiente = actual->siguiente;
		actual->siguiente = anterior;
		anterior = actual;
		actual = siguiente;
	}
	primero = anterior;
}

void Lista::eliminarDato(int dato)
{
    Nodo *actual = primero;
    Nodo *anterior = new Nodo();
    anterior = NULL;

    bool encontrado = false;

    if(!esVacia())
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
            cout<<"\n\n No existe dato en la lista";
        }

    }
    else{
        cout<<"\n La lista esta vacia \n\n";
    }
    cout<<"\n\n";
}

void Lista::modificarDato(int dato)
{
    Nodo *actual = primero;
    bool encontrado = false;

    if(!esVacia())
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
            cout<<"\n\n No existe dato en la lista";
        }
    }
    else{
        cout<<"\n La lista esta vacia \n\n";
    }
    cout<<"\n\n";
}


bool Lista::esVacia()
{
    return (primero == NULL);
}

//Main Function
int main()
{
	Lista *lista = new Lista();

	lista->insertarFrente(5);
	lista->insertarFrente(10);
	lista->insertarFrente(15);
	lista->insertarFinal(9);

	lista->imprimir();
	
	//lista->eliminarFrente();
	//lista->eliminarFinal();
	
	//lista->imprimir();
	
	lista->invertirLista();
	lista->imprimir();
	
	return 0;
}

