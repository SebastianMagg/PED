#include <iostream>
#include <cmath>
using namespace std;

struct polinomio{
	float coefi, variable;
	int expo, posicion;
	polinomio *sig;	
};
void imprimirMenu(void);
void imprimirDatos(polinomio *lista);
void insertarMono(polinomio **pInicio);
float evaluarMono(polinomio *lista, float variaX, float sumatoria);

int posi=0;
int longiPoli=0;
int main(void){
	int opcion=0, longi=0;
    float valor=0;
	polinomio *pInicio= NULL;
	cout<<"Ingrese la cantidad de nodos (monomios) de la lista: "; cin>>longiPoli;
	do{
		imprimirMenu(); cin >> opcion;
		cout<<endl;

		switch (opcion) {
		case 1:
			insertarMono(&pInicio);
			cout<<endl;
			longi--;
			break;
		case 2:
			imprimirDatos(pInicio);
			cout<<endl;
			break;
		case 3:
			cout<<endl;
			cout<<"Ingrese el valor de x para evaluar el polinomio ingresado: "; cin>>valor;
			cout<<"El valor del polinomio ingresado es: "<<evaluarMono(pInicio, valor, 0);
			cout<<endl;
			break;
		}
	} while (opcion != 0);

	return 0;
}

void imprimirMenu(void) {
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Insertar Monomio . . ." << endl;
	cout << "2. Mostrar todos los monomios ingresados . . ." << endl;
	cout << "3. Evaluar polinomio es un 'x' especifico . . ." << endl;
	cout << "0. Salir   Su opcion: ";
}
void imprimirDatos(polinomio *lista){
	if(!lista)
		return;
	else{
		cout<<endl;
		cout << "Monomio en la posicion: "<<lista->posicion<<endl;
		cout << "Coeficiente: " << lista->coefi << endl;
		cout << "Exponente: " << lista->expo << endl;
		imprimirDatos(lista->sig);		 
	}
}
void insertarMono(polinomio **pInicio){
	if(longiPoli>0){
		polinomio* nuevo = new polinomio;
		int newposi=posi+1;
		cout<<"Ingrese el coeficiente del monomio: "; cin>>nuevo->coefi;
		nuevo->expo=posi;
		cout<<"El exponente en este monomio:  "<<nuevo->expo<<endl;
		nuevo->posicion=newposi;
		nuevo->sig = NULL;

		if (!*pInicio){
			*pInicio = nuevo;
		}
		else {
			polinomio* aux = *pInicio;		
			while (aux->sig)
			aux = aux->sig;
			aux->sig = nuevo;
		}
		posi++;
		longiPoli--;
    }else{
    	cout<<"Ha llenado el espacio disponible para ingresar monomios"<<endl;
    	return;
	}
}

float evaluarMono(polinomio *lista, float variaX, float sumatoria){
	if(!lista)
		return sumatoria;
	else{
		sumatoria+=((lista->coefi*pow(variaX, lista->expo))+evaluarMono(lista->sig, variaX, sumatoria));
	}
}
