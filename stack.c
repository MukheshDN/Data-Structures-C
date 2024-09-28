// Online C compiler to run C program online
#include <stdio.h>
 int top=-1;
 int n;
 
void push( int stack[],int val){
       if(top==n-1){
           printf("stack is fulled \n");
           return;
       }
       else{
           top++;
           stack[top]=val;
       }
       printf("stack elements are\n");
       for(int i=top;i>=0;i--){
           printf("%d \n",stack[i]);
       }
       printf("\n");
   }
   
int pop(int stack[]){
    if (top==-1){
        printf("under flow\n ");
        return 0;
    }
    else{
        printf("the element removed is \n");
        printf("%d \n",stack[top]);
        top--;
    }
}
   

int main() {
   printf("enter the size:");
   scanf("%d",&n);
   int stack[n];
   int d;
   char ans='y';
   while(ans=='y'|| ans=='Y'){
   printf("enter to  1 insert into the stack and enter 2 to remove elemnt from stack\n");
   scanf("%d",&d);
   switch(d){
       case 1:
         int val;
         printf("enter the value:");
         scanf("%d",&val);
         push(stack, val);
         break;
         
       case 2:
            pop(stack);
            break;
        default:
           printf("enter a valid number\n");
           break;
   }
   
   printf("do you want to continue, enter y or n");
     scanf("%s",&ans);
     if(ans =='y' || ans =='Y'){
         continue;
     }
     else{
         break;
     }
   
   }
}