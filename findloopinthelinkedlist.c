/* Program to detect wheather here is loop or not */
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
 void loop(); //Function to check the loop
 void main()
 {

 struct node *p,*temp,*temp1,*temp2;
 int i,n;
 clrscr();
 printf("Enter the number of nodes \n"); //The number of nodes you want to create.
 scanf("%d",&n);
 //Method to create n number of linked list.
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

 temp2=start;
 //Method to create the loop by linking last node to first node i.e;last node now points to first node
 //by containing the address of first node
 while(temp2->next!=NULL)
 temp2=temp2->next;
 temp2->next=start;
 loop(); //function called 
 getch();
 }
 void loop()
 {
 int c=0;
 struct node *slow,*fast;
 slow=fast=start;
 //here we take two pointers one will be move two times and one will move for one time
 //means fast node will move two times and slow will move for one time.
 while(fast && slow && fast->next)
 {
 fast=fast->next->next;
 slow=slow->next;
 if(fast==slow) //if slow and fast both are pointing to same node then there is loop 
 {
 c=1;    //variable to check wheather condition is satisfied or not.
 break;
 }
 }
 if(c!=0)
 printf("The loop is here ");
 else
 printf("The loop is not here ");
 }
