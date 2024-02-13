#include <stdio.h>

int printArray(int arr[],int size){
    int i = 0;

    for(i=0; i<5 ;i++){
        printf("%d",arr[i]);
    }
}

int main(){

    int arr[]={2,3,1,7,9};
    int size=5;

    printArray(arr,size);
    return 0;
}
