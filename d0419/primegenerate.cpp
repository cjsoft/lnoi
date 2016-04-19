#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char isP[1000007];
int P[1000007];
int tot = 0;
void genP(int n) {
    memset(isP, 1, sizeof(isP));
    isP[1] = isP[0] = 0;
    tot = 0;
    for (int i = 2; i <= n; i++) {
        if (isP[i]) {
            P[tot++] = i;
        }
        for (int j = 0; j < tot; j++) {
            if (i * P[j] > n) break;
            isP[i * P[j]] = 0;
            if (i % P[j] == 0) break;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    genP(n - 1);
    for (int i = 0; i < tot; i++) {
        printf("%d", P[i]);
        if (i != tot - 1) putchar(' ');
    }
    putchar('\n');
    return 0;
}
