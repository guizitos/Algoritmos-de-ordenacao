void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Bubble Sort
void bubbleSort(int arr[], int n, int* numComparisons, int* numSwaps) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) {     
       for (j = 0; j < n-i-1; j++) { 
           (*numComparisons)++;
           if (arr[j] > arr[j+1]) {
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
              (*numSwaps)++;
           }
       }
   }
}

// Insertion Sort
void insertionSort(int arr[], int n, int* numComparisons, int* numSwaps) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
       while (j >= 0 && arr[j] > key) {
           (*numComparisons)++;
           arr[j + 1] = arr[j];
           j = j - 1;
           (*numSwaps)++;
       }
       arr[j + 1] = key;
   }
}

// Selection Sort
void selectionSort(int arr[], int n, int* numComparisons, int* numSwaps) {
   int i, j, min_idx;
   for (i = 0; i < n-1; i++) {
       min_idx = i;
       for (j = i+1; j < n; j++) {
         (*numComparisons)++;
         if (arr[j] < arr[min_idx])
           min_idx = j;
       }
       swap(&arr[min_idx], &arr[i]);
       (*numSwaps)++;
   }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

