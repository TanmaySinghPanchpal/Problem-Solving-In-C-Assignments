/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment007.c
 Submission Date : 18-11-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *file;
    int count[256] = {0};
    int character;
    int Character_Counter, Word_Counter, In_Word, Paragraph_Counter = 0;

    file = fopen("TheTimeMachine.txt", "r");
    if (file == NULL)
    {
        printf("Error! Opening file\n");
        return 1;
    }

    while ((character = fgetc(file)) != EOF)
    {
        count[character]++;
        Character_Counter++;

        // Counting the words
        if (isspace(character))
        {
            if (In_Word)
            {
                Word_Counter++;
                In_Word = 0;
            }
        }
        else
        {
            In_Word = 1;
        }

        // Counting the paragraphs
        if (character == '\n')
        {
            int nextCharacter = fgetc(file);
            if (nextCharacter == '\n')
                Paragraph_Counter++;

            ungetc(nextCharacter, file);
        }
    }

    // If file ends in a word, then counting it:
    if (In_Word)
    {
        Word_Counter++;
    }

    fclose(file);

    printf("No of Characters : %d\n", Character_Counter);
    printf("No of Words : %d\n", Word_Counter);
    printf("No of Paragraph : %d\n", Paragraph_Counter);

    printf("Each term is <Character> : (<Ascii Value>) : Occurence Count\n");
    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            if (i < 32 || i == 127) // To handle non printable characters
                printf("ASCII %d: %d times\n", i, count[i]);

            else
                printf("'%c' : (%d) : %d\t\t", i, i, count[i]);
        }
    }

    // Count and print the characters not present in TheTimeMachine.txt
    printf("\n\nCharacters that do not occur : (<Character> : <AsciiValue>)\n");
    for (int i = 0; i < 128; i++)
    {
        if (count[i] == 0)
        {
            if (i < 32 || i == 127)
                continue;
            else
                printf("'%c' : (%d)\t\t", i, i);
        }
    }

    return 0;
}
