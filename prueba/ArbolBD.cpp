#include "ArbolBD.h"
#include "Nodo.h"
#include "sqlite/sqlite3.h"
#include <exception>
#include <sstream>
#include <iostream>


void ArbolBD::crearTablas()
{
	sqlite3* bd;
	char* mensajeerror;
	if (!sqlite3_open(_archivo.c_str(), &bd)) {
		std::string consulta= "create table if not exists arboles(ID integer primary key AUTOINCREMENT, longitud INTEGER NOT NULL)";
		if (sqlite3_exec(bd, consulta.c_str(),nullptr, nullptr,&mensajeerror ) != SQLITE_OK) {
			throw std::exception(sqlite3_errmsg(bd));
		}
		else {
			std::string consulta = 
				"create table if not exists datos(ID integer primary key AUTOINCREMENT, "
				"dato integer not null, arbolid integer not null, "
				"FOREIGN KEY (arbolid) REFERENCES arboles(ID))";
			if (sqlite3_exec(bd, consulta.c_str(), nullptr, nullptr, &mensajeerror) != SQLITE_OK) {
				throw std::exception(sqlite3_errmsg(bd));
			}
			
		}
		sqlite3_close(bd);

	}
	else {
		throw std::exception(sqlite3_errmsg(bd));
	}
}

unsigned long long ArbolBD::guardarDatos(const std::vector<int>& datos)
{
	sqlite3* bd;
	char* mensajeerror;

	if (datos.empty()) {
		//TODO
	}

	if (sqlite3_open(_archivo.c_str(), &bd) == SQLITE_OK) {
		unsigned long long id;
		std::string consulta = "INSERT INTO arboles (longitud) VALUES (" + std::to_string(datos.size()) + ") RETURNING ID";
		auto arbolCallback = [](void* idPtr, int argc, char** argv, char** cols) {
			if (argc > 0)
			{
				std::stringstream ss(argv[0]);
				ss >> *reinterpret_cast<unsigned long long*>(idPtr);
			}
			return 0; 
		};
		if (sqlite3_exec(bd, consulta.c_str(), arbolCallback, &id, &mensajeerror) != SQLITE_OK) {
			
			throw std::exception(sqlite3_errmsg(bd));

		}
		consulta = "INSERT INTO  datos (dato, arbolid) VALUES ";
		std::string arbolId = std::to_string(id);
		for (int dato : datos)
		{
			consulta += " (" + std::to_string(dato) + ", " + arbolId + " ), ";
		}
		consulta = consulta.substr(0, consulta.size() - 2);
		if (sqlite3_exec(bd, consulta.c_str(), nullptr, nullptr, &mensajeerror) != SQLITE_OK) {

			throw std::exception(sqlite3_errmsg(bd));

		}


		sqlite3_close(bd);
		return id;
	}
	else {
		throw std::exception(sqlite3_errmsg(bd));
	}
}


Nodo* ArbolBD::consultar(unsigned long long ID)
{
	sqlite3* bd;
	char* mensajeerror;
	if (!sqlite3_open(_archivo.c_str(), &bd)) {
		std::string consulta = "SELECT dato FROM datos WHERE arbolid=" + std::to_string(ID) ;
		Nodo* arbol = nullptr;
		auto arbolCallback = [](void* nodoPtr, int argc, char** argv, char** cols) {
			if (argc > 0)
			{
				Nodo** arbolPtr = reinterpret_cast<Nodo**>(nodoPtr);
				int valor;
				std::stringstream ss(argv[0]);
				ss >> valor;

				Nodo* arbol = *arbolPtr;
				if (arbol == nullptr)
				{
					*arbolPtr = new Nodo(valor);
				}
				else
				{
					arbol->insertarNodo(valor);
				}
			}
			return 0;
		};

		if (sqlite3_exec(bd, consulta.c_str(), arbolCallback, &arbol, &mensajeerror) != SQLITE_OK) {
			throw std::exception(sqlite3_errmsg(bd));
		}
		sqlite3_close(bd);
		return arbol;
	}
	else {
		throw std::exception(sqlite3_errmsg(bd));
	}
	
}

ArbolBD::ArbolBD(const std::string& archivo) :_archivo(archivo)
{

}


