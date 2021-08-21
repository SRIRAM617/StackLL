#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void display(struct Node *p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
void push(int element)
{
     struct Node *t;
     t=(struct Node*)malloc(sizeof(struct Node));
     if(t==NULL){printf("\nStack Overflow\n");}
  else if(t!=NULL)
  {


      t->data=element;
      t->next=top;
      top=t;
  }

}
int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("\nStack Underflow\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;

}
int peak(int pos)
{
    struct Node *t;
    int x=-1,i;
    t=top;
    for(i=0;i<pos-1;i++)
    {
        top=top->next;
    }
    x=top->data;
    top=t;
    return x;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display(top);
    printf("%d",pop());
    return 0;
}
