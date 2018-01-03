/*this is the program to merge two sorted linked list    */
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
 }*start=NULL,*start1=NULL;


 struct node *merge(struct node *,struct node *,struct node *); //Function to merge two linked list
 void main()
 {

 struct node *p,*temp,*temp1,*temp2,*p1,*sorting;
 int i,n1,n2;
 clrscr();
 sorting=NULL; //This is the node that will contain the whole result.
 printf("Enter the number of nodes \n");  //Enter the first sorted node.
 scanf("%d",&n1);
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
 printf("Enter the number of nodes \n"); //Enter the second sorted node
 scanf("%d",&n2);

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
 // print1();
 // print2();
 temp2=merge(start,start1,sorting); //Merge function called.
 //Fucntion to print the resultant data
 while(temp2!=NULL)
 { 
 printf("The data is %d \n",temp2->data);
 temp2=temp2->next;
 }
  getch();
  }

  struct node *merge(struct node *p,struct node *q,struct node *s)
{
  struct node *newnode; //This the head node of resultant node 
  newnode=NULL;
  if(p==NULL) //if first node is empty the result will be  second node.
  return q;
  if(q==NULL) // if second node is empty the result will be first node.
  return p; 
  if(p && q)  //if both  nodes are non-empty and data are present.
  {
  if(p->data<=q->data)  //if the data of first node is less than second node.
  {
  s=p;  //Then points the resultant to first node
  p=s->next; //and move first node to point to next node.
  }
  else
  {
  s=q;   //if the data of second node is less than first node.then the resultant points to second node 
  q=s->next; //and move second node to point to next node.
  }}
  newnode=s;  //And intialize the head of resultant node.
  while(p && q) //Now till both the nodes are present.
  {
  if(p->data<=q->data) //If the first node is small 
  {
  s->next=p; //then add the first node to resultant node
  s=p;  //now take the resultant to point to new node
  p=s->next; //and move first node to point to next node.
  }
  else
  {
  s->next=q; //if second node is small then add the second node to resultant node
  s=q;//now take the resultant to point to new node
  p=s->next; //and move first node to point to next node.
  }
  }
  if(p==NULL) //if first node is traversed completely then add the remainings of second node
  s->next=q; //to the resultant node.
  if(q==NULL)//if second node is traversed completely then add the remainings of first node
  s->next=p;//to the resultant node
  return newnode; //return the resultant node.
  }

