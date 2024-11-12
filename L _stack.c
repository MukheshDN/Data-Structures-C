#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next
};

struct node* head=NULL;
void push(int val){

 struct node* newNode=(struct node*)malloc(sizeof(struct node));
 newNode->data=val;
 newNode->next=head;
 head=newNode;

}


void pop(){
    struct node* temp;

   if(head==NULL){
    printf("the List is empty\n");
   }
   else{
    printf("the removed element is %d\n", head->data);
    temp=head;
    head=head->next;
    free(temp);
   }
}

void printList(){
 struct node*temp=head;
 while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
 }
 printf("NULL\n");

}
int val;
int main(){
    while(1){
        int n ;
       printf("enter the choice \n 1. to push \n 2.to pop \n 3.to display \n 4.exit ");
       scanf("%d", &n);
        switch(n){
            case 1:

               printf("enter the value to insert\n");
               scanf("%d",&val);
               push(val);
               break;
           case 2:
              pop();
              break;
           case 3:
                printList();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");



        }

    }

}
