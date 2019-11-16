#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
};

struct listaDatos{
	int num;
	listaDatos* sig;
};
//Funciones de lista
void insertarDatos(listaDatos** pInicio);
void imprimirDatos(listaDatos* lista, int contador);
void imprimirMenu(void);
//Funciones de arbol
nodo *crearnodo(int n);
void insertar(nodo *&arbol, int n);
void mostrarArbol(nodo *arbol, int contador);
bool busquedaEnArbol(nodo *&arbol, int n);

void insertandoEnArbol(nodo *&arbol, listaDatos* lista);

nodo *arbol=NULL;

int main(void) {
	int opcion=0, busca=0, contador=0, n=0, conta=0;
	listaDatos* pInicio = NULL;
	cout<<"ESTE PROGRAMA PERMITE CONSTRUIR UN ARBOL BINARIO DE BUSQUEDA A PARTIR"<<endl;
	cout<<"DE UNA LISTA SIMPLEMENTE ENLAZADA, SE PUEDE VOLVER A INGRESAR DATOS DESPUES"<<endl;
	cout<<"DE HABER CREADO EL ARBOL Y LOS NUEVOS DATOS SERAN GUARDADOS SIN REPETIR"<<endl<<endl;
	do{
		imprimirMenu(); cin >> opcion;
		cout<<endl;
		switch (opcion) {
		case 1:
			insertarDatos(&pInicio);
			cout<<endl;
			break;
		case 2:
			imprimirDatos(pInicio, 0);
			cout<<endl;
			break;
		case 3:
			insertandoEnArbol(arbol, pInicio);
			if(conta==0){
				cout<<"Arbol CREADO exitosamente!"<<endl<<endl;
			}else{
				cout<<"Arbol ACTUALIZADO exitosamente!"<<endl<<endl;
			}
			conta++;
			break;
		case 4:
		    cout<<"MOSTRANDO ARBOL COMPLETO."<<endl<<endl;
		    mostrarArbol(arbol, contador);
		    cout<<endl;
		    break;
	}
	}while (opcion != 0);
	
	return 0;
}

//Funciones de lista y MENU

void imprimirDatos(listaDatos* lista,int contador){
	if(!lista){
		if(contador==0){
			cout<<"LISTA VACIA"<<endl;
		}
		return;
	}
	else{
		cout << "Dato:\t" << lista->num << endl;
		imprimirDatos(lista->sig, contador+1);		 
	}	
}

void imprimirMenu(void) {
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Introducir datos (numeros enteros) a lista simple. . ." << endl;
	cout << "2. Mostrar datos en lista simple. . ." << endl;
	cout << "3. Crear/Actualizar Arbol a partir de lista simple. . ." << endl;
	cout << "4. Mostrar Arbol. . ." << endl;
	cout << "0. Salir   Su opcion: ";
}

void insertarDatos(listaDatos** pInicio) {
	listaDatos* nuevo = new listaDatos;
	cout << "Ingrese un numero: "; cin >> nuevo->num;
	nuevo->sig = NULL;

	if (!*pInicio)
		* pInicio = nuevo;
	else {
		listaDatos* aux = *pInicio;
		
		while (aux->sig)
			aux = aux->sig;

		aux->sig = nuevo;
	}
}

//Funciones de arbol

void insertar(nodo *&arbol, int n){
	if(arbol==NULL){
		nodo *nuevo_nodo = crearnodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n<valorRaiz){
			insertar(arbol->izq, n);
			
		}
		else{
			insertar(arbol->der, n);
		}
	}
}

void mostrarArbol(nodo *arbol, int contador){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, contador+1);
		for(int i=0;i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, contador+1);
	}
}

void insertandoEnArbol(nodo *&arbol, listaDatos* lista){
	if(!lista)
		return;
	else{
		if(busquedaEnArbol(arbol, lista->num)){
			insertandoEnArbol(arbol, lista->sig);
		}else{
			insertar(arbol, lista->num);
		insertandoEnArbol(arbol, lista->sig);
		}		 
	}	
}

bool busquedaEnArbol(nodo *&arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n<arbol->dato){
		busquedaEnArbol(arbol->izq, n);
	}
	else{
		busquedaEnArbol(arbol->der, n);
	}
}

nodo *crearnodo(int n){
	nodo *nuevo_nodo=new nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->der=NULL;
	
	return nuevo_nodo;
}
