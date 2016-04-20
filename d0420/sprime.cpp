#include <iostream>
#include <cmath>
#include <cstdio>
int n;
bool isprime(int x) {
    if (x == 1) return 0;
    int q = sqrt(x);
    for (int i = 2; i <= q; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int sequence[11];
void dfs(int pos, int num) {
    if (pos == n) {
        for (int i = 0; i < pos; i++) {
            putchar((char)sequence[i] + 48);
        }
        putchar('\n');
        return;
    }
    if (pos == 0) {
        sequence[pos] = 2;
        dfs(pos + 1, 2);
    }
    for (int i = 1; i < 10; i += 2) {
        if (isprime(num * 10 + i)) {
            sequence[pos] = i;
            dfs(pos + 1, num * 10 + i);
        }
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}
