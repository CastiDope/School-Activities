#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};

struct node *root=NULL;
struct node *create(struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

int main() {
    int ch;
    do
    {
    system("cls");
    printf("\n1. Create a tree \n2. Preorder \n3. Inorder \n4. Postorder \n5. Exit ");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1: root=create(root);
        printf("Tree created ");
        break;
        case 2: printf("Preorder traversal is ");
        preorder(root);
        system("pause");
        break;
        case 3: printf("Inorder traversal is ");
        inorder(root);
        system("pause");
        break;
        case 4: printf("Postorder traversal is ");
        postorder(root);
        system("pause");
        break;
        }
    }while(ch!=5);
    return 0;
}

struct node *create(struct node *root)
    {
    struct node *ptr,*nodeptr,*parentptr;
    int val;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data ");
    scanf("%d",&val);
        ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
            if(root==NULL)
            root=ptr;
            else
            {
            parentptr=NULL;
            nodeptr=root;
            while(nodeptr!=NULL)
            {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            nodeptr=nodeptr->right;
            }
            if(val<parentptr->data)
            parentptr->left=ptr;
            else
            parentptr->right=ptr;
  }
    return root;
}

void preorder(struct node *root) {
    if(root!=NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
    }
}
    
void postorder(struct node *root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
    }
}

