
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

constexpr int grid[7][13] = {
    //  0,1,2,3,4,5,6,7,8,9,
    {1,1,1,1,1,1,1,1,1,1,1,1,1},//0
    {0,1,0,0,0,0,0,0,0,1,0,0,0},//1
    {0,1,0,0,1,1,1,1,0,1,1,1,0},//2
    {0,1,0,0,0,0,0,1,0,1,0,1,0},//3
    {0,1,1,1,1,1,1,1,1,1,0,1,0},//4
    {0,1,0,0,0,0,0,0,0,1,0,1,0},//5
    {0,1,0,0,0,0,0,0,0,1,0,1,0},//6
};