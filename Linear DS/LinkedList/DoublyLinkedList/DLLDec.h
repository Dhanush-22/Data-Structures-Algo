#ifndef DLLDEC_H_ // To include Guard
#define DLLDEC_H_
struct node{
    int data;
    struct node *pre;
    struct node *next;
};

int init(struct node **head, struct node **tail);

int insertElement(struct node **head, struct node **tail,int pos, int data);
int traverse(struct node *head,struct node *tail,int flag);
int search(struct node *head,int key, struct node **keyPtr);
int deleteElement(struct node **head, struct node **tail, int key);
int reverse(struct node **head,struct node **tail);

int destroy(struct node **head);

#endif