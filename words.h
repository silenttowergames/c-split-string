#pragma once

char** split(const char* phrase, char delimiter, int* wordCount);
void freeSplit(char** words, int wordCount);
