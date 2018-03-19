#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X;
    int Y;
    scanf("%d%d", &X, &Y);

    int X0 = X;
    int Y0 = Y;
    int X1 = W;
    int Y1 = H;
    int prevY = 0;
    int Yrepeated = 0;
    int maxturn = N;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "bombDir: %s \n", bombDir);
        fprintf(stderr, "Batman position (%d,%d)\n", X, Y);
        fprintf(stderr, "X0 Y0 (%d,%d)\n", X0, Y0);
        fprintf(stderr, "X1 Y1 (%d,%d)\n", X1, Y1);
        fprintf(stderr, "strstr(bombDir, U) = %s\n", strstr(bombDir, "U"));
        fprintf(stderr, "strstr(bombDir, D) = %s\n", strstr(bombDir, "D"));
        fprintf(stderr, "strstr(bombDir, L) = %s\n", strstr(bombDir, "L"));
        fprintf(stderr, "strstr(bombDir, R) = %s\n", strstr(bombDir, "R"));

       /* This was for Evasive but it didn't work
       if (maxturn < 8){
            Y1 = H/2;
            Y = 0;
            Y0 = 0;
            maxturn = 8;
        }
        */
        if(strstr(bombDir, "U") != NULL){
            fprintf(stderr, " U worked\n");
            Y1 = Y - 1;
        }else if (strstr(bombDir, "D") != NULL){
            fprintf(stderr, " D worked\n");
            Y0 = Y + 1;
        }

        if(strstr(bombDir, "L") != NULL){
            fprintf(stderr, " L worked\n");
            X1 = X - 1;
        } else if (strstr(bombDir, "R") != NULL){
            fprintf(stderr, " R worked\n");
            X0 = X + 1;
        }

        fprintf(stderr, "X0 Y0 (%d,%d)\n", X0, Y0);
        fprintf(stderr, "X1 Y1 (%d,%d)\n", X1, Y1);
        fprintf(stderr, "prevY %d\n", prevY);

        X = (X0 + X1) / 2;
        Y = (Y0 + Y1) / 2;

        if(Yrepeated == 2){
            Y1 = Y;
            Y = 0;
            Y0 = 0;
            Yrepeated++;
        } else if (Yrepeated > 5){
         Yrepeated = 0;
        }

        if(prevY == Y){
         Yrepeated++;
        }

        prevY = Y;
        // the location of the next window Batman should jump to.
        printf("%d %d\n", X, Y);
    }

    return 0;
}
