#pragma once


class Nodo
{

	int _dato;
	Nodo *_der;
	Nodo *_izq;
	
public:

	void insertarNodo(int dato);
	
	Nodo(int n);
	~Nodo();

	int verDato();

	Nodo* verIzq();
	Nodo* verDer();
	
};






