#include "1stackDL.h"
#include "1stackDF.c"
#include <stdio.h>
#include <string.h>

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

int evalPostfix(char *ptr){
    struct Stack *s = NULL;
    init(&s); 
    int ans;
    int op1;
    int op2;
    while (*ptr != '\0'){   //"234*+82/-"
        if (isOperand(*ptr)){
            push(s,*ptr - '0');
        }
        else{
            pop(s,&op1);
            pop(s,&op2);
            
            switch(*ptr){
                case '+' : ans = op2+op1; break;
                case '-' : ans = op2-op1; break;
                case '*' : ans = op2*op1; break;
                default : ans = op2/op1; break;
            }
            push(s,ans);
        }
        ptr++;
    }
    pop(s,&ans);
    return ans;
} 

int main()
{
    struct Stack *s;
    char *pos = "234*+82/-";
    printf("Postfix : %s\n",pos);
    int res = evalPostfix(pos);
    printf("%d",res);
    return 0;
}