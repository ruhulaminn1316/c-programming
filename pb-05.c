#include <stdio.h>

int main() {
    int n;
    long long s, d;
    scanf("%d %lld %lld", &n, &s, &d);

    long long price;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &price);

        if (s >= price) {
            printf("%d\n", i);
            return 0;
        }
        s += d;
    }

    printf("-1\n");
    return 0;
}

