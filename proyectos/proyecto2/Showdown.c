#include <stdio.h>
#include <string.h> //memcmp & memcpy
#include <stdbool.h> //bool
#include <stdlib.h> //malloc & free

static void lineup(int n, int r, int p, int s);

int main() {
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++) {
		int n, r, p, s;
		scanf("%d %d %d %d", &n, &r, &p, &s);
		printf("Case #%d: ", i);
		lineup(n, r, p, s);
		printf("\n");
	}
	return 0;
}

// function to check there is enough players of each preference in a lineup to have a valid showdown
static bool valid(int n, char* str, int r, int p, int s) {
  // (1 << n) is a bit shift operation used to get the number of players according to the number of rounds (2^n)
	for(int i = 0; i < (1 << n); i++) {
		switch(str[i]) {
		case 'R': r--; break;
		case 'P': p--; break;
		case 'S': s--; break;
		}
	}
	return r == 0 && p == 0 && s == 0;
}

static void lineup(int n, int r, int p, int s){
  //pointers for blocks of memory for P R & S and their lineups
	char* currp;
	char* currr;
	char* currs;

	char* nextp;
	char* nextr;
	char* nexts;

  //buffer
	char* buf;

	buf = (char*)malloc(4);
	buf[0] = 'P';
	buf[1] = 'R';
	buf[2] = 'S';

	currp = &buf[0];
	currr = &buf[1];
	currs = &buf[2];

  //Testing for each round
	for(int i = 0; i < n; i++) {
    //To store the building lineups, each with 2 players
		char* nextbuf = (char*)malloc((6 << i) + 1);
		nextp = &nextbuf[0];
		nextr = &nextbuf[2 << i];
		nexts = &nextbuf[4 << i];

		int test;

    /*
    BASE TEST CASES FOR EACH ROUND
    PR (P), PS (S), RS (R)
    */

    // For nextP when Paper would win (PR)
		test = memcmp(currp, currr, 1 << i);
		if(test < 0) {
			memcpy(&nextp[0], currp, 1 << i);
			memcpy(&nextp[1 << i], currr, 1 << i);
		} else {
			memcpy(&nextp[0], currr, 1 << i);
			memcpy(&nextp[1 << i], currp, 1 << i);
		}

    // For nextS when Scissor would win (PS)
		test = memcmp(currp, currs, 1 << i);
		if(test < 0) {
			memcpy(&nexts[0], currp, 1 << i);
			memcpy(&nexts[1 << i], currs, 1 << i);
		} else {
			memcpy(&nexts[0], currs, 1 << i);
			memcpy(&nexts[1 << i], currp, 1 << i);
		}

    // For nextR when Rock would win (RS)
    test = memcmp(currr, currs, 1 << i);
    if(test < 0) {
      memcpy(&nextr[0], currr, 1 << i);
      memcpy(&nextr[1 << i], currs, 1 << i);
    } else {
      memcpy(&nextr[0], currs, 1 << i);
      memcpy(&nextr[1 << i], currr, 1 << i);
    }

    //Add the new lineups
		currp = nextp;
		currr = nextr;
		currs = nexts;

    //free memory space to store the built lineup
		free(buf);
		buf = nextbuf;
	}

  //booleans for valid lineups
	bool pvalid = valid(n, currp, r, p, s);
	bool rvalid = valid(n, currr, r, p, s);
	bool svalid = valid(n, currs, r, p, s);

  //tests for overall showdown between lineups
	int showdown_pr = memcmp(currp, currr, 1 << n);
	int showdown_rs = memcmp(currr, currs, 1 << n);
	int showdown_ps = memcmp(currp, currs, 1 << n);

  //if currp is not a valid lineup it affects PR & PS lineups
	if(!pvalid) {
		showdown_pr = -1;
		showdown_ps = -1;
	}

  //if currr is not a valid lineup it affects PR & RS lineups
	if(!rvalid) {
		showdown_pr = 1;
		showdown_rs = -1;
	}

  //if currs is not a valid lineup it affects RS & PS lineups
	if(!svalid) {
		showdown_rs = 1;
		showdown_ps = 1;
	}

  //if currP is a valid lineup, and on the showdowns P is winner (no ties), return currP
	if(pvalid && showdown_pr >= 0 && showdown_ps >= 0) {
		currp[1 << n] = '\0';
		printf("%s", currp);
		return;
	}

  //if currR is a valid lineup, and on the showdowns R is winner (no ties), return currR
	if(rvalid && showdown_pr <= 0 && showdown_rs >= 0) {
		currr[1 << n] = '\0';
		printf("%s", currr);
		return;
	}

  //if currS is a valid lineup, and on the showdowns S is winner (no ties), return currS
	if(svalid && showdown_ps <= 0 && showdown_rs <= 0) {
		currs[1 << n] = '\0';
		printf("%s", currs);
		return;
	}

  //if none of the cases applies, a tie is unavoidable
	printf("IMPOSSIBLE");
}
