# Lab 3 -- Counting Assembly

This is the starting readme for this assignment.  Please edit the following 
information by removing the "*edit me*" and replace it with appropriate 
information your assignment. If it is asking you a question, please provide 
a response.

- Name: Po-Shen Lee

- Title: Lab03 -- Counting Assembly

- How many hours did it take you to complete this assignment? 5 hours

- Did you collaborate with any other students/TAs/Professors? If so, tell 
  us who and in what capacity.
  - *edit me (add more rows if needed)*
  
- Did you use any external resources? (Cite them below)
  - https://www.fresh2refresh.com/c-programming/c-strings/c-strupr-function/
  - https://www.geeksforgeeks.org/toupper-function-in-c/
  
- Use your tool to measure the  number of instructions that are require to 
  execute your implementation of the guessing game program that you 
  implemented in Homework 1 using two different levels of optimization:

  - When your program is compiled using the -O0 flag:

    ```
    The purpose of using the -O0 flag is to provide an unoptimized version of the code for debugging purposes, as the generated code is easier to understand and debug than the optimized code. The -O0 option sets the optimization level to 0, which disables optimization for the compiled code.

    gcc -S -O0 hw1.c
    ./estimator hw1.s

    ADD  5
    SUB  2
    DIV  1
    MOV  49
    LEA  14
    PUSH  1
    POP  1
    RET  1

    Total Instructions = 74
    Total Cycles = 125
    ```

  - When your program is compiled using the -O3 flag:

    ```
    gcc -S -O3 hw1.c
    ./estimator hw1.s

    ADD  11
    SUB  7
    MUL  5
    MOV  59
    LEA  53
    PUSH  6
    POP  6
    RET  1

    Total Instructions = 148
    Total Cycles = 264

    ```

- (Optional) What was your favorite part of the assignment? 
  - *edit me*
  
- (Optional) How would you improve the assignment? 
  - *edit me*

## Logistics

For this assignment (and every assignment/lab), you must login into the 
servers through `your_khoury_name@login.khoury.northeastern.edu` to complete 
and test your work. The reason is the examples I will provide below are 
compiled strictly for our machine's architecture, and this is a consistent 
architecture where your submission will be graded.

### Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. 
  Make sure you test your programs on these machines, as this is where we 
  grade your assignments.
* You must commit any additional files (if any) into your repository so we 
  can test your code.
  * Points will be lost if you forget!
* Do not forget to push your changes in your private repo for grading before 
  the assignment deadline!**

