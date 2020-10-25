#include <stdio.h>
#include <string.h>
#include "functions.h"
#define MAX 100

int main(void)
{
    char word[MAX];
    char obscuredWord[MAX];
    printf("Enter a word: \n");
    scanf("%s", word);
    obscureWord(word, obscuredWord);
    guessLetter(word, obscuredWord);
    waitForUserInput();
    return 0;
}