/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment010.c
 Submission Date : 18-11-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>
#include <stdlib.h>

// Function for Bubble Sort
void Bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function forInsertion Sort
void Insertion_Sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0....i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function for Selection Sort
void Selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to Merge two halves of an array
void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function for Merge Sort
void Merge_Sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);

        // Merging the sorted halves
        Merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate sorting algorithms
int main()
{
    printf("\nAVAILABLE FUNCTIONS :-\n"
           "\t(1) Using Bubble Sort.\n"
           "\t(2) Using Insertion Sort.\n"
           "\t(3) Using Selection Sort.\n"
           "\t(4) Using Merge Sort.\n"
           "\t(5) Exit the program.\n");

    while (1)
    {
        int N;
        printf("\nEnter the number of elements in the array : ");
        scanf("%d", &N);

        int arr[N];
        printf("Enter %d numbers for the array which is to be sorted :\n", N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        int n = sizeof(arr) / sizeof(arr[0]);

        int choice;
        printf("\nEnter your choice of function : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            Bubble_Sort(arr, n);
            printf("Sorted array using Bubble Sort:\n");
            printArray(arr, n);
        }

        else if (choice == 2)
        {
            Insertion_Sort(arr, n);
            printf("Sorted array using Insertion Sort:\n");
            printArray(arr, n);
        }

        else if (choice == 3)
        {
            Selection_Sort(arr, n);
            printf("Sorted array using Selection Sort:\n");
            printArray(arr, n);
        }
        else if (choice == 4)
        {
            Merge_Sort(arr, 0, n - 1);
            printf("Sorted array using Merge Sort:\n");
            printArray(arr, n);
        }

        else
        {
            printf("\nExitting the program....");
            break;
        }
    }
    return 0;
}
