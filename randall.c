/* Generate N bytes of random output.  */

/* When generating output this program uses the x86-64 RDRAND
   instruction if available to generate random numbers, falling back
   on /dev/random and stdio otherwise.

   This program is not portable.  Compile it with gcc -mrdrnd for a
   x86-64 machine.

   Copyright 2015, 2017, 2020 Paul Eggert

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "options.h"
#include "output.h"
#include "rand64-hw.h"
#include "rand64-sw.h"
#include "rand64-mrand.h"


/* Main program, which outputs N bytes of random data.  */
int main(int argc, char** argv)
{
    struct flags set;
    set.mrand = false;
    set.file = false;
    set.filename = "/dev/random";

    set.n = -1;
    set.n_output = false;

    setOptions(argc, argv, &set);

    long long nbytes = 0;

    if (!getArguments(argc, argv, &nbytes))
    {
        return 0;
    }

    void (*initialize) (void);
    unsigned long long (*rand64) (void);
    void (*finalize) (void);

    if (set.mrand)
    {
        initialize = mrand_rand64_init;
        rand64 = mrand_rand64;
        finalize = mrand_rand64_fini;
    }
    else if (set.filename && set.file == true)
    {
        getFile(set.filename);
        initialize = software_rand64_init;
        rand64 = software_rand64;
        finalize = software_rand64_fini;
    }
    else
    {
        if (rdrand_supported())
        {
            initialize = hardware_rand64_init;
            rand64 = hardware_rand64;
            finalize = hardware_rand64_fini;
        }
        else if (!rdrand_supported() && nbytes == NULL)
        {
            return 0;
        }
        else
        {
            printf("This CPU is not supported by RDRAND \n");
            printf("To use software support, please use -i /path/file \n");
            return 0;
        }
    }

    initialize();
    int wordsize = sizeof rand64();
    int output_errno = 0;

    if (set.n_output)
    {
        int total = 0;
        int buffer = set.n; 
        int index = 0;

        char* arr = malloc(sizeof(char) * (buffer));

        while (total < nbytes)
        {
            unsigned long long x = rand64();
            print_n(arr, &total, buffer, index, x, nbytes);
        }
    }
    else
    {
        do
        {
            unsigned long long x = rand64();
            printBytes(&nbytes, wordsize, output_errno, x);
        } 
        while (0 < nbytes);
    }

    if (fclose(stdout) != 0)
        output_errno = errno;

    if (output_errno)
    {
        errno = output_errno;
        perror("output");
    }

    finalize();
    return !!output_errno;
}
