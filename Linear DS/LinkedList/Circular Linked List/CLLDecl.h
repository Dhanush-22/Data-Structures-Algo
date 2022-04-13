#ifndef CLLDECL_H_ // To include Guard
#define CLLDECL_H_

struct Node {
    int data;
    struct Node *next;
};

int init(struct Node **);
int insertAfterNode(struct Node**, int, int );
int traverse(struct Node *);
int searchElement(struct Node *, int, struct Node **);
int deleteElement(struct Node **, int);
int destroy(struct Node **);

#endif
