#ifndef RNG_H_INCLUDED
#define RNG_H_INCLUDED




#include <stdint.h>




uint32_t GenRanNum(uint32_t seed);
uint32_t GenRanNumRange(uint32_t seed, uint32_t min, uint32_t max);
long long GetMS();
#endif