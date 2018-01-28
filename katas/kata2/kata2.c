#include <stdio.h>
#include <string.h>

int strongPasswordChecker(char *s) {
  int size = strlen(s);
  int repeatChar = 0, countChar = 0, haveLower = 0, haveUpper = 0, haveDigit = 0, changes = 0;
  char prevChar = (char) 0, nextChar;
  for (int i = 0; i < size; i++) {
    //Para revisar caracteres que se repiten
    nextChar = s[i];
    if(nextChar == prevChar){
      countChar++;
    } else {
      countChar = 0;
    }
    if(countChar >= 2){
      repeatChar++;
    }
    prevChar = s[i];

    //Para revisar si es minuscula
    if(islower(s[i])){
      haveLower++;
    }

    //Para revisar si es mayuscula
    if(isupper(s[i])){
      haveUpper++;
    }

    //Para revisar si tiene digito
    if(isdigit(s[i])){
      haveDigit++;
    }
  }
  //contar los cambios necesarios
  changes = repeatChar;
  if(haveLower == 0){
    changes++;
  }
  if(haveUpper == 0){
    changes++;
  }
  if(haveDigit == 0){
    changes++;
  }
  //Si la contraseña cumple con los criterios regresar 0
  if(changes == 0 && size >= 6 && size <= 20){
    return 0;
  }
  //Si no, revisar casos segun tamaño de contraseña, si faltan o sobran caracteres aun con los cambios
  if(size < 6){
    //En el caso de que aun con cambios sigue teniendo menos de 6 caracteres es necesario contar el numero de caracteres a agregar
    if(size+changes < 6){
      return ((-1)*((size+changes)-6)) + changes;
    } else {
      return changes;
    }
  }
  if(size > 20){
    //En el caso de que aun con cambios sigue teniendo más de 20 caracteres es necesario contar el numero de caracteres a borrar
    if(size-changes > 20){
      return ((size-changes)-20) + changes;
    } else {
      return changes;
    }
  }
  //Si la contraseña se encuentra en el intervalo de tamaño, solo regresar el numero de cambios
  return changes;
}

// funciones para detectar si es minuscula, mayuscula o digito
int islower(int c) {
    return ((c >= 'a' && c <= 'z')); }

int isupper(int c) {
        return ((c >= 'A' && c <= 'Z')); }

int isdigit(int c) {
        return (c >= '0' && c <= '9'); }

int main(){
  char a[] = "Con7raseña";
  printf("Minimum change(s) needed: %i\n", strongPasswordChecker(a));
}
