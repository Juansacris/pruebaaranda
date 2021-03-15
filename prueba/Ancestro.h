#pragma once
#include <optional>
#include <vector>

class Nodo;

class Ancestro
{
	Nodo* _arbol;
	bool encontrarCamino(Nodo* nodo, std::vector<int> &camino, int a);


public: 

	Ancestro(Nodo* arbol);
	std::optional<int> encontrarAncestro(int a, int b);

};

