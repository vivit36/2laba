#include "stack.h"
#include <stdlib.h>
#define LIST



#ifdef VECTOR

void stack_delete(struct Stack* stack)
{
    //----------------------------------------------------------------
    //      Функция освобождение памяти, занятой стеком (вектор)
    //----------------------------------------------------------------

    free(stack->vector);
    stack->head = 0;
    stack->size = 0;
    free(stack);
}

void stack_empty(struct Stack* stack)
{
    //----------------------------------------------------------------
    //      Функция освобождение памяти, занятой стеком (вектор)
    //----------------------------------------------------------------

    free(stack->vector);
    stack->vector = (char*)calloc(stack->size, sizeof(char));
    stack->head = 0;
}

void stack_print(const struct Stack* stack)
{
    //----------------------------------------------------------------
    //      Вывод стека (вектор)
    //----------------------------------------------------------------

    for (int i = stack->head - 1; i >= 0; i--)
    {
        printf("%c", stack->vector[i]);
    }
    printf("\n");
}

struct Stack* stack_new()
{
    //----------------------------------------------------------------
    //      Функция создания и инициализации стека (вектор)
    //----------------------------------------------------------------

    const char* message = "";
    int n;
    int size = 0;
    do
    {
        printf("%s", message);
        printf("Please enter size of stack: ");
        n = scanf_s("%d", &size);
        scanf_s("%*[^\n]");
        scanf_s("%*c");
        message = "Error! Please repeat entering size of stack\n";
    } while ((n < 1) || (size < 1));
 
    struct Stack* ptr;
    ptr = (struct Stack*)calloc(1, sizeof(struct Stack));
    if (!ptr)
    {
        printf("Error! Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    ptr->head = 0;
    ptr->size = size;
    ptr->vector = (char*)calloc(ptr->size, sizeof(char));
    if (!ptr->vector)
    {
        printf("Error! Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int stack_push(struct Stack* stack, char data)
{
    //----------------------------------------------------------------
    //      Функция добаления элемента в стек (вектор)
    //----------------------------------------------------------------
    if ((stack->head + 1) == (stack->size))
    {
        printf("Error! Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->vector[stack->head] = data;
    stack->head = stack->head + 1;
    return 0;
}

int stack_pop(struct Stack* stack, char* output)
{
    //----------------------------------------------------------------
    //      Функция чтения элемента из стека (вектор)
    //----------------------------------------------------------------

    if (stack->head == 0)
    {
        return -1;
    }
    *output = stack->vector[stack->head - 1];
    stack->head = stack->head - 1;
    return 0;
}

struct Stack* stack_copy (struct Stack* stack)
{
    struct Stack* ptr;
    ptr = (struct Stack*)calloc(1, sizeof(struct Stack));
    if (!ptr)
    {
        printf("Error! Failed to copy stack!");
        exit(EXIT_FAILURE);
    }
    ptr->head = 0;
    ptr->size = stack->size;
    ptr->vector = (char*)calloc(ptr->size, sizeof(char));
    if (!ptr->vector)
    {
        printf("Error! Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
#endif

#ifdef LIST

struct Stack* stack_new(int size) {
    //----------------------------------------------------------------
    //      Функция создания и инициализации стека (список)
    //----------------------------------------------------------------
    return (struct Stack*)calloc(1, sizeof(struct Stack));
}
struct Stack* stack_copy(struct Stack* stack)
{
    return (struct Stack*)calloc(1, sizeof(struct Stack));
}

void stack_delete(struct Stack* stack) {
    //----------------------------------------------------------------
    //      Функция освобождение памяти, занятой стеком (список)
    //----------------------------------------------------------------

    Item* ptr = stack->head, * ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(stack);
}

void stack_empty(struct Stack* stack)
{
    Item* ptr = stack->head, * ptr_prev;
    while (ptr) 
    {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    stack->head = NULL;
}
void stack_print(const struct Stack* stack) {
    //----------------------------------------------------------------
    //      Вывод стека (список)
    //----------------------------------------------------------------
    Item* ptr = stack->head;
    while (ptr) {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int stack_push(struct Stack* stack, char data) {
    //----------------------------------------------------------------
    //      Функция добаления элемента в стек (список)
    //----------------------------------------------------------------

    Item* ptr = (Item*)malloc(sizeof(Item));
    if (!ptr)
    {
        return -1;
    }
    ptr->data = data;
    ptr->next = stack->head;
    stack->head = ptr;
    return 0;
}

int stack_pop(struct Stack* stack, char* output) {
    //----------------------------------------------------------------
    //      Функция чтения элемента из стека (вектор)
    //----------------------------------------------------------------
    if (!stack->head) {
        return -1;
    }
    *output = stack->head->data;
    Item* head = stack->head;
    stack->head = head->next;
    free(head);
    return 0;
}

#endif