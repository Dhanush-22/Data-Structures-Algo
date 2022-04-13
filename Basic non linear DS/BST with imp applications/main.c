#include "BST.h"
#include "BST.c"




/*

             [[[21]]]
            /        \      
          2           25
            \        /   \
             5      23   100         
            /  \                     
           4    11                   
               / \                    
              10  13
*/

int main()
{
    struct node *root = NULL;
    int arr[] = {21,25,2,23,100,5,4,11,10,13};
    //int arr[] = {43,7,59,6,42,63};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->left = newNode->right = NULL;
        insertNode(&root,newNode);
    }
    int count = 0;

    printf("Preorder : ");                            
    preorder(root);
    count++;
  
    printf("\nInorder : ");                            
    inorder(root);
    count++; 

    printf("\nPostorder : ");                            
    postorder(root);
    count++;

    printf("\nLevel order : ");                      
    levelOrder(root);

    printf("\nIterative inorder : ");
    itInorder(root);

    printf("\nIterative Preorder : ");
    itPreOrder(root);

    //printf("\nNo. of nodes : %d",count(root));
    //printf("\nNo. of leaf nodes : %d",countLeaf(root));
    printf("\nHeight : %d\n",height(root));
    checkAVL(root);

    printf("Number of leaf nodes : %d\n",getLeafCount(root));
    printf("Number of Full nodes : %d\n",getFullCount(root));
    

    if (searchNode(root,100)) printf("\nThe node with 100 is found");  
    else printf("\n100 is not found in BST"); 

    if (searchNode(root,99)) printf("\nThe node with 99 is found");  
    else printf("\n99 is not found in BST\n");
    
    printf("Path between 4 and 23 : ");
    pathBetweenNodes(root,4,23);
    printf("Path between 4 and 21 : ");
    pathBetweenNodes(root,4,21);
    printf("Path between 21 and 11 : ");
    pathBetweenNodes(root,21,11);
    printf("Path between 2 and 11 : ");
    pathBetweenNodes(root,2,11);
    printf("Path between 11 and 2 : ");
    pathBetweenNodes(root,11,2);

    //Deleting leaf node
    deleteNode(&root,10);
    printf("After deleting 10, the level order : ");                      
    levelOrder(root);

    //Deleting node with two children
    deleteNode(&root,25);
    printf("\nAfter deleting 25, the level order : ");                  
    levelOrder(root); 

    destroyTree(&root);
    //printf("\nAfter destroying tree, the level order : "); 
    //levelOrder(root);
    return 0;                                      
}                                                    
                                        
/*
             [[[21]]]
            /        \      
          2           25
            \        /   \
             5      23   100         
            /  \                     
           4    11                   
               / \                    
              10  13
*/