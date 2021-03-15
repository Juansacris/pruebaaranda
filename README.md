# Prueba Aranda 
## Juan Esteban Sacristan
Prueba postulación cargo desarrollador C++.

Se realiza la implementacion de un API REST exponiendo dos endpoints uno para crear un arbol binario y otro para consultar el ancestro comun entre dos nodos 
del arbol. Para el desarrollo de la solucion se requiere usar una base de datos en sqlite3 y para montar el servidor REST se requiere la libreria cpprestsdk.
Para probar el funcionamiento del API se requiere el uso de postman, esto para enviar las peticiones POST para enviar a la base los valores del arbol y GET para 
solitar el ancestro comun entre los dos nodos. 

##Instalar vcpkg
Se requiere instalar vcpkg [GitHub](https://github.com/microsoft/vcpkg.git), una vez instalado el vcpk 
Se corre el siguiente comando para buscar la libreria que se requiere instalar 
*.\vcpkg search cpprestsdk
El power shell devuelve la libreria que se esta consultado, una vez aparezca la libreria se corre el siguiente comandoo:
*.\vcpkg install cpprestsdk
Una vez el proceso de instalacion termine se puede entrar a Visual Studio e incluir la libreria. 


