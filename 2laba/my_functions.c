#include "my_functions.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int prinadleznost(char data, char* alfabet, int lenght)
{
    //----------------------------------------------------------------
    //      Функция проверки принадлежности символа к алфавиту
    //----------------------------------------------------------------
    for (int i = 0; i < lenght; i++)
    {
        if (data == alfabet[i])
        {
            return 0;
        }
    }
    return -1;
}

int GetChar_of_formula(char* symbol)
{
    //----------------------------------------------------------------
    //      Функция ввода определенного символа для формулы
    //----------------------------------------------------------------
    int status;
    do
    {
        status = scanf_s("%c", symbol);
        if ((status < 0) || (*symbol == '\n'))
        {
            return 0;
        }
        if (status == 0)
        {
            printf("%s\n", "Error! Please enter symbol of formula.");
            scanf_s("%*c");
        }
    } while (status == 0);
    return 1;
}

int priority(char znak)
{
    //----------------------------------------------------------------
    //      Функция, которая вычисляет приоритет операции
    //----------------------------------------------------------------
    if (znak == '*')
    {
        return 8;
    }
    if (znak == '/')
    {
        return 8;
    }
    if (znak == '+')
    {
        return 6;
    }
    if (znak == '-')
    {
        return 6;
    }
    if (znak == '(')
    {
        return 1;
    }
    return 0;
}

void Input(struct Stack* stack, char *alfabet, int lenght_alf)
{
    char xx;

    printf("Please enter the expression in the infix formula: \n");
    stack_push(stack, ')');

    while (GetChar_of_formula(&xx)!= 0)
    {
        if (prinadleznost(xx, alfabet, lenght_alf) == -1)
        {
            printf("Please, enter only variables or signs of mathematical operations\n");
            scanf_s("%*[^\n]");
            scanf_s("%*c");
            stack_empty(stack);
            printf("Please, repeat entering formula\n");
            stack_push(stack, ')');  
        }
        else
        {
            if ((xx == '(') || (xx == ')'))
            {
                if (xx == '(')
                {
                    xx = ')';
                }
                else
                {
                    xx = '(';
                }
            }
            stack_push(stack, xx);
        }
    }
    printf("Our expression in stack: ");
    stack_print(stack);
}

int Conversion(struct Stack* stack1, struct Stack* stack2, struct Stack* stack3)
{
    char xx, promezhutok;
    stack_push(stack2, '(');
    do
    {
        if (stack_pop(stack1, &xx) == -1)
        {
            printf("Error! Stack is empty\n");
        }
        if (xx == '(')
        {
            stack_push(stack2, xx);
        }
        if ((int)xx > 96)
        {
            stack_push(stack3, xx);
        }
        if (xx == ')')
        {
            stack_pop(stack2, &promezhutok);
            while (promezhutok != '(')
            {
                if (stack2->head == 0)
                {
                    printf("Error! Your formula is wrong! Wrong parentheses!\n");
                    stack_delete(stack1);
                    stack_delete(stack2);
                    stack_delete(stack3);
                    exit(EXIT_FAILURE);
                }
                stack_push(stack3, promezhutok);
                stack_pop(stack2, &promezhutok);
            }
            promezhutok = ' ';
        }
        if (((int)xx < 96) && (xx != '(') && (xx != ')'))
        {
            stack_pop(stack2, &promezhutok);
            if (priority(promezhutok) >= priority(xx))
            {
                stack_push(stack3, promezhutok);
            }
            else /////
            {
                stack_push(stack2, promezhutok);
            }
            stack_push(stack2, xx);
        }
    } while (stack1->head != 0);

    while (stack2->head != 0)
    {
        stack_pop(stack2, &promezhutok);
        if (promezhutok == '(')
        {
            printf("Error! Your formula is wrong! Wrong parentheses!\n");
            stack_delete(stack1);
            stack_delete(stack2);
            stack_delete(stack3);
            exit(EXIT_FAILURE);
        }
        stack_push(stack3, promezhutok);
    }

    return 0;
}