#include <iostream>
#include <stdlib.h>
	
using namespace std;


class Nodo
{
public:
	int dato; 
	Nodo *der;
	Nodo *izq;
	};


void menu();
Nodo *CrearNodo(int);
void insertarNodo( Nodo *&,int);
void verArbol(Nodo *,int);
Nodo *Arbol = NULL;

int main()
{
	menu();

	cin.get();
}

void menu()
{

	int dato,opcion,cuenta=0;
	
	do {
		cout << "\t.:MENU:." << endl;
		cout << "Digite el numero que desee segun la accion que requiera." << endl;
		cout << "1. Insertar un nuevo nodo" << endl;
		cout << "2. Mostrar el Arbol" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:  cout << "\nDigite un numero:  ";
			cin >> dato;
			insertarNodo(Arbol, dato); //insertamos un nodo.
			cout << "\n";
			system("pause");
			break;
		case 2:	cout << "\nARBOL BINARIO:\n\n\n ";
			verArbol(Arbol, cuenta);
			cout << "\n\n";
			system("pause");
			break;

		}
		system("cls");
	} while (opcion != 3);
}

//fundion para crear los nodos del arbol 
Nodo *CrearNodo(int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

//funcion para insertar elementos al arbol 

void insertarNodo(Nodo *&Arbol, int n)
{
	if (Arbol == NULL) { //si el arbol esta vacio
		Nodo *nuevo_nodo = CrearNodo(n);
		Arbol = nuevo_nodo;
		}
	else { // si el arbol tiene uno o mas nodos 
		int valorRaiz = Arbol->dato; //obtener el valor de la raiz
		if (n < valorRaiz) {		//si n es menor a la raiz insertams por la izquierda
			insertarNodo(Arbol->izq, n);
		}
		else {
			insertarNodo(Arbol->der, n);
		}
	}
}

//funcion para mostrar el arbol
void verArbol(Nodo* Arbol, int cuenta)
{
	if (Arbol == NULL)
	{
		return;
	}
	else {
		verArbol(Arbol->der, cuenta + 1);
		for (int i = 0; i <= cuenta; i++) {
			cout << "    ";
		}
		cout << Arbol->dato << endl;
		verArbol(Arbol->izq, cuenta + 1);
	}
}