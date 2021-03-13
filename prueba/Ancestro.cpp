#include "Ancestro.h"
#include "Nodo.h"


Ancestro::Ancestro(Nodo* arbol): _arbol(arbol)
{

}

int Ancestro::encontrarAncestro(int a, int b)
{
	std::vector<int> camino1, camino2;
	if (!encontrarCamino(_arbol, camino1, a) || !encontrarCamino(_arbol, camino2, b)) {
		
	}
}

bool Ancestro::encontrarCamino(Nodo* nodo, std::vector<int>& camino, int a) {

	if (nodo == nullptr) {

		return false;
	}
	camino.push_back(nodo->verDato());
	if (nodo->verDato() == a) {
		return true;
	}
	if (encontrarCamino(nodo->verIzq(), camino, a) ||
		encontrarCamino(nodo->verDer(), camino, a)) {
		return true;
	}
	camino.pop_back();
	return false;
	
}