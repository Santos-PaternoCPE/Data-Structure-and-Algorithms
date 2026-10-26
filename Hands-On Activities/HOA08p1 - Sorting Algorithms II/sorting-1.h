#ifndef SORTING_H
#define SORTING_H

// Procedure:
void shellSort(int arr[], int size){
    for (int gap = size / 2; gap > 0; gap = gap / 2){
        for (int i = gap; i < size; i++){
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }
}

void merging(int arr[], int left, int middle, int right){
    int i = left;
    int j = middle + 1;
    int k = 0;
    int temp[100];
    
    while (i <= middle && j <= right){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }
}


void mergeSort(int arr[], int left, int right){
    if (left < right){
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merging(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Supplementary Task:
void dispArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int arr[], int low, int high){
    for (int i = low + 1; i <= high; i++){
        int temp = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
#endif
