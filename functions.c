#include <stdio.h>
#include <ctype.h>

int checkWin(char word[], char obscuredWord[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        if(tolower(word[i]) != tolower(obscuredWord[i])) 
        {
            return 0;
        }
        i++;
    }
    printf("You win!\n");
    return 1;
}

char* obscureWord(char word[], char obscuredWord[])
{
    int i = 0;
    while(word[i] != '\0')
    {
        obscuredWord[i] = '*';
        printf("%c", obscuredWord[i]);
        i++;
    }
    printf("\n");
    return obscuredWord;
}

void guessLetter(char word[], char obscuredWord[])
{
    int guessesRemaining = 10;
    int isWinner = 0;
    while(!isWinner && guessesRemaining > 0)
    {
        char letter;
        printf("Guess a letter: \n");
        fflush(stdin);
        scanf(" %c", &letter);

        int correctLetter = 0;
        int i = 0;
        while (word[i] != '\0')
        {
            if(tolower(word[i]) == tolower(letter))
            {
                obscuredWord[i] = letter;
                correctLetter = 1;
            }
            i++;
        }
        int j = 0;
        while (obscuredWord[j])
        {
            printf("%c", obscuredWord[j]);
            j++;
        }
        printf("\n");
        if(!correctLetter)
        {
            guessesRemaining--;
            printf("Guesses remaining: %d\n", guessesRemaining);
            if(!guessesRemaining)
            {
                printf("You loose!\n");
            }
        }
        isWinner = checkWin(word, obscuredWord);
    }
}

void waitForUserInput(void)
{
    printf("Press any key to exit\n");
    while (getchar() != '\n')
    {
    }
    getchar();
}