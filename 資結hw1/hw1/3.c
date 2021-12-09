#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){
    int a[10]={0};    
    int b[2000]={0};
    printf("input 10 numbers:\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    int max=0;
    for (int i = 0; i < 10; i++){
        b[a[i]]++;
        if(max<a[i])
            max=a[i];
    }

    //printf("\n%d:\n",max);
    int sum =0;
    int i=0;
    for (int i = 0; i < 10; i++){
        if(b[a[i]]==1){
            sum+=a[i];
        }
    }
    printf("\nrest is:  %d\n",sum);
}