/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment005.c
 Submission Date : 27-09-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>
#include <string.h> 
// Function to count the number of digits of a positive integer
int Digits_counter(int n)
{
    int counter = 0;
    while (n > 0)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}

// Function to produce the sum of digits of a positive integer
int Sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n = n / 10;
    }
    return sum;
}

// Function to convert a set of 'N' digits into a single decimal integer
int Digits_into_integer(int digits[], int N)
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result = result * 10 + digits[i];
    }
    return result;
}

// Function to convert a positive integer into its reverse order
int Reverse_integer(int n)
{
    int reverse = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }
    return reverse;
}

// Functions to convert a positive & negative integer
// (as a character string) into its equivalent decimal form
int String_to_decimal(char str[])
{
    int sign = 1;
    int decimal = 0;
    if (str[0] == '-')
    {
        sign = -1;
        str++; // To skip the sign '-' character from str
    }
    for (str; *str != '\0'; str++)
    {
        int digit = *str - '0';
        decimal = decimal * 10 + digit;
    }
    return sign * decimal;
}

// Function to convert a positive number in decimal radix
// and convert it into a positive base B number
// char* Decimal_to_baseB(int n, int B) {
//     char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     char result[64] = ""; // assume max 64 characters needed
//     while (n > 0) {
//         int digit = n % B;
//         if (B > 10) {
//             result[0] = digits[digit];
//         } else {
//             result[0] = '0' + digit;
//         }
//         strcat(result, &result[0]);
//         n = n / B;
//     }
//     return strdup(result); // Return a dynamically allocated copy of the result string
// }

int main()
{
    int num;
    printf("\nAVAILABLE FUNCTIONS :-\n"
            "\t(1) Digit counter \n"
            "\t(2) Sum of digits\n"
            "\t(3) Convert a set of 'N' digits into a number\n"
            "\t(4) Convert a positive integer and reverses the order of its digits\n"
            "\t(5) Convert a positive or negative integer as a character string into its equivalent decimal form\n"
            "\t(6) Convert a positive number in decimal radix and converts it into a positive base B\n"
            "\t(7) Exit the program.\n");

    while (1)
    {
        int choice;
        printf("\nEnter your choice of function : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter a positive integer : ");
            scanf("%d", &num);
            int digit_count = Digits_counter(num);
            printf("The number of digits in %d is : %d\n", num, digit_count);
        }

        else if (choice == 2)
        {
            printf("\nEnter a positive integer : ");
            scanf("%d", &num);
            int digit_sum = Sum_of_digits(num);
            printf("The sum of digits in %d is : %d\n", num, digit_sum);
        }

        else if (choice == 3)
        {
            printf("\nEnter a positive integer : ");
            scanf("%d", &num);

            int N;
            printf("Enter the number of digits : ");
            scanf("%d", &N);

            int digits[N];
            printf("Enter the %d digits :\n", N);
            for (int i = 0; i < N; i++)
            {
                scanf("%d", &digits[i]);
            }

            int number = Digits_into_integer(digits, N);
            printf("The number formed by the digits is : %d\n", number);
        }

        else if (choice == 4)
        {
            printf("\nEnter a positive integer : ");
            scanf("%d", &num);

            int reverse_num = Reverse_integer(num);
            printf("The reversed integer is : %d\n", reverse_num);
        }

        else if (choice == 5)
        {
            char str[20];
            printf("Enter a positive or negative integer as a string : ");
            scanf("%19s", str);

            int decimal = String_to_decimal(str);
            printf("The decimal equivalent is 1 : %d\n", decimal);
        }

        // else if (choice == 6)
        // {
        //     int n;
        //     printf("\nEnter a positive decimal number: ");
        //     scanf("%d", &n);

        //     int B;
        //     printf("Enter the base B (1 < B ≤ 36): ");
        //     scanf("%d", &B);

        //     if (B < 2 || B > 36) {
        //         printf("Invalid base B. Please enter a value between 2 and 36.\n");
        //         continue;
        //     }

        //     char* baseB = Decimal_to_baseB(n, B);
        //     printf("The base %d representation is: %s\n", B, baseB);
        //     free(baseB); // free the dynamically allocated memory
        // }

        else
        {
            printf("\nExitting the program....");
            break;
        }
    }
    return 0;
}