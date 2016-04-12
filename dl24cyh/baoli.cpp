#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int p[37];
int n, m;
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
int lcs(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", p + i);
    }
    int global_cnt = 0;
    for (int i = 0; i < m; i++) {
        global_cnt += n / p[i];
    }
    for (int i = 0; i <= m; i++) {
        for (int j = i + 1; j < m; j<`6:++`>) {
            global_cnt -= n / lcs(p[i], p[j]);
        }
    }
    return 0;
}
