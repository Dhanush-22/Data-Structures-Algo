#include "avlDec.h"
#include "avlDef.c"


int main()
{
    struct node *root = NULL;

    int arr[] = {20,10,15,50,80,100,8};
    //int arr[] = {20,10,8,5};
    //int arr[] = {50,80,20};
    int n = sizeof(arr)/sizeof(int);

    root = insertNode(&root,root,arr[0]);
    printf("After inserting %d, Level Order : ",arr[0]);
    levelOrder(root);
    for (int i=1;i<n;i++){
        insertNode(&root,root,arr[i]);
        printf("\nAfter inserting %d, Level Order : ",arr[i]);
        levelOrder(root);
    }

    printf("\n          TRAVERSALS      \n");
    
    printf("Inorder : ");
    inorder(root);
    printf("\nPreorder : ");
    preorder(root);
    printf("\nPostorder : ");    
    postorder(root);
    printf("\nLevelorder :");
    levelOrder(root); 

    DeleteAVL(&root,root,100);
    printf("\nAfter deletion of 100 Levelorder :");
    levelOrder(root);

    DeleteAVL(&root,root,50);
    printf("\nAfter deletion of 50 Levelorder :");
    levelOrder(root);

    DeleteAVL(&root,root,10);
    printf("\nAfter deletion of 10 Levelorder :");
    levelOrder(root);



    destroyTree(&root);
}
