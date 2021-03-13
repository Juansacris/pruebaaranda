#pragma once


class Nodo
{

	int _dato;
	Nodo *_der;
	Nodo *_izq;
	Nodo *_raiz;

public:

	void insertarNodo(int dato);
	
	Nodo(int n);

	int verDato();

	Nodo* verIzq();
	Nodo* verDer();
	
};






