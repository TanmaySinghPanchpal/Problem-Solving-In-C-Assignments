/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment003.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>

// 1. Function to find a factorial of a number
// using iteration
int Factorial_iterative(int N)
{
    int result = 1;
    for (int i = 1; i <= N; i++)
    {
        result *= i;
    }
    return result;
}

// 2. Function to find a factorial of a number
// using recursion
int Factorial_recursive(int N)
{
    if (N == 0)
    {
        return 1;
    }
    else
    {
        return N * Factorial_recursive(N - 1);
    }
}

// 3. Function to calculate 1/N!
double One_over_factorial(int N)
{
    return (1 / (double)Factorial_iterative(N));
}

// 4. Function to calculate x^N/N!
double Xn_over_factorial(int x, int N)
{
    double result, xn = 1.0;
    for (int i = 0; i < N; i++)
    {
        xn *= x;
    }
    result = xn / Factorial_iterative(N);
    return result;
}

int Is_factorial(int M)
{
    int i = 1;
    int factorial = 1;
    while (factorial <= M)
    {
        if (factorial == M)
        {
            return 1; // M is a factorial number
        }
        i++;
        factorial *= i;
    }
    return 0; // M is not a factorial number
}

double Binomial_coefficient(int n, int r)
{
    if (r > n)
    {
        printf("\nError : Since R cannot be greater than N");
        return -1.0;
    }
    double result = Factorial_iterative(n) / (Factorial_iterative(r) * Factorial_iterative(n - r));
    return result;
}

int main()
{
    int N, x, M, n, r;
    printf("Enter the number (N) to calculate the factorial : ");
    scanf("%d", &N);
    printf("Enter a number (M, N > M) : ");
    scanf("%d", &M);
    printf("\nFactorial of %d using iterative method : %d", N, Factorial_iterative(N));
    printf("\nFactorial of %d using recursive method : %d", N, Factorial_recursive(N));
    printf("\nOne over factorial of %d is : %f\n", N, One_over_factorial(N));

    printf("\nEnter the base number x to calculate x^N/N! : ");
    scanf("%d", &x);

    printf("\nX^%d over factorial of %.3f is : %f", N, (double)N, Xn_over_factorial(x, N));
    if (Is_factorial(M))
    {
        printf("\n%d is a factorial number\n", M);
    }
    else
    {
        printf("\n%d is not a factorial number\n", M);
    }

    printf("\nEnter the value of n : ");
    scanf("%d", &n);
    printf("Enter the value of r : ");
    scanf("%d", &r);

    double result = Binomial_coefficient(n, r);
    if (result != -1.0)
    {
        printf("\nThe binomial coefficient %dC%d is : %.2f\n", n, r, result);
    }
    return 0;
}
