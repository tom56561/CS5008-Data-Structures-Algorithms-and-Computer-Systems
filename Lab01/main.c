// Your name: Po-Shen
// Date
//
// Add your program here!
// 

#include <math.h>
#include <stdio.h>

double power(double base, double n) {
    return pow(base, n);
}

int main() {
    for (double i = 1; i <= 10; i++) {
        printf("power(2, %f) = %f\n" , i, power(2, i));
    }
    return 0;
}

