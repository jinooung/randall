#include "options.h"

bool getArguments(int argc, char** argv, long long* nbytes)
{
    /* Check arguments.  */
    bool valid = false;
    if (argc == 2)
    {
        char* endptr;
        errno = 0;

        *nbytes = strtoll(argv[1], &endptr, 10);
        if (errno)
            perror(argv[1]);
        else
            valid = !*endptr && 0 <= *nbytes;
    }
    if (!valid)
    {
        fprintf(stderr, "%s: usage: %s NBYTES\n", argv[0], argv[0]);
        return true;
    }

    /* If there's no work to do, don't worry about which library to use.  */
    if (*nbytes == 0)
    {
        return false;
    }

    return true;
}
