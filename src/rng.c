#include "rng.h"
#include <stdint.h>
#include <windows.h>






static inline uint32_t xorshift32(uint32_t* state) {
    uint32_t x = state[0];
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state[0] = x;
    return x;
}

uint32_t GenRanNum(uint32_t seed) {
    uint32_t state[1];
    state[0] = seed; 
    uint32_t random_number = xorshift32(state);

    return random_number;
}

uint32_t GenRanNumRange(uint32_t seed, uint32_t min, uint32_t max) {
    uint32_t state[1];
    state[0] = seed; 
    uint32_t random_number = xorshift32(state);

    return (random_number % (max - min + 1)) + min;
}

long long GetMS() {
    LARGE_INTEGER frequency, counter;
    QueryPerformanceFrequency(&frequency); 
    QueryPerformanceCounter(&counter);     
    return (counter.QuadPart * 100000000) / frequency.QuadPart; 
}