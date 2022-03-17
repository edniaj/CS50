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
    float temp = 100 / wordCount;  // 100 / 70 = 1.42 , wordcount = 70
    float L = temp * charCount; // 1.42 * 295 = 421
    float S = temp * sentence; // 1.42 * 
    printf("\nL =%f S=%f",L,S);
    float t = 0.0588 * L;
    printf("\n0.0588 * L = %f\n",t);
    t = 0.296 * S;
    printf("\n - 0.296 * S  =%f",t);
    int index = 0.0588 * L - 0.296 * S - 15.8;
    printf("\nindex=%i\n", index);

}

