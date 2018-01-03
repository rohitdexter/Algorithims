/*This is the program for sorting and merging the linked list    */
/*This is same as previous two programs but in this we have combined both the programs
for more you can see my previous codes    */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
}*start1=NULL,*start2=NULL;
//int compare(struct node*,struct node*);
//void reverse(struct node **);
struct node *merge(struct node *,struct node *,struct node*);
//void print(struct node *);
//struct node *result;
void sort(struct node **);
void main()
{
int n1,n2,i,result;
struct node *p1,*p2,*temp1,*temp2,*printnode1,*printnode2,*temp3,*sorting,*res;
clrscr();
printf("Enter the number of nodes for first list \n");
scanf("%d",&n1);
printf("Enter the number of nodes for second list \n");
scanf("%d",&n2);
for(i=0;i<n1;i++)
{
p1=(struct node*)malloc(sizeof(struct node));
printf("Enter the data for first list \n");
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
}}
sorting=NULL;
for(i=0;i<n2;i++)
{
 p2=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data \n");
 scanf("%d",&p2->data);
 if(start2==NULL)
 {
 start2=p2;
 p2->next=NULL;
 }
 else
 {
 temp2=start2;
 while(temp2->next!=NULL)
 temp2=temp2->next;
 temp2->next=p2;
 p2->next=NULL;
 }}
sort(&start1);
sort(&start2);
/*temp2=start1;
while(temp2!=NULL)
{
printf("The data will be %d \n",temp2->data);
temp2=temp2->next;
} */
printnode1=merge(start1,start2,sorting);
while(printnode1!=NULL)
{
 printf("The data of node is %d \n",printnode1->data);
 printnode1=printnode1->next;
 }
getch();
}
void sort(struct node **head)
{
 struct node *prev,*current;
 prev=(*head);
 current=(*head)->next;
 while(current!=NULL)
 {
 if(current->data<prev->data)
 {
 prev->next=current->next;
 current->next=(*head);
 (*head)=current;
 current=prev;
 }
 else
 {
 prev=current;
 current=current->next;
 }}
 }
 struct node *merge(struct node *p,struct node *q,struct node *sorting)
 {
 struct node *newnode=NULL;
 if(p==NULL)
 return q;
 if(q==NULL)
 return p;
 if(p && q)
 {
 if(p->data<=q->data)
 {
 sorting=p;
 p=sorting->next;
 }
 else
 {
 sorting=q;
 q=sorting->next;
 }}
 newnode=sorting;
 while(p && q)
 {
  if(p->data<=q->data)
  {
   sorting->next=p;
   sorting=p;
   p=sorting->next;
   }
   else
   {
   sorting->next=q;
   sorting=q;
   q=sorting->next;
   }
   }
   if(p==NULL)
   sorting->next=q;
   if(q==NULL)
   sorting->next=p;
   return newnode;
   }
