#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){
    int i=0;
    int n=0;
    //int a[9]={11,12,13,14,15,16,17,18,19};

    int a[9]={0};
    printf("Enter 9 Number:  ");
    int k=0;
    while(k<9)
        scanf("%d", &a[k++]);
    printf("\n");   

    int count[9]={0};
    int b[9]={0};//order[9]
    srand((unsigned)time(NULL));
    int i3=0;
    while(1){
        int t=(rand()%8)+1;
        //printf("%d",count[t]);
        //printf("%d",i3);
        if(count[t]==0){
            count[t]+=1;
            b[i3]=t;
            //printf("%d  ", t);
            i3+=1;
            if(i3==8)
                break;
        }
    }
    printf("\n\n");
    
    int i5=0;    
    int c[9]={0};
    while(i5<9){
        //printf("%d  ", b[i5]);
        c[b[i5]] = a[i5];
        i5+=1;
    }

    int col1[3] = {0};
    int col2[3] = {0};
    int col3[3] = {0};
    for (i = 0; i < 3; i++) {
        col1[i] = c[i];
        col2[i] = c[i+3];
        col3[i] = c[i+6];
    }

    printf("\nnine-square division are:\n");
    for (i = 0; i < 3; ++i) {
        printf("%10d   %10d   %10d\n", col1[i], col2[i], col3[i]);
    }

}