# Prueba Aranda 
## Juan Esteban Sacristan

Prueba postulación cargo desarrollador C++.

Para realizar la implementación de un API REST es necesario exponer dos endpoints, el primero de ellos para crear un árbol binario y el restante para consultar el ancestro común entre dos nodos 
del árbol. Para el desarrollo de la solución se requiere utilizar una base de datos en sqlite3, para subir el servidor REST se realiza por medio de la librería cpprestsdk.
El funcionamiento del API se verificara a partir del uso de Postman o cualquier herramienta o librería para hacer peticiones REST, con el fin de remitir las peticiones POST para enviar a la base los valores del arbol y GET con el objeto de 
solitar el ancestro común entre los dos nodos. 

## Instalar vcpkg

Para instalar el vcpkg: [GitHub](https://github.com/microsoft/vcpkg.git), una vez instalado el vcpkg se corre el siguiente comando para buscar la librería que se requiera instalar 

```
* .\vcpkg search cpprestsdk
```

El power shell devuelve la librería consultada, una vez aparezca la librería se corre el siguiente comando:
```
* .\vcpkg install cpprestsdk
```
Para integrar la librería a Visual Studio se corre el siguiente comando:
```
* .\vcpkg integrate
```
Cuando finalice el proceso de instalacion es posible ingresar a Visual Studio e incluir la librería. 

## Descripcion
### POST 

Para entregar el árbol al servidor es necesario implemetar el método POST, debido a que se requiere que el servidor reciba los recursos del árbol, en este caso se debe enviar la petición POST 
de la siguiente manera: 

POST http://localhost:8080/arboles
Posteriormente, se debe construir un JSON con los valores del árbol. 
```
{
    "dato":[xx,xx,xx,.....]
}
```
**"xx" Los valores de cada nodo del árbol**
*El programa puede recibir un árbol de cualquier tamaño. Su funcionamiento se da internamente, organizando la raiz del árbol como el primer valor ingresado, los nodos restantes se crean 
siguiendo el orden: si el valor es mayor a la raiz se organiza a la izquierda, y si es menor lo organiza a la derecha.* 

En la URL se debe especificar que se va almacenar un árbol esto se realiza mediante la última parte de la URL (/arboles), Una vez el árbol quede almacenado el servidor, este responde
con un número de identificación para el árbol, para este caso coresponde al id 1. Es importnte mencionar que los id van incrementando de acuerdo a l cantidad de peticiondes para crear árboles.

### GET.

Para recibir el ancestro común es necesario implementar el método GET debido a que se quiere retornar un dato que corresponde al ancestro común entre los dos nodos del árbol. 
Se realiza la siguiente petición: 

GET  http://localhost:8080/arboles/1/ancestro 
Haciendo un JSON de la  siguiente manera:
```
{
    "nodo1": xx,
    "nodo2": xx
}
```
**"xx" son los valores de los nodos que se requieran validar**

Una vez se envíe esta petición el servidor responde otro JSON de la siguiente manera:
```
{
    "Ancestro": xx
}
```
**"xx" el ancestro entre los dos nodos pedidos.** 

Se debe tener en cuenta que para consultar un arbol se debe especificar en la URL /arboles...  El siguiente espacio en la URL es utilizado para ingresar el id del árbol a consultar, 
/id... Finalmente, se debe especificar lo que se requiere para la consulta del ancestro del siguiente modo: /ancestro. Con esto se construye la URL para la petición http://localhost:8080/arboles/1/ancestro 

El programa está diseñado para que el usuario escriba la URL, como se expone anteriormente, si el usuario no lo escribe de esa forma el servidor mostrara un mensaje de error. 

