#include <stdio.h>
#include <stdlib.h>

//global variable to count the number of nodes in the tree
//each time, insert a valid node, num_node add 1, 
//delete a valid node, num_node minus 1, 
int num_node = 0;

//建立node結構，
//並且指定每個node有3條pointer指向leftchild、rightchild、parent
typedef struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent;
} node;

//建立整個二元搜尋樹，
//並且內部含有一個指向root node的pointer。
typedef struct BST{
    node *root;
} BST;

//生成新的node。
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

//code1 for hw4 
//算出指定的node按照規則可以到達的最遠距離，儲存在max_path
void DFS(node* x, bool is_left, int &max_path, int curr_path){
    if(x == NULL) 
        return; 

    curr_path += 1;
    
    if(curr_path > max_path){
        max_path = curr_path;
    }

    node *p_next==NULL;
    if(is_left == true)
        p_next = x->leftchild;
    if(is_left == false)
        p_next = x->rightchild;    

    DFS(p_next, !is_left, max_path, curr_path);

    return;
}

//code2 for hw4 
//這個回傳的integer值就是所求
void longestZigZag(BST* tree){
    node *tmp = tree->root;
    if(tmp == NULL) 
        return 0;
    
    int max_path = 0; 
    DFS(tmp->rightchild, true, max_path, 0); // L 
    DFS(tmp->leftchild, false, max_path, 0); //R
    printf("max path is: %d", max_path);

    //return max_path;
}