#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

bool writebytes(unsigned long long x, int nbytes);
void printBytes(long long* nbytes, int wordsize, int output_errno, unsigned long long x);

#endif
