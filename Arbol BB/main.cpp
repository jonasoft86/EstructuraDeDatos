#include <iostream>
#include <cstdlib>

using namespace std;

class ABB{

private:
	struct Nodo{
		int dato;
		Nodo* izquierdo;
		Nodo* derecho;
	};
	
	void nuevoNodoABB(Nodo *nodo,int dato);
	void insertarABB(Nodo* Ptr,int dato);
	void verArbolABB(Nodo* node,int n);
	int buscarMinimoABB(Nodo* Ptr);
	void removerNodoABB(Nodo* nodo,int dato);
	void removerNodoRaiz();
	void removerNodoEncontrado(Nodo* nodo, Nodo* encontrado, bool esIzquierdo);
	void imprimirPreOrdenABB(Nodo *nodo);
	void imprimirEnOrdenABB(Nodo *nodo);
	void imprimirPostOrdenABB(Nodo *nodo);
	Nodo* buscarNodoABB(Nodo* nodo,int dato);
	
public:
	ABB();
	Nodo* raiz;
	Nodo* nuevoNodo(int dato);
	void insertar(int dato);
	void verArbol(int n);
	void verArbolEnOrden();
	int buscarMinimo();
	void removerNodo(int dato);
	void imprimirPreOrden();
	void imprimirEnOrden();
	void imprimirPostOrden();
	void buscarNodo(int dato);
};

ABB::ABB(){
	raiz = NULL;
}

ABB::Nodo* ABB::nuevoNodo(int dato){
	Nodo* n = new Nodo;
	n->dato = dato;
	n->izquierdo = NULL;
	n->derecho = NULL;
	return n;
}

void ABB::insertar(int dato)
{
	insertarABB(raiz,dato);
}

void ABB::insertarABB(Nodo* nodo,int dato)
{
	// 2.- Partiendo de la raíz preguntamos: Nodo == null ( o no existe ) ? 
	if(raiz==NULL)
	{
		// 3.- En caso afirmativo X pasa a ocupar el lugar del nodo y ya 
        // hemos ingresado nuestro primer dato. 
		raiz=nuevoNodo(dato);
	}
	// 4.- En caso negativo preguntamos: X < Nodo 
	else if(dato < nodo->dato)
	{
	    /* 
	     * 5.- En caso de ser menor pasamos al Nodo de la IZQUIERDA del
	     * que acabamos de preguntar y repetimos desde el paso 2 
	     * partiendo del Nodo al que acabamos de visitar 
	     */
		if(nodo->izquierdo != NULL)
		{
			insertarABB(nodo->izquierdo,dato);
		}
		else
		{
			nodo->izquierdo = nuevoNodo(dato);
		}
	}
	else if(dato> nodo->dato)
	{
    	/* 
         * 6.- En caso de ser mayor pasamos al Nodo de la DERECHA y tal
         * cual hicimos con el caso anterior repetimos desde el paso 2
         * partiendo de este nuevo Nodo.
         */
		if(nodo->derecho != NULL)
		{
			insertarABB(nodo->derecho,dato);
		}
		else
		{
			nodo->derecho = nuevoNodo(dato);
		}
	}
	else{
		cout <<"The key "<<dato<<"has already been added to the tree\n";
	}
}

void ABB::verArbol(int n)
{
	verArbolABB(raiz,n);
}

void ABB::verArbolABB(Nodo *nodo,int n)
{
    if (raiz != NULL)
    {
		if(nodo->derecho!=NULL)
    	{
    		verArbolABB(nodo->derecho,n+1);
		}
		
		for(int i=0; i<n; i++)
         cout<<"   ";
         
		cout<< nodo->dato <<endl;

		if(nodo->izquierdo!=NULL)
    	{
    		verArbolABB(nodo->izquierdo,n+1);
		}
	}
	else
	{
		cout<<"El arbol esta vacio";
	}  
}

int ABB::buscarMinimo()
{
	return buscarMinimoABB(raiz);
}

