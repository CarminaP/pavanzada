#include <stdio.h>
#include <string.h> //strcpy
#include <stdlib.h> //malloc

int doFullName(char *firstName,
               char *lastName,
               char **fullName)
{
  int sizeFirstName = strlen(firstName);
  int sizeLastName = strlen(lastName);
  // para calcular el tamaño es el numero de elementos por el tamaño de cada elemento
  *fullName = (char *)malloc( (sizeFirstName + sizeLastName + 1) * sizeof(char) );
  strcpy(*fullName, firstName);
  strcpy(*fullName + sizeFirstName, " ");
  strcpy(*fullName + sizeFirstName + 1, lastName);

  return 0;
}

int main(){
  char firstName[] = "Miguel"; //crea arreglo y puedo modificarlo
  char *lastName = "Palomera"; //constante
  char *fullName;

  // se usa & por que se va a modificar esa variable usando su direccion
  doFullName(firstName,lastName, &fullName);

  printf("fullName = %s \n", fullName); //%s -> string
  free(fullName);
  return 0;
}

/*RESULTADO
fullName = Miguel Palomera
*/
