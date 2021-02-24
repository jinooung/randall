#ifndef RAND64_SW_H_
#define RAND64_SW_H_

#include <stdio.h>
#include <stdlib.h>

/* Input stream containing random bytes.  */
static FILE* urandstream;
static char* input;

void getFile(char* file);
void software_rand64_init();
unsigned long long software_rand64(void);
void software_rand64_fini(void);

#endif