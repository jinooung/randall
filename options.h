#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>

struct flags
{
    bool rdrand;
    bool mrand;
    bool file;
    char* filename;
    bool stdio;
    bool n_output;
    int n;
};

bool getArguments(int argc, char** argv, long long *nbytes);
void setOptions(int argc, char** argv, struct flags *set); 

#endif