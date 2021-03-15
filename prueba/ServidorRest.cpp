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
		if (rutas.size() == 3) {
			utility::stringstream_t ss(rutas[1]);
			unsigned long long id;
			ss >> id;
			Nodo* arbol;
			try {
				arbol = _bd.consultar(id);
			}
			catch(std::exception&exc){
				std::string error(exc.what());
				mensaje.reply(status_codes::BadRequest, utility::conversions::to_string_t(error));
				return;

			}
			if (arbol == nullptr) {
				mensaje.reply(status_codes::NotFound, U("El arbol no existe"));
				return;
			}


			if (rutas[2] == U("ancestro"))
			{
				Ancestro ancestro(arbol);
				auto valores = mensaje.extract_json().get();
				if (valores.has_integer_field(U("nodo1")) && valores.has_integer_field(U("nodo2")))
				{


					int nodo1 = valores[U("nodo1")].as_integer();
					int nodo2 = valores[U("nodo2")].as_integer();

					std::optional<int> ancestroComun = ancestro.encontrarAncestro(nodo1, nodo2);
					if (ancestroComun)
					{
						json::value respuesta;
						respuesta[U("Ancestro")] = ancestroComun.value();
						mensaje.reply(status_codes::OK, respuesta);
						return;
					}
					else
					{
						mensaje.reply(status_codes::NotFound, U("Alguno de los nodos no pertence al arbol"));
					}

				}
				else
				{
					mensaje.reply(status_codes::NotFound, U("Debe colocar los nodos a consultar"));
				}
			}
			else
			{
				mensaje.reply(status_codes::NotFound, U("No se encuentra el nodo"));
			}
		}
		else
		{
			mensaje.reply(status_codes::NotFound, U("Url Invalida"));
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
