#include <iostream>
#include "bottles_solver.h"

/*
 * input:
 * vol0 = one volume for a bottle
 * vol1 = one volume for other bottle
 * vol2 = desired volume to be derived from mixing 2 bottles
 */
Bottles_Solver::Bottles_Solver(int vol0, int vol1, int vol2) {
    desired_volume = vol2;
    ready_to_go = false;
    // check for bad initial conditions
    bool bottles_not_same = vol0 != vol1;
    bool both_bottles_even = vol0 % 2 == 0 && vol1 % 2 == 0;
    bool desire_odd = vol2 % 2 == 1;
    bool desire_less_than_bottles = vol2 < vol0 && vol2 < vol1;
    bool all_gt0 = vol0 > 0 && vol1 > 0 && desired_volume > 0;

    // if initial conditions valid, set bottles volumes accordingly
    if (bottles_not_same
            && !(both_bottles_even && desire_odd)
            && desire_less_than_bottles
            && all_gt0) {
        if (vol0 > vol1)
        {
            large_bottle = Bottle(vol0);
            small_bottle = Bottle(vol1);
        }
        else
        {
            small_bottle = Bottle(vol1);
            large_bottle = Bottle(vol0);
        }
        ready_to_go = true;
    }
}

/*
 * go thru steps to desired volume in either bottle
 * repeating steps
 * 0 fill large bottle
 * 1 pour large bottle into small bottle
 * 2 dump small bottle
 * 3 pour large bottle into small bottle
 * go back to 0
 * outputs steps of process to terminal
 */
void Bottles_Solver::solve() {
    int step = 0;
    while ((large_bottle.volume() != desired_volume && small_bottle.volume() != desired_volume) && ready_to_go)
    {
        switch (step % 4)
        {
            case 0:
                large_bottle.fill();
                break;
            case 1:
            case 3:
                large_bottle.set(small_bottle.add(large_bottle));
                break;
            case 2:
                small_bottle.dump();
                break;
        }
        std::cout << large_bottle.volume() << " " << small_bottle.volume() << std::endl;
        step++;
    }
}
