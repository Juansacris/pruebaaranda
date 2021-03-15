#pragma once

#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/uri.h"
#include "ArbolBD.h"


using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
using namespace web::http::experimental::listener;

class ServidorRest
{
	void handleGet(http_request message);
	void handlePost(http_request message);
	http_listener _listener;
	ArbolBD _bd;

		
public:

	ServidorRest(const utility::string_t &url, const ArbolBD &archivo);
	pplx::task<void> open() 
	{ 
		return _listener.open(); 
	}
	pplx::task<void> close() 
	{
		return _listener.close(); 
	}

};

