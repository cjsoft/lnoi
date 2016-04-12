#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
int p[37];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", p + i);
    }
    sort(p, p + m);
    int global_cnt = 0;
    for (int i = 0; i < m; i++) {
        global_cnt += n / p[i];
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            global_cnt -= n / (p[i] * p[j]);
        }
    }
    // for (int i = 0; i < m - 2; i++) {
        // for (int j = i + 1; j < m - 1; j++) {
            // for (int k = j + 1; k < m; k++) {
                // global_cnt += n / (p[i] * p[j] * p[k]);
            // }
        // }
    // }
    printf("%d\n", global_cnt);
    return 0;
}

