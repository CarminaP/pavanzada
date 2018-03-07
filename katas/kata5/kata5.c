#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // tolower()
#include "hash.h"

//for an easier to understand syntax
#define bool int
#define true 1
#define false 0

unsigned hash2(void *key, unsigned size){
  unsigned char *str = (char *)key;
    unsigned hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; // hash * 33 + c

    return hash % size;
}

int cmpKeys(void *e1, void *e2){
  return strcmp((char *)e1, (char *)e2);
}

void * copy(void *element){
  char *realValue = (char *) element;
  return (void *)strdup(realValue);
}

bool isletter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool ispunctuation(int c) {
  //{. : ! ?}
    return ((c == '.')||(c == ':')||(c == '!')||(c == '?'));
}

char * getword(char * line){
    int size = 0;
    char *c;
    for (c = size; isletter(*c); ++c){
        ++size;
    }
    char *word = malloc(sizeof(char) * (size+1));
    for (int i = 0; i < size; ++i){
        word[i] = tolower(line[i]);
    }
    word[size] = '\0';
    return word;
}

static int wordcloud(char *text){
  Hash myHash;
  unsigned size = 55; //El string que se usa es de 52 palabras
  char key[100];
  char value[100];
  initHash(&myHash,size,hash2,cmpKeys, copy, copy);
  char *c;
  for (c = text; *c != '\0'; ++c) {
    if (isletter(*c)){
        char *word = getword(c);
        int result = (int)getHash(&myHash, word);
        if (result == NULL){
          insertHash(&myHash, (void *)word,(void *)1);
        } else {
          updateHash(&myHash, word, (void *)result++);
          free(word);
        }

        while (isletter(*c)){
            ++c;
          }
      }
    }
    unsigned pos = myHash.hash(key,myHash.size);
    for(int i = 0; i < myHash.data[pos].count; i++){
      char *word = (char *)myHash.copyKey(myHash.data[pos].elements[i].key);
      int value = (int)myHash.copyValue(myHash.data[pos].elements[i].value);
      printf("%s = %d\n", word, value);
    }
  }

int main(){
  char test[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu.";
  wordcloud(test);
  return 0;
}
