#include <iostream>
#include "bottles_solver.h"


Bottles_Solver::Bottles_Solver(int vol0, int vol1, int volume) {
    std::cout << vol0 << " " << vol1 << " " << volume << std::endl;
    desired_volume = volume;
    ready_to_go = false;
    bool bottles_not_same = vol0 != vol1;
    bool both_bottles_even = vol0 % 2 == 0 && vol1 % 2 == 0;
    bool desire_odd = volume % 2 == 1;
    bool desire_less_than_bottles = volume < vol0 && volume < vol1;
    bool all_gt0 = vol0 > 0 && vol1 > 0 && desired_volume > 0;
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

void Bottles_Solver::solve() {
    int step = 0;
    while ((large_bottle.volume() != desired_volume && small_bottle.volume() != desired_volume) && step < 10 && ready_to_go)
    {
        switch (step % 4)
        {
            case 0:
                large_bottle.fill();
                break;
            case 1:
            case 3:
                large_bottle.leftover(small_bottle.add(large_bottle));
                break;
            case 2:
                small_bottle.dump();
                break;
        }
        std::cout << large_bottle.volume() << " " << small_bottle.volume() << std::endl;
        step++;
    }
}
