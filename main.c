
#include <stdio.h>


void swap(int* data, int i, int j){
    int tmp=0;
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void Heapify(int* array, int root, int length){
    int Left_Child = root*2 + 1;	    // The left sub-element of the root
    int Right_Child = root*2 + 2;    // The right sub-element of the root
    int Max_Node = -1;
    
    // Max_Node = MAX(root, Left_Child, Right_Child)
    if(Left_Child < length && (array[Left_Child] > array[root]))
        Max_Node = Left_Child;
    else
        Max_Node = root;
    if(Right_Child < length && (array[Right_Child] > array[Max_Node]))
        Max_Node = Right_Child;

    if(Max_Node != root){
        swap(array, root, Max_Node);
        Heapify(array, Max_Node, length);
    }
}

int* Heap_Sort(int* array, int array_length){
    
    //array -> Max Heap
    for(int i = floor(array_length/2)-1; i >= 0; i--){
        Heapify(array, i, array_length);
    }
    
    //Sorting
    for(int j = array_length - 1; j > 0; j--){
        swap(array, 0, j);
        Heapify(array, 0, j);
    }
    return array;
}
