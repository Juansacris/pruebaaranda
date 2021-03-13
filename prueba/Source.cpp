#include <iostream>
#include <exception>
#include <stdlib.h>
#include "ArbolBD.h"



int main()
{
	try {
		ArbolBD dato("mi_tabla.sqlite");
		dato.crearTablas();
		unsigned long long ID = dato.guardarDatos({ 1,2,3,4 });
		Nodo* arbol = dato.consultar(ID);
	}
	catch (std::exception& ex){
		std::cout << ex.what() << std::endl;

	}
}