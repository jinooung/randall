#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdbool.h>
#include <limits.h>
#include <errno.h>

static bool writebytes(unsigned long long x, int nbytes);
void printBytes(long long* nbytes, int wordsize, int output_errno, unsigned long long x);
void print_n(char* arr, int* total, int buffer, int index, unsigned long long x, int nbytes);

#endif
