#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
 }*start=NULL;

 //void fun(struct node *);
 void swap();
 void main()
 {

 struct node *p,*temp,*temp1,*temp2;
 int i,n;
 clrscr();
 printf("Enter the number of nodes \n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 p=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data \n");
 scanf("%d",&p->data);
 if(start==NULL)
 {
 start=p;
 p->next=NULL;
 }
 else
 {
  temp=start;
  while(temp->next!=NULL)
  temp=temp->next;
  temp->next=p;
  p->next=NULL;
  }
 }

 swap();
 // fun(temp1);
 temp2=start;
 while(temp2!=NULL)
 {
 printf("The data are %d \n",temp2->data);
 temp2=temp2->next;
 }
 getch();

 }
 void swap()
 {
 struct node *prevX,*currX,*prevY,*currY,*temp;
 int d1,d2,i=1;
 prevX=prevY=NULL;
 currX=currY=start;
 printf("Enter the data1 \n");
 scanf("%d",&d1);
 printf("ENter the data 2 \n");
 scanf("%d",&d2);
 if(d1==d2)
 {
 printf("Same Element \n");
 return;
 }
 while(currX && currX->data!=d1)
 {
 prevX=currX;
 currX=currX->next;
 }
 while(currY && currY->data!=d2)
 {
 prevY=currY;
 currY=currY->next;
 }
  if(currX==NULL || currY==NULL)
  {
  printf("Element not found \n");
  return;
  }
 if(prevX==NULL || currX==NULL)
 {
  temp=currY->next;
  start=currY;
  currY->next=currX->next;
  prevY->next=currX;
  currX->next=temp;

 }
 else
 {
 temp=currY->next;
 prevX->next=currY;
 currY->next=currX->next;
 prevY->next=currX;
 currX->next=temp;
 }
 }



 //printf("The data is %d ",p->data);


