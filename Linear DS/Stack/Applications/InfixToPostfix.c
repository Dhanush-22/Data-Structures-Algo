#include "2_stackDL.h"
#include "2_stackDF.c"
#include <stdio.h>

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

int priority(char oper){
    if (oper == '+' || oper == '-')
        return 1;
    else if (oper == '*' || oper == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char *ptr, int len){  
    char* postfix = (char *)malloc(len*sizeof(char));
    int i=0;
    int j=0;
    char popped;
    char chr;
    struct Stack *s;   
    init(&s);
    while( ptr[i] != '\0'){

        if (ptr[i] == '('){           //2+(3*4)-(8/2) ==>     234*+82/-
            push(s,'(');
            i++;
        }

        else if (ptr[i]==')'){
            i++;
            pop(s,&popped);
            while (popped != '('){
                postfix[j++] = popped;
                pop(s,&popped);
            }
        }

        else if (isOperand(ptr[i]))
            postfix[j++] = ptr[i++];

        else{ //It is an operator
            peek(s,&chr);
            while (!isEmpty(s) && (priority(ptr[i]) <= priority(chr))){
                pop(s,&popped);
                postfix[j++] = popped;
                peek(s,&chr);
            }
            push(s,ptr[i]);
            i++;
        }
    }

    while (!isEmpty(s)){
        pop(s,&popped);
        postfix[j++] = popped;
    }

    destroy(&s);
    return postfix;
}

int main()
{
    char exp[] = "1+3*5/(1-4)";
    char* ans = infixToPostfix(exp,sizeof(exp)/sizeof(char));
    printf("%s \n",exp);
    printf("%s",ans);
    free(ans);
    return 0;
}
