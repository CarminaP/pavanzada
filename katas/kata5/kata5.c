#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // tolower()
#include <stdbool.h>
#include "hash.h"

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
    for (c = line; isletter(*c); ++c){
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
  HashInt myHash;
  hashInit(&myHash, 55);//El string que se usa es de 52 palabras
  char *c;
  for (c = text; *c != '\0'; ++c) {
    if(ispunctuation(*c)){
      ++c;
      continue;
    }
    if (isletter(*c)){
        char *word = getword(c);
        int *result = hashGet(&myHash, word);
        if (result == NULL){
          hashInsert(&myHash, word, 1);
        } else {
          hashInsert(&myHash, word, *result++);
          free(word);
        }

        while (isletter(*c)){
            ++c;
          }
        }
      }
      for (int i = 0; i < myHash.size; ++i)
      {
        for (int j = 0; j < myHash.data[i].length; ++j)
        {
          char *word = myHash.data[i].elements[j].key;
          int value = myHash.data[i].elements[j].value;
          if(word != NULL){
            printf("%s = %d\n", word, value);
          }
        }
      }
      /*
    unsigned pos = myHash.hash(key,myHash.size);
    for(int i = 0; i < myHash.data[pos].count; i++){
      char *word = (char *)myHash.copyKey(myHash.data[pos].elements[i].key);
      int value = (int)myHash.copyValue(myHash.data[pos].elements[i].value);
      printf("%s = %d\n", word, value);
    }
    */
  }

int main(){
  char test[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu.";
  wordcloud(test);
  return 0;
}
