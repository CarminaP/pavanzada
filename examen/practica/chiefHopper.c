#include <stdio.h>
#include <stdlib.h>


/*
    case 1 - lose: h > e new energy ne = e - (h-e) = 2e - h
    case 2 - gain: h < e new energy ne = e + (e-h) = 2e - h
    in both cases: new energy ne on reaching height h is 2e - h hence e = (ne+h)/2
    We want the energy after the last jump (n) to be 0, we start from there and traverse backwards:
    e(n-1) = ( e(n) + h(n-1) ) / 2 ... ... until e(0)
    Complexity of O(n)
*/


int chiefHopper(int n, int* h) {
    int ne = 0;
    for(int i = n-1; i >= 0; i--){
        ne = (ne + h[i] + 1) / 2;
    }
    return ne;
}

int main() {
    int n;
    scanf("%i", &n);
    int *buildings = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
       scanf("%i",&buildings[i]);
    }
    int result = chiefHopper(n, buildings);
    printf("%d\n", result);
    return 0;
}
