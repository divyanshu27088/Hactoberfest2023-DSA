int findMajorityElement(int arr[], int n) {
    int cnt = 0;
    int ele = 0;

    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            ele = arr[i];
            cnt++;
        } else if (arr[i] == ele) {
            cnt++;
        } else {
            cnt--;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele) {
            cnt1++;
        }
    }

    if (cnt1 > n / 2) {
        return ele;
    } else {
        return -1;
    }
}
