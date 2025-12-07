
#pragma once


/*The hard-coded grid
  1 = open, 0 = wall
  Another notable construction requirement is that we
  _have_ to have at least 2 long 'hallways' between turns
  otherwise straight line compression fails catastrophically
  E.g diagonal zigzags are not allowed, below will not work
  1,1,1,0,0
  0,0,1,1,1
*/

constexpr int grid[7][11] = {
    //  0,1,2,3,4,5,6,7,8,9,
    {1,1,1,1,1,1,1,1,1,1,1},//0
    {0,0,1,0,0,0,0,0,1,0,0},//1
    {0,0,1,0,1,1,1,0,1,1,1},//2
    {0,0,1,0,0,0,1,0,1,0,1},//3
    {0,0,1,1,0,1,1,1,1,0,1},//4
    {0,0,1,0,0,0,0,0,1,0,1},//5
    {0,0,1,0,0,0,0,0,1,0,1},//6
};