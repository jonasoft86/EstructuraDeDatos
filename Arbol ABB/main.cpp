#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *izquierdo;
    Nodo *derecho;
};

class ABB
{
    public:
        ABB() : _raiz(NULL) { }
        Nodo* nuevoNodo(int dato);
        void insertar(Nodo *nodo,int dato);
        
        Nodo *buscar(Nodo *nodo,int dato);
        Nodo* eliminar(Nodo *nodo,int dato);
        void preOrden(Nodo *nodo);
        void enOrden(Nodo *nodo);
        void postOrden(Nodo *Nodo);
        void eliminarArbol(Nodo *nodo);
        void verArbol(Nodo *nodo,int data);
        int  minimo(Nodo* Ptr);
		int  maximo(Nodo* Ptr);
	
        Nodo* raiz() { return this->_raiz; }
    private:
        Nodo *_raiz;
};


Nodo* ABB::nuevoNodo(int dato){
	Nodo* n = new Nodo;
	n->dato = dato;
	n->izquierdo = NULL;
	n->derecho = NULL;
	return n;
}

void ABB::insertar(Nodo *nodo,int dato)
{
    if(_raiz==NULL)
	{
		_raiz=nuevoNodo(dato);
	}
    else if(dato < nodo->dato)
    {
        if(nodo->izquierdo != NULL)
		{
			insertar(nodo->izquierdo, dato);
		}
		else
		{
			nodo->izquierdo = nuevoNodo(dato);
		}
    }
    else if(dato > nodo->dato)
    {
        if(nodo->derecho != NULL)
		{
			insertar(nodo->derecho,dato);
		}
		else
		{
			nodo->derecho = nuevoNodo(dato);
		}
    }
}

void ABB::verArbol(Nodo *nodo,int n)
{
    if (nodo == NULL)
    {
    	return;
	}

	if(nodo->derecho!=NULL)
	{
		verArbol(nodo->derecho,n+1);
	}

	for(int i=0; i<n; i++)
     cout<<"   ";

	cout<< nodo->dato <<endl;

	if(nodo->izquierdo!=NULL)
	{
		verArbol(nodo->izquierdo,n+1);
	}
}

int ABB::minimo(Nodo* nodo)
{
	if (_raiz == NULL)
	{
		return -1000;
	}
	else
	{
		if (nodo->izquierdo == NULL)
		{
			return nodo->dato;
		}
		else
		{
			return minimo(nodo->izquierdo);
		} 
	}
}

int ABB::maximo(Nodo* nodo)
{
	if (_raiz == NULL)
	{
		return -1000;
	}
	else
	{
		if (nodo->derecho == NULL)
		{
			return nodo->dato;
		}
		else
		{
			return maximo(nodo->derecho);
		} 
	}
}

Nodo* ABB::buscar(Nodo *nodo,int dato)
{
	if(nodo!=NULL)
	{
		if(nodo->dato == dato)
		{
			return nodo;
		}
		else if(dato < nodo->dato)
		{
			return buscar(nodo->izquierdo,dato);
		}
		else if(dato > nodo->dato)
		{
			return buscar(nodo->derecho,dato);
		}
	}
	else
		return NULL;
}


Nodo* ABB::eliminar(Nodo *nodo,int dato)
{
	if(nodo!=NULL)
	{
		if(dato < nodo->dato){
			nodo->izquierdo = eliminar(nodo->izquierdo,dato);
		}
		else if(dato > nodo->dato){
			nodo->derecho = eliminar(nodo->derecho,dato);
		}
		else {
            Nodo* tmp;
            if(nodo->izquierdo != NULL && nodo->derecho != NULL)
            {
				// get dato from the derechomost Nodo in the izquierdo subtree
				tmp = nodo->izquierdo;
				
				int minimoIzquierdo = minimo(tmp->derecho);
				nodo->dato = minimoIzquierdo;

				//delete the derechomost Nodo in the izquierdo subtree
				nodo->izquierdo =  eliminar(nodo->izquierdo,nodo->dato) ;
			}
			else
            {
                if(nodo->izquierdo == NULL){
                    tmp = nodo->derecho;

                }
                else if(nodo->derecho == NULL){
                    tmp = nodo->izquierdo;
                }
                delete nodo;
                nodo = NULL;

                if(tmp){
                    return tmp;
                }
                return nodo;
            }
		}
	}
	return nodo;
}


void ABB::preOrden(Nodo *nodo){

	if(!nodo) return;

	std::cout << nodo->dato << " ";
	preOrden(nodo->izquierdo);
	preOrden(nodo->derecho);
}

void ABB::enOrden(Nodo *nodo){

	if(!nodo) return;

	enOrden(nodo->izquierdo);
	std::cout << nodo->dato << " ";
	enOrden(nodo->derecho);
}


void ABB::postOrden(Nodo *nodo){

	if(!nodo) return;

	postOrden(nodo->izquierdo);
	postOrden(nodo->derecho);
	std::cout << nodo->dato << " ";
}


void ABB::eliminarArbol(Nodo *nodo)
{
	if(nodo)
	{
		eliminarArbol(nodo->izquierdo);
		eliminarArbol(nodo->derecho);
		delete nodo;
		nodo = NULL;
	}
}

int main() {
	ABB arbol;

	arbol.insertar(arbol.raiz(),15);
	arbol.insertar(arbol.raiz(),9);
	arbol.insertar(arbol.raiz(),12);
	arbol.insertar(arbol.raiz(),27);
	arbol.insertar(arbol.raiz(),21);
	arbol.insertar(arbol.raiz(),13);
	arbol.insertar(arbol.raiz(),24);
	arbol.insertar(arbol.raiz(),36);
	
    arbol.verArbol(arbol.raiz(),0);
    
    //arbol.eliminar(bt.raiz(),15);
    cout << "\n";
    cout << "\n";
    //arbol.verArbol(bt.raiz(),0);

	cout<<"EnOrden: ";
	arbol.enOrden(arbol.raiz());
	cout << "\n";
	
	cout<<"PreOrden: ";
	arbol.preOrden(arbol.raiz());
	cout << "\n";

	cout<<"PostOrden: ";
	arbol.postOrden(arbol.raiz());
	cout << "\n";

	return 0;
}

