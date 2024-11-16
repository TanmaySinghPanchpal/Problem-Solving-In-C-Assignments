/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment009.c
 Submission Date : 18-11-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>

// Function to perform sequendtial search
int Sequential_Search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; // Return -1 if the value is not found
}

// Function to perform binary search
int Binary_Search(int arr[], int size, int value)
{
    int begin = 0;
    int end = size - 1;
    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2; // To prevendt overflow

        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] < value)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1; // Return -1 if the value is not found
}

int main()
{
    int N;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&N);

    int arr[N];
    printf("Enter %d numbers for the array :\n", N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int value;
    printf("\nEnter the number to search in the array : ");
    scanf("%d",&value);

    int s_search = Sequential_Search(arr, size, value);
    if (s_search != -1)
    {
        printf("\nSequential Search :\nThe element %d was found at index %d\n", value, s_search);
    }
    else
    {
        printf("\nSequential Search :\nThe element %d was not found\n", value);
    }

    // Using bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int b_search = Binary_Search(arr, size, value);
    if (b_search != -1)
    {
        printf("\nBinary Search :\nThe element %d was found at index %d\n", value, b_search);
    }
    else
    {
        printf("\nBinary Search :\nThe element %d was not found\n", value);
    }

    return 0;
}
