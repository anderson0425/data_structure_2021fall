#include <stdio.h>
#include <stdlib.h>

//建立node結構，
//並且指定每個node有3條pointer指向leftchild、rightchild、parent
//Definition for a binary tree node.
typedef struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent;
} node;

//建立整個二元搜尋樹，
//並且內部含有一個指向root node的pointer。
//Definition for a binary tree.
typedef struct BST{
    node *root;
} BST;

//建立一個名稱為new_node的function: 生成新的node。
//pointer *n指向新生成的node
//大小會是自定義結構node的大小，以動態配置記憶體malloc()的方式去建立。
//一開始會將輸入的value=data，傳給這個pointer *n 的data
//(n->data = data 表示將value傳給 *n指向的node的 data)
//然後將新生成的node的leftchild、rightchild、parent這3個pointers指向沒東西的地方(指向NULL)
//n->leftchild = NULL;
//(表示將pointer *n 指向的node擁有的leftchild pointer指向NULL)
//(其他兩個也一樣)
//回傳指向這個新生成的node的pointer n。
//每次呼叫它，都會生成一個沒有與其它node和tree相連的node。
node* new_node(int data){
    node *new = malloc(sizeof(node));

    new->data = data;
    new->leftchild = NULL;
    new->rightchild = NULL;
    new->parent = NULL;

    return new;
}

//回傳更大的值
int LARGER(int left_depth, int right_depth){
    int max = 0;
    if(left_depth>right_depth)
        max = left_depth;
    else
        max = right_depth;
    return max;
}

//code for hw1
//求出樹高的函式
void maxDepth(BST *tree){

    node *tmp = tree -> root; 

    if (tmp == NULL) 
        return 0;

    int left_depth = maxDepth(tmp->leftchild);
    int right_depth = maxDepth(tmp->rightchild);
    int depth =  LARGER(left_depth, right_depth) + 1;
    printf("the max depth of tree is: %d", depth);
    //return  (LARGER(left_depth, right_depth) + 1);
}