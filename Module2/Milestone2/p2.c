/*
### Linked list based Challenges
* Create a linked list for Complex numbers
	* Write function to add complex number to a linked list
		* At beginning
		* At End
		* In between
	* Write function to print all the elements in a linked list

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct complex_num complex_num;
struct complex_num
{
    int real;
    int img;
};
typedef struct node node; 
struct node
{
    complex_num c_num;
    node *next;
};

typedef struct list list;
struct list
{
    int size;
    node* head;
    node* tail;
};
list ll;
node* create_node(int val1, int val2)
{
    node *new_node = (node*)malloc(sizeof(node));
    (new_node->c_num).real = val1;
    (new_node->c_num).img = val2;
    new_node->next = NULL;
    return new_node;
}

void insert_begin(list *ll, int val1, int val2)
{
    if(ll->head==NULL)
    {
        ll->head = create_node(val1, val2);
        ll->tail = ll->head;
        ll->size = 1;
    }
    else
    {
        node* new = create_node(val1, val2);
        new->next = ll->head;
        ll->head = new;
        ll->size+=1;
    }
}

void insert_end(list *ll, int val1, int val2)
{
    if(ll->head == NULL)
    {
        ll->head = create_node(val1, val2);
        ll->tail = ll->head;
        ll->size = 1;
    }
    else
    {
        node* new = create_node(val1, val2);
        (ll->tail)->next = new;
        ll->tail = new;
        ll->size+=1;
    }
}

void insert_between(list *ll, int idx, int val1, int val2)
{
    if(idx>=0 && idx<=ll->size)
    {
        if(idx == 0)
        {
            insert_begin(ll, val1, val2);
        }
        else if(idx == ll->size)
        {
            insert_end(ll, val1, val2);
        }
        else
        {
            int c = 1;
            node* cur = ll->head;
            node* prev = ll->head;
            while(c!=idx-1)
            {
                cur = cur->next;
                prev = cur;
                c++;
            }
            node* new = create_node(val1, val2);
            new->next = prev->next;
            prev->next = new;
        }
    }
    else
    {
        printf("Entered position is larger than size of the linked list\n");
    }
}

void traverse(list *ll)
{
    if(ll->head==NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        node* temp = ll->head;
        while(temp->next!=NULL)
        {
            printf("[%d, %d]->",(temp->c_num).real,(temp->c_num).img);
            temp = temp->next;
        }
        printf("[%d, %d]->NULL\n",(temp->c_num).real,(temp->c_num).img);
    }
}

int main()
{
    ll.head = NULL;
    ll.tail = NULL;
    
    insert_begin(&ll, 1, 1);
    insert_end(&ll, 2, 2);
    insert_end(&ll, 3, 3);
    insert_between(&ll, 0, 0, 0);
    insert_between(&ll, 4, 5, 5);
    insert_between(&ll, 5, 6, 6);
    traverse(&ll);
    return 0;
}