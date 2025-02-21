#include <stdio.h>

long long sum_of_squares(long long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

long long find_smallest_n(long long m) {
    long long left = 1, right = 2000000, mid, result = -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (sum_of_squares(mid) >= m) {
            result = mid;
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    return result;
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int i = 1; i <= t; i++) {
        long long m;
        scanf("%lld", &m);

        long long n = find_smallest_n(m);
        printf("Case #%d: %lld\n", i, n);
    }

    return 0;
}

