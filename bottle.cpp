#include "bottle.h"


Bottle::Bottle() {
    max_volume = 0;
    current_volume = 0;
}

/*
 * constructor with user defined max volume
 * input:
 * max = capacity of bottle
 */
Bottle::Bottle(int max) {
    max_volume = max > 0 ? max : 0;
    current_volume = 0;
}

/*
 * add another bottle to current bottle
 * input:
 * other_bottle
 * output:
 * volume fluid leftover source bottle
 */
int Bottle::add(Bottle other_bottle)
{
    int added_volume = other_bottle.current_volume;
    int total_volume = current_volume + added_volume;
    // make sure max volume not exceeded
    current_volume = total_volume > max_volume ? max_volume : total_volume;
    // calculate leftover in source if anything leftover
    int extra_volume = total_volume > max_volume ? total_volume - max_volume : 0;
    return extra_volume;
}
