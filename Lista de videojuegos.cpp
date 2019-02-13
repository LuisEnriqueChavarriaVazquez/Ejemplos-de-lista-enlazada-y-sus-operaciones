#include <stdio.h>
#include <iostream>

using namespace std;

struct Nodo{
	string nombre;
	string genero;
	int costo;
	Nodo *sig;
	Nodo *ant;
};

void insertarElemento(Nodo *&lista, string nombre, string genero, int costo);
void imprimirElementos(Nodo *lista);
void buscarElementos(Nodo *lista, string nombre, string genero, int cosoto);
void anularElementos();
void eliminarElementos();

int main(){
	//Declaraciones para el menu
	int opcion,close = 1;
	
	//Declaraciones para las funciones
	int costo;
	string nombre;
	string genero;
	Nodo *lista = NULL;
	
	while(close){
		cout << "°\tBienvenido a tu lista personal de videojuegos" << endl;
		cout << "°\t/////////////////////////////////////////////" << endl;
		cout << "°\t[1]. Insertar un elemento." << endl;
		cout << "°\t[2]. Imprimir la lista." << endl;
		cout << "°\t[3]. Eliminar elemento de la lista." << endl;
		cout << "°\t[4]. Anular la lista. (Borrar todo)" << endl;
		cout << "°\t[X ENTERO] salir" << endl;
		cout << "°\t/////////////////////////////////////////////" << endl;
		cout << "°\n\tIndique que es lo que quiere hacer: ";
		cin >> opcion; 
	
		switch(opcion) {
		case 1:
			cout << "\n\n\tDigite un Nombre: "; /**/ cin >> nombre;
			cout << "\n\n\tDigite un Genero: "; /**/ cin >> genero;
			cout << "\n\n\tDigite un Costo: "; /**/ cin >> costo;
			insertarElemento(lista, nombre,genero,costo);
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tEl elemento " << nombre << " ha sido insertado correctamente\n" << endl;
			break;
		case 2:
			cout << "°°°°°°\tLista Impresa" << endl;
			imprimirElementos(lista);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tLa lista fue impresa.\n"<< endl;
			break;
		case 3:
			cout << "°°°°°°\tBusqueda de elemento" << endl;
			cout << "°°°°°°\tDanos el nombre del juego que buscas: "; cin >> nombre;
			buscarElementos(lista,nombre,genero,costo);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tElemento " << nombre << " estuvo en proceso de busqueda.\n" << endl;
			break;
			
		default:
			close = 0;
			break;
		}
	}
}

void insertarElemento(Nodo *&lista, string nombre, string genero, int costo){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->costo = costo;
	nuevo_nodo->genero = genero;
	nuevo_nodo->nombre = nombre;
	
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL)){
		aux2 = aux1;
		aux1 = aux1 -> sig;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}else{
		aux2->sig = nuevo_nodo;
	}
	
	nuevo_nodo->sig = aux1;
}

void imprimirElementos(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){
		cout << "\t °°°Nombre: " << actual -> nombre << endl;
		cout << "\t °°°Genero: " << actual -> genero << endl;
		cout << "\t °°°Costo: " << actual -> costo << endl;
		cout <<"////////////////////////////////////////////\n";
		actual = actual -> sig;
	}
}

void buscarElementos(Nodo *lista, string nombre, string genero, int costo){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){
		if(actual -> nombre == nombre){
			cout << "\t °°°Nombre: " << actual -> nombre << endl;
			cout << "\t °°°Genero: " << actual -> genero << endl;
			cout << "\t °°°Costo: " << actual -> costo << endl;
			cout <<"////////////////////////////////////////////\n";
		}
		actual = actual -> sig;
	}
}
