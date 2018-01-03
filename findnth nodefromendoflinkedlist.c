
/*Program to find the nth node from end of the linked list   */

#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next;
 }*start=NULL;
static int c=0;  //Static data type so that the value will be saved during function calls. 
 
int find(struct node *);  //Function to find the length of linked list.
void ndata(int);    //To find the nth node from end of the linked list.
 void main()
 {

 struct node *p,*temp,*temp1,*temp2;
 int i,n,k;
 clrscr();
 printf("Enter the number of nodes \n"); //Number of nodes we want 
 scanf("%d",&n);

 //Method to create n linked list
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
temp1=start;
k=find(temp1); //length of the linked list returned here
ndata(k);     //Function  called to find the nth node from end of linked list.
//printf("The length is %d",k);
 getch();
   }
   int find(struct node *p) //Function to calculate the length of linked list recursively.
   {
   if(p==NULL)
   return 0;
   else
   {
   c++;
   find(p->next);
   }
    return c;
   }
  void ndata(int x) //Function to find the nth node
  {
  int len,loc,i;
  struct node *temp;
  len=x;
  temp=start;
  printf("Enter the location \n");
  scanf("%d",&loc);
  for(i=1;i<(len-loc+1);i++) //method to reach the nth node from end fo the linked list
  temp=temp->next;
  printf("The data is %d",temp->data);
  }
