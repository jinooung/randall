#include "output.h"

static bool writebytes(unsigned long long x, int nbytes)
{
    do
    {
        if (putchar(x) < 0)
            return false;
        x >>= CHAR_BIT;
        nbytes--;
    } 
    while (0 < nbytes);

    return true;
}

void printBytes(long long *nbytes, int wordsize, int output_errno, unsigned long long x)
{
    while (0 < *nbytes)
    {
        int outbytes = *nbytes < wordsize ? *nbytes : wordsize;
        if (!writebytes(x, outbytes))
        {
            output_errno = errno;
            break;
        }
        *nbytes -= outbytes;
    }
}

void print_n(char* arr, int* total, int buffer, int index, unsigned long long x, int nbytes) 
{
    if (*total + buffer > nbytes)
    {
        buffer = nbytes - *total;
    }

    while (x > 0 && index < buffer)
    {
        arr[index] = x;
        x >>= 1;

        if (*total + index < nbytes)
        {
            index++;
        }
    }

    if (index == buffer)
    {
        write(1, arr, buffer);
        *total += index;
    }
}