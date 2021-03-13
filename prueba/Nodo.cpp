
#include "Nodo.h"

Nodo::Nodo(int n):_dato(n),_der(nullptr),_izq(nullptr)
{

}

Nodo::~Nodo()
{
	delete _izq;
	delete _der;
}

void Nodo::insertarNodo(int dato)
{
	
	if (dato < _dato)
	{
		if (_izq == nullptr)
		{
			_izq = new Nodo(dato);
		}
		else
		{
			_izq->insertarNodo(dato);
		}

	}
	else if (dato > _dato)
	{
		if (_der == nullptr)
		{
			_der = new Nodo(dato);
		}
		else
		{
			_der->insertarNodo(dato);
		}

		
	}

}

int Nodo::verDato() 
{
	return _dato;
}

Nodo* Nodo::verIzq()
{
	return _izq;
}
Nodo* Nodo::verDer()
{
	return _der;
}

