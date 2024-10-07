#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "handsign.h"

void game(int rd_num, char userinput[10]){
    
    char* choice[3] = { rock, paper, scissors }; // store handsign 
    char* choice2[3] = {"rock", "paper", "scissors"}; // text to compare
    
    // printing user choice handsign
    printf("You chose: %s\n", userinput);
    if (strcmp(userinput, "rock")== 0){
        printf("%s\n", rock);
    }else if(strcmp(userinput, "paper")== 0){
        printf("%s\n", paper);
    }else if (strcmp(userinput, "scissors") ==0){
        printf("%s\n", scissors);
    }
    // printing computer choice handsign
     printf("Computer chose: %s", choice2[rd_num]);
    printf("\n\n%s\n\n", choice[rd_num]);
    // Compare user input with computer choice
    if (strcmp(userinput, choice2[rd_num]) == 0) {
        printf("It's a tie!\n");

    } else if ((strcmp(userinput, "rock") == 0 && rd_num == 2) || 
               (strcmp(userinput, "paper") == 0 && rd_num == 0) || 
               (strcmp(userinput, "scissors") == 0 && rd_num == 1)) {
        printf("You win!\n\n");
       
    } else {
        printf("You lose!\n\n");
    }
}

int printRandoms(int min, int max) {
    // Seed the random number generator with current time
    srand(time(0)); 
    
    // Generate and print a random number
    int rd_num = rand() % (max - min + 1) + min;
    return rd_num;
}

int main() {
    
    char userInput[10];
    int min = 0, max = 2;
    printf("\n\nWelcome to Ultimate Fun Game\n\n");
    printf("%s", logo);
    
    

    // printf("you entered %s\n", userInput);
    while(1) {
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Choose an option (rock/paper/scissors or type 'exit' to quit): ");
        scanf("%s", userInput);

        // Check if the user wants to exit
        if (strcmp(userInput, "exit") == 0) {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }

        // Validate input
        if (strcmp(userInput, "rock") != 0 && strcmp(userInput, "paper") != 0 && strcmp(userInput, "scissors") != 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Generate random choice for computer
        int rd_num = printRandoms(min, max);
        
        // Play the game
        game(rd_num, userInput);
        printf("\n");
        
    }

    return 0;

    
}