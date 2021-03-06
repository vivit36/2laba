#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "my_functions.h"
#define LIST

#define _CRTDBG_MAP_ALLOC //
#include <crtdbg.h> //

int main()
{
    char alfabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+','-','*','/','(',')' };
    int lenght_alf = sizeof(alfabet);

    //----------------------------------------------------------------
    //      ???????? ? ????????????? ??????
    //----------------------------------------------------------------
        Stack1* s1 = stack_new();
        Stack2* s2 = stack_copy(s1);
        Stack3* s3 = stack_copy(s1);
        //----------------------------------------------------------------

        //----------------------------------------------------------------
        //      ???? ????????? (???????)
        //----------------------------------------------------------------
        Input(s1, alfabet, lenght_alf);
        //----------------------------------------------------------------

        //----------------------------------------------------------------
        //      ?????????????? ????????? ????? ? ??????????
        //----------------------------------------------------------------
        Conversion(s1, s2, s3);
        //----------------------------------------------------------------



        //----------------------------------------------------------------
        //      ????? ???????
        //----------------------------------------------------------------
        printf("Prefix form:\n");
        stack_print(s3);
        //----------------------------------------------------------------


        //----------------------------------------------------------------
        //  ???????????? ??????
        //----------------------------------------------------------------
        stack_delete(s1);
        stack_delete(s2);
        stack_delete(s3);
        //----------------------------------------------------------------


    _CrtDumpMemoryLeaks();
    return 0;

}