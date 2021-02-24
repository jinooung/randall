#include "rand64-mrand.h"

/* Initialize the mrand rand64 implementation.  */
void mrand_rand64_init(void)
{
    srand48(time(NULL));
}

/* Return a random value, using mrand operations.  */
unsigned long long mrand_rand64(void)
{
    unsigned long long int x;
    x = mrand48();
    return x;
}

/* Finalize the mrand rand64 implementation.  */
void mrand_rand64_fini(void)
{

}