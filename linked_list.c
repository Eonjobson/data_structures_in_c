#include<stdio.h>
#include<malloc.h>
#include<stdlib.h> 
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *start = NULL;
    struct node *create_ll(struct node *);
    struct node *display( struct node *);
    struct node *insert_start(struct node * );
    struct node *insert_end(struct node *);
    struct node *insert_before(struct node *);
    struct node *insert_after(struct node *);
    struct node *delete_start(struct node *);
    struct node *delete_end(struct node *);
    struct node *delete_node(struct node *);
    struct node *delete_after(struct node *);
    struct node *delete_list(struct node *);
    struct node *sort_list(struct node *);
    int main()
    { return 0;}
    struct node *create_ll(struct node *start)
    {
        struct node *new_node,*ptr;
        int num;
        printf("\nenter -1 to end");
        printf("\n enter data");
        scanf("%d",&num);
        while(num!=-1)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node ->data=num;
            if(start==NULL)
            {
                new_node->next=NULL;
                start = new_node;
            }
            else
            {
                ptr = start;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                    ptr->next=new_node;
                    new_node->next=NULL;
                }
                printf("\n enter data");
                scanf("%d",&num);
            }
        }
        return start;
    }
    struct node * display(struct node* start)
    {
        struct node *ptr;
        ptr = start;
        while(ptr!=NULL)
        {
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
        return start;
    }
    struct node* insert_start(struct node* start)
    {
        struct node* new_node;
        int num;
        printf("\nenter data: ");
        scanf("%d",&num);
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = start;
        start = new_node;
        return start;

    }
    struct node* insert_end(struct node* start)
    {
        struct node* new_node;
        struct node* ptr;
        ptr = start;
        int num;
        printf("enter data: ");
        scanf("%d",&num);
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=new_node;
        return start;
    }
    struct node *insert_before(struct node *start)
    {
        struct node* new_node;
        struct node* ptr;
        struct node* preptr;
        int num,val;
        printf("\nenter data");
        scanf("%d",&num);
        printf("enter value post which u wish to insert");
        scanf("%d",&val);
        ptr = start;
        preptr=ptr;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr = ptr->next;

        }
        preptr->next = new_node;
        new_node->next = ptr;
        return start;
    }
    struct node *insert_after(struct node * start)
    {
        struct node* new_node;
        struct node* ptr;
        struct node* preptr;
        int num,val;
        printf("\nenter data");
        scanf("%d",&num);
        printf("enter value post which u wish to insert");
        scanf("%d",&val);
        ptr = start;
        preptr=ptr;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        while(preptr->data!=val)
        {
            preptr=ptr;
            ptr = ptr->next;

        }
        preptr->next = new_node;
        new_node->next = ptr;
        return start;
    }
    struct node *delete_start(struct node *start)
    {
         struct node* ptr;
         ptr = start;
         start = start->next;
         free(ptr);
         return start;
    }
    struct node *delete_end(struct node *start)
    {
         struct node* ptr;
         struct node* preptr;
         ptr = start;
         while(ptr->next!=NULL)
         {
             preptr = ptr;
             ptr = ptr->next;

         }
         preptr->next = NULL;
         free(ptr);
         return start;
    }
    struct node* delete_node(struct node* start)
    {
        struct node* ptr;
        struct node* preptr;
        printf("enter value of node to be deleted");
        int val;
        scanf("%d",&val);
         ptr = start;
         if(ptr->data==val)
         {
             start = delete_start(start);
             return start;
         }
         else
         {
             while(ptr->data!=val)
             {
                 preptr = ptr;
                 ptr = ptr->next;

             }
             preptr->next = ptr->next;
             free(ptr);
             return start;
         }

    }
    struct node *delete_after(struct node *start)
    {
        struct node* ptr;
        struct node* preptr;
        printf("enter value after which the node needs to be deleted");
        int val;
        scanf("%d",&val);
         ptr = start;
         preptr = ptr;
         while(preptr->data!=val)
             {
                 preptr = ptr;
                 ptr = ptr->next;

             }
             preptr->next = ptr->next;
             free(ptr);
             return start;
    }
    struct node *delete_list(struct node *start)
    {
        struct node* ptr;
        if(start !=NULL)
        {
            ptr = start;
            while(ptr!=NULL)
            {
                start = delete_start(ptr);
                ptr=start;
            }
        }
        return start;

    }
    struct node *sort_list(struct node *start)
    {
        struct node *ptr1;
        struct node *ptr2;
        int temp;
        ptr1 = start;
        while(ptr1->next!=NULL)
        {
            ptr2 = ptr1->next;
            while(ptr2->next!=NULL)
            {
                if(ptr1->data>ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        return start;

    }






    
    
    
    
