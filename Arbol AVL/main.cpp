#include<iostream>

using namespace std;

struct Nodo
{
    int dato;		
    Nodo* izquierdo;     	
    Nodo* derecho; 	
    int altura; 	
};

class AVL
{
    public:
		AVL() : _raiz(NULL) { }

		Nodo* nuevoNodo(int dato);
		void insertar(Nodo* &nodo,int dato);
        Nodo *buscar(Nodo *nodo,int dato);
		void eliminar(Nodo* &rt,int dato);
        int  getTamano();
        
        void preOrden(Nodo *nodo);
        void enOrden(Nodo *nodo);
        void postOrden(Nodo *Nodo);
        void eliminarArbol(Nodo *nodo);
        
        void verArbol(Nodo *nodo,int data);
        Nodo* minimo(Nodo* nodo);
        Nodo* maximo(Nodo* nodo);
        
		Nodo* &raiz() { return this->_raiz; }
			
    private:
        Nodo* _raiz;	
        int tamano;
        
        int esBalanciado(Nodo* nodo);
        void balance(Nodo* &nodo);
        void actualizarAltura(Nodo* nodo);
        void rotacionIzquierda(Nodo* &nodo);
        void rotacionDerecha(Nodo* &nodo);
};

int AVL::getTamano()
{
    return this->tamano;
}

Nodo* AVL::nuevoNodo(int dato){
	Nodo* n = new Nodo;
	n->dato = dato;
	n->izquierdo = NULL;
	n->derecho = NULL;
	return n;
}

void AVL::insertar( Nodo* &nodo,int dato)
{
	if(this->_raiz == NULL)
    {
        this->_raiz = nuevoNodo(dato);
        this->tamano = 1;
    }
    else
    {
	    if(nodo == NULL)
	    {
	        nodo = nuevoNodo(dato);
	        ++this->tamano;
	    }
	    else
	    {
	        if(dato < nodo->dato)
	            insertar( nodo->izquierdo,dato);
	        else
	            insertar( nodo->derecho,dato);
	    }
	    balance(nodo);
	}
}

void AVL::verArbol(Nodo *nodo,int n)
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
     std::cout<<"   ";

	std::cout<< nodo->dato <<std::endl;

	if(nodo->izquierdo!=NULL)
	{
		verArbol(nodo->izquierdo,n+1);
	}
}

Nodo* AVL::minimo(Nodo* node)
{
    return (node->izquierdo == NULL ? node : minimo(node->izquierdo));
}

Nodo* AVL::maximo(Nodo* node)
{
    return (node->derecho == NULL ? node : maximo(node->derecho));
}

Nodo* AVL::buscar(Nodo *nodo,int dato)
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

void AVL::eliminar( Nodo* &nodo,int dato)
{
    if(nodo == NULL)
    {
        std::cout << "Elemento no encontrado\n";
    }
    else if(dato < nodo->dato)
        eliminar( nodo->izquierdo,dato);
    else if(dato > nodo->dato)
        eliminar( nodo->derecho,dato);
    else
    {
    	Nodo* tmp;
        if(nodo->izquierdo == NULL && nodo->derecho == NULL)
        {
            tmp = nodo;
            nodo = NULL;
            delete tmp;
        }
        else if(nodo->derecho != NULL && nodo->izquierdo != NULL)
        {
            tmp = minimo(nodo->derecho);
            nodo->dato = tmp->dato;
            eliminar(nodo->derecho,nodo->dato);
        }
        else
        {
            if(nodo->izquierdo)
            {
                tmp = nodo->izquierdo;
                nodo->dato = nodo->izquierdo->dato;
                nodo->izquierdo = tmp->izquierdo;
                nodo->derecho = tmp->derecho;
                delete tmp;
            }
            else if(nodo->derecho)
            {
                tmp = nodo->derecho;
                nodo->dato = nodo->derecho->dato;
                nodo->derecho = tmp->derecho;
                nodo->izquierdo = tmp->izquierdo;
                delete tmp;
            }
        }
        --this->tamano;
    }
    if(nodo != NULL)
        balance(nodo);
}


int AVL::esBalanciado(Nodo* nodo)
{
    int alturaIzquierda = (nodo->izquierdo ? nodo->izquierdo->altura : 0);
    int alturaDerecha = (nodo->derecho ? nodo->derecho->altura : 0);
    return alturaDerecha - alturaIzquierda;
}

void AVL::actualizarAltura(Nodo* nodo)
{
    int alturaIzquierda = (nodo->izquierdo ? nodo->izquierdo->altura : 0);
    int alturaDerecha = (nodo->derecho ? nodo->derecho->altura : 0);
    nodo->altura = (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha) + 1;
}

void AVL::balance(Nodo* &nodo)
{
    actualizarAltura(nodo);
    if(esBalanciado(nodo) == 2)
    {
        if(esBalanciado(nodo->derecho) < 0)
        {
            rotacionDerecha(nodo->derecho);
        }
        rotacionIzquierda(nodo);
    }
    else if(esBalanciado(nodo) == -2)
    {
        if(esBalanciado(nodo->izquierdo) > 0)
        {
            rotacionIzquierda(nodo->izquierdo);
        }
        rotacionDerecha(nodo);
    }
}

void AVL::rotacionIzquierda(Nodo* &nodo)
{
    Nodo* aux = nodo;
    nodo = nodo->derecho;
    aux->derecho = nodo->izquierdo;
    nodo->izquierdo = aux;
    actualizarAltura(aux);
    actualizarAltura(nodo);
}

void AVL::rotacionDerecha(Nodo* &nodo)
{
    Nodo* aux = nodo;
    aux = nodo->izquierdo;
    aux->izquierdo = nodo->derecho;
    nodo->derecho = aux;
    actualizarAltura(aux);
    actualizarAltura(nodo);
}

int main()
{
    AVL arbol;

    arbol.insertar(arbol.raiz(),10);
    arbol.insertar(arbol.raiz(),5);
    arbol.insertar(arbol.raiz(),15);
    arbol.insertar(arbol.raiz(),12);
    arbol.insertar(arbol.raiz(),16);
    arbol.insertar(arbol.raiz(),18);
    arbol.verArbol(arbol.raiz(),0);
    
    cout << "\n";
    cout << "\n";
    
    //arbol.eliminar(arbol.raiz(),15);
    //arbol.verArbol(arbol.raiz(),0);
	
    return 0;
}

