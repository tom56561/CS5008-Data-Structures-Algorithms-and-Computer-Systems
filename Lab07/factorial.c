// Your Name Here
// Date
//
// gcc -Wall factorial.c -o factorial
// ./factorial

#include <stdio.h>

int factorial(int n){
  // TODO: Implement iterative solution here
  int i;
  int sum = 1;
  for (i = 1; i <= n; i++){
    sum *= i;
  }

  return sum;
};

int factorial_rec(int n){
  // TODO: Implement recursive solution here
  if(n == 1 || n == 0){
    return 1;
  }
  return n * factorial_rec(n-1);
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));


  return 0;
}
