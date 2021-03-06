#ifndef RAND64_HW_H_
#define RAND64_HW_H_

#include <cpuid.h>
#include <immintrin.h>

/* Description of the current CPU.  */
static struct cpuid { unsigned eax, ebx, ecx, edx; };

static struct cpuid cpuid(unsigned int leaf, unsigned int subleaf);
_Bool rdrand_supported(void);
void hardware_rand64_init(void);
unsigned long long hardware_rand64(void);
void hardware_rand64_fini(void);

#endif
