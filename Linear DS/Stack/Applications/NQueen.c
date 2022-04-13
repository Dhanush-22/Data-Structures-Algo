#include <stdio.h>
#include <stdlib.h>
#include "1stackDL.h"
#include "1stackDF.c"

// -------------------------------------
// | Change the chess board size here (n)|
// -------------------------------------
#define n 4

// ---------------------------------------

int isFeasible(int arr[][n],int x, int y){
    for (int i=0;i<x;i++){
        if (arr[i][y]==1)
            return 0;
    }

    for (int j=0;j<y;j++){
        if (arr[x][j]==1)
            return 0;
    }

    int i = x;
    int j = y;
    while (i>=0 && j>= 0)
    {
        if(arr[i][j]==1)
            return 0;
        i--;
        j--;
    }

    i = x;
    j = y;

    while (i>=0 && j < n) 
    {
        if(arr[i][j]==1)
            return 0;
        i--;
        j++;
    }
    return 1;
}


void display(int arr[][n]){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    struct Stack *s;
    init(&s);
    int arr[n][n]= {0};
    int row = 0;
    int col = 0;
    //display(arr);

    int flag = 0;


    int popX;
    int popY;

    int x;
    int y;

    while (row < n){
        while (col < n && row <n){
            if (isFeasible(arr,row,col)){
                push(s,row);//x
                push(s,col);//y
                //printf("Pushing : %d, %d\n",row,col);
                arr[row][col] = 1;
                if (row==n-1){
                    //printf("\nChess Board : \n");
                    display(arr);
                    printf("\n");
                }
                row++;
                col = 0;
            }
            else
                col++;

            while (col >= n ){
                pop(s,&popY);
                pop(s,&popX);
                //printf("Popping : %d, %d \n",popX,popY);
                arr[popX][popY] = 0;
                row = popX;
                col = popY+1;
                if(row == 0 && col == n){
                    flag = 1; //Using flag to check whether it reached end or not
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        //Making Stack empty
        while (!isEmpty(s)){
            pop(s,&y);
            pop(s,&x);
            //printf("(%d,%d)\n",x,y);
        }

        if (flag == 1)
            break;

        //Find out column in 1st row
        for(int i=0;i<n;i++){
            if (arr[0][i] == 1 && (i+1)<n){
                row=0;
                col = i+1;
            }
                
        }

        //Make all zeroes (chess board empty)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j] = 0;
    }
    destroy(&s); 
    return 0;
 
}