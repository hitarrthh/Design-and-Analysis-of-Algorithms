#include <stdio.h>

struct cal {
    int max;
    int min;
};

struct cal sort(int a[], int low, int high) {
    struct cal ans, left, right;
    int mid;

    if (low == high) {
        ans.max = a[low];
        ans.min = a[low];
        return ans;
    } else if (high == low + 1) {
        if (a[low] < a[high]) {
            ans.max = a[high];
            ans.min = a[low];
        } else {
            ans.max = a[low];  
            ans.min = a[high]; 
        }
        return ans;
    }

    mid = (low + high) / 2;
    left = sort(a, low, mid);
    right = sort(a, mid + 1, high);

    ans.max = (left.max > right.max) ? left.max : right.max;
    ans.min = (left.min < right.min) ? left.min : right.min;

    return ans; 
}

int main() { 
    int a[10], i, n;
    printf("ENTER NUMBER OF ELEMENTS\n");
    scanf("%d", &n);
    printf("ENTER ELEMENTS\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int low, mid, high;
    low = 0;
    high = n - 1;
    struct cal result = sort(a, low, high);

    printf("MAXIMUM = %d\n", result.max);
    printf("MINIMUM = %d\n", result.min);

    return 0; // Added this line
}
