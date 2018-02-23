#include <stdio.h>
#include <string.h>

//para tener una sintaxis mas facil de entender
#define bool int
#define true 1
#define false 0

// funciones para detectar si es punto, coma, e o digito
bool ispoint(int c) {
    return ((c == '.')); }

bool iscomma(int c) {
  return ((c == ',')); }

bool ise(int c) {
        return ((c == 'e')); }

bool isdigit(int c) {
        return (c >= '0' && c <= '9'); }

//La funcion principal
int validNumber(char *s) {
  int size = strlen(s);
  //ambos count se usan para revisar las comas al final
  int countNum = 0, countComma = 0;
  // booleanos que nos ayudan en la revision
  bool hasPoint = false, hasE = false, noMoComma = false, checkNum = false;
  //loop que revisa caracter por caracter
  for (int i = 0; i < size; i++) {
    if(isdigit(s[i])){
      checkNum = true;
      //solo cuenta los numeros donde puede haber comas
      if(!noMoComma){
        countNum++;
      }
    }
      //Solo puede haber 1 solo punto, no puede estar despues de la e y no puede ir justo despues de una coma
      else if(ispoint(s[i]) && hasPoint == false && hasE == false && !iscomma(s[i-1])) {
      //un punto debe ser seguido por un numero, mientras no sea así, no es un numero
      checkNum = false;
      hasPoint = true;
      //Para que no pueda haber comas despues del punto
      noMoComma = true;
    }
    //Solo puede haber 1 sola e, no puede estar sin un numero antes y no puede ir justo despues de una coma o punto
    else if(ise(s[i]) && checkNum == true && !iscomma(s[i-1]) && !ispoint(s[i-1])){
      //una e debe ser seguida por un numero, mientras no sea así, no es un numero
      checkNum = false;
      hasE = true;
      //Para que no pueda haber comas despues de e
      noMoComma = true;
    }
    //Solo puede haber comas despues de un numero
    else if(iscomma(s[i]) && checkNum == true){
      //Si no se supone que haya comas en este punto, termina el loop y regresa false
      if(noMoComma){
        printf("%s\n","False");
        return 0;
      }
      //una coma debe ser seguida por una coma, mientras no sea así, no es numero
      checkNum = false;
      countComma++;
    }
    //Si ninguno de los casos aplican, termina el loop y regresa false
    else {
      printf("%s\n","False");
      return 0;
    }
  }

  //Para revisar si las comas son coherentes
  if(countComma > 0){
  if((countNum % 3) == 0){
    checkNum = ((countNum/3)-1 == countComma);
  } else if((countNum % 3) < 3){
    int temp = countNum - (countNum % 3);
    checkNum = ((countNum/3) == countComma);
  } else {
    checkNum = false;
  }
}
  //Regresa el booleano resultante despues de las revisiones
  if (checkNum){
    printf("%s\n", "True");
  } else {
    printf("%s\n","False");
  }
  return 0;
}

int main(){
  /*
  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
  */
  char a[] = "2e10";
  validNumber(a);
  return 0;
}
