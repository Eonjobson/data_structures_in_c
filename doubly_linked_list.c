#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *start(struct node *);
struct node *create_DLL(struct node *);
struct node *display(struct node *);
struct node *insert_start(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_start(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main()
{ 

}
struct node *create_DLL(struct node *start)
{
    int num;
    struct node *new_node,*ptr;
    printf("enter -1 to stop entering\n");
    printf("enter data: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = num;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
         printf("enter data: ");
         scanf("%d",&num);

    }
    return start;

}
struct node *display(struct node *start)
{
    struct node *new_node,*ptr;
    ptr = start;
    while(ptr!=NULL)
    {  
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
struct node *insert_start(struct node *start)
{
    int num;
    struct node *new_node;
    printf("enter data: ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    start->prev=new_node;
    new_node->prev =NULL;
    new_node->next=start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    int num;
    struct node *new_node,*ptr;
    printf("enter data: ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}
struct node *insert_before(struct node *start)
{
    int num,val;
    struct node *new_node,*ptr;
    printf("enter data: ");
    scanf("%d",&num);
    printf("enter the value before which node must be inserted");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return start;
}
struct node *insert_after(struct node *start)
{
    int num,val;
    struct node *new_node,*ptr;
    printf("enter data: ");
    scanf("%d",&num);
    printf("enter the value after which node must be inserted");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}
struct node *delete_start(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev=NULL;
    free(ptr);
    return start;

}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return start;
        
}
struct node *delete_before(struct node *start)
{
    struct node *ptr,*temp;
    ptr = start;
    printf("enter the value before which the node has to be deleted");
    int val;
    scanf("%d",&val);
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    temp = ptr->prev;
    if(temp==start)
    {
        start = delete_start(start);
    
    }
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next=ptr;

    }
    free(temp);
    return start;

}
struct node *delete_after(struct node *start)
{
    struct node *ptr,*temp;
    ptr = start;
    printf("enter the value after which the node has to be deleted");
    int val;
    scanf("%d",&val);
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev=ptr;
    free(temp);
    return start;
}
struct node *delete_list(struct node *start)
{
    while(start!=NULL)
    {
        start = delete_start(start);
    }
    return start;
}









