/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment004.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */
#include <stdio.h>

#define PI 3.14159265358979
#define ERROR_BOUND 1.0e-15
#define ABS(x) ((x) >= 0 ? (x) : -(x))

// 1. Function to calculate sin(x) using Taylor series
double sine(double x)
{
    int i = 1;      // Start with the first term (x)
    int sign = 1;   // To alternate signs
    double s = 0.0; // Sum of the series
    double t = x;   // First term (x)

    // Loop until the absolute value of the term is less than the error bound
    while (ABS(t) >= ERROR_BOUND)
    {
        s += t;
        i += 2;
        sign = -sign;
        t = t * x * x / (i * (i - 1)) * sign;
    }
    return s;
}

// 2. Function to calculate cos(x) using Taylor series
double cosine(double x)
{
    int i = 0;
    int sign = 1;
    double s = 1.0; // Sum of the series starting with 1
    double t = 1.0; // First term (1)

    while (ABS(t) >= ERROR_BOUND)
    {
        i += 2;
        sign = -sign;
        t = t * x * x / (i * (i - 1)) * sign;
        s += t;
    }
    return s;
}

// 4. Function to calculate e^x using Taylor series
double exponential(double x)
{
    double sum = 1.0;
    double term = 1.0; // First term (x^0 / 0!)
    int n = 1;         // Counter for factorial

    // Loop until the absolute value of the term is less than the error bound
    while (ABS(term) >= ERROR_BOUND)
    {
        term *= x / n;
        sum += term;
        n++;
    }
    return sum; // Return the final sum
}

// 5. Function to calculate sine hyperbolic(x)
double sin_hyperbolic(double x)
{
    double hyperbolic = (exponential(x) - exponential(-x)) / 2;
    return sine(hyperbolic);
}

// 6. Function to calculate cosine hyperbolic(x)
double cos_hyperbolic(double x)
{
    double hyperbolic = (exponential(x) + exponential(-x)) / 2;
    return cosine(hyperbolic);
}

unsigned long long factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// 8. Function to calculate the sum of factorials from 0! to N!
unsigned long long factorial_sum(int N)
{
    unsigned long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        int n = (i * (i + 1)) / 2;
        sum += factorial(n);
    }
    return sum;
}

double degree_to_radian(double degree)
{
    return (degree * (PI / 180.0));
}

int main()
{
    double degree, x, sin_x, cos_x, tan_x, cot_x, sec_x, cosec_x;
    double sinh_x, cosh_x, tanh_x, coth_x, sech_x, cosech_x;
    int N;
    unsigned long long series_sum;

    // Input validation
    printf("Enter the value of x (in degrees) = ");
    if (scanf("%lf", &degree) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    x = degree_to_radian(degree);
    printf("The value of x (in radians)  = %.6f\n", x);

    sin_x = sine(x);
    cos_x = cosine(x);

    // To prevent division by 0
    if (cos_x == 0)
    {
        printf("Cannot calculate tangent, cotangent, secant, and cosecant due to division by zero.\n");
    }

    else
    {
        tan_x = sin_x / cos_x;
        cot_x = cos_x / sin_x;
        sec_x = 1 / cos_x;
        cosec_x = 1 / sin_x;

        printf("\nsin(%f) = %f\n", x, sin_x);
        printf("cos(%f) = %f\n", x, cos_x);
        printf("tan(%f) = %f\n", x, tan_x);
        printf("cot(%f) = %f\n", x, cot_x);
        printf("sec(%f) = %f\n", x, sec_x);
        printf("cosec(%f) = %f\n", x, cosec_x);

        double exp = exponential(x);
        printf("\ne^(%.2f) = %.6f\n", x, exp);

        sinh_x = sin_hyperbolic(x);
        cosh_x = cos_hyperbolic(x);
        tanh_x = sinh_x / cosh_x;
        coth_x = cosh_x / sinh_x;
        sech_x = 1 / cosh_x;
        cosech_x = 1 / sinh_x;

        printf("\nsinh(%f) = %f\n", x, sinh_x);
        printf("cosh(%f) = %f\n", x, cosh_x);
        printf("tanh(%f) = %f\n", x, tanh_x);
        printf("coth(%f) = %f\n", x, coth_x);
        printf("sech(%f) = %f\n", x, sech_x);
        printf("cosech(%f) = %f\n", x, cosech_x);

        printf("\nEnter the number of terms for the series\n0! + 1! + 3! + 6! + ... + N! : ");
        scanf("%d", &N);
        if (N > 0)
        {
            series_sum = factorial_sum(N);
            printf("\nThe sum of the series (0! + 1! + 3! + ... + N!) =  %llu\n", series_sum);
        }

        else
        {
            printf("Invalid number! Please enter a positive integer.\n");
        }
    }

    return 0;
}
