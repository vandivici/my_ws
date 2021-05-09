void SWAP(int *x, int *y) {
    if (*x != *y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

void Q_sort(int *arr, int st, int end) {
    if (st >= end) // st:0, end:0 에서 무한호출. st>end 가 아니라`st>=end` 해줘야한다
        return;
    int target = arr[st];
    int left = st;
    int right = end;
    while (left < right) {
        while (target < arr[right]) // 기준점이 arr[st]라 배열범위 안벗어남
            right--;
        while (left < right && target >= arr[left])
            left++;
        SWAP(arr + left, arr + right);
    }
    SWAP(arr + st, arr + left);
    Q_sort(arr, st, left - 1);
    Q_sort(arr, left + 1, end);
}