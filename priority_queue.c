#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
struct node *insert(struct node *start)
{
    int val,pri;
    struct node *ptr,*p;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("enter value and priority");
    scanf("%d%d",&val,&pri);
    ptr->data =val;
    ptr->priority = pri;
    if(start==NULL || pri<start->priority)
    {
        ptr->next = start;
        start = ptr;

    }
    else{
        p=start;
        while(p->next!=NULL && p->next->priority <=pri)
        {
            p=p->next;
            ptr->next = p->next;
            p->next  = ptr;
        }
    }
    return start;
}
struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        ptr = start;
        printf("value being deleted is: %d",ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}
void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if(start==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        printf("priority queue: \n");
        while(ptr!=NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
}


