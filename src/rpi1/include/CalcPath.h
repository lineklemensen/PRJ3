#ifndef CALC_PATH_H
#define CALC_PATH_H

#include <iostream>
#include "Point.h"

class DR{
    public:
    std::pair <double, double> current_pos = {0, 0};
    std::pair <double, double> last_pos = {current_pos.first, current_pos.second};
    

    DR(){};
    std::pair <double, double> calc_route(std::pair <double, double> next_pos);

    
 



};


#endif