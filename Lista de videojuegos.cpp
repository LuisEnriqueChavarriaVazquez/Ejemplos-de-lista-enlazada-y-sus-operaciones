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
void recuperaElementos(Nodo *lista, string nombre, string genero, int costo);
void eliminarElementos(Nodo *&lista, string nombre);
void anularElementos(Nodo *&lista, string &nombre, string &genero, int &costo);
void buscarPrimero(Nodo *&lista);
void localizarElemento(Nodo *lista, string nombre);

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
		cout << "°\t[3]. Buscar (recuperar) elemento en la lista por (nombre)." << endl;
		cout << "°\t[4]. Eliminar elemento de la lista." << endl;
		cout << "°\t[5]. Anular la lista. (Borrar todo)" << endl;
		cout << "°\t[6]. Retornar e imprimir el primer valor de la lista" << endl;
		cout << "°\t[7]. Localizar la posicion del elemento en la lista" << endl;
		cout << "°\t[8]. Antes [->]" << endl;
		cout << "°\t[9]. Despues [<-]" << endl;
		cout << "°\t[X ENTERO] salir" << endl;
		cout << "°\t/////////////////////////////////////////////" << endl;
		cout << "°\n\tIndique que es lo que quiere hacer: ";
		cin >> opcion; 
	
		switch(opcion) {
		case 1:
			cout << "\n\tDigite un Nombre: "; /**/ cin >> nombre;
			cout << "\n\tDigite un Genero: "; /**/ cin >> genero;
			cout << "\n\tDigite un Costo: "; /**/ cin >> costo;
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
			recuperaElementos(lista,nombre,genero,costo);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tElemento " << nombre << " estuvo en proceso de busqueda.\n" << endl;
			break;
		case 4:
			cout << "°°°°°°\tBorrar un elemento" << endl;
			cout << "°°°°°°\tDanos el nombre del juego que buscas: "; cin >> nombre;
			eliminarElementos(lista,nombre);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tElemento " << nombre << " fue eliminado.\n" << endl;
			break;
		case 5:
			cout << "°°°°°°\tBorrar toda la lista" << endl;
			anularElementos(lista,nombre,genero,costo);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tToda la lista ha sido eliminada.\n" << endl;
			break;
			
		case 6:
			cout << "°°°°°°\tBuscar el primer elemento" << endl;
			buscarPrimero(lista);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tEl primer elemento ha sido impreso.\n" << endl;
			break;
		/*case 7:
			cout << "°°°°°°\tRetornar direccion del elemento\n" << endl;
			localizarElemento(lista,nombre);
			system("pause");
			system("CLS");
			cout << "\n°°°°°Actividad reciente°°°°°\tEl direccion del elemento " << nombre << " ha sido retornada.\n" << endl;
			break;*/
			
			/*case 8:
				antes
				break;*/
			
		default:
			cout << "Estas seguro de que quiere salir?? // SI = 0 // NO = 1 // :";
			int final;
			cin >> final;
			if(final == 0){
				close = 0;
			}else{
				close = 1;
				system("CLS");
			}
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

void buscarPrimero(Nodo *&lista){
	for(int i = 1; i <= 1; i++){
		Nodo *aux = lista;
		cout << "\t °°°Nombre: " << aux -> nombre << endl;
		cout << "\t °°°Genero: " << aux -> genero << endl;
		cout << "\t °°°Costo: " << aux -> costo << endl;
		cout <<"////////////////////////////////////////////\n";
	}
}

void recuperaElementos(Nodo *lista, string nombre, string genero, int costo){
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

/*void localizarElemento(Nodo *lista,string nombre){
	Nodo *actual = new Nodo();
	actual = lista;
	direccion = *lista;
	while(actual != NULL){
		if(actual -> nombre == nombre){
			cout << "\t °°°Nombre: " << actual -> nombre << endl;
			cout << "\t °°°Direccion elemento: " << actual -> &direccion << endl;
			cout <<"////////////////////////////////////////////\n";
		}
		actual = actual -> sig;
	}
}*/

void eliminarElementos(Nodo *&lista, string nombre){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *ant = NULL;
		aux_borrar = lista; 
	
		while((aux_borrar != NULL) && (aux_borrar->nombre != nombre)){
			ant = aux_borrar;
			aux_borrar = aux_borrar -> sig;
		}
	
		if(aux_borrar == NULL){
			cout <<"\t°°°°°Este elemento no existe" << endl;
		}else if(ant == NULL){
			lista = lista -> sig;
			delete aux_borrar;
		}else{
			ant -> sig = aux_borrar ->sig;
			delete aux_borrar;
		}
	}
}

void anularElementos(Nodo *&lista, string &nombre, string &genero, int &costo){
	Nodo *aux = lista;
	nombre = aux -> nombre;
	genero = aux -> genero;
	costo = aux -> costo;
	
	lista = aux -> sig;
	delete aux;
}

