#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST* NODE;
NODE createtree(NODE root, int item)
{
    if (root == NULL)
    {
        NODE root;
        root=(NODE)malloc(sizeof(struct BST));
        root->data = item;
        root->left = root->right = NULL;
        return root;
    }
    if (item < (root->data))
        root->left = createtree(root->left, item);
    else if (item > root->data)
        root -> right = createtree(root->right, item); 
    return root;
}
int search(NODE root, int key)
{
    if(root == NULL)
        return (printf("%d is not present\n",key));
    else
    {
        if(key==root->data)

            return (printf("%d is present\n",key));

        else if(key>root->data)
            search(root->right,key);
        else
        search(root->left,key);
    }
}
int noofnodes(NODE root)
{
    int c=0;
    if(root==NULL)
        return c;
    c++;
    c = c + noofnodes(root->right);
    c = c + noofnodes(root->left);
    return c;
}
int leafnodes(NODE root)
{
    int c=0;
    if(root==NULL)
        return c;
    if(root->right==NULL && root->left==NULL)
        c++;
    c=c+leafnodes(root->right); 
    c=c+leafnodes(root->left);
    return c;
}
int MAX(NODE root)
{
    if(root->right==NULL)
        return root->data;
    MAX(root->right);
}
int nonleaf(NODE root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else
        return (1 + nonleaf(root->left) + nonleaf(root->right));
}
int main()
{
    int item,key, ch, i, n; NODE root;
    while (1)
    {
        printf("\n1.Create a BST");
        printf("\n2.Count no of nodes in BST");
        printf("\n3.Count no of leafnodes");
        printf("\n4.Count no of non-leaf nodes");
        printf("\n5.print Maximum Value in BST");
        printf("\n6.Search a given key in BST");
        printf("\n7.Exit");
        printf("\nEnter your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter no of nodes to insert:");
                scanf("%d", &n);
                printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2):\n");
                for(i=0; i<n; i++)
                {
                    scanf("%d",&item);
                    root=createtree(root,item);
                }
                break;
            case 2:
                printf("\nThe no of nodes is %d\n",noofnodes(root));
                break;
            case 3:
                printf("\nThe no of leaf nodes is %d\n",leafnodes(root));
                break;
            case 4:
                printf("\nThe no of Non-leaf nodes is %d\n",nonleaf(root));
                break;
            case 5:
                printf("\nThe Maximum node is %d\n",MAX(root));
                break;
            case 6:
                printf("\nEnter the element to search:"); scanf("%d", &key);
                search(root,key);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid Choice");
                break;
            return 0;
        }
    }
}