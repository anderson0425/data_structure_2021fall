#include <stdio.h>
#include <stdlib.h>

//�إ�node���c�A
//�åB���w�C��node��3��pointer���Vleftchild�Brightchild�Bparent
typedef struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent;
} node;

//�إ߾�ӤG����A
//�åB�����t���@�ӫ��Vroot node��pointer�C
typedef struct BT{
    node *root;
} BT;

//�ͦ��s��node�C
node* new_node(int data){
    if(data>=1 && data<=100 && num_node<=5*104 && num_node>=1){
        node *new = malloc(sizeof(node));

        new->data = data;
        new->leftchild = NULL;
        new->rightchild = NULL;
        new->parent = NULL;
        num_node++;
        return new;
    }
    else{
        printf("value for node is valid !!\n");
        return;
    }

}

//�^�Ǥ���j��
int get_bigger(int a, int b){
    if(a<b)
        return b;
    else
        return a;
}


//code for HW6
//�]��parent�֦���p��chidren value�A�ҥH�̰��I(root���V��node)�@�w�O�̤p�ȡC
//�G�A�ĤG�p�ȵo�ͦb�Proot�۳s�����kchild
void second_min(BT* tree){
    node *root_tmp = tree->root;
    if(root_tmp == NULL)//empty
        return -1;
    if(root_tmp->leftchild==NULL){//ONLY ONE
        return -1;
    }

    //AT LEAST 3 NODES
    if(root_tmp->leftchild->data  ==  root_tmp->rightchild->data){
        return -1;
    }
    else{
        int bigger = get_bigger(root_tmp->leftchild->data,  root_tmp->rightchild->data);
        printf(">>>second_largest value is: %d", bigger);
    }
}
