#include<stdio.h>
#define max 5
int stack[max];
int rear=-1;
int front=-1;
void enqueue(int val){
    if((rear+1)%max==front)
    {
        printf("overflow");
    }
    if(front==-1&&rear==-1){
        front=0;
        rear=0;
        stack[rear]=val;
    }
    else{
        rear=(rear+1)%max;
        stack[rear]=val;

    }
};
void display()
{
    printf("elements are:");
    for(int i=0;i<max;i++)
    {
        printf("%d\n",stack[i]);

    }
};
int main(){
    enqueue(10);
    enqueue(89);
    enqueue(679);
    enqueue(90);
    display();
    
}
  