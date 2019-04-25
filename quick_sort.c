#include "stdio.h"

#define MAX 100

void quickSort(int a[], int low, int up);
int partion(int a[], int low, int up);

int main(){

    int n, a[MAX];

    printf("Enter the number of elements that you would like to add to the array: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter the data to be stored at %d: \n", i);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d | ", a[i]);
    }
    printf("\n");

    quickSort(a, 0, n-1);
    
    for(int i = 0; i < n; i++){
        printf("%d | ", a[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int a[], int low, int up){
    int p;

    //base case
    if(low>= up){
        return;
    }

    p = partion(a, low, up);
    quickSort(a, low, p-1); //left sublist
    quickSort(a, p+1, up); //right sublist

}

int partion(int a[], int low, int up){
    int i = low + 1;
    int j = up;
    int pivot = a[low];
    int temp;

    while(i <= j){
        while( (a[i] <= pivot) && (i < up) ){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }

        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        else{
            break;
        }
    }
    a[low] = a[j];
    a[j] = pivot;

    return j;
}