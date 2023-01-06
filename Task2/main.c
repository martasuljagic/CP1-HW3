#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int try(char in, char word[], int n, char guess[]) //one try
{
    if(strchr(word, in) > 0) //checking if its there
    {
        for (int i = 0; i < n; i++)// finding where
        {
            if(word[i] == in)
            {
                guess[i] = in;
            }
        }  
    return 0;
    }
    else
    {
        return 1;
    }
}
void drawing(int mistakes) // could have been done better
{
    switch (mistakes)
    {
        case 0:
        break;
        case 1:
            printf("O \n");
            break;
        case 2:
            printf("O \n");
            printf("| \n");
            break;
        case 3:
            printf(" O \n");
            printf("/| \n");
            break;
        case 4:
            printf(" O \n");
            printf("/|\\ \n");
            break;
        case 5:
            printf(" O \n");
            printf("/|\\ \n");
            printf("/ \n");
            break;
        case 6:
            printf(" O \n");
            printf("/|\\ \n");
            printf("/ \\ \n");
            break;
        default:
            printf("Something is wrong.\n");
            break;
    }
}
int checkingGuess(char in, char letters[], int n) // checking if the guess has already occured
{
    for (int i = 0; i < n; i++)
        {
            if(letters[i] == in)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
}
int correctInput(char in) // checking if input is correct
{
    if(in < 'a' || in > 'z')
    {
        return 1;
    }
    else 
        return 0;
}
int isEnd(int n, char guess[]) //is the game done
{
    for (int j = 0; j < n; j++)
            {
            if(guess[j] == '_')
                {
                    return 0;
                }
            }
            return 1;
}
int main()
{
    char dictionary[8][10] = {"word", "smart", "cat", "dodge", "equals", "banana", "chocolate", "brain", "computer"};
    time_t tm; //otherwise random gives the same number
    srand((unsigned) time(&tm));//same
    int r = rand() % 8;
    int n = strlen(dictionary[r]);
    char word[n], letters[7], guess[n], in;
    int i, mistakes = 0;
    for (i = 0; i < n; i++)//making an array for chosen word
    {
        word[i] = dictionary[r][i];
    }
    printf("Your current word and guesses.\n");
    for(i = 0; i < n; i++)
    {
        guess[i]='_';
        printf("%c", guess[i]);//making it in right format
    }
    printf("\n");
    i = 0;
    int c;//checking if guess already happened
    int ic;//input check
    int ie;// isEnd check
        while(mistakes < 6)
        {
            scanf(" %c", &in);
            ic = correctInput(in);
            c = checkingGuess(in, letters, i);
            
            if(ic == 1)
            {
                printf("Wrong input.\n");
            }
            if(c == 1)
            {
                printf("Already had that char.\n");
                continue;
            }
            letters[i] = in;
            int t = try(in, word, n, guess);
            mistakes+=t;//counting mistakes
            printf("%s\n", guess);
            drawing(mistakes);
            printf("Guesses you used: \n %s\n", letters);
            ie = isEnd(n, guess);
            if(ie == 1)
            {
                printf("\nYou won!\n");
                break;
            }
            i++;
    }

    return 0;
}