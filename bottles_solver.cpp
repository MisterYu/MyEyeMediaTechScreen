#include <iostream>
#include "bottles_solver.h"


Bottles_Solver::Bottles_Solver(Bottle b0, Bottle b1, int volume) {
    std::cout << b0.max() << " " << b1.max() << " " << volume << std::endl;
    desired_volume = volume;
    ready_to_go = false;
    bool bottles_not_same = b0.max() != b1.max();
    bool both_bottles_even = b0.max() % 2 == 0 && b1.max() % 2 == 0;
    bool desire_odd = volume % 2 == 1;
    bool desire_less_than_bottles = volume < b0.max() && volume < b1.max();
    bool all_gt0 = b0.max() > 0 && b1.max() > 0 && desired_volume > 0;
    if (bottles_not_same
            && !(both_bottles_even && desire_odd)
            && desire_less_than_bottles
            && all_gt0) {
        if (b0.max() > b1.max())
        {
            large_bottle = b0;
            small_bottle = b1;
        }
        else
        {
            small_bottle = b0;
            large_bottle = b1;
        }
        ready_to_go = true;
    }
    std::cout << large_bottle.max() << " " << small_bottle.max() << " " << volume << std::endl;
}

Bottles_Solver::Bottles_Solver(int vol0, int vol1, int desired_volume){
    std::cout << vol0 << " " << vol1 << " " << desired_volume << std::endl;
    Bottles_Solver(Bottle(vol0), Bottle(vol1), desired_volume);
}

void Bottles_Solver::solve() {
    int step = 0;
    std::cout << large_bottle.max() << " " << small_bottle.max() << " " << desired_volume << std::endl;
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
