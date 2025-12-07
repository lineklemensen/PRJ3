#include "CalcPath.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>


// Returns two values. First is the turning angle, second is the length of the drive.
std::pair<double, double> DR::calc_route(std::pair<double, double> next_pos)
{

    // The three sides of each triangle. 
    std::pair<double, double> last_pos_vector = {current_pos.first - last_pos.first, current_pos.second - last_pos.second};
    std::pair<double, double> next_pos_vector = {next_pos.first - current_pos.first, next_pos.second - current_pos.second};
    std::pair<double, double> last_to_next = {next_pos.first - last_pos.first, next_pos.second - last_pos.second};

    // Finding the length of each side using the pythagoras theorem.
    double length_next_vector = sqrt((pow(next_pos_vector.first, 2) + pow(next_pos_vector.second, 2)));
    double length_last_vector = sqrt((pow(last_pos_vector.first, 2) + pow(last_pos_vector.second, 2)));
    double length_last_to_next = sqrt((pow(last_to_next.first, 2) + pow(last_to_next.second, 2)));

    // Calculating angle B and converting it from radians to degrees. 
    double angle = (pow(length_next_vector, 2) + pow(length_last_vector, 2) - pow(length_last_to_next, 2)) / (2 * length_last_vector * length_next_vector);
    double cos_angle = acos(angle) * (180 / M_PI);


    // Making sure the angle is negative when we go against the unit circle.
    if (current_pos.first < next_pos.first && last_pos.first < next_pos.first && last_pos.second < next_pos.second)
    {
        cos_angle = cos_angle * -1;
    }
    else if(current_pos.second > next_pos.second && last_pos.second > current_pos.second && last_pos.first < current_pos.first)
    {
        cos_angle = cos_angle * -1;
    }
    else if(current_pos.second < next_pos.second && last_pos.first > current_pos.first)
    {
        cos_angle = cos_angle * -1;
    }
    else if(current_pos.second > next_pos.second && last_pos.second > next_pos.second && last_pos.first < current_pos.first)
    {
        cos_angle = cos_angle * -1;
    }
    else if(current_pos.first > next_pos.first && last_pos.second > current_pos.second && last_pos.first > next_pos.first)
    {
        cos_angle = cos_angle * -1;
    }

    if(cos_angle == 0 || cos_angle == -0){
        cos_angle = 180;
    }

    // Set the angle to zero if our current point is home base.
    if (current_pos.first == 0 && current_pos.second == 0)
    {
        cos_angle = 0;
    }




    if (last_pos.first == next_pos.first && last_pos.second == next_pos.second)
    {
        cos_angle = 180;
    }

    last_pos.first = current_pos.first;
    last_pos.second = current_pos.second;
    current_pos.first = next_pos.first;
    current_pos.second = next_pos.second;


    double inch = 2.54;
    return {cos_angle, length_next_vector*inch};
}