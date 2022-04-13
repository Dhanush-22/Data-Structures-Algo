#include <stdio.h>
#include "stackdeclaration.h"
#include "stackDefinitions.c"

int main()
{
    int a,b;
    struct stack *s;
    init(&s);

    push(s,16);
    push(s,32);
    push(s,64);
    push(s,128);
    push(s,256);
    push(s,512); 
    push(s,1024);

    peek(s,&a);
    printf("%d \n",a);

    printf("Elements in stack : ");
    while (!isEmpty(s))
    {
        pop(&s,&b);
        printf("%d ",b);
    }
    printf("\n");
    
    destroy(&s);
    return 0;
}