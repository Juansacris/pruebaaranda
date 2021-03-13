#include "Ancestro.h"
#include "Nodo.h"


Ancestro::Ancestro(Nodo* arbol): _arbol(arbol)
{

}

std::optional<int> Ancestro::encontrarAncestro(int a, int b)
{
	std::vector<int> camino1, camino2;
	if (!encontrarCamino(_arbol, camino1, a) || !encontrarCamino(_arbol, camino2, b)) {
		return {};
	}
	int i;
	for (i = 0; i < camino1.size() && i < camino2.size(); i++) {
		if (camino1[i] != camino2[i]) {
			break;
		}
	}
	return camino1[i - 1];
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