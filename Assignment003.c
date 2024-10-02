/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment003.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>

// Function to find a factorial of a number 
// using iteration
int Factorial_iterative(int N) {
    int result = 1;
    for (int i = 1; i <= N; i++) {
        result *= i;
    }
    return result;
}

// Function to find a factorial of a number 
// using recursion
int Factorial_recursive(int N) {
    if (N == 0) {
        return 1;
    } else {
        return N * Factorial_recursive(N-1);
    }
}

// Function to calculate 1/N!
int One_over_factorial(int N){
    return 1 / Factorial_iterative(N);
}

// Function to calculate x^N/N!
int Xn_over_factorial(int N){
    int xn = 0.0, x = 0.0;
    printf("\nEnter a floating point number : ");
    scanf("%f",&x);
    for (int i = 0; i < N; i++)
    {
        xn += x*x;
    }
    int  result = xn / Factorial_iterative(N);
    return result;
}


int main(){
    int N;
    printf("Enter the number to  calculate the factorial : ");
    scanf("%d",&N);
    printf("\nFactorial of %d using iterative method : %d", N, Factorial_iterative(N));
    printf("\nFactorial of %d using recursive method : %d", N, Factorial_recursive(N));
    printf("\nOne over factorial of %d is : %d\n", N, Factorial_recursive(N));
    printf("\nX^N over factorial of %d is : %f", N, Xn_over_factorial(N));
    return 0;
}