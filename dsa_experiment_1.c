#include <stdio.h>
void displayarray(int arr[], int size){
      for(int k=0;k<size;k++){
            printf(“%d ”,arr[k]);
      }
      printf(“\n”);
}
void bubblesort(int arr[],int size)
{
       int i,j,temp;
       for(i=0;i<size-1;i++){
             for(j=0;j<size-i-1;j++){
                   if(arr[j] > arr[j+1]){
                         temp=arr[j];
                         arr[j]=arr[j+1];
                         arr[j+1] = temp;
                  }
             }
      }
}
void selectionSort(int array[], int size) {
    int i, j, maxIndex, temp;
    for (i = 0; i < size - 1; i++) {
        maxIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] > array[maxIndex]) {
                maxIndex = j;
            }
        }
        temp = array[maxIndex];
        array[maxIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int original_array[n], array_copy[n];
    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &original_array[k]);
        array_copy[k] = original_array[k];
    }

    printf("\nOriginal array: ");
    displayarray(original_array, n);

    bubblesort(original_array, n);
    printf("Array after Bubble Sort (Ascending): ");
    displayarray(original_array, n);

    selectionSort(array_copy, n);
    printf("Array after Selection Sort (Descending): ");
    displayarray(array_copy, n);

    return 0;
}




