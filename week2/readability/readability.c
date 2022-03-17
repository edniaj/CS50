#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char word[40];
    int wordCount =1;
    int charCount = 0;
    int sentence = 0;
    word = get_string("Text: ");
    for(int i=0; i<strlen(word); i++)
    {
        if (strcmp(word[i]," ") == 0)
        {
            wordCount++
        }
        if (isalpha(word[i]) != 0)
        {
            charCount++
        }
        if (strcmp(word[i],"?") == 0 )
        {
            sentence++
        }
        if (strcmp(word[i],".") == 0 )
        {
            sentence++
        }
        if (strcmp(word[i],"!") == 0 )
        {
            sentence++
        }
    }
    printf("\n%i %i %i ",wordCount, charCount, sentence);
}

