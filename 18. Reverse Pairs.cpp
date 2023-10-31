#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0, cnt = 0;
    int temp[high - low + 1];
    int i = low, j = mid + 1;
    
    while (i <= mid && j <= high) {
        if (arr[i] > 2ll * arr[j]) {
            count += (mid - i + 1);
            j++;
        } else {
            i++;
        }
    }
    
    i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[cnt++] = arr[i++];
        else
            temp[cnt++] = arr[j++];
    }
    
    while (i <= mid) {
        temp[cnt++] = arr[i++];
    }
    
    while (j <= high) {
        temp[cnt++] = arr[j++];
    }
    
    cnt = 0;
    for (int k = low; k <= high; k++) {
        arr[k] = temp[cnt++];
    }
    
    return count;
}

int mergesort(vector<int>& arr, int low, int high) {
    int count = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }
    return count;
}

int reversePairs(vector<int> &arr, int n) {
    return mergesort(arr, 0, n - 1);
}
