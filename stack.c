#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct StackNode {
    uint32_t data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void push(Stack* stack, uint32_t data) {
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

uint32_t pop(Stack* stack) {
    if (stack->top == NULL) {
        return 0; // Pilha vazia
    }

    StackNode* poppedNode = stack->top;
    uint32_t poppedData = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);

    return poppedData;
}

int main() {
    Stack* stack;
    stack->top = NULL;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

   
    while (stack->top != NULL) {
        uint32_t value = pop(stack);
        printf("Popped value: %d\n", value);
    }

    return 0;
}
