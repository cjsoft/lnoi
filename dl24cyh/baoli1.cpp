#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int p[37];
int n, m;
int main() {
    freopen("moli.in", "r", stdin);
    freopen("moli.out", "w", stdout);
    scanf("%d %d", &n, &m);
    bool tag = false;
    for (int i = 0; i < m; i++) {
        scanf("%d", p + i);
        if (p[i] & 1 == 0) tag = true;
    }
    int global_cnt = 0;
    if (tag = false) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % p[j] == 0) {
                    ++global_cnt;
                    break;
                }
            }
        }
    } else {
        global_cnt += (n >> 1);
        for (int i = 1; i <= n; i += 2) {
            for (int j = 0; j < m; j++) {
                if (i % p[j] == 0) {
                    ++global_cnt;
                    break;
                }

            }
        }
    }
    printf("%d\n", global_cnt);
    return 0;
}
