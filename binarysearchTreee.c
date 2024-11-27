#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* createNode( int val){
   struct node* newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=val;
   newNode->left=NULL;
   newNode->right=NULL;
   return newNode;

};


struct node* createBST(struct node* root , int val){
   if(root==NULL){
    return createNode(val);

   }
   else if( root->data>val){
    root->left=createBST(root->left, val);

   }
   else if(root->data <val){
     root-> right=createBST(root->right,val);
   }

   return root;
};


void preOrder(struct node* root){
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(struct node* root){
    if(root==NULL){
        return ;
    }

    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);

}

void postOrder(struct node* root){
    if(root==NULL){
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
     printf("%d ",root->data);
}









int main(){
    struct node* root=NULL;
    int val;
    int c;
    while(1){

        printf("\n 1.insert \n 2.preorder \n 3.inOrder \n 4.postorder \n  5. exit \n enter the choice :");
        scanf("%d", &c);
        switch (c){
         case 1:
             printf("enter the value to insert\n");
             scanf("%d", &val);
            if(root==NULL){
                root=createBST(root, val);
            }
            else{
                createBST(root,val);
            }
            break;

         case 2:
            preOrder(root);
            break;


         case 3:
            inOrder(root);
            break;

         case 4:
            postOrder(root);
            break;
         case 5:
            exit(0);
         default:
            printf("enter the correct value\n");


    }



}
}
