#include <stdio.h>

void main(){
    
    int a[2000]={0};
    int n=0;
    int b[2000]={0};
    printf("Enter a Number:  ");
    scanf("%d", &n);
    printf("\n");
    int tmp = n;

    int c=2;
    int current=0;
    int max=0;
    while(n > 1){
        if(n % c == 0){
            b[c]++;
            if(c>max)
                max=c;
            //printf("%d",b[c]);
	        n /= c;
        }
        else 
            c++;
    }

    printf("\n%d:\n",tmp);
    int i=0;
    while(1){
        if(b[i]){
            printf("%d^%d",i,b[i]);
            if(i<max)
                printf(" + ");
            else
                break;
        }
        i++;
    }  
}