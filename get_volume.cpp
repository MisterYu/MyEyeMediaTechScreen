#include <iostream>
#include <string>
#include <cstdlib>
#include "bottle.h"
#include "bottles_solver.h"

int main(int argc, char *argv[])
{
    int vol0, vol1, desired_volume;
    Bottle big_bottle, small_bottle;
    if (argc != 4)
    {
        std::cerr << argc << " incorrect number of args\n";
    }
    else
    {
        vol0 = atoi(argv[1]);
        vol1 = atoi(argv[2]);
        desired_volume = atoi(argv[3]);
        if (vol0 > vol1)
        {
            big_bottle = vol0;
            small_bottle = vol1;
        }
        else
        {
            big_bottle = vol1;
            small_bottle = vol0;
        }

        Bottles_Solver solver(vol0, vol1, desired_volume);
        solver.solve();
    }

    return 0;
}
