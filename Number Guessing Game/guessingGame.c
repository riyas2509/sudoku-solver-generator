#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int random, guess, count=0; 
    //'random' is a random number from our end which the user will guess 
    //'guess' is the number that we will take input from the user
    //'count' is the no of attempts the user took to guess the number
    srand(time(NULL));

    printf("Welcome to the World of Guessing Numbers\n");
    random = rand() % 100 + 1; //Generating between 0 to 100

    //Using Do-While loop as 1 input has to be always taken
    do
    {
        printf("\nPlease enter your Guess Number between(1 to 100): ");
        scanf("%d", &guess);
        count++;

        if(guess < random)
        {
            printf("Guess a larger number.\n");
        }
        else if(guess > random)
        {
            printf("Guess a smaller number.\n");
        }
        else
        {
            printf("\nCongratulations !! You have successfully Guessed the Number in %d attempts.", count);
        }
    }
    while(guess != random);

    printf("\nBye Bye, Thanks for Playing.\nDeveloped By RIYA SHAH.");
    return 0;
}