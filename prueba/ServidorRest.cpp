#include "ServidorRest.h"
#include "ArbolBD.h"
#include "Ancestro.h"

// url:puerto/arbol/2/ancentro
void ServidorRest::handleGet(http_request mensaje)
{
	auto rutas = http::uri::split_path(http::uri::decode(mensaje.relative_uri().path()));
	if (rutas.empty())
	{
		mensaje.reply(status_codes::BadRequest, U("No se especifico recurso"));
		return;
	}
	if (rutas[0] == U("arboles"))
	{

		utility::stringstream_t ss(rutas[1]);
		unsigned long long id;
		ss >> id;

		Nodo* arbol = _bd.consultar(id);


		if (rutas[2] == U("ancestro"))
		{
			Ancestro ancestro(arbol);
			auto valores = mensaje.extract_json().get();
			int nodo1 = valores[U("nodo1")].as_integer();
			int nodo2 = valores[U("nodo2")].as_integer();

			std::optional<int> ancestroComun = ancestro.encontrarAncestro(nodo1, nodo2);
			if (ancestroComun)
			{
				json::value respuesta;
				respuesta[U("Ancestro")] = ancestroComun.value();
				mensaje.reply(status_codes::OK, respuesta);
			}
		}
		else
		{
			mensaje.reply(status_codes::NotFound, U("No se encuentra el nodo"));
		}

	}

	mensaje.reply(status_codes::NotFound, U("No se encuentra la url"));
}

void ServidorRest::handlePost(http_request mensaje)
{
	auto rutas = http::uri::split_path(http::uri::decode(mensaje.relative_uri().path()));
	if (rutas.empty())
	{
		mensaje.reply(status_codes::BadRequest, U("No se especifico recurso"));
		return;
	}
	if (rutas[0] == U("arboles")) 
	{
		auto valores = mensaje.extract_json().get();
		json::array dato = valores[U("dato")].as_array();
		std::vector<int> datos;
		datos.reserve(dato.size());
		for (auto& valor : dato) {
			datos.push_back(valor.as_integer());
		}
		unsigned long long id =_bd.guardarDatos(datos);
		json::value respuesta;
		respuesta[U("id")] = id;
		mensaje.reply(status_codes::OK, respuesta);

	}

}


ServidorRest::ServidorRest(const utility::string_t& url, const ArbolBD& archivo) :_listener(url), _bd(archivo)
{
	
	_listener.support(methods::POST, [this](http_request mensaje) {handlePost(mensaje); });
	_listener.support(methods::GET, [this](http_request mensaje) {handleGet(mensaje); });
		

}
