#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

int test(const char* phrase)
{
    int wordCount = 0;
    char** words = split(phrase, strlen(phrase), ' ', &wordCount);
    
    printf("Phrase: \"%s\"\n", phrase);
    printf("Word Count: %d\n", wordCount);
    
    split_free(words, wordCount);
}

int main()
{
    test("volume sfx 0");
    
    return 0;
}
