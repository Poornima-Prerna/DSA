#include<stdio.h>
int queue[10];
int size=10;
int rear=-1;
int front=-1;
void enqueue(int val)
{
    if((rear+1)%size==front){
        printf("overflow \n");
    }
     if(front==-1&&rear==-1)
     {
        front=0;
        rear=0;
        queue[rear]=val;
     }
     else{
        rear=(rear+1);
     }

}