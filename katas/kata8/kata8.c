#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);
        int thrust;
        int boost = 0;

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        fprintf(stderr, "Distance: %d\n", nextCheckpointDist);
        if(nextCheckpointAngle > 70 || nextCheckpointAngle < -70){
            thrust = 2;
        } else {
         thrust = 100;
         if(nextCheckpointDist >= 10000 && boost == 0){
           boost = 1;
           }
        }

       if(boost == 1){
           printf("%d %d %s\n", nextCheckpointX, nextCheckpointY, "BOOST");
           boost = 2;
       } else {
           printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
       }
        //printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
    }

    return 0;
}
