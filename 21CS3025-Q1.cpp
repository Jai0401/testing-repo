#include <iostream>
#include <vector>


using namespace std;




void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;


    vector<int> leftArr(n1);
    vector<int> rightArr(n2);


    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }


    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }


    while (i < n1) {
        arr[k++] = leftArr[i++];
    }


    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


// Find the median of the sorted array
double findMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        // If the number of elements is odd, return the middle element
        return static_cast<double>(arr[n / 2]);
    } else {
        // If the number of elements is even, return the average of the middle two elements
        int mid1 = n / 2 - 1;
        int mid2 = n / 2;
        return (static_cast<double>(arr[mid1]) + static_cast<double>(arr[mid2])) / 2.0;
    }
}


int main() {
    vector<int> arr = {7, 3, 2, 1, 4, 8};



    mergeSort(arr, 0, arr.size() - 1);



    double median = findMedian(arr);


    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\nMedian: " << median << endl;


    return 0;
}
