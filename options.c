#include "options.h"

void setOptions(int argc, char** argv, struct flags *set)
{
    int option = 0;
    char *input = NULL;

    while ((option = getopt(argc, argv, "i:o:")) != -1)
    {
        switch (option)
        {
            case 'i':
            {
                input = optarg;

                if (0 == strcmp(input, "rdrand"))
                {
                    set->rdrand = true;
                    break;
                }

                if (0 == strcmp(input, "mrand48_r"))
                {
                    set->mrand = true;
                    break;
                }

                if (input[0] == '/')
                {
                    set->file = true;
                    set->filename = input;
                    break;
                }
            }

            case 'o':
            {
                if (optarg == "stdio")
                {
                    // output to stdio
                }
            }

            default:
            {
                exit(1);
            }
        }
    }
}

bool getArguments(int argc, char** argv, long long *nbytes)
{
    bool valid = false;
    if (argv[optind] != NULL)
    {
        /* Check arguments.  */
        char* endptr;
        errno = 0;

        *nbytes = strtoll(argv[optind], &endptr, 10);
        if (errno)
            perror(argv[optind]);
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