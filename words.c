#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "words.h"

char** split(const char* phrase, int phraseLength, char delimiter, int* wordCount)
{
    // Get number of words
    
    char** words;
    int c = 1;
    
    for(int i = 0; i < phraseLength; i++)
    {
        if(phrase[i] == delimiter)
        {
            c++;
        }
    }
    
    // Get list of words
    
    words = malloc(sizeof(char*) * c);
    
    int cc = 0;
    int oldWordStart = -1;
    for(int i = 0; i < phraseLength + 1; i++)
    {
        if(oldWordStart == -1)
        {
            oldWordStart = i;
        }
        
        if(phrase[i] == '\0' || phrase[i] == delimiter)
        {
            words[cc] = malloc(sizeof(char) * ((i - oldWordStart) + 1));
            
            memcpy(words[cc], &phrase[oldWordStart], (i - oldWordStart));
            
            words[cc][i + 1] = '\0';
            
            if(phrase[i] == '\0')
            {
                break;
            }
            
            oldWordStart = -1;
            
            cc++;
        }
    }
    
    *wordCount = c;
    
    return words;
}

char** split_str(const char* phrase, char delimiter, int* wordCount)
{
    return split(phrase, strlen(phrase), delimiter, wordCount);
}

void split_free(char** words, int wordCount)
{
    for(int i = 0; i < wordCount; i++)
    {
        free(words[i]);
    }
    
    free(words);
}
