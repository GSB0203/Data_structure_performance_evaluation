#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    char data;
    struct TNode *left, *right;
}TNode;

TNode *NewNode(char data)
{
    TNode *New;
    New = (TNode*)malloc(sizeof(TNode));
    New->data = data;
    New->left = NULL;
    New->right= NULL;
    return New;
}

TNode *search_Node(TNode *root, char data)
{
    if (root != NULL) {
        if (root->data==data) {
            return root;
        }
        else {
            TNode *tmp = search_Node(root->left,data);
            if (tmp != NULL) {
                return tmp;
            }

            return search_Node(root->right,data);
        }
    }
    return NULL;
}

void insert_Node(TNode *root,char data,char left,char right)
{
    root->data = data;
    if (left != '.')
    {
        root->left = NewNode(left);
    }
    if (right != '.')
    {
        root->right = NewNode(right);
    }
}
 
void preorder(TNode* root)
{
    if(root){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TNode* root)
{
    if(root){        
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(TNode* root)
{
    if(root){        
        postorder(root->left);        
        postorder(root->right);
        printf("%c", root->data);
    }
}
 
 
int main()
{
    TNode *root = NewNode(NULL);
    TNode *tmp;
    int n;
    int i;
    scanf("%d", &n);
    getchar();
    for (i = 0;i < n;i++)
    {
        char data, left, right;
        scanf("%c %c %c", &data, &left, &right);
        getchar();
        tmp = search_Node(root, data);
        if (tmp != NULL)
            insert_Node(tmp, data, left, right);
        else
        insert_Node(root,data,left,right);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}