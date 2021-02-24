#ifndef MRAND_H_
#define MRAND_H_

#include <stdlib.h>
#include <stddef.h>
#include <time.h>

void mrand_rand64_init(void);
unsigned long long mrand_rand64(void);
void mrand_rand64_fini(void);

#endif