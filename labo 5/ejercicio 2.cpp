#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
};

nodo *crearnodo(int n);
void insertar(nodo *&arbol, int n);
void menu();
void mostrarArbol(nodo *arbol, int contador);
int contarNodosPares(nodo *arbol);
int contarNodosImpares(nodo *arbol);
int contarNodosNulos(nodo *arbol);
int contarNodosNegativos(nodo *arbol);
int contarNodosPositivos(nodo *arbol);


nodo *arbol=NULL;
int main(void){
	
	menu();
	return 0;
}

nodo *crearnodo(int n){
	nodo *nuevo_nodo=new nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->der=NULL;
	
	return nuevo_nodo;
}
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
void menu(){
	int dato, opcion, contador=0;
	
	do{
		cout<<"\t.:MENU:. "<<endl;
		cout<<"1. Insertar un nuevo nodo."<<endl;
		cout<<"2. Mostrar el arbol completo."<<endl;
		cout<<"3. Mostrar la cantidad nodos pares e impares."<<endl;
		cout<<"4. Cantidad de nodos negativos, ceros o positivos."<<endl;
		cout<<"0. Salir... Su eleccion: ";cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nDigite un numero: ";
				cin>>dato;
				insertar(arbol, dato);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\nMostrando el arbol completo \n\n";
				mostrarArbol(arbol, contador);
				cout<<endl;
				system("pause");
				break;
			case 3: 
			    cout<<"\nMostrando la cantidad de nodos pares: "<< contarNodosPares(arbol)<<endl;
			    cout<<"\nMostrando la cantidad de nodos impares: "<< contarNodosImpares(arbol)<<endl;
			    system("pause");
			    break;
			case 4: 
			    cout<<"\nCantidad de nodos nulos: "<< contarNodosNulos(arbol)<<endl;
			    cout<<"\nCantidad de nodos negativos: "<< contarNodosNegativos(arbol)<<endl;
			    cout<<"\nCantidad de nodos positivos: "<< contarNodosPositivos(arbol)<<endl;
			    system("pause");
			    break;
		}
		system("cls");
	}while(opcion != 0);
	
}

int contarNiveles(nodo *arbol){
	if(arbol!=NULL){
		int izq = contarNiveles(arbol->izq)+1;
		int der = contarNiveles(arbol->der)+1;
		if(izq>der){
			return izq;
		}else{
			return der;
		}
	}
	return -1;
	
}

int contarNodosPares(nodo *arbol){
	if(arbol==NULL){
		return 0;
	}else{
		if(arbol->dato % 2 == 0){
			return 1 + contarNodosPares(arbol->izq) + contarNodosPares(arbol->der);
		}else{
			return contarNodosPares(arbol->izq) + contarNodosPares(arbol->der);
		}
	}
}

int contarNodosImpares(nodo *arbol){
	if(arbol==NULL){
		return 0;
	}else{
		if(arbol->dato % 2 != 0){
			return 1 + contarNodosImpares(arbol->izq) + contarNodosImpares(arbol->der);
		}else{
			return contarNodosImpares(arbol->izq) + contarNodosImpares(arbol->der);
		}
	}
}

int contarNodosNulos(nodo *arbol){
	if(arbol==NULL){
		return 0;
	}else{
		if(arbol->dato == 0){
			return 1 + contarNodosNulos(arbol->izq) + contarNodosNulos(arbol->der);
		}else{
			return contarNodosNulos(arbol->izq) + contarNodosNulos(arbol->der);
		}
	}
}

int contarNodosNegativos(nodo *arbol){
	if(arbol==NULL){
		return 0;
	}else{
		if(arbol->dato < 0){
			return 1 + contarNodosNegativos(arbol->izq) + contarNodosNegativos(arbol->der);
		}else{
			return contarNodosNegativos(arbol->izq) + contarNodosNegativos(arbol->der);
		}
	}
}

int contarNodosPositivos(nodo *arbol){
	if(arbol==NULL){
		return 0;
	}else{
		if(arbol->dato > 0){
			return 1 + contarNodosPositivos(arbol->izq) + contarNodosPositivos(arbol->der);
		}else{
			return contarNodosPositivos(arbol->izq) + contarNodosPositivos(arbol->der);
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
