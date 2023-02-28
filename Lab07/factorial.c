// Your Name Here
// Date
//
// gcc -Wall factorial.c -o factorial
// ./factorial

#include <stdio.h>

unsigned long long int factorial(unsigned long long int n){
  // TODO: Implement iterative solution here
  unsigned long long int i;
  unsigned long long int sum = 1;
  for (i = 1; i <= n; i++){
    sum *= i;
  }

  return sum;
};

unsigned long long int factorial_rec(unsigned long long int n){
  // TODO: Implement recursive solution here
  if(n == 1 || n == 0){
    return 1;
  }
  return n * factorial_rec(n-1);
}

int main(){

  // Both of these should print the same result!
  
  printf("factorial(10) = %llu\n",factorial(10));
  printf("factorial_rec(10) = %llu\n",factorial_rec(10));


  return 0;
}
