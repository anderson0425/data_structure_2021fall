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

void print_SLL(single_linked_list *SLL, node *x){
    if(x != NULL){
        printf("%d->", x->data);
        print_SLL(SLL, x->next);
    }
    else
        printf("null\n");
}

//這個會根據value是奇或偶，來形成2串sub-linked-list，並且最後再合成為一個linked list。
single_linked_list* odd_even_division(single_linked_list *SLL){
    node *head_tmp = SLL -> head;
    node *tmp1 = NULL;
    node *tmp2 = NULL;
    node *even = NULL; //指向只有even value的linked list的第一個element的位置
    node *odd = NULL; //指向只有odd value的linked list的第一個element的位置
    node *even_last = NULL; //指向只有even value的linked list的最後一個element的位置
    node *odd_last = NULL;  //指向只有odd value的linked list的最後一個element的位置

    tmp2 = head_tmp;

    int c=0; //當c一直是0，表示linked list原本就是empty。
    int turn = 0;  //當turn=0，表示正在處理的node為偶數index; 當turn=1，表示正在處理的node為奇數index

    while(1){
        //當原本的linked list本來就是EMPTY，則t2==NULL會成立。跳出迴圈
        //另一種狀況是: 當原本的linked list已經走到最後了，則t2==NULL會成立。跳出迴圈
        if(tmp2==NULL){
            break; //跳出迴圈
        }

        c=1;

        tmp1 = tmp2;
        tmp2 = tmp2->next;

        if(turn == 0){  //even index
            if(even == NULL){ //at first, even pointers points to a empty list
                tmp1->next == NULL;
                even = head_tmp;
                even_last = even;
            }
            else{ //even pointers points to a non-empty list
                tmp1->next = NULL;
                even_last->next = tmp1;
                even_last = tmp1;
            }
            turn =1;
        }
        else if(turn ==1){  //odd index
            if(odd == NULL){ //at first, odd pointers points to a empty list
                tmp1->next == NULL;
                odd = head_tmp;
                odd_last = odd;
            }
            else{ //odd pointers points to a non-empty list
                tmp1->next = NULL;
                odd_last->next = tmp1;
                odd_last = tmp1;
            }
            turn=0;
        }
        else{
            printf("\n??\n");
        }

        head_tmp = tmp2;
    }

    //now, even and odd both have a linked list
    //combine two linked list
    if(c==1){ //不是原本就空，則重新將head放到新的linked list的頭，再回傳head。
        head_tmp = even;
        even_last->next = odd;
        SLL -> head = head_tmp;
        return SLL;
    }
    else if (c==0){ //原本就空，則直接回傳
        return SLL;
    }
    else{ //其他不可能狀況
        printf("\nerror\n");
        return SLL;
    }
}







int main(void) {
    single_linked_list *SLL = new_single_linked_list();

    int node_num = 0; //記錄節點數目，最多104

    for(;;){
        printf("\n\nenter 0, 1 (0 for insert, and 1 for RE-CONSTRUCT linked list(problem 3 required))\n");
        int select = 0;

        scanf("%d", &select);
        switch (select){

            case 0: //insert

                printf(">>insert.............\n");
                printf("please enter the value for new node\n");
                int key=0;
                scanf("%d", &key);
                if(node_num<=104){
                    if(key>=-106 && key<=106){ //節點值在-106 ~ 106
                        node* new = new_node(key);
                        insert(SLL, new);

                        printf("\nprint_linked list:.....head->");
                        print_SLL(SLL, SLL->head);
                        printf("\ninsert success\n");
                        node_num++;
                        break;
                    }
                    else{
                        printf("\ninvalid insert\n");
                        break;
                    }
                }
                else{
                    printf("\nthe linked list is full (104 nodes)\n");
                    break;
                }


            case 1: //reverse
                printf(">>RE-CONSTRUCT linked list(problem 3 required).............\n");

                printf("\noriginal_linked list:.......head->");
                print_SLL(SLL, SLL->head);

                SLL = odd_even_division(SLL);

                printf("\nresult___linked list:.......head->");
                print_SLL(SLL, SLL->head);
                break;
            default:
                break;
        }
    }
    return 0;
}
