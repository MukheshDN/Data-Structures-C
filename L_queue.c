#include<stdio.h>
#include<stdlib.h>
struct node{

  int data;
  struct node* next;

};
struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int val){
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=val;
  newNode->next=NULL;
  if(front==NULL && rear ==NULL){
    front =rear=newNode;
  }else{
    rear->next=newNode;
    rear=newNode;

  }

}
void dequeue(){
 struct node*temp;
 if(front==NULL){
    printf("the list is empty\n");
 }else{
     printf("the removed element is %d\n",front->data);
   temp=front;
   front=front->next;
   free(temp);



 }




}
void printList(){
   struct node* temp=front;
   while (temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
   }
   printf("NULL\n");



}



int main(){
int val;
while(1){
        int n ;
       printf("enter the choice \n 1. to push \n 2.to pop \n 3.to display \n 4.exit ");
       scanf("%d", &n);
        switch(n){
            case 1:

               printf("enter the value to insert\n");
               scanf("%d",&val);
               enqueue(val);
               break;
           case 2:
              dequeue();
              break;
           case 3:
                printList();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");
            break;


        }

    }


}
