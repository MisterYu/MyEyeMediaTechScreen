#include "bottle.h"


Bottle::Bottle() {
    max_volume = 0;
    current_volume = 0;
}

Bottle::Bottle(int max) {
    max_volume = max > 0 ? max : 0;
    current_volume = 0;
}


int Bottle::add(Bottle other_bottle)
{
    int added_volume = other_bottle.current_volume;
    int total_volume = current_volume + added_volume;
    current_volume = total_volume > max_volume ? max_volume : total_volume;
    int extra_volume = total_volume > max_volume ? total_volume - max_volume : 0;
    return extra_volume;
}
