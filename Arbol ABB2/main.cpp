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
		int contarHojas(Nodo* node);
		void mostrarPorNivel(Nodo* node,int nivel);
		int esArbolBusqueda(Nodo* node);
		int arbolesIdenticos(Nodo* a,Nodo* b);
	
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

int ABB::contarHojas(Nodo *nodo)
{
  if(nodo == NULL)       
    return 0;
  if(nodo->izquierdo == NULL && nodo->derecho==NULL)      
    return 1;            
  else
    return contarHojas(nodo->izquierdo)+contarHojas(nodo->derecho);      
}

void ABB::mostrarPorNivel(Nodo *nodo, int nivel)
{
    if (nodo == NULL)
        return;
    if (nivel == 1)
        cout<<" "<<nodo->dato<<", ";
    else if (nivel > 1)
    {
        mostrarPorNivel(nodo->izquierdo, nivel-1);
        mostrarPorNivel(nodo->derecho, nivel-1);
    }
}

int ABB::esArbolBusqueda(Nodo* nodo) 
{ 
  if (nodo == NULL) 
    return 1; 
     
  if (nodo->izquierdo != NULL && nodo->izquierdo->dato > nodo->dato) 
    return 0; 
     
  if (nodo->derecho != NULL && nodo->derecho->dato < nodo->dato) 
    return 0; 
   
  if (!esArbolBusqueda(nodo->izquierdo) || !esArbolBusqueda(nodo->derecho)) 
    return 0; 
     
  return 1; 
}

/*
1. Si ambos árboles están vacíos, regrese 1.
2. Else Si ambos árboles no son vacíos
      (A) Verifique los datos de los nodos raíz (tree1-> data == tree2-> data)
      (B) Compruebe recursivamente los subárboles izquierdos, es decir, llame a mismoTree (
           Árbol1-> left_subtree, tree2-> left_subtree)
      (C) Compruebe los subárboles rectos recursivamente, es decir, llame a mismoTree (
           Tree1-> right_subtree, tree2-> right_subtree)
      (D) Si a, byc son verdaderos, entonces regrese 1.
3 Else return 0 (uno está vacío y otro no)
*/
int ABB::arbolesIdenticos(Nodo* a,Nodo* b)
{
    //1
    if (a==NULL && b==NULL)
        return 1;
 
    //2
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->dato == b->dato &&
            arbolesIdenticos(a->izquierdo, b->izquierdo) &&
            arbolesIdenticos(a->derecho, b->derecho)
        );
    }
     
    //3
    return 0;
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
	cout << "\n\n";
	
	cout<<"PreOrden: ";
	arbol.preOrden(arbol.raiz());
	cout << "\n\n";

	cout<<"PostOrden: ";
	arbol.postOrden(arbol.raiz());
	cout << "\n\n";
	
	cout<<"Numero de hojas: "<<arbol.contarHojas(arbol.raiz());
	cout << "\n\n";
	
	cout<<"-- Mostrar por nivel --\n";
	cout<<"Nivel: 2 \n";
	arbol.mostrarPorNivel(arbol.raiz(),2);
	cout << "\n\n";
	
	cout<<"Es arbol busqueda: "<<arbol.esArbolBusqueda(arbol.raiz());
	cout << "\n\n";

	return 0;
}

