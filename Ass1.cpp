//1

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] > target){
            return binarySearch(arr, low, mid - 1, target);
        }
        else{
            return binarySearch(arr, mid + 1, high, target);
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1){
        cout << "Element " << target << " is at index " << result << endl;
    } else{
        cout << "Element " << target << " not found." << endl;
    }

    return 0;
}


//2

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[50], R[50];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n1 = 6;

    mergeSort(arr, 0, n1 - 1);
    printArray(arr, n1);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = 7;

    mergeSort(arr2, 0, n2 - 1);
    printArray(arr2, n2);

    return 0;
}


//3

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {4, 2, 6, 9, 2};
    int n = 5;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

//4

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (currentSum < 0)
            currentSum = arr[i];
        else
            currentSum += arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    cout << maxSum;
    return 0;
}

















