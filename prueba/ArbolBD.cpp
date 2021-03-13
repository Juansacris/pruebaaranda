#include "ArbolBD.h"
#include "sqlite/sqlite3.h"



void ArbolBD::crearTablas()
{
	sqlite3* bd;
	char* mensajeerror;
	if (sqlite3_open(_archivo.c_str(), &bd)) {
		std::string consulta= "create table arboles(ID integer primary key not null,)";
		if (sqlite3_exec(bd, consulta.c_str(),nullptr, nullptr,&mensajeerror ) != SQLITE_OK) {
			
		}
		else {
			std::string consulta = 
				"create table datos(ID integer primary key not null, "
				"dato integer not null, arbolid integer not null, "
				"FOREIGN KEY (arbolid) REFERENCES arboles(ID))";
			if (sqlite3_exec(bd, consulta.c_str(), nullptr, nullptr, &mensajeerror) != SQLITE_OK) {

			}
			else {

			}
		}
		sqlite3_close(bd);

	}
	else {

	}
}

unsigned long long ArbolBD::guardarDatos(const std::vector<int>& datos)
{
	return 0;
}

Nodo* ArbolBD::consultar(unsigned long long ID)
{
	return nullptr;
}

ArbolBD::ArbolBD(const std::string& archivo) :_archivo(archivo)
{

}


