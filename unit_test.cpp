#include <vector>
#include <iostream>
#include <cstdio>
#include "arg_check.h"
#include "bottle.h"

int main()
{
    // unit tests for test_arg class
    std::vector<char*> arg_check_in = {"-1", "1.3", "0", "10"};
    std::vector<int> arg_check_out = {0, 0, 0, 10};
    std::cout << "arg_check unit test results:\n";
    for (int i = 0; i < arg_check_in.size(); ++i)
    {
        bool pass_fail = arg_check(arg_check_in[i]).get_value() == arg_check_out[i];
        std::printf("test %d: %s\n", i, pass_fail ? "pass" : "fail");
    }

    // unit tests for bottle class
    // max test
    std::vector<int> bottle_max_in = {0, -1, 1};
    std::vector<int> bottle_max_out = {0, 0, 1};
    std::cout << "bottle init test results:\n";
    for (int i = 0; i < bottle_max_in.size(); ++i)
    {
        bool pass_fail = Bottle(bottle_max_in[i]).max() == bottle_max_out[i];
        std::printf("test %d: %s\n", i, pass_fail ? "pass" : "fail");
    }
    // add test
    std::vector<Bottle> bottle_add_in0 = {Bottle(1), Bottle(1), Bottle(1)};
    bottle_add_in0[2].fill();
    std::vector<Bottle> bottle_add_in1 = {Bottle(1), Bottle(2), Bottle(1)};
    for (int i = 0; i < bottle_add_in1.size(); ++i)
        bottle_add_in1[i].fill();
    std::vector<int> bottle_add_out0 = {1, 1, 1};
    std::vector<int> bottle_add_out1 = {0, 1, 1};
    std::cout << "bottle add test results:\n";
    for (int i = 0; i < bottle_add_in0.size(); ++i)
    {
        bool add_out0 = bottle_add_in0[i].add(bottle_add_in1[i]) == bottle_add_out1[i];
        bool add_out1 = bottle_add_in0[i].volume() == bottle_add_out0[i];
        bool pass_fail = add_out0 && add_out1;
        std::printf("test %d: %s\n", i, pass_fail ? "pass" : "fail");
    }
}
