#pragma once
#include <vector>
#include <string>

class Nodo;

class ArbolBD
{
	std::string _archivo;
public:
	void crearTablas();
	unsigned long long guardarDatos(const std::vector<int> &datos);
	Nodo* consultar(unsigned long long ID);

	ArbolBD(const std::string &archivo);

};

