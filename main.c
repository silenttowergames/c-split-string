#include <stdio.h>
#include "words.h"

int main()
{
    const char* phrase = "The quick brown fox jumps over the lazy dog";
    
    int wordCount = 0;
    char** words = split(phrase, ' ', &wordCount);
    
    printf("Phrase: \"%s\"\n", phrase);
    printf("Word Count: %d\n", wordCount);
    
    for(int i = 0; i < wordCount; i++)
    {
        printf("'%s'\n", words[i]);
    }
    
    freeSplit(words, wordCount);
    
    return 0;
}
