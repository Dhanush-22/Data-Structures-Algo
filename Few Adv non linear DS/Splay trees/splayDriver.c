#include "dec.h"
#include "Def.c"


//Driver
int main()
{
    struct node *root = NULL;
    //int arr[] = {1,2,4,3};
    int arr[] = {50,15,10,7,20};
    int n = sizeof(arr)/sizeof(int);
    
    struct node *newroot = NULL;
    for(int i=0;i<n;i++){
        insertMyNode(&newroot,newroot,arr[i]);
    }
    printf("newRoot Level order  : ");
    levelOrder(newroot);

    printf("\nLevel order : ");                      
    levelOrder(root);

    printf("\nInorder : ");                            
    inorder(root); 
    printf("\n");

    
    printf("Preorder : ");                            
    preorder(root);
  
    printf("\nPostorder : ");                            
    postorder(root);

    //Deleting leaf node
    deleteNode(&root,10);
    printf("After deleting 10, the level order : ");                      
    levelOrder(root);

    //Deleting node with two children
    deleteNode(&root,25);
    printf("\nAfter deleting 25, the level order : ");                  
    levelOrder(root); 

    destroyTree(&root);


    return 0;                                      
}                                                    
                                        
