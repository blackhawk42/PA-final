# PA-final
Programación Avanzada - Proyecto Final

# Generador de hashes

Por el momento, el programa debe hacer lo siguiente:

1. Tomar de la linea de comandos un archivo de texto, que contendrá
una lista de palabras ("contraseñas") a ser procesadas.

2. Computar el PBKDF2_HMAC_SHA1 de cada contraseña.

3. Escribir los hashes en la salida estandar, conforme estén listos.

## Librerías necesarias

* OpenSSL: Para hashes y operaciones criptográficas
* OpenMP: Para multiprocesamiento.

# Links útiles

Leer un archivo línea por línea:
* https://people.cs.uchicago.edu/~dmfranklin/tutorials/fgets.txt
* https://www.daniweb.com/programming/software-development/code/216411/reading-a-file-line-by-line

Usar OpenSSL para sacar el PBKDF2:
* https://www.openssl.org/docs/man1.1.0/man3/PKCS5_PBKDF2_HMAC.html

Trabajador-Consumidor en OpenMP:
* http://sybrandt.com/post/producer-consumer-openmp-cpp/

Simple hash con OpenSSL:
* https://stackoverflow.com/questions/17456343/encrypting-sha512-example-in-c

Instalar OpenSSL en Linux:
* http://theshybulb.com/2015/10/10/use-openssl-c-library.html
