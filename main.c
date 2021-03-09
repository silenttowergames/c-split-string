#include <stdio.h>
#include <string.h>
#include "split.h"

int main()
{
    const char* phrase = "                ";
    
    int wordCount = 0;
    char** words = split(phrase, strlen(phrase), ' ', &wordCount);
    
    printf("Phrase: \"%s\"\n", phrase);
    printf("Word Count: %d\n", wordCount);
    
    for(int i = 0; i < wordCount; i++)
    {
        printf("'%s'\n", words[i]);
    }
    
    split_free(words, wordCount);
    
    return 0;
}
