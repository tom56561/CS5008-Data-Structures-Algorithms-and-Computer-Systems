// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall dll_test.c -o dll_test
//
// Run with: ./dll_test
//
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.


// A sample collection of tests for your program
// We will be adding our own to test your program.


// Tests creation and deletion of list
// Ideally does not cause any segfaults, and this
// is considered passing.
// Dll should also be empty.
int unitTest1(int status){
    int passed = 0;
    dll_t* test = create_dll();
    if(dll_empty(test)){
    	passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests push_front and size functions
int unitTest2(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_front(test,789);
    if(1==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}


// Tests push_back and size functions
int unitTest3(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test,142);
    if(1==dll_size(test)){
       passed = 1;
    }else{
       passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_front and dll_pop_back functions
int unitTest4(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test,142);
    dll_pop_back(test);
    if(0==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_back twice, then pops once
// then should compute the correct size.
int unitTest5(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_back(test,142);
    dll_push_front(test,142);
    dll_pop_back(test);
    if(1==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
    }
    free_dll(test);

    return passed;
}

// Fill a DLL, empty the DLL, fill the DLL, and empty the DLL again.
int unitTest6(int status){
    int passed = 0;
    dll_t* test = create_dll();
    int i;
    for (i = 0; i < 10; i++){
        dll_push_back(test,142);
    }
    if(10==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
        return passed;
    }
    for(i = 0; i < 10; i++){
        dll_pop_back(test);
    }
    if(0==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
        return passed;
    }
    for (i = 0; i < 10; i++){
        dll_push_front(test,142);
    }
    if(10==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
        return passed;
    }
    for(i = 0; i < 10; i++){
        dll_pop_front(test);
    }
    if(0==dll_size(test)){
       passed = 1;
    }else{
    	passed = 0;
        return passed;
    }
    free_dll(test);

    return passed;
}

// Test each function in your DLL when the DLL is not empty.
int unitTest7(int status){
    int passed = 0;
    dll_t* test = create_dll();
    dll_push_front(test,1);
    if(dll_empty(test) == 0){
    	passed = 1;
    }else{
        passed = 0;
        return passed;
    }
    dll_push_back(test,2);
    if(dll_size(test) == 2){
        passed = 1;
    } else{
        passed = 0;
        return passed;
    }

    if(dll_pop_front(test) == 1){
        passed = 1;
    } else{
        passed = 0;
        return passed;
    }

    if(dll_pop_back(test) == 2){
        passed = 1;
    } else{
        passed = 0;
        return passed;
    }

    dll_push_front(test,1);

    dll_insert(test, 1, 3);
    if(dll_get(test, 1) == 3){
        passed = 1;
    } else{
        passed = 0;
        return passed;
    }
    dll_remove(test, 1);
    if(dll_size(test) == 1){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }

    free_dll(test);

    return passed;
}

// Test each function in your DLL when the DLL is empty.
int unitTest8(int status){
    int passed = 0;
    dll_t* test = create_dll();
    if(dll_pop_front(test) == 0){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }
    if(dll_pop_back(test) == 0){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }

    if(dll_insert(test, 0, 5) == 1){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }
    dll_pop_back(test);

    if(dll_get(test, 0) == 0){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }

    if(dll_remove(test, 0) == 0){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }

    if(dll_size(test) == 0){
        passed = 1;
    } else {
        passed = 0;
        return passed;
    }

    free_dll(test);

    return passed;
}

// An array of function pointers to all of the tests
// that main() can use iterate over them.
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    NULL
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter]!=NULL){
    	printf("========unitTest %d========\n",counter);
        if(1==unitTests[counter](1)){
    		printf("passed test\n");
    		testsPassed++;	
    	}else{
    		printf("failed test, missing functionality, or incorrect test\n");
    	}
    counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}
