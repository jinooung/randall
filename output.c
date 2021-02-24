#include "output.h"

bool writebytes(unsigned long long x, int nbytes)
{
    do
    {
        if (putchar(x) < 0)
            return false;
        x >>= CHAR_BIT;
        nbytes--;
    } while (0 < nbytes);

    return true;
}


void printBytes(long long *nbytes, int wordsize, int output_errno, unsigned long long x)
{
    do 
    {
        int outbytes = *nbytes < wordsize ? *nbytes : wordsize;
        if (!writebytes(x, outbytes))
        {
            output_errno = errno;
            break;
        }
        *nbytes -= outbytes;
    } while (0 < *nbytes);
}