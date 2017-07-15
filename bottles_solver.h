#ifndef BOTTLES_SOLVER_H
#define BOTTLES_SOLVER_H

#include "bottle.h"

class Bottles_Solver {
    private:
        Bottle large_bottle;
        Bottle small_bottle;
        int desired_volume;
        bool ready_to_go;
    public:
        Bottles_Solver(int, int, int);
        void solve();
};

#endif
