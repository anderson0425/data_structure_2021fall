#include <stdio.h>
#include <stdlib.h>

//---------------------------------//
//每個node擁有一個next pointer
//有一個head pointer指向開頭的node(將開頭的node視為在最左邊)
//最尾端的node(視為在最右邊)擁有的next pointer指向NULL
//
//反轉指的是:
// head--> 1 -> 2 -> 5 -> 8 -->NULL
// head--> 8 -> 5 -> 2 -> 1 -->NULL
//---------------------------------//

//建立node結構，
//並且指定每個node有1條pointer指向next node
typedef struct node{
    int data;
    struct node *next;
} node;

//建立整個single_linked_list，
//並且內部含有一個指向head node的pointer。
typedef struct single_linked_list{
    node *head;
} single_linked_list;

//建立一個名稱為new_node的function: 生成新的node。
//pointer *n指向新生成的node
//大小會是自定義結構node的大小，以動態配置記憶體malloc()的方式去建立。
//一開始會將輸入的value=data，傳給這個pointer *n 的data
//(n->data = data 表示將value傳給 *n指向的node的 data)
//然後將新生成的node的next這1個pointer指向沒東西的地方(指向NULL)
//n->next = NULL;
//(表示將pointer *n 指向的node擁有的next pointer指向NULL)
//回傳指向這個新生成的node的pointer n。
//每次呼叫它，都會生成一個沒有與其它node和linked list相連的node。
node* new_node(int data){
    node *new = malloc(sizeof(node));

    new->data = data;
    new->next = NULL;

    return new;
}

//建立一個新的single_linked_list
//但其實只有建立指向這個single_linked_list的head node的pointer而已。
//SLL->head = NULL;
//(表示將single_linked_list擁有的head pointer指向NULL)
single_linked_list*  new_single_linked_list(void){
    single_linked_list *SLL = malloc(sizeof(single_linked_list));  //head是一個指向single_linked_list的head node的pointer
    
    SLL->head = NULL;

    return SLL;
}


//如果要建立
//head--> 1 -> 2 -> 3 -> 4 -> 5 -->NULL
//則輸入順序為:1 2 3 4 5 (左先右後)
void insert(single_linked_list *SLL, node *new){
    node *y = NULL;
    node *tmp = SLL -> head; 

    if(tmp==NULL){   //當single_linked_list並沒有任何node，因此將single_linked_list的head指向這個新的node
        SLL->head = new;
        return;
    }

    //當tmp走到NULL(當y無法再往下方走)，則跳出迴圈。
    //此時y位於linked list最尾端的node.
    while(tmp != NULL){
        y=tmp;
        tmp = tmp->next;
    }
    y->next = new; //linked list最尾端的node會將它擁有的next pointer改指向新進來的node。
}

single_linked_list* reverse(single_linked_list *SLL){
    node *new_head = NULL;//t1
    node *old_head = NULL;//t2
    node *tmp = SLL -> head; 
    
    if(tmp==NULL) //when empty
        return;
    
    //這幾行，只在最一開始執行
    new_head = tmp;
    tmp = tmp->next;
    new_head->next = NULL;
    old_head = tmp;
        
    while(tmp->next != NULL){
        tmp = tmp->next;
        old_head->next = new_head;
        new_head = old_head;
        if(tmp->next != NULL) //當執行到最後一個時，這個不會執行
            old_head = tmp;
    }
    
    tmp->next = old_head;
    SLL->head = tmp;
    return SLL;
}

void print_SLL(single_linked_list *SLL, node *x){
    if(x != NULL){
        printf("%d->", x->data);
        print_SLL(SLL, x->next);
    }
    else
        printf("null\n");
}

int main(void) {
    single_linked_list *SLL = new_single_linked_list();

    for(;;){
        printf("\n\nenter 0, 1 (0 for insert, and 1 for reverse linked list)\n");
        int select = 0;
        
        scanf("%d", &select);
        switch (select){
            
            case 0: //insert
                printf(">>insert.............\n");
                printf("please enter the value for new node\n");
                int key=0;
                scanf("%d", &key);
                node* new = new_node(key);
                insert(SLL, new);

                printf("\n>>>print_linked list:.....head->");
                print_SLL(SLL, SLL->head);
                break;
            case 1: //reverse
                printf(">>reverse.............\n");

                printf("\n>>>original_linked list:.....head->");
                print_SLL(SLL, SLL->head);

                SLL = reverse(SLL);

                printf(">>>reversed_linked list:.....head->");
                print_SLL(SLL, SLL->head);
                printf("\n");
                return 0;
                //break;
            default:
                break;
        }
    }
    return 0;
}
