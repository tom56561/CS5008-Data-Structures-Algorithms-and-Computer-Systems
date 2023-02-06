// Your Name Here
// Date Here
// CS5008 Lab03
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define NUM_INSTRUCTIONS 9
#define MAX_LEN 100

//Covert char to upper case.
void convertUpperCase(char* str){
    int i;
    for (i = 0; i < 5; i++) {
        str[i] = toupper(str[i]);
    }
}

// Implement your cycle count tool here.
int main(int argc, char** argv){
    
    char instructions[NUM_INSTRUCTIONS][5] = {"ADD", "SUB", "MUL", "DIV", "MOV", "LEA", "PUSH", "POP", "RET"};
    int cycle[] = {1, 1, 3, 24, 1, 3, 1, 1, 1};
    int count[NUM_INSTRUCTIONS] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int totalInstructions = 0;
    int totalCycles = 0;
    int i;

    if (argc != 2) {
        printf("There is no input file or more than one input file.");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }
    
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, input)) {
        convertUpperCase(line);
        for (i = 0; i < 9; i++){
            if(strstr(line, instructions[i])){
                count[i]++;
                totalInstructions++;
                totalCycles += cycle[i];
            }   
        }
    }

    for (i = 0; i < NUM_INSTRUCTIONS; i++){
        if(count[i] > 0){
            printf("%s  %d\n",instructions[i], count[i]);
        }
    }
    printf("\nTotal Instructions = %d\n", totalInstructions);
    printf("Total Cycles = %d\n", totalCycles);

    fclose(input);
    return 0;
}
