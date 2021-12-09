#include <stdio.h>
#include <stdlib.h>

//---------------------------------//
//�C��node�֦��@��next pointer
//���@��head pointer���V�}�Y��node(�N�}�Y��node�����b�̥���)
//�̧��ݪ�node(�����b�̥k��)�֦���next pointer���VNULL
//---------------------------------//

//�إ�node���c�A
//�åB���w�C��node��1��pointer���Vnext node
typedef struct node{
    int data;
    struct node *next;
} node;

//�إ߾��single_linked_list�A
//�åB�����t���@�ӫ��Vhead node��pointer�C
typedef struct single_linked_list{
    node *head;
} single_linked_list;

//�إߤ@�ӦW�٬�new_node��function: �ͦ��s��node�C
node* new_node(int data){
    node *new = malloc(sizeof(node));

    new->data = data;
    new->next = NULL;

    return new;
}

//�إߤ@�ӷs��single_linked_list
//�����u���إ߫��V�o��single_linked_list��head node��pointer�Ӥw�C
//SLL->head = NULL;
//(��ܱNsingle_linked_list�֦���head pointer���VNULL)
single_linked_list*  new_single_linked_list(void){
    single_linked_list *SLL = malloc(sizeof(single_linked_list));  //head�O�@�ӫ��Vsingle_linked_list��head node��pointer

    SLL->head = NULL;

    return SLL;
}


//�p�G�n�إ�
//head--> 1 -> 2 -> 3 -> 4 -> 5 -->NULL
//�h��J���Ǭ�:1 2 3 4 5 (�����k��)
void insert(single_linked_list *SLL, node *new){
    node *y = NULL;
    node *tmp = SLL -> head;

    if(tmp==NULL){   //��single_linked_list�èS������node�A�]���Nsingle_linked_list��head���V�o�ӷs��node
        SLL->head = new;
        return;
    }

    //��tmp����NULL(��y�L�k�A���U�訫)�A�h���X�j��C
    //����y���linked list�̧��ݪ�node.
    while(tmp != NULL){
        y=tmp;
        tmp = tmp->next;
    }
    y->next = new; //linked list�̧��ݪ�node�|�N���֦���next pointer����V�s�i�Ӫ�node�C
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

//�p��{�blinked list����node�ƥ�
int count_SLL(single_linked_list *SLL){
    int num=0;
    node *head_tmp = SLL -> head;

    while(head_tmp!=NULL){
        num++;
        head_tmp = head_tmp->next;
    }
    return num;
}

//��X�p����t�`�I�ƥص�k�Ӥp��
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

    //�o�̰ʺA�ͦ�array�A�j�p��k��int
    //�W��hw���{���X
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



//�Φ�k��sub-linked-list
//��X�p����t�`�I�ƥص�k�Ӥp��
//123456 K=10-->1/2/3/4/5/6/ / / / /
//123456 K=2-->123/456
//123456 K=4-->2/2/2/2-->3/3/2/2
void divide_k_parts(single_linked_list *SLL, int k){
    int node_number = count_SLL(SLL);//�D�X�`�I�`�ƥ�
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
    //1�ӫ��Vk��node pointers��pointer
    //node *new_head[k] = NULL;
    //node *new_last[k] = NULL;

    int index_arrange = 0;
    while(head_tmp!=NULL){ //��w�g�N�쥻��linked list���w�g���ѧ��F�A�hhead==NULL���ߡA���Xwhile
        tmp1 = head_tmp;
        for(int i=0; i<arrange[index_arrange]-1; i++)//����(arrange[i]-1)�����k��
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
    //����new_head, new_last���֦��@�ӭ�sub-linked-list�A�Y�٦�new_head, new_last�S��element�A�h�S���Y�A�ܥ��`�A�]���D�شN�O�o�˳]�p�W�h�C
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

    int node_num = 0; //�O���`�I�ƥءA�̦h104

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
                if(count_SLL(SLL)<=1000){//�`�I�ƥئb1000�H��
                    if(key>=0 && key<=1000){ //�`�I�Ȧb0~1000
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
                if(k>=1 && k<=50){ //�`�I�Ȧb1~50
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
