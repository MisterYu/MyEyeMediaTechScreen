/*
 * ArgCheck.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: lyu
 */

#include <string>
#include <cstdlib>
#include "arg_check.h"

using std::string;

arg_check::arg_check(char *argv) {
    // TODO Add comments
    value = 0;
    std::string s = argv;
    bool is_pos = is_pos_int(s);
    if (is_pos)
    {
        int temp = std::atoi(s.c_str());
        value = temp > 0 ? temp : 0;
    }
}

bool arg_check::is_pos_int(std::string s)
{
    bool check_says = (s.find_first_not_of( "0123456789" ) == string::npos);
    return check_says;
}

