// Task: Implement the divide-and-conquer algorithm 
// for calculating mixed-up-ness score

// =================== Libraries ==================
#include <stdio.h> // Include file for standard input/output


// =============== Helper Functions ===============
// TODO: Implement your helper functions here

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;
    int inv_count = 0;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else { 
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int merge_sort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if (right > left) {
        mid = (left + right) / 2;
        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}



// Provided below is a mixed-up-ness score.
// Name: mixedupness
// Input(s):
//    (1) 'array' is a pointer to an integer address. 
//         This is the start of some 'contiguous block of memory' that we will sort.
//    (2) 'size' tells us how big the array of data is we are sorting.
// Output: The mixedupness score of the original array
int mixedupness(int* array, unsigned int size){
  // TODO: Implement me!!
  int temp[size];
  return merge_sort(array, temp, 0, size - 1);
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {100,87,65,10,54,42,27,37};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};

  // Print out an array
  printf("dataset 1: ");
  printIntArray(dataset1, 11);
  printf("dataset 2: ");
  printIntArray(dataset2, 8);
  printf("dataset 3: ");
  printIntArray(dataset3, 11);
  printf("dataset 4: ");
  printIntArray(dataset4, 11);
  printf("dataset 5: ");
  printIntArray(dataset5, 11);
  printf("dataset 6: ");
  printIntArray(dataset6, 11);
  printf("\n");
  
  // TODO: Change these so that they print 
  // both the expected score and the calculated score
  printf("dataset 1 expected = %d, actual = %d\n", 0, mixedupness(dataset1, 11));
  printf("dataset 2 expected = %d, actual = %d\n", 23, mixedupness(dataset2, 8));
  printf("dataset 3 expected = %d, actual = %d\n", 6, mixedupness(dataset3, 11));
  printf("dataset 4 expected = %d, actual = %d\n", 55, mixedupness(dataset4, 11));
  printf("dataset 5 expected = %d, actual = %d\n", 27, mixedupness(dataset5, 11));
  printf("dataset 6 expected = %d, actual = %d\n", 18, mixedupness(dataset6, 11));
  
  return 0;
}
