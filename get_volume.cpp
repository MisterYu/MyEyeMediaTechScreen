#include <iostream>
#include <string>
#include <cstdlib>
#include "bottles_solver.h"
#include "arg_check.h"

int main(int argc, char *argv[])
{
    int vol0, vol1, desired_volume;
    if (argc != 4)
    {
        std::cerr << argc << " - incorrect number of args\n";
        std::cerr << "usage: get_volume <bottle1 volume> <bottle2 volume> <desired volume>\n";
    }
    else
    {
        // check argument values
        vol0 = arg_check(argv[1]).get_value();
        vol1 = arg_check(argv[2]).get_value();
        desired_volume = arg_check(argv[3]).get_value();

        // set then kick off solver
        Bottles_Solver solver(vol0, vol1, desired_volume);
        solver.solve();
    }

    return 0;
}
