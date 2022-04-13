#include "DLLDec.h"
#include <stdio.h>
#include <stdlib.h>

int init(struct node **head, struct node **tail){
    *head = NULL;
    *tail = NULL;
}

int insertElement(struct node **head, struct node **tail,int pos, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) return 0;

    newNode->data = data;
    newNode->pre = NULL;
    newNode->next = NULL;

    struct node *pred = NULL;
    struct node *iter = *head; 
    int i=1;
    while (iter && i<pos){
        i++;
        pred = iter;
        iter = iter->next;
    } 
    if(!iter && i!=pos) return 0; //Invalid Position

    if(!pred){ //i.e Insert before head
        newNode->next = *head;
        if (*head == NULL)
            *tail = newNode;
        else
            (*head)->pre = newNode;           
        *head = newNode;
        return 1;
    }

    struct node *ps = pred->next;
    pred->next = newNode;
    newNode->pre = pred;
    if (pred == *tail){
        newNode->next = NULL;
        *tail = newNode;
    }
    else{
        newNode->next = ps;
        ps->pre = newNode;
    }
    return 1;
}
int traverse(struct node *head,struct node *tail,int flag){
    if (flag){
        while(head){
            printf("%d ",head->data);
            head = head->next;
        }
    }
    else{
        while(tail){
            printf("%d ",tail->data);
            tail = tail->pre;
        }
    }
    printf("\n");
    return 1;
}

int search(struct node *head,int key, struct node **keyPtr){
    struct node *iter = head;
    while (iter){
        if (iter->data == key){
            *keyPtr = iter;
            return 1;
        }
        iter = iter->next;
    }
    return 0;
}

int deleteElement(struct node **head, struct node **tail, int key){
    struct node *keyPtr = NULL;
    search(*head,key,&keyPtr);
    if(!keyPtr) return 0; //Not Found

    if (keyPtr == *head){
        *head = (*head)->next;
        if(*head == NULL)
            *tail == NULL;
        else
            (*head)->pre = NULL;
        free(keyPtr);
        return 1;
    }

    if (keyPtr == *tail){
        *tail = (*tail)->pre;
        //if(*tail == NULL)
        //    *tail == NULL;
        (*tail)->next = NULL;
        free(keyPtr);
        return 1;
    }

    struct node *pred = keyPtr->pre;
    struct node *ps = keyPtr->next;
    pred->next = ps;
    ps->pre = pred;
    free(keyPtr);
    return 1;
}

int reverse(struct node **head,struct node **tail){
    if(*head == NULL || (*head)->next == NULL)
        return 0;

    struct node *pre = NULL;
    struct node *iter = *head;
    struct node *cur = NULL;
    *tail = *head;
    do{
        pre = cur;
        cur = iter;
        iter = iter->next;
        cur->pre = iter;
        cur->next = pre;
    }while(iter != NULL);
    *head = cur;
    return 1;
}

int destroy(struct node **head){
    struct node *iter = *head;
    struct node *temp;
    while (iter){
        temp = iter;
        iter = iter->next;
        free(temp);
    }
    *head = NULL;
    return 1;
}