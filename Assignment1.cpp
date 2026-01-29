//Ques.1)
#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;

    int index = binarySearch(arr, 0, 9, key);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found"<<endl;

    return 0;
}
//Output : 5

//--------------------------------------------------------------------

//Ques.2)
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = 6;

    mergeSort(arr1, 0, n1 - 1);
    cout << "Sorted Array 1: ";
    printArray(arr1, n1);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = 7;

    mergeSort(arr2, 0, n2 - 1);
    cout << "Sorted Array 2: ";
    printArray(arr2, n2);

    return 0;
}
//Output:Sorted Array 1: 5 6 7 11 12 13 
       //Sorted Array 2: 3 9 10 27 38 43 82 

//--------------------------------------------------------------------

//Ques.3)
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {4, 2, 6, 9, 2};
    int n = 5;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
//Output:Sorted array: 2 2 4 6 9

//--------------------------------------------------------------------

//Ques.4)
#include <iostream>
using namespace std;

int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = arr[m];

    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = arr[m + 1];

    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    int left_max = maxSubArraySum(arr, l, m);
    int right_max = maxSubArraySum(arr, m + 1, h);
    int cross_max = maxCrossingSum(arr, l, m, h);

    return maximum(maximum(left_max, right_max), cross_max);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int result = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}
//Output: 7
