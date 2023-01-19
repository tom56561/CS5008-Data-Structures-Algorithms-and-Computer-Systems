// Your name Po-Shen Lee (Eddie)
// Date 19/01/2023
//
// Add your program here!
#include <stdio.h>
#include <stdlib.h>

int main(){

    int answer = 0;
    int guess = 0;
    int guesses[] = {0, 0, 0, 0, 0};


    for(int i = 0; i < 5; i++) {
        answer = (rand() % 10) + 1;
        printf("============================\n");
        printf("CPU Says: Pick a number 1-10\n");
        printf("============================\n");
        do
        {
            printf("Make a guess:");
            scanf("%d", &guess);
            guesses[i]++;
            if(guess < answer){
                printf("No guess higher!\n");
            } else if(guess > answer) {
                printf("No guess lower!\n");
            } else {
                printf("You got it!\n");
            }
        } while (guess != answer);
    }

    printf("===============================================\n");
    printf("|Here are the results of your guessing abilities|\n");
    printf("===============================================\n");

    for(int i = 0; i < 5; i++) {
        printf("Game %d took you %d guesses\n", i, guesses[i]);
    }
    
    

}

