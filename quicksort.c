#include <stdio.h>
#include "quicksort.h"
#include "stack.h" 

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort_iterative(int arr[], int n){
    t_stack* stack = create_stack(n); 
    int low = 0, high = n-1;
    push(stack, low);
    push(stack, high);

    while(!is_empty(stack)){
        pop(stack, &high);
        pop(stack, &low);
        
        int pivot_index = partition(arr, low, high); 

        int left_partition_low = low;
        int left_partition_high = pivot_index - 1;
        int right_partition_low = pivot_index + 1;
        int right_partition_high = high;


        int left_size = (left_partition_high >= left_partition_low) ? (left_partition_high - left_partition_low + 1) : 0;
        int right_size = (right_partition_high >= right_partition_low) ? (right_partition_high - right_partition_low + 1) : 0;

        if (left_size > 0 && right_size > 0) {
            if (left_size < right_size) {
                push(stack, right_partition_low);
                push(stack, right_partition_high);
                push(stack, left_partition_low);
                push(stack, left_partition_high);
            } else {
                push(stack, left_partition_low);
                push(stack, left_partition_high);
                push(stack, right_partition_low);
                push(stack, right_partition_high);
            }
        } else if (left_size > 0) { 
            push(stack, left_partition_low);
            push(stack, left_partition_high);
        } else if (right_size > 0) { 
            push(stack, right_partition_low);
            push(stack, right_partition_high);
        }
    }

    destroy(stack);
}