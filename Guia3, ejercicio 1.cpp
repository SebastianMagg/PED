#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct listaDatos{
	int num, pos;
	listaDatos* sig;
};
void insertarDatos(listaDatos** pInicio, int lon);
void imprimirDatosPares(listaDatos* lista);
void imprimirDatosImpares(listaDatos* lista);
void imprimirMenu(void);
void imprimirDatos(listaDatos* lista);
void impDatosInversamente(listaDatos *lista);

int main(void) {
	srand (time(NULL));
	int opcion=0, busca=0, longi=0;
	cout<<"Ingrese la cantidad de nodos de la lista: "; cin>>longi;
	listaDatos* pInicio = NULL;
	insertarDatos(&pInicio, longi);
	do{
		imprimirMenu(); cin >> opcion;
		cout<<endl;

		switch (opcion) {
		case 1:
			imprimirDatos(pInicio);
			cout<<endl;
			break;
		case 2:
			imprimirDatosPares(pInicio);
			cout<<endl;
			break;
		case 3:
			imprimirDatosImpares(pInicio);
			cout<<endl;
			break;
		case 4:
			impDatosInversamente(pInicio);
			cout<<endl;
			break;
		}
	} while (opcion != 0);

	return 0;
}

void imprimirMenu(void) {
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Mostrar todos los elementos de la lista . . ." << endl;
	cout << "2. Mostrar numeros pares de la lista . . ." << endl;
	cout << "3. Mostrar numeros impares de la lista . . ." << endl;
	cout << "4. Mostrar numeros en sentido inverso . . ." << endl;
	cout << "0. Salir   Su opcion: ";
}

void insertarDatos(listaDatos** pInicio, int longi) {
	while(longi>0){
	listaDatos* nuevo = new listaDatos;
	//srand (time(0));
	nuevo->num= (rand() % 100) + 1;
	nuevo->sig = NULL;

	if (!*pInicio){
		*pInicio = nuevo;
		longi--;
	}
	else {
		listaDatos* aux = *pInicio;
		
		while (aux->sig)
			aux = aux->sig;

		aux->sig = nuevo;
		longi--;
	}
 }
}

void imprimirDatos(listaDatos* lista){
	if(!lista)
		return;
	else{
		cout << "Numero: " << lista->num << endl;
		imprimirDatos(lista->sig);		 
	}	
}

void imprimirDatosPares(listaDatos* lista){
	if(lista != NULL){
		if(lista->num % 2==0){
			cout << "Numero: " << lista->num << endl;
			imprimirDatosPares(lista->sig);
		}else{
			imprimirDatosPares(lista->sig);
		}
   }
}

void imprimirDatosImpares(listaDatos* lista){
	if(lista != NULL){
		if(lista->num % 2!=0){
			cout << "Numero: " << lista->num << endl;
			imprimirDatosImpares(lista->sig);
		}else{
			imprimirDatosImpares(lista->sig);
		}
   }
}

void impDatosInversamente(listaDatos *lista){
	if(lista!=NULL){
		impDatosInversamente(lista->sig);
		cout<<lista->num<<endl;
	}		
}
