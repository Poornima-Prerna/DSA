#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
int arr[max]={9,3,10,30,52};
char *str[max];
void insertion_sort()
{
    int i,j,temp;
    for(i=1;i<max;i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>temp)
        {
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=temp;
        
    }
   
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void int_to_str()
{
    int i;
    for(i=0;i<max;i++)
    {
        str[i]=(char*)malloc(12*sizeof(char));
        if(str[i]==NULL)
        {
            printf("memory not allocated");
            return;
        }
        sprintf(str[i],"%d",arr[i]);
    }
     for (i = 0; i < max - 1; i++) {
        for (int j = i + 1; j < max; j++) {
            char temp1[24], temp2[24];
            sprintf(temp1, "%s%s", str[i], str[j]);
            sprintf(temp2, "%s%s", str[j], str[i]);
            if (strcmp(temp1, temp2) < 0) { 
                char *temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
}}
void display()
{
    int i;
    printf("\n string is:\n");
    printf("'");
    for(i=0;i<max;i++)
    {
        printf("%s",str[i]);
    }
    printf("'");
}
void main()
{
  //  insertion_sort();
    int_to_str();
    display();
}