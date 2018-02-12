#include <stdio.h>

int answer = 0;
int k = 0;
int s = 0;
int ngcd = 0;
int gcd[50][50];

//using Euclid's algoritm to calculate greatest common divisors
int calc_gcd(int a , int b) {
  if(b == 0){
    return a;
  }
  a = a % b;
  return calc_gcd(b,a);
}

//generate a matrix of gcds to make quick analysis further on
void gcd_matrix() {
  for(int i = 1; i <= s; i++){
    for(int j = i; j <= s; j++){
      //since gcd(a,b) = gcd(b,a) we use the same operation for both
      gcd[i][j] = gcd[j][i] = calc_gcd(i, j);
    }
  }
}

void tmutarakan(int current, int cgcd, int count) {
  //if a set of K numbers is found add to the answer
  if(k == count) {
    answer++;
    return;
  }

  for(int i = current+1; i <= s; i++) {
    //for the first iteration when count would be 0
    if(count == 0){
      ngcd = i;
    } else {
      //get the gcd of the set
      ngcd = gcd[i][cgcd];
    }
    //to avoid having sets with a gcd of 1
    if(ngcd == 1){
      continue;
    } else {
      //iteration of the function tmutarakan(j, gcd(gcd,j), k+1)
      tmutarakan(i, ngcd, count+1);
    }
  }
}

int main() {
  printf("Write the values of K and S\n");
  //get the values of K & S
  scanf("%d%d", &k, &s);
  //generate matrics of gcds
  gcd_matrix();
  //start the function iteration
  tmutarakan(1, 1, 0);
  //new student number can't exceed 10000
  if (answer >= 10000) {
    printf("The maximal possible number of new students is: 10000");
  } else {
    printf("The maximal possible number of new students is:\n%d\n", answer);
  }
  return 0;
}
