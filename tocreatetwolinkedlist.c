/*This is the program to create two linked list */

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
 }*start=NULL,*start1=NULL;

 //void fun(struct node *);
 //void swap();
 void print1();
 void print2();
 void main()
 {

 struct node *p,*temp,*temp1,*temp2,*p1;
 int i,n1,n2;
 clrscr();
 printf("Enter the number of nodes \n"); //Enter the number of nodes for first linked list
 scanf("%d",&n1);
 //Method for creating first linked list
 for(i=0;i<n1;i++)
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
 printf("Enter the number of nodes \n");  //Number of second nodes in linked list
 scanf("%d",&n2);
//Method to create second linked list.
 for(i=0;i<n2;i++)
 {
  p1=(struct node*)malloc(sizeof(struct node));
  printf("Enter the number of nodes \n");
  scanf("%d",&p1->data);
  if(start1==NULL)
  {
  start1=p1;
  p1->next=NULL;
  }
  else
  {
  temp1=start1;
  while(temp1->next!=NULL)
  temp1=temp1->next;
  temp1->next=p1;
  p1->next=NULL;
  }
  }
  print1();  //Function to print the data of first linked list
  print2();  //Function to print the data of second linked list
  getch();
  }
  void print1()  
  {
  struct node *temp;
  temp=start; //temporary variable for traversing the linked list
  while(temp!=NULL)
  {
  printf("The data of first node is %d \n",temp->data);
  temp=temp->next;
  }
  }
   void print2()
  {
  struct node *temp;
  temp=start1; //temporary variable for traversing the linked list.
  while(temp!=NULL)
  {
  printf("The data of second node is %d \n",temp->data);
  temp=temp->next;
  }
  }