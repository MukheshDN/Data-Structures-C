#include<stdio.h>
#include <ctype.h>
#include <string.h>
 int max=100;
 int top=-1;
 // push function
 void push( int stack[],char c){
   if(top==max-1){
    printf("stack overflow");
    return;
   }
   
    top++;
    stack[top]=c;
 }
 //pop function
 int pop(int stack[]){
   if(top==-1){
    printf("stack underflow");
    return -1;
   }
   return stack[top--];
 }
 // preferrence checking function
 int preference( char c){
   if(c=='+'|| c=='-'){
    return 1;
   }
   else if(c=='/'|| c=='*'){
    return 2;
   }
   return 0;
 }
 void infixtopostfix(int stack[] , char* exp){
     char postfix[max];
     int k=0;

     for(int i=0; exp[i]!='\0';i++){
            if(isalnum(exp[i])){
                    postfix[k++]=exp[i];
            }
            else if(exp[i]=='('){
                    push(stack,exp[i]);

            }
            else if(exp[i]==')'){
                while(top!=-1 && stack[top]!='('){
                        postfix[k++]=pop(stack);
                      }
                pop(stack);
            }
            else{
   
                while(top!=-1 && preference(stack[top])>=preference(exp[i])){
                    postfix[k++]=pop(stack);
                }
                push( stack ,exp[i]);
            }
            

     }
     while (top != -1) {
        postfix[k++] = pop(stack);
    }


    postfix[k]='\0';
    printf("postfix expression is %s", postfix);

 }

int main(){

     int stack[max];
    char exp[max];
    printf("enter the expression\n");
    scanf("%s",exp);

    infixtopostfix(stack ,exp);

}
