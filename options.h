#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

bool getArguments(int argc, char** argv, long long *nbytes);

#endif