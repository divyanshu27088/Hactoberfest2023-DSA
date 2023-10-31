#include <bits/stdc++.h>

using namespace std;

long long merge(long long *arr, long long *temp, long long left, long long mid, long long right) {
    long long i, j, k;
    long long count = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // Increase the count
            count += (mid - i);
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

    return count;
}

long long mergeSort(long long *arr, long long *temp, long long left, long long right) {
    long long mid, count = 0;

    if (right > left) {
        mid = (right + left) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

long long getInversions(long long *arr, int n) {
    long long temp[n];
    long long ans = mergeSort(arr, temp, 0, n - 1);

    return ans;
}
