#include <iostream>
#include <exception>
#include <stdlib.h>
#include "ArbolBD.h"
#include "ServidorRest.h"




int main()
{
    ArbolBD dato("arbol_binario.sqlite");
    dato.crearTablas();
    ServidorRest servior(U("http://localhost:8080"), dato);
    servior.open().wait();
    std::cin.get();
    servior.close().wait();

}
