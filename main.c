#include <stdio.h>
#include <stdlib.h> // Used for malloc function
#include <string.h> // Used for strcmp and other string functions

#define true 1;
#define false 0;

typedef struct StackStruct {
    int *darr; // Dynamic array
    int allocated; // Amount of memory space allocated
    int inUse; // Top of stack indicator - how many values are on the stack
} Stack;

int grow_array(Stack *stack) {
    int *temp = stack->darr;
    stack->darr = (int *) malloc((stack->allocated + 2) * sizeof(int));
    int i;
    for (i = 0; i < stack->allocated; i++) {
        stack->darr[i] = temp[i];
    }
    free(temp);
    stack->allocated = stack->allocated + 2;
}


void init(Stack *stack) {
    stack->allocated = 2;
    stack->darr = (int *) malloc(sizeof(int) * stack->allocated);
    stack->inUse = 0;
}

int is_empty(Stack *stack) {
    if (stack->inUse == 0) {
        return true;
    } else {
        return false;
    }
}

void push(Stack *stack, int value) {
    if (stack->inUse >= stack->allocated) {
        grow_array(stack);
    }
    stack->darr[stack->inUse] = value;
    stack->inUse++;
}

void pop(Stack *stack) {
    stack->inUse--;
}

int top(Stack *stack) {
    return stack->darr[stack->inUse - 1];
}

void clear(Stack *stack) {
    free(stack->darr);
    init(stack);
}

int main(int argc, char **argv) {
    char input[301];

    /* set up an infinite loop */
    while (1) {
        /* get line of input from standard input */
        printf("\nEnter input to check or q to quit\n");
        fgets(input, 300, stdin);

        /* remove the newline character from the input */
        int i = 0;
        while (input[i] != '\n' && input[i] != '\0') {
            i++;
        }
        input[i] = '\0';

        /* check if user enter q or Q to quit program */
        if ((strcmp(input, "q") == 0) || (strcmp(input, "Q") == 0))
            break;

        printf("%s\n", input);

        /* run the algorithm to determine is input is balanced */

    }

    printf("\nGoodbye\n");
    return 0;
}