void quickSort(int a[], int left, int right) {
    int index = partition(a, left, right);
    if (left < index-1) quickSort(a, left, index-1);
    if (index < right) quickSort(a, index, right);
}
int partition(int a[], int left, int right) {
    int pivot = a[(left + right) / 2]; 
    while (left <= right) {
        // Find element on left that should be on right
        while (a[left] < pivot) left++;
        // Find element on right that should be on left
        while (a[right] > pivot) right--;
        // Swap elements, and move left and right indeices
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left;
}
