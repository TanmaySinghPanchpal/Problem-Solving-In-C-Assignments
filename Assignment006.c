/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment006.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>
#include <string.h>

// 1. Function to convert a positive integral number (as a string)
//    to an integral data type.
int string_to_positive_int(char *str)
{
    int num = 0;
    int i = 0;

    // Iterating through the string from left to right
    while (str[i] != '\0')
    {
        // Convert each character to its respective integer value
        num = (num * 10 + (str[i] - '0')); // Since the ASCII value of '0' = 48 , and then it further increses for each digit
        i++;
    }
    return num;
}

// 2. Function to handle strings represented negative integral number
int string_to_any_int(char *str)
{
    int num = 0;
    int i = 0;
    int is_negative = 0; // To check if the number is negative

    if (str[0] == '-')
    {
        is_negative = 1;
        i++; // Skipping the index number with the minus sign
    }

    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    // If the number is negative, multiply it by (-1)
    if (is_negative)
    {
        num = (-1) * num;
    }

    return num;
}

int main()
{

    printf("\nAVAILABLE FUNCTIONS :-\n"
           "\t(1) String to positive integer.\n"
           "\t(2) String to any integer.\n"
           "\t(3) Exit the program.\n");

    while (1)
    {
        int choice;
        printf("\nEnter your choice of function : ");
        scanf("%d", &choice);
        getchar(); // It is used to consume the newline character made by scanf()

        if (choice == 1)
        {
            char str[100]; // Character array to store the input string
            printf("Enter a positive integer : ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = 0; // Remove the newline character

            int num = string_to_positive_int(str);
            if (num != -1)
            {
                printf("Converted integer value : %d\n", num);
            }
        }

        else if (choice == 2)
        {
            char str[100]; // Character array to store the input string
            printf("Enter any integer : ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = 0; // Remove the newline character

            int num = string_to_any_int(str);
            printf("Converted integer value : %d\n", num);
        }

        else
        {
            printf("\nExitting the program....");
            break;
        }
    }

    return 0;
}