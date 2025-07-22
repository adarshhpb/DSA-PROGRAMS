#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int queue[maxsize],r=-1,f=-1,i,n,item;
void display()
{
      i= f;
      printf("Elements: ");
      while(i<=r)
      {
        printf("%d\t",queue[i]);
        i=(i+1)%5;
      }
    }
void Enqueue()
{
 if(f==(r+1)%maxsize)
{
printf("Queue is full.\n");
}
else if(f==-1&&r==-1)
{
 r=r+1;
 f=f+1;
 printf("Enter the element:");
 scanf("%d",&n);
 queue[r]=n;
}
else
{  
r=(r+1)%maxsize;
printf("Enter the element:");
scanf("%d",&n);
queue[r]=n;
}
}
void Dequeue()
{
if(f==-1)
  {
  printf("Queue is Empty.\n");
  }
  else if(f==r)
  {
   n=queue[f];
   printf("Removed Element is :%d",n);
   f=-1;
   r=-1;
  }
  else
  {
   n=queue[f];
   printf("Removed Element is :%d",n);
   f=(f+1)%maxsize;
  }
 }
 void main()
 {
 int ch;
 while(1)
 {
 printf("\n\tMenu\t\n");
 printf("1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n");
 printf("ENTER THE CHOICE:");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: 
{
  Enqueue();
  break;
 } 
case 2:
 {
  Dequeue();
  break;
 } 
case 3:
 { 
 Display();
 break;
 } 
case 4:
 { 
 exit(0);
 break;
 } 
default:
 {
 printf("\nError No Choice Found.");
 break;
 }
 }
}
}
