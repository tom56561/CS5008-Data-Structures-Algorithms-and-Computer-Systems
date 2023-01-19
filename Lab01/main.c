// Your name: Po-Shen Lee (Eddie)
// Date: 01/19/2023
//
// Add your program here!
// 

#include <math.h>
#include <stdio.h>

double power(double base, double n) {
    double res = base;
    for (int i = 1; i < n; i++){
        res *= base;
    }
    return res;
}

int main() {
    for (double i = 1; i <= 10; i++) {
        printf("power(2, %f) = %f\n" , i, power(2, i));
    }
    return 0;
}

