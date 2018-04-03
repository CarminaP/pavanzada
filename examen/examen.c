#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Para leer la linea completa se usa fgets y se elimina el enter del final.
Para lograr poner todas las palabras en reversa, primero se invertirán las palabras individuales.
Hello world -> olleH dlrow
Despues invertimos todo el string de principio a fin y obtenemos las palabras completas pero en orden invertido.
olleH dlrow -> world Hello

La complejidad, debido a que se ejecuta cada linea a la vez y al invertirlas solo se recorre el string dos veces, es de 2n+1 que es aproximadamente O(n)

*/

// 100 palabras por 10 caracteres cada uno
#define MAX_LEN 2000

void reverse(char *begin, char *end);

void reverseLine(char *s)
{
  char *wstart = s;
  char *temp = s;

  //Invertir las palabras individuales
  while( *temp )
  {
    temp++;
    //si se llega al final de la linea
    if (*temp == '\0')
    {
      //invertir la ultima palabra
      reverse(wstart, temp-1);
    }
    //si es el final de una palabra individual
    else if(*temp == ' ')
    {
      //invertir la palabra
      reverse(wstart, temp-1);
      //empezar con la siguiente palabra
      wstart = temp+1;
    }
  }
   //Invertir el string completo de principio a fin
  reverse(s, temp-1);
}

//Esta funcion invierte cualquier string desde un apuntador de inicio a una apuntador de final
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

int main() {
	int n;
	scanf("%d",&n);

	for(int i = 1; i <= n+1; i++) {

    char buffer[MAX_LEN];

    //Se evita la primera iteracion por que fgets lee una linea de mas al inicio
    if(i == 1){
      fgets(buffer, MAX_LEN, stdin);
    }
    else {
      fgets(buffer, MAX_LEN, stdin);

      //para no copiar el enter del final
      char *nl = strchr(buffer, '\n');
      if (nl != NULL){
        *nl = '\0';
      }
      reverseLine(buffer);
  		printf("%s\n", buffer);
    }
	}
	return 0;
}
