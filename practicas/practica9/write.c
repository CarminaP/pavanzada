#include <stdio.h>

typedef struct s {
  char firstName[20];
  char lastName[20];
  short Id;
  char semester[3];
} Student;

int main(){
  char *dbName = "student.dat";
  Student pAvanzada[10];

  for(int i= 0; i < 10; i++) {
    sprintf(pAvanzada[i].firstName, "name%i", i);
    sprintf(pAvanzada[i].lastName, "lastname%i", i);
    pAvanzada[i].Id = i;
    sprintf(pAvanzada[i].semester, "S%i", 8);
  }
  FILE *data = fopen(dbName, "wb");
  //arreglo, tamaño del arreglo, numero de elementos y donde se va a guardar
  fwrite(pAvanzada, sizeof(Student), 10, data);
  fclose(data);
  return 0;
}
