#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long left_gcd[n];
    left_gcd[0] = a[0];
    for (int i = 1; i < n; i++) {
        left_gcd[i] = gcd(left_gcd[i - 1], a[i]);
    }

    long long suf_gcd[n];
    suf_gcd[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_gcd[i] = gcd(suf_gcd[i + 1], a[i]);
    }

    long long g[n];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            g[i] = suf_gcd[1];
        } else if (i == n - 1) {
            g[i] = left_gcd[n - 2];
        } else {
            g[i] = gcd(left_gcd[i - 1], suf_gcd[i + 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%lld", g[i]);
    }
    printf("\n");

    return 0;
}
