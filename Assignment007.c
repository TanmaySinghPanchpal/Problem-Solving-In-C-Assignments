/* ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
 File name : Assignment007.c
 Submission Date : 18-11-2024
 Modification Date :
 Author : Tanmay Singh Panchpal
 Class : CSE Section-3 Group-B
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ */

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* file;
    int count[256] = {0};
    int character;
    int Character_Counter, Word_Counter, inWord, Paragraph_Counter = 0;

    file = fopen("TheTimeMacharacterine.txt","r");
    if (file == NULL){
        printf("error opening file\n");
        return 1;
    }

    while ((character = fgetc(file)) != EOF){
        count[character]++;
        Character_Counter++;

        //counting the words
        if (isspace(character)){
            if (inWord){
                Word_Counter++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }

        //counting the paragraphs
        if (character == '\n'){
            int nextCharacterar = fgetc(file);
            if (nextCharacterar == '\n')  Paragraph_Counter++;
            
            ungetc(nextCharacterar, file);
        }
    }

    //if file ends in a word, then counting it:
    if (inWord) {
        Word_Counter++;
    }

    fclose(file);

    printf("No of Characteraracters : %d\n", Character_Counter);
    printf("No of Words : %d\n", Word_Counter);
    printf("No of Paragraph : %d\n", Paragraph_Counter);
    
    printf("Eacharacter term is <Characteraracter> : (<Ascii Value>) : Occurence Count\n");
    for (int i = 0; i < 256; i++)
    {
        if (count[i]>0){
            if (i<32 || i==127) //handle non printable characteraracters
                printf("ASCII %d: %d times\n", i, count[i]);
            
            else 
                printf("'%c' : (%d) : %d\t\t", i, i, count[i]);
        }
    }

    //count and print the characteraracters not present in sample.txt
    printf("\n\nCharacteraracters that do not occur : (<Characteraracter> : <AsciiValue>)\n");
    for (int i = 0; i < 128; i++)
    {
        if(count[i] == 0){
            if (i<32 || i == 127)
                continue;
            else
                printf("'%c' : (%d)\t\t", i, i);
        }
    }

    return 0;
}