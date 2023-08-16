#include <stdio.h>

float fastInverseSqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;

    // Using bitwise operations to manipulate the floating-point bits
    i = *(long*)&y;           // Interpret y as an integer (bit manipulation)
    i = 0x5f3759df - (i >> 1); // Magic number

    y = *(float*)&i; // Interpret back as a float
    y = y * (threehalfs - (x2 * y * y)); // Newton-Raphson iteration

    return y;
}

int main() {
    float num = 25.0;
    float inv_sqrt = fastInverseSqrt(num);
    
    printf("Inverse square root of %.2f is %.5f\n", num, inv_sqrt);
    return 0;
}