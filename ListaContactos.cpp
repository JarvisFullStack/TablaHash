#include <bits/stdc++.h>
#include "TablaHash.cpp"
using namespace std;

class Nodo{
	public:
	
		string nombre;
		Nodo *siguiente;
		Nodo *anterior;
		Nodo(){
			
			siguiente = NULL;
			anterior = NULL;
		}
		
		Nodo(string nombre){
			this->nombre = nombre;
			this->siguiente = NULL;
			this->anterior = NULL;
		}
};

class Controlador{
	public:
		Nodo *primero;
		Nodo *ultimo;
		Controlador(){
			primero = NULL;
			ultimo = NULL;
		}
		void agregar(Nodo *nuevo){
			if(!primero){
				primero = ultimo = nuevo;
			}else{
				nuevo->anterior = ultimo;
				nuevo->siguiente = primero;
				primero->anterior = nuevo;
				ultimo->siguiente = nuevo;
				ultimo = nuevo;
				
			}
		}
		
		void listar(){
			Nodo *aux = primero;
			do{
				cout<<"Nombre: "<<aux->nombre<<endl;
				aux = aux->siguiente;
			}while(aux!=primero);
		}
		void listarrev(){
			Nodo *aux = ultimo;
			do{
				cout<<"Nombre: "<<aux->nombre<<endl;
				aux = aux->anterior;
			}while(aux!=ultimo);
			
		}
};


int main(){
	HashMap *hm = new HashMap();
	
	return 0;
}
