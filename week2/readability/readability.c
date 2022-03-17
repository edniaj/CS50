#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char* word = malloc(40);
    int wordCount =1;
    int charCount = 0;
    int sentence = 0;
    word = get_string("Text: ");
    free(word);
}