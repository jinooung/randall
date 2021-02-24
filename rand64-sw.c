#include "rand64-sw.h"

/* Software implementation.  */

void getFile(char* file)
{
    input = file;
}

/* Initialize the software rand64 implementation.  */
void software_rand64_init(void)
{
    urandstream = fopen(input, "r");
    if (!urandstream)
    {
        printf("No file found \n");
        abort();
    }
}

/* Return a random value, using software operations.  */
unsigned long long software_rand64(void)
{
    unsigned long long int x;
    if (fread(&x, sizeof x, 1, urandstream) != 1)
        abort();
    return x;
}

/* Finalize the software rand64 implementation.  */
void software_rand64_fini(void)
{
    fclose(urandstream);
}

