#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

struct flags
{
    bool mrand;
    bool file;
    char* filename;
    bool n_output;
    int n;
};

bool getArguments(int argc, char** argv, long long *nbytes);
void setOptions(int argc, char** argv, struct flags *set); 

#endif