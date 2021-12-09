// A complete working C program to
// demonstrate all insertion
// methods
#include <stdio.h>
#include <stdlib.h>

int* create_array(int n){

    // Dynamically allocate memory using malloc()
    int *ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        //printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
            ptr[i] = 0;
        }
        // Print the elements of the array
        //printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            //printf("%d  ", ptr[i]);
        }
        //printf("\n");
    }
    return ptr;
}

// A linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int a[1000]={0};
int k=0;
int s=0;

/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL
     */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the
 * given node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    /* 3. put in the data  */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
    struct Node* last;
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

int f=1;
int sf=0;
/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if(f) f=0;
    else if(!f) f=1;
    else ;

    if(!f) a[k++] = del->data;
    if(f){
        s = del->data;
        sf=1;
    }

    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

/* Driver program to test above functions*/
int main()
{
    int n=0;
    printf("enter no. of cards\n");
    scanf("%d", &n);
    int* d = create_array(n);
    for(int i=0;i<n;i++){
        d[i]= n-i;
        //printf("%d",d[i]);
    }
    printf("\n");

    /* Start with the empty list */
    struct Node* head = NULL;


    //append(&head, 0);
    for(int i=0;i<n;i++)
        push(&head, d[i]);
    printList(head);


    for(int i=0;i<n-1;){
        deleteNode(&head, head); /*delete first node*/
        deleteNode(&head, head); /*delete first node*/
        if(sf){
            append(&head, s);
        }
        printList(head);
        i++;
    }

    int* count = create_array(n+1);
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n;j++){
            if(i ==a[j] && !count[i])
                count[i]++;
        }
    }

    int r=0;
    for(int i=1;i<n+1;i++){
        //printf("%d  ", count[i]);
        if(!count[i])
            r=i;
    }
    printf("\n\n");

    printf("discard order is:  ");
    for(int i=0;i<n-1;i++){
        printf("%d ", a[i]);
    }
    printf("\nrest card is:  %d", r);

    return 0;
}
