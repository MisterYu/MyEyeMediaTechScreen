/*
 * ArgCheck.h
 *
 *  Created on: Jul 14, 2017
 *      Author: lyu
 */

#ifndef ARG_CHECK_H_
#define ARG_CHECK_H_
#include <string>

class arg_check {
private:
    int value;
    bool is_all_ints(std::string);
public:
	arg_check(char *);
    int get_value() { return value; }
};

#endif /* ARG_CHECK_H_ */
