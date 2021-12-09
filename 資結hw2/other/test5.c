#include <stdio.h>
#include <stdlib.h>

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

    for(int i=0; i<k; i++){
        printf("%d", arrange[i]);
    }

    return arrange;
}

int main(){
    int* arr = NULL;
    int node_number = 10, k=6;
    arr = divide_k(node_number, k);
    printf("\n");
    for(int i=0; i<k; i++){
        printf("%d", arr[i]);
    }
    return 0;
}