int ABB::buscarMinimoABB(Nodo* nodo)
{
	if (raiz == NULL)
	{
		cout << "The tree is empty";
		return -1000;
	}
	else
	{
		if (nodo->izquierdo != NULL)
		{
			return buscarMinimoABB(nodo->izquierdo);
		}
		else
		{
			return nodo->dato;
		} 
	}
}

void ABB::removerNodo(int dato)
{
    removerNodoABB(raiz,dato);
}

void ABB::removerNodoABB(Nodo* nodo,int dato)
{
    if (raiz!=NULL)
    {
        if (dato == raiz->dato)
        {
            removerNodoRaiz();
        }
        else
        {
            if (dato < nodo->dato && nodo->izquierdo != NULL)
            {
                nodo->izquierdo->dato == dato ?
                removerNodoEncontrado(nodo, nodo->izquierdo, true):
                removerNodoABB(nodo->izquierdo,dato);
            }
            else if (dato > nodo->dato && nodo->derecho != NULL)
            {
                nodo->derecho->dato == dato ?
                removerNodoEncontrado(nodo, nodo->derecho, false):
                removerNodoABB(nodo->derecho,dato);
            }
            else
                cout<<"El dato "<< dato << "no se encuentra en el arbol";
        }
    }
    else
        cout<<"El arbol esta vacio\n";
    
}

void ABB::removerNodoRaiz()
{
    if (raiz != NULL)
    {
        Nodo* delPtr = raiz;
        int raizdato = raiz->dato;
        int minimoValorSubArbol;
        
        //caso 0 - 0 hijos
        if (raiz->izquierdo == NULL && raiz->derecho==NULL)
        {
            raiz = NULL;
            delete delPtr;
        }
        //caso 1 - 1 hijo
        else if (raiz->izquierdo==NULL && raiz->derecho != NULL)
        {
            raiz = raiz->derecho;
            delPtr->derecho = NULL;
            delete delPtr;
           	cout<<"El nodo raiz con dato "<< raizdato<<" ha sido eliminado \n"<<
           	"La nueva raiz contiene el dato " << raiz->dato << endl;
        }
        else if (raiz->izquierdo!=NULL && raiz->derecho == NULL)
        {
            raiz = raiz->izquierdo;
            delPtr->izquierdo = NULL;
            delete delPtr;
          	cout<<"El nodo raiz con dato "<< raizdato<<" ha sido eliminado \n"<<
           	"La nueva raiz contiene el dato " << raiz->dato << endl;
        }
        //caso 2 - 2 hijos
        else
        {
            minimoValorSubArbol = buscarMinimoABB(raiz->derecho);
            removerNodoABB(raiz,minimoValorSubArbol);
            raiz->dato = minimoValorSubArbol;
            cout<<"El dato de raiz "<<raizdato <<" ha sido sobreescrito por "<< minimoValorSubArbol << endl;
        }
    }
    else
        cout<<"El arbol esta vacio \n";
}

void ABB::removerNodoEncontrado(Nodo* nodo, Nodo* nodoEncontrar, bool isizquierdo)
{
    if (raiz != NULL)
    {
        Nodo* delPtr;
        int datoEncontrado = nodoEncontrar->dato;
        int minimoValorSubArbol;
        
        //caso 0 - 0 hijo
        if (nodoEncontrar->izquierdo == NULL && nodoEncontrar->derecho==NULL)
        {
            delPtr = nodoEncontrar;
            isizquierdo == true?
            nodo->izquierdo = NULL:
            nodo->derecho = NULL;
            delete delPtr;
            cout<<"El nodo que contiene el dato "<< datoEncontrado <<" ha sido eliminado\n";
        }
        //caso 1 - 1 hijo
        else if (nodoEncontrar->izquierdo==NULL && nodoEncontrar->derecho!=NULL)
        {
            isizquierdo == true?
            nodo->izquierdo = nodoEncontrar->derecho:
            nodo->derecho = nodoEncontrar->derecho;
            
            nodoEncontrar->derecho = NULL;
            delPtr = nodoEncontrar;
            delete delPtr;
            cout<<"El nodo que contiene el dato "<< datoEncontrado <<" ha sido eliminado\n";
        }
        else if (nodoEncontrar->izquierdo!=NULL && nodoEncontrar->derecho==NULL)
        {
            isizquierdo == true?
            nodo->izquierdo = nodoEncontrar->izquierdo:
            nodo->derecho = nodoEncontrar->izquierdo;
            
            nodoEncontrar->izquierdo = NULL;
            delPtr = nodoEncontrar;
            delete delPtr;
            cout<<"El nodo que contiene el dato "<< datoEncontrado <<" ha sido eliminado\n";
        }
        //caso 2 - 2 hijos
        else
        {
            minimoValorSubArbol = buscarMinimoABB(nodoEncontrar->derecho);
            removerNodoABB(nodoEncontrar,minimoValorSubArbol);
            nodoEncontrar->dato = minimoValorSubArbol;
        }
    }
    else
        cout<<"El arbol esta vacio \n";
}


void ABB::imprimirPreOrden() 
{
	imprimirPreOrdenABB(raiz);
}

void ABB::imprimirPreOrdenABB(Nodo* nodo) 
{
	if (raiz != NULL)
	{
		cout<<nodo->dato << " "; 
		if (nodo->izquierdo !=NULL) 
		{
			imprimirPreOrdenABB(nodo->izquierdo); 
		}
		
		if (nodo->derecho != NULL) 
		{
			imprimirPreOrdenABB(nodo->derecho); 
		}
	}
	else
	{
		cout<<"El arbol esta vacio!\n";
	}
}

void ABB::imprimirEnOrden() 
{
	imprimirEnOrdenABB(raiz);
}

void ABB::imprimirEnOrdenABB(Nodo* nodo) 
{
	if (raiz != NULL)
	{
		if (nodo->izquierdo !=NULL) 
		{
			imprimirEnOrdenABB(nodo->izquierdo); 
		}
		cout<<nodo->dato << " "; 
		if (nodo->derecho != NULL) 
		{
			imprimirEnOrdenABB(nodo->derecho); 
		}
	}
	else
	{
		cout<<"El arbol esta vacio!\n";
	}
}

void ABB::imprimirPostOrden()
{
    imprimirPostOrdenABB(raiz);
}

void ABB::imprimirPostOrdenABB(Nodo* nodo)
{
    if (raiz!=NULL)
    {

        if (nodo->izquierdo != NULL)
        {
            imprimirPostOrdenABB(nodo->izquierdo);
        }
        
        if (nodo->derecho != NULL)
        {
            imprimirPostOrdenABB(nodo->derecho);
        }
        
        cout<<nodo->dato<<" ";
    }
    else
        cout<<"El arbol esta vacio!\n";
}

void ABB::buscarNodo(int dato)
{
	Nodo *nodo = buscarNodoABB(raiz,dato);
	cout<<" Dato encontrado: "<<nodo->dato;
}

ABB::Nodo* ABB::buscarNodoABB(Nodo *nodo,int dato)
{
	if(nodo!=NULL)
	{
		if(nodo->dato == dato)
		{
			return nodo;
		}
		else
		{
			if(dato < nodo->dato)
			{
				return buscarNodoABB(nodo->izquierdo,dato);
			}
			else
			{
				return buscarNodoABB(nodo->derecho,dato);
			}
		}
	}
	else
	{
		return NULL;
	}
}


int main() 
{
	ABB miArbol;

	miArbol.insertar(8);
	miArbol.insertar(3);
	miArbol.insertar(1);
	miArbol.insertar(6);
	miArbol.insertar(4);
	miArbol.insertar(7);
	miArbol.insertar(10);
	miArbol.insertar(14);
	miArbol.insertar(13);
	
	miArbol.verArbol(0);
	cout<<"\n";
	cout<<"\n";	
	
	cout<<"En PreOrden: ";
	miArbol.imprimirPreOrden();
	
	cout<<"\n";
	cout<<"\n";
	
	cout<<"En Orden: ";
	miArbol.imprimirEnOrden();
	
	cout<<"\n";
	cout<<"\n";
	
	cout<<"En PostOrden: ";
	miArbol.imprimirPostOrden();
	/*
	miArbol.removerNodo(50);
	miArbol.verArbol(0);
	*/
	
	
	return 0;
}
