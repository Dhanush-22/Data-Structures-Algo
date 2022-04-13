#include "CLLDecl.h"
#include <stdio.h>
#include <stdlib.h>

int init(struct Node **tail){
    *tail = NULL;
    return 1;
}

int insertAfterNode(struct Node **tail, int pre, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
        return 0; 
    newNode->data = data;
    if (!(*tail)){
        newNode->next = newNode;
        *tail = newNode;
        return 1;
    }
    struct Node *prePtr = (*tail)->next; //prePtr = head
    do{
        if(prePtr->data == pre){
            newNode->next = prePtr->next;
            prePtr->next = newNode;
            return 1;
        }
        prePtr = prePtr->next;
    }while(prePtr != (*tail)->next);

    free(newNode);
    return 0;
}

int traverse(struct Node *tail){
    if (!tail)
        return 0;
    struct Node *iter = tail->next;
    do{
        printf("%d ",iter->data);
        iter = iter->next;
    }while(iter != tail->next);
    printf("\n");
    return 1;
}

int searchElement(struct Node *tail, int key, struct Node **keyPtr){
    *keyPtr = NULL;
    if (!tail)
        return 0;
    struct Node *iter = tail->next; //iter = head
    do{
        if(iter->data = key){
            *keyPtr = iter;
            return 1; 
        }
        iter = iter->next;
    }while(iter != tail->next);
    return 0;   
}

inline int deleteElement(struct Node **tail, int key){
    struct Node *iter = NULL;
    struct Node *pre = NULL;
    if (!(*tail))
        return 0;
    pre = *tail;
    iter = (*tail)->next;
    do{
        if (iter->data == key){
            if(iter == pre)
                *tail = NULL;
            else{
                pre->next = iter->next;
                if(iter == *tail)
                    *tail = pre;
            free(iter);
            return 1;
            }
        }
        pre = iter;
        iter = iter->next;
    } while(iter != (*tail)->next);
    return 0;
}

int destroy(struct Node **tail){
    struct Node *iter = NULL;
    struct Node *temp = NULL;
    if (!(*tail))
        return 1;
    iter = (*tail)->next;
    do{
        deleteElement(&tail,iter->data);
        iter=iter->next;
        
    } while (iter != (*tail)->next);
    *tail = NULL;
}
