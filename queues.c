//implemented using linked lists,eventhough arrays is easier and generally faster,however has a fixed size.
//this is a linear queue,FIFO
//implement your own main function as per requirements
#include<stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node*next;

};
struct queue
{
    struct node* front,*rear;
};
struct queue* q;
void create_queue(struct queue*);
struct queue *insert(struct queue*,int );
struct queue *delete_element(struct queue*);
struct queue *display(struct queue*);
int peek(struct queue*);
int main()
{ return 0;}
void create_queue(struct queue*q)
{
    q->rear = NULL;
    q->front = NULL;
}
struct queue *insert(struct queue*q,int val )
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    if(q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next=q->rear->next = NULL
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}
struct queue *display(struct queue*q)
{
    struct node* ptr;
    ptr = q->front;
    if(ptr==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        printf("\n");
        while(ptr!=q->rear)
        {
            printf("%d  ",ptr->data);
            ptr= ptr->next;

        }
        printf("%d\t",ptr->data);
    }
    return q;
}
struct queue *delete_element(struct queue*q)
{
    struct node*  ptr;
    ptr = q->front;
    if(q->front == NULL)
    {
        printf("\nunderflow");
    }
    else
    {
        q->front = q->front->next;
        printf("value being deleted is:  %d",ptr->data);
        free(ptr);
    }
    return q;

}
int peek(struct queue* q)
{
    if(q->front==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        return q->front->data;
    }
    
    
}



int main()
{ return 0;}