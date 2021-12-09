#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* create_array(int n){

    // Dynamically allocate memory using malloc()
    int *ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        //printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
            ptr[i] = 0;
        }
        // Print the elements of the array
        //printf("The elements of the array are: ");
        for (int i = 0; i < n; ++i) {
            //printf("%d  ", ptr[i]);
        }
        //printf("\n"); 
    }
    return ptr; 
}

int** initialize_2D_array(int m, int n){
    int **ptr = (int**)malloc(m * sizeof(int *));

    for(int i = 0; i < m; i++){
        ptr[i] = (int *)malloc(n * sizeof( int));
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &ptr[i][j]); // Or *(*(arr+i)+j) 
    /*
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            printf("%d ", ptr[i][j]);
    */
    //printf("Memory successfully allocated using malloc.\n");
    return ptr; 
}

void main(){
    int m=0, n=0;
    printf("Enter m, n:  ");
    scanf("%d", &m);    scanf("%d", &n);    printf("\n"); 

    int** ma;
    ma = initialize_2D_array(m, n);//ma[m][n]

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d  ", ma[i][j]);
        }    
        printf("\n");
    }

    int *in=create_array(m);
	int *iin=create_array(m);
	int *jin=create_array(n);
    int *ax=create_array(m);
    int *iax=create_array(m);
    int *jax=create_array(n);

    for (int i = 0; i < m; i++){
        in[i]=100;
        for (int j = 0; j < n; j++){
            if(in[i]>ma[i][j]){
                in[i]=ma[i][j];
                iin[i]=i;
                jin[i]=j;
            }
        }    
        printf("\n");
    }
    
    for (int i = 0; i < m; i++){
        printf("%d   %d   %d\n", in[i], iin[i], jin[i]);
    }

    for (int j = 0; j < n; j++){
        ax[j]=0;
        for (int i = 0; i < m; i++){
            if(ax[j]<ma[i][j]){
                ax[j]=ma[i][j];
                iax[j]=i;
                jax[j]=j;
            }
        }    
        printf("\n");
    }
    

    for (int i = 0; i < n; i++){
        printf("%d   %d   %d\n", ax[i], iax[i], jax[i]);
    }   

    
    int f=0;
    for (int i = 0; i < m; i++){
        for(int j=0;j<n;j++){
            if(ax[j]==in[i]){
                printf("\nsaddle point is: %d  in index(%d, %d)\n", ax[j], iax[j], jax[j]);
                f=1;
            }
        }
    }   
    if(!f)
        printf("NO saddle point \n");
}