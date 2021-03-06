
#define LIST
#ifndef STACK_H
#define STACK_H



#ifdef VECTOR

typedef struct Stack
{
    char* vector;
    int head;
    int size;
} Stack1, Stack2, Stack3;
#endif


#ifdef LIST

typedef struct Item
{
    char data;
    struct Item* next;
}   Item;

typedef struct Stack
{
    Item* head;
} Stack1, Stack2, Stack3;
#endif


void stack_delete(struct Stack* stack);
struct Stack* stack_new();
struct Stack* stack_copy(struct Stack* stack);
void stack_print(const struct Stack* stack);
int stack_push(struct Stack* stack, char data);
int stack_pop(struct Stack* stack, char* output);
void stack_empty(struct Stack* stack);

#endif