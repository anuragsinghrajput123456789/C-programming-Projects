


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int game(char you, char computer) {
    // DRAW
    if (you == computer)
        return -1;

    // User's choice: stone, computer: paper
    if (you == 's' && computer == 'p')
        return 0;

    // User's choice: paper, computer: stone
    else if (you == 'p' && computer == 's')
        return 1;

    // User's choice: stone, computer: scissor
    if (you == 's' && computer == 'z')
        return 1;

    // User's choice: scissor, computer: stone
    else if (you == 'z' && computer == 's')
        return 0;

    // User's choice: paper, computer: scissor
    if (you == 'p' && computer == 'z')
        return 0;

    // User's choice: scissor, computer: paper
    else if (you == 'z' && computer == 'p')
        return 1;

    return -1; // Default return to avoid warnings
}

// Driver code
int main() {
    char playAgain;
    int userScore = 0, computerScore = 0;

    do {
        int n;
        char you, computer;
        int result;

        // Generate random number for computer's choice
        srand(time(NULL));
        n = rand() % 100;

        if (n < 33) {
            computer = 's';
        } else if (n < 66) {
            computer = 'p';
        } else {
            computer = 'z';
        }

        printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");


        scanf(" %c", &you);

        
        result = game(you, computer);

        if (result == -1) {
            printf("\n\n\t\t\t !!!!!!!!!!!!!!GAME DRAW!!!!!!!!!! \n");
        } else if (result == 1) {
            printf("\n\n\t\t YOU WON THE GAME !! BOLO ZUBA KESHARI..\n");
            userScore++;
        } else {
            printf("\n\n\n\n\t  BHAI HAAR GAYA TOO JAAKE DOOB MAR.....\n");
            computerScore++;
        }

        printf("\t\t\t You chose: %c and computer chose: %c\n", you, computer);

        // Ask if the user wants to play again
        printf("\n\n\t\t\t Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\n\n\t\t\t Final Score:\n");
    printf("\t\t\t User: %d\n", userScore);
    printf("\t\t\t Computer: %d\n", computerScore);

    printf("\n\n\t\t\t Thank you for playing! Bye!\n");
    return 0;
}