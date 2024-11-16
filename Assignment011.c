#include <stdio.h>
#include <stdlib.h>

// Function to perform vector addition
void Vector_Addition(int A[], int B[], int C[], int N)
{
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i]; // Sum corresponding elements
    }
}

// Function to print an array
void Print_Array(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform vector addition
void Vector_Addition_Inputs()
{
    int N;
    printf("\nEnter the number of elements for the arrays (A , B , C) : ");
    scanf("%d", &N);
    if (N <= 0)
    {
        printf("Please enter a positive integer for the number of elements.\n");
        return; // Exit the function if input is invalid
    }

    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));

    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed!\n");
        return; // Exit the function if memory allocation fails
    }

    printf("\nArray A :\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nArray B :\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }

    // Perform vector addition
    Vector_Addition(A, B, C, N);
    printf("\nResult of vector addition :\n");
    Print_Array(C, N);

    free(A);
    free(B);
    free(C);
}

// Main function to demonstrate vector addition
int main()
{
    printf("\nAVAILABLE FUNCTIONS :-\n"
           "\t(1) Using Vector Addition.\n"
           "\t(2) Using Insertion Sort.\n"
           "\t(3) Using Selection Sort.\n"
           "\t(4) Using Merge Sort.\n"
           "\t(5) Exit the program.\n");

    while (1)
    {
        int choice;
        printf("\nEnter your choice of function : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            Vector_Addition_Inputs(); // Call the vector addition function
        }
        else if (choice == 2)
        {
            // Placeholder for Insertion Sort functionality
        }
        else if (choice == 3)
        {
            // Placeholder for Selection Sort functionality
        }
        else if (choice == 4)
        {
            // Placeholder for Merge Sort functionality
        }
        else
        {
            printf("\nExiting the program.\n");
            break;
        }
    }
    return 0;
}