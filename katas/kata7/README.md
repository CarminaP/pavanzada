# Shadows of the Knight - Episode 1
[LINK] (https://www.codingame.com/training/medium/shadows-of-the-knight-episode-1)

##The Goal

Batman will look for the hostages on a given building by jumping from one window to another using his grapnel gun. Batman's goal is to jump to the window where the hostages are located in order to disarm the bombs. Unfortunately he has a limited number of jumps before the bombs go off...

##Rules

Before each jump, the heat-signature device will provide Batman with the direction of the bombs based on Batman current position:

* U (Up)
* UR (Up-Right)
* R (Right)
* DR (Down-Right)
* D (Down)
* DL (Down-Left)
* L (Left)
* UL (Up-Left)

Your mission is to program the device so that **it indicates the location of the next window Batman should jump to** in order to reach the bombs' room **as soon as possible**.

Buildings are represented as a rectangular array of windows, the window in the **top left corner of the building is at index (0,0)**.


## Breakdown
Basing ourselves with the Bisection Method we can adjust the variables to find the correct coordinates, that would mean that to adjust we would use x = (x0 + x1)/2 and y = (y0 + y1)/2. If the bomb direction has to go up, we need to actualize y1 to be 1 cell less than the actual y, if batman has to go down, we actualize y0 to be 1 cell more than the actual y.
If the bomb direction has to go left, we need to actualize x1 to be 1 cell less than the actual x, if batman has to go right, we actualize x0 to be 1 cell more than the actual x.
