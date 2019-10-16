#include <iostream>
using namespace std;

struct listaDatos{
	int num;
	listaDatos* sig;
};

void insertarDatos(listaDatos** pInicio);
void imprimirDatos(listaDatos* lista);
void imprimirMenu(void);
int sumarPares(listaDatos* lista, int sumaPares);
int sumarImpares(listaDatos* lista, int sumaImpares);

int main(void){
	int opcion=0;
	listaDatos* pInicio = NULL;
	do{
		imprimirMenu(); cin >> opcion;

		switch (opcion) {
		case 1:
			insertarDatos(&pInicio);
			break;
		case 2:
		    cout<<endl;
			imprimirDatos(pInicio);
			break;
		case 3:
			cout<<endl;
			cout<<"La suma de los numeros pares es: "<<sumarPares(pInicio, 0)<<endl;
			break;
		case 4:
			cout<<endl;
			cout<<"La suma de los numeros impares es: "<<sumarImpares(pInicio, 0)<<endl;
			break;	
		}

	} while (opcion != 0);

	return 0;
}

void imprimirMenu(void) {
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Introducir datos (numeros enteros) . . ." << endl;
	cout << "2. Mostrar lista . . ." << endl;
	cout << "3. Realizar y mostrar sumatoria de numeros pares contenidos en la lista. . ." << endl;
	cout << "4. Realizar y mostrar sumatoria de numeros impares contenidos en la lista. . ." << endl;
	cout << "0. Salir   Su opcion: ";
}

void imprimirDatos(listaDatos* lista){
	if(!lista)
		return;
	else{
		cout << "Numero:\t" << lista->num << endl;
		imprimirDatos(lista->sig);		 
	}	
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

int sumarPares(listaDatos* lista, int sumaPares){
	if(lista==NULL){
		return sumaPares;
	}
	else{
		if(lista->num %2 ==0){
			sumaPares=sumaPares+lista->num;
		}
		sumarPares(lista->sig, sumaPares);
	}	
}

int sumarImpares(listaDatos* lista, int sumaImpares){
	if(lista==NULL){
		return sumaImpares;
	}
	else{
		if(lista->num %2 !=0){
			sumaImpares=sumaImpares+lista->num;
		}
		sumarImpares(lista->sig, sumaImpares);
	}	
}

