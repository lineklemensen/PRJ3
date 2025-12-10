# Software implementation



## calc_route()
To begin with I keep track of where the car currently is, where the next point is, and where the car last were. Then I can get the three sides for a triangle using the code below, for each side. 
```cpp
std::pair<double, double> last_pos_vector = {
        current_pos.first - last_pos.first, current_pos.second - last_pos.second
};
```

I'm doing this so that I'm able to use pythagoras theorem to calculate each side of the triangle. Doing this I can find the angle bewteen the last point and the current, and the current and the next point. I can then take the angle, and check if the car would go against the unit circle in relation to which way the car is facing.  
```cpp
if(current_pos.first < next_pos.first &&  
last_pos.first < next_pos.first && last_pos.second < next_pos.second) {
        cos_angle = cos_angle * -1;
} 
```
The code above, is then used three more times to handle the three other directions. It then returns an angle and length, that can be used as parameters for another function that makes driving instructions.