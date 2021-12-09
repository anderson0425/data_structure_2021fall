#include <stdio.h>
#include <stdlib.h>

//---------------------------------//
//每個node擁有一個next pointer
//有一個head pointer指向開頭的node(將開頭的node視為在最左邊)
//最尾端的node(視為在最右邊)擁有的next pointer指向NULL
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

void print_SLL(node *x){
    if(x != NULL){
        printf("%d->", x->data);
        print_SLL(x->next);
    }
    else{
        printf("null");
    }
}

//計算現在linked list內的node數目
int count_SLL(single_linked_list *SLL){
    int num=0;
    node *head_tmp = SLL -> head;

    while(head_tmp!=NULL){
        num++;
        head_tmp = head_tmp->next;
    }
    return num;
}

//算出如何分配節點數目給k個小串
//6 K=10-->0/0/0/0/0/0/0/0/0/0-->1/1/1/1/1/1/0/0/0/0
//6 K=2-->3/3
//6 K=4-->1/1/1/1-->2/2/1/1
//10 K=3-->3/3/3-->4/3/3
//10 K=2-->5/5
//10 K=4-->2/2/2/2-->3/3
//10 K=6-->1/1/1/1/1/1-->2/2/2/2/1/1
//10 K=8-->1/1/1/1/1/1/1/1-->2/2/1/1/1/1/1/1
int*  divide_k(int node_number, int k){
    int base;
    printf("\nnode_number is : %d\nK is: %d\n", node_number, k);
    base = node_number/k;  // 10/8=1
    node_number = node_number - base*k; //10-8*1=2

    //這裡動態生成array，大小為k個int
    //上次hw有程式碼
    //int arrange[k]={0};
    int *arrange = NULL;
    arrange = (int*)malloc(sizeof(int) * k);

    for(int i=0; i<k; i++){
        arrange[i] = base;
    }

    for(int i=0; i<k; i++){
        if(node_number<=0){
            break;
        }
        arrange[i] += 1;
        node_number--;
    }

    //for(int i=0; i<k; i++){
    //    printf("%d", arrange[i]);
    //}

    return arrange;
}



//形成k串sub-linked-list
//算出如何分配節點數目給k個小串
//123456 K=10-->1/2/3/4/5/6/ / / / /
//123456 K=2-->123/456
//123456 K=4-->2/2/2/2-->3/3/2/2
void divide_k_parts(single_linked_list *SLL, int k){
    int node_number = count_SLL(SLL);//求出節點總數目
    //printf("\nnode_number is : %d\nK is: %d\n", node_number, k);

    int* arrange = NULL;
    arrange = divide_k(node_number, k);

    //printf("\nprint arrangement\n");
    //for(int i=0; i<k; i++){
    //    printf("%d  ", arrange[i]);
    //}
    //printf("\n");

    node *head_tmp = SLL -> head;
    node *tmp1 = NULL;
    node *tmp2 = NULL;

    node **new_head = NULL;
    new_head = (node**)malloc(sizeof(node*) * k);
    node **new_last = NULL;
    new_last = (node**)malloc(sizeof(node*) * k);
    //1個指向k個node pointers的pointer
    //node *new_head[k] = NULL;
    //node *new_last[k] = NULL;

    int index_arrange = 0;
    while(head_tmp!=NULL){ //當已經將原本的linked list都已經分解完了，則head==NULL成立，跳出while
        tmp1 = head_tmp;
        for(int i=0; i<arrange[index_arrange]-1; i++)//執行(arrange[i]-1)次的右移
            tmp1 = tmp1->next;
        tmp2 = tmp1;
        tmp1 = tmp1->next;
        new_head[index_arrange] = head_tmp;
        head_tmp = tmp1;
        tmp2->next = NULL;
        new_last[index_arrange] = tmp2;
        tmp2 = NULL;
        index_arrange++;
    }
    //printf("\nindex_arrange: %d\n", index_arrange);
    int index_arrange_tmp = index_arrange;
    for(; index_arrange_tmp<k; index_arrange_tmp++){
        new_head[index_arrange_tmp] = NULL;
        new_last[index_arrange_tmp] = NULL;
    }


    printf("\n>>>>>>>start print result.............\n");
    //此時new_head, new_last都擁有一個個sub-linked-list，若還有new_head, new_last沒有element，則沒關係，很正常，因為題目就是這樣設計規則。
    for(int i=0;i<k;i++){
        printf("\n");
        printf("print sub-linked-list (%d) : .....head->", i+1);
        //if(new_head[i]==NULL){
            //printf("null (empty sub-linked-list)");
        //    printf("null");
        //}
        //else{
        //    //printf("new_head[i]->data: ...%d", new_head[i]->data);
        //    print_SLL(new_head[i]);
        //}
        print_SLL(new_head[i]);


    }

    //return SLL;
}










int main(void) {
    single_linked_list *SLL = new_single_linked_list();

    int node_num = 0; //記錄節點數目，最多104

    for(;;){
        printf("\n\nenter 0, 1\n>>0 for insert (between 0~1000),\n>>and 1 for divide linked list for K parts(problem 5 required)\n");
        int select = 0;

        scanf("%d", &select);
        switch (select){

            case 0: //insert

                printf(">>insert.............\n");
                printf("please enter the value for new node\n");
                int key=0;
                scanf("%d", &key);
                if(count_SLL(SLL)<=1000){//節點數目在1000以內
                    if(key>=0 && key<=1000){ //節點值在0~1000
                        node* new = new_node(key);
                        insert(SLL, new);
                        printf("insert success\n");

                        printf("\nprint_linked list:.....head->");
                        print_SLL(SLL->head);

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


            case 1: //divide linked list for K part----problem 5 required
                printf("\n>>divide linked list for K part----problem 5 required.............\n");
                printf("enter a number for K (between 1~50)\n");
                int k=0;
                scanf("%d", &k);
                if(k>=1 && k<=50){ //節點值在1~50
                    divide_k_parts(SLL, k); //problem 5 required
                    printf("\n");
                    return 0;
                }
                else
                    printf("\ninvalid value for k\n");

                break;
            default:
                printf("invalid input(please enter 0 or 1)\n");
                break;
        }
    }
    return 0;
}
