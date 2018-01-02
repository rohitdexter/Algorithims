/*This  is the program for sorting the singly linked list*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
 }*start=NULL;

 
 void sort(struct node **); //Function to sort the linked list
 void main()
 {

 struct node *p,*temp,*temp1,*temp2;
 int i,n;
 clrscr();
 printf("Enter the number of nodes \n"); //Number of node you want to create
 scanf("%d",&n);

 /* here is the method to create a linked list and all the 
 new linked lists are inserting to the end of old linked lst */
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
 }  //here is the end of the method


  sort(&start); //here we have called the sorting function
  temp1=start;
  while(temp1!=NULL)
  {
  printf("The data is %d \n",temp1->data);
  temp1=temp1->next;
  }
  getch();
  }
  /* Starting of sorting linked list*/
  void sort(struct node **head)
  {
  struct  node *prev,*current;
  prev=(*head);  //its pointing the first node
  current=(*head)->next; //its pointing to second node
  while(current!=NULL)
  {
  if(current->data<prev->data) //if the second node of the linked list is bigger 
    {                            //than first linked list i.e; unsorted form then
    prev->next=current->next;
   current->next=start;
   start=current;
   current=prev;

  }
  else  // if the linked list in order then perform this
  {
  prev=current;
  current=current->next;
  }
  }
  }
