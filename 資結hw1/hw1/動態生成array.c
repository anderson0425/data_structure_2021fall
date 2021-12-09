#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(){
 
    int n, i;
    printf("Enter number of elements:");
    scanf("%d",&n);

    int* ptr; 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 5;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d  ", ptr[i]);
        }
    }
 
    return 0;
}