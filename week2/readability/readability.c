#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    string word;
    int wordCount =1;
    int charCount = 0;
    int sentence = 0;
    word = get_string("Text: ");
    for(int i=0; i<strlen(word); i++)
    {
        if (word[i] == ' ')
        {
            wordCount++;
        }
        if (isalpha(word[i]) != 0)
        {
            charCount++;
        }
        if (word[i] == '?')
        {
            sentence++;
        }
        if (word[i] == '.')
        {
            sentence++;
        }
        if (word[i] == '!')
        {
            sentence++;
        }
    }
    printf("\n %i %i %i",wordCount, charCount, sentence);
    float temp = 100 / wordCount;
    float L = temp * charCount;
    float S = temp * sentence;
    printf("L =%f S=%f",L,S);
    int index = 0.0588 * L - 0.296 * S - 15.8;
    printf("\nindex=%i", index);

}

