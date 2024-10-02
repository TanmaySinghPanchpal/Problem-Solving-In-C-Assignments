/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment002.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>

// Q1 i. Function to calculate the minimum element of the array
int Min_element(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

// Q1 ii. Function to calculate the maximum element of the array
int Max_element(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Q1 iii. Function to find the minimum and maximum elements in the array
void MinandMax_element(int arr[], int size, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}

// Q1 iv. Function to calculate the mean of the array
double Mean_element(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

// Q1 v. Function to calculate the variance of the numbers of an array
double Variance(int arr[], int size)
{
    double mean = Mean_element(arr, size);
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += (arr[i] - mean) * (arr[i] - mean); // To calculate the squared difference from the mean
    }
    return sum / (size - 1);
}

// Q1 vi. Function to calculate the sum of the squares of the numbers in the array
double Sum_of_Squares(int arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        // printf("%d\n",arr[i]*arr[i]);
        sum += arr[i] * arr[i];
    }
    return sum;
}

// Q1 vii. Function to calculate the harmonic mean of the numbers in an array
double Harmonic_mean(int arr[], int size)
{
    double sum = 0.0;
    // calculate the sum of reciprocals (1/A)
    for (int i = 0; i < size; i++)
    {
        sum += 1.0 / arr[i]; // Adding the reciprocal of each number to the sum
    }

    double harmonic_mean = size / sum;
    return harmonic_mean;
}

// Q2 i. Function to compute the sum of the first N terms of series 1 : s = 1 + 2 + 3 + ...
int series1(int N)
{
    return N * (N + 1) / 2;
}

// Q2 ii. Function to compute the sum of the first N terms of series 2 : s = 1 + 3 + 5 + ...
int series2(int N)
{
    return N * N;
}

// Q2 iii. Function to compute the sum of the first N terms of series 3 : s = 2 + 4 + 6 + ...
int series3(int N)
{
    return N * (2 * N + 2) / 2;
}

// Q2 iv. Function to compute the sum of the first N terms of series 4 : s = 1/1 + 1/2 + 1/3 + ...
double series4(int N)
{
    double sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += (1.0 / i); // Using 1.0 instead of 1 to avoid integer division
    }
    return sum;
}

// Q3 Function to compute the sum of the first N terms of sequence : 1, 2, 4, 8, 16, ...
void Sequence(int N)
{
    int term = 1;
    printf("The sequence is : ");
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", term);
        printf(",");
        term *= 2;
    }
}

// Q4 Function to compute the series s = 1 - 3 + 5 - 7 + 9 - ...
int Alternating_series(int N) {
    int sum = 0;
    int term = 1;
    int sign = 1; // alternating sign

    for (int i = 1; i <= N; i++) {
        sum += sign * term;
        term += 2; // Incrementing the term by 2
        sign *= -1; // Alternating the sign
    }

    return sum;
}


int main()
{
    int N = 10; // N = 10 is given in the question
    int arr[N];
    printf("Enter %d numbers for the array :\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nAVAILABLE FUNCTIONS :-\n"
           "\t(1) Find the minimum element.\n"
           "\t(2) Find the maximum element.\n"
           "\t(3) Find the minimum element and the maximum element in pass over the array.\n"
           "\t(4) Find the mean of the array.\n"
           "\t(5) Find the variance of the numbers in the array.\n"
           "\t(6) Find the sum of the squares of the numbers in the array.\n"
           "\t(7) Find the harmonic mean of the numbers in the array.\n"
           "\t(8) Sum s = 1 + 2 + 3 + ...\n"
           "\t(9) Sum s = 1 + 3 + 5 + ...\n"
           "\t(10) Sum s = 2 + 4 + 6 + ...\n"
           "\t(11) Sum s = 1/1 + 1/2 + 1/3 + ...\n"
           "\t(12) Compute the first N terms of the sequence : 1,2,4,8,16, ...\n"
           "\t(13) Compute the series s = 1 - 3 + 5 - 7 + 9 - ...\n"
           "\t(14) Exit the program.\n");

    while (1)
    {
        int choice;
        printf("\nEnter your choice of function : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int min_1 = Min_element(arr, N);
            printf("\n\tMinimum element in the array: %d\n", min_1);
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");
        }

        else if (choice == 2)
        {
            int max_2 = Max_element(arr, N);
            printf("\n\tMaximum element in the array: %d\n", max_2);
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");

        }

        else if (choice == 3)
        {

            int min_3, max_3;
            MinandMax_element(arr, N, &min_3, &max_3);
            printf("\n\tMinimum element in the array: %d\n", min_3);
            printf("\tMaximum element in the array: %d\n", max_3);
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");

        }

        else if (choice == 4)
        {

            double mean = Mean_element(arr, N);
            printf("\n\tMean of the array: %.3f\n", mean); // Mean upto 3 decimal spaces
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");

        }

        else if (choice == 5)
        {
            double variance = Variance(arr, N);
            printf("\n\tVariance of the numbers in the array : %.3f\n", variance); // Variance upto 3 decimal spaces
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");

        }

        else if (choice == 6)
        {
            double sum_6 = Sum_of_Squares(arr, N);
            printf("\n\tSum of the squares of the numbers in the array : %.3f\n", sum_6); // Sum of squares upto 3 decimal spaces
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");
    
        }

        else if (choice == 7)
        {
            double harmonic_mean = Harmonic_mean(arr, N);
            printf("\n\tThe harmonic mean of the numbers in the array is : %.3f\n", harmonic_mean); // Harmonic mean upto 3 decimal spaces
            printf("\tThe time complexity of the developed algorithm is : O(n)\n");

        }

        else if (choice == 8)
        {
            int N_terms; // Number of terms
            printf("\nEnter the number of terms for the series : ");
            scanf("%d", &N_terms);
            int sum_1 = series1(N_terms);
            printf("\tThe sum of the first %d terms is : %d", N_terms, sum_1);
        }

        else if (choice == 9)
        {
            int N_terms; // Number of terms
            printf("\nEnter the number of terms for the series : ");
            scanf("%d", &N_terms);
            int sum_2 = series2(N_terms);
            printf("\tThe sum of the first %d terms is : %d", N_terms, sum_2);
        }

        else if (choice == 10)
        {
            int N_terms; // Number of terms
            printf("\nEnter the number of terms for the series : ");
            scanf("%d", &N_terms);
            int sum_3 = series3(N_terms);
            printf("\tThe sum of the first %d terms is : %d", N_terms, sum_3);
        }

        else if (choice == 11)
        {
            int N_terms; // Number of terms
            printf("\nEnter the number of terms for the series : ");
            scanf("%d", &N_terms);
            double sum_4 = series4(N);
            printf("\tThe sum of the first %.4d terms is : %.3f", N, sum_4); // Sum upto 3 decimal places
        }

        else if (choice == 12)
        {
            int N_terms; // Number of terms
            printf("\nEnter the number of terms for the sequence : ");
            scanf("\t%d", &N_terms);
            Sequence(N);
        }

        else if (choice == 13)
        {
            int N_terms, sum; // Number of terms,sum
            printf("Enter the number of terms : ");
            scanf("\t%d", &N_terms);
            sum = Alternating_series(N);
            printf("\tSum of the series upto %d terms = %d\n", N_terms, sum);
        }

        else
        {
            printf("\nExitting the program....");
            break;
        }
    }

    return 0;
}