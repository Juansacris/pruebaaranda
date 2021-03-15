# Prueba Aranda 
## Juan Esteban Sacristan

Prueba postulación cargo desarrollador C++.

Se realiza la implementacion de un API REST exponiendo dos endpoints uno para crear un arbol binario y otro para consultar el ancestro comun entre dos nodos 
del arbol. Para el desarrollo de la solucion se requiere usar una base de datos en sqlite3 y para montar el servidor REST se requiere la libreria cpprestsdk.
Para probar el funcionamiento del API se requiere el uso de postman, esto para enviar las peticiones POST para enviar a la base los valores del arbol y GET para 
solitar el ancestro comun entre los dos nodos. 

## Instalar vcpkg

Se requiere instalar vcpkg [GitHub](https://github.com/microsoft/vcpkg.git), una vez instalado el vcpk 
Se corre el siguiente comando para buscar la libreria que se requiere instalar 

*.\vcpkg search cpprestsdk


El power shell devuelve la libreria que se esta consultado, una vez aparezca la libreria se corre el siguiente comandoo:

*.\vcpkg install cpprestsdk
Una vez el proceso de instalacion termine se puede entrar a Visual Studio e incluir la libreria. 

## Descripcion
### POST 

Para entregar el arbol al servidor de implementa el metodo POST, por que se requiere entregar un recurso el arbol, en este caso se debe enviar la peticion POST 
usando postman, de la siguiente manera. 

POST http://localhost:8080/arboles
Se debe construir un JSON con los valores del arbol. 
{
    "dato":[xx,xx,xx,.....]
}
** "xx" los valores de cada nodo del arbol **
*El programa puede recibir un arbol de cualquier tamaño. internamente lo organiza colocando la raiz del arbol como el primer valor ingresado, el resto de los nodos se crean 
siguiendo el orden si el valor es mayor a la raiz se organiza a la izquierda, y si es menor lo organiza a la derecha* 

En la URL se debe especificar que se va almacenar un arbol esto se realiza mediante la ultima parte de la URL (/arboles), Una vez el arbol quede almacenado el servidor contesta
con un numero de identificacion del arbol en este caso seria el id 1. Los id van incrementando de a uno. 

###GET.

Para recibir el ancestro comun se implementa el metodo GET ya que se quiere retornar un dato que es el dato del ancestro comun entre los dos nosdos del arbol. 
Usando Postam se realiza la siguiente peticion 

GET  http://localhost:8080/arboles/1/ancestro 
haciendo un JSON de la  siguiente manera:
{
    "nodo1": xx,
    "nodo2": xx
}
** "xx" son los valores de los nodos que se requieran validar**

Una vez se envie esta peticion el servidor contesta otro JSON de la siguiente manera
{
    "Ancestro": xx
}
** "xx" el ancestro entre los dos nodos pedidos. 

Se debe tener encuenta que para la consulta como se requiere consultar un arbol en la URL se debe especificar /arboles..  el siguiente espacio es para poner el id del arbol a consultar,  
/id... y por ultimo se debe especificar lo que requerimos que en este desarrollo es consultar el ancestro y se espicifica asi /ancestro.   con esto formamo la URL para la peticion http://localhost:8080/arboles/1/ancestro 

El programa esta diseñado para que el usuario escriba la url tal cual como se especifica anteriormente, si el usuario no lo escribe de esa manera el servidor contestara un error. 

