#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

//BRUTE FORCE APPROACH
static int brutesolution(int flight_length, int movie_lengths[]) {
  int arrsize = sizeof(movie_lengths)/sizeof(int);
  for (int i = 0; i < arrsize; i++) {
  	int first_movie = movie_lengths[i];
    for (int j = 1; j < arrsize; j++) {
      //not to choose the same movie twice
      if(j == i) {
        continue;
      }
      //if we find a matching second movie
    	if (first_movie + movie_lengths[j] == flight_length) {
          return 1;
      }
    }
  }
  return 0;
}

//HASH MAP APPROACH
static int hashsolution(int flight_length, int movie_lengths[]) {
  int arrsize = sizeof(movie_lengths)/sizeof(int);

  HashInt myHash;
  hashInit(&myHash, arrsize);

  for (int i = 0; i < arrsize; i++) {
    hashInsert(&myHash, movie_lengths[i], "movie"+i);
  }

  for (int i = 0; i < arrsize; i++) {
    int first_movie = movie_lengths[i];
    int second_movie = hashGet(&myHash, flight_length-first_movie);;
    if (second_movie != NULL && strcmp(hashGet(&myHash, first_movie),second_movie) == 0) {
      return 1;
    } else {
      return 0;
    }
  }
}

int main() {
  int flight_length = 240;
  int movie_lengths[] = {90, 160, 70, 210, 80, 60, 190};
  int result;

  result = brutesolution(flight_length,movie_lengths);
  printf("Brute force result: %s \n", result ? "true" : "false");

  result = hashsolution(flight_length,movie_lengths);
  printf("Hash map result: %s \n", result ? "true" : "false");

  return 0;
}
