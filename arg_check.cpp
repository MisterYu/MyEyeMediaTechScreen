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
    // default retrieved value to 0
    value = 0;
    // convert to string
    std::string s = argv;
    // check if all char in string are ints
    bool is_ints = is_all_ints(s);
    if (is_ints)
    {
        // convert to int and reassign if > 0
        int temp = std::atoi(s.c_str());
        value = temp > 0 ? temp : 0;
    }
}

bool arg_check::is_all_ints(std::string s)
{
    // check for anything other than integer
    bool all_int_chars = (s.find_first_not_of( "0123456789" ) == string::npos);
    return all_int_chars;
}

