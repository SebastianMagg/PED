#include <iostream>

using namespace std;

struct ListaD{
   int Numero;
   ListaD* sig;
};

void Insertar(ListaD** PI);
void ImprimirMenu(void);
void ImprimirD(ListaD* Lista);
void Eliminar(ListaD** Lista, int Find);

int main(void){
  int opcion=0, Find=0;
  ListaD* PI = NULL;

  do{
    ImprimirMenu();cin>>opcion;

    switch(opcion){
       case 1:
       Insertar(&PI);
       break;

       case 2:
       ImprimirD(PI);
       break;

       case 3:
       cout<<"Que numero eliminara: ";cin>>Find;
       Eliminar(&PI,Find);
       break;
    }
  } while(opcion!=0);
  return 0;
}

void ImprimirMenu(void){
  cout<<"1. Inserte los datos:  "<<endl;
  cout<<"2. Mostrar Lista:  "<<endl;
  cout<<"3. Borrar un numero:  "<<endl;
  cout<<"0. Salir       Su opcion: "<<endl;
}

void Insertar(ListaD** PI){
  ListaD* nuevo = new ListaD;
  cout<<"Inserte un numero: ";cin>>nuevo->Numero;
  nuevo->sig = NULL;
  if(!* PI)
     * PI = nuevo;
  else{
    ListaD* aux = *PI;

    while(aux->sig)
    aux=aux->sig;

    aux->sig = nuevo;
  }
}

void ImprimirD (ListaD* Lista){
  if(!Lista)
  return ;
  else{
    cout<<"Numero: \t"<< Lista->Numero<<endl;
    ImprimirD(Lista->sig);
  }
}

void Eliminar(ListaD** Lista, int Find){
  if(*Lista){
    if((*(*Lista)).Numero == Find){
      *Lista = (*(*Lista)).sig;
      Eliminar(Lista,Find);
    }
    else{
      Eliminar(&(*(*Lista)).sig, Find);
    }
  }
}
