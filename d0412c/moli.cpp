#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll p[37];
ll n;
int m;
ll global_resu = 0;

void dfs(int id, int cnt, ll number) {
    if (number > n) return;
    if (id == m) {
        if (number > 1)
            global_resu += (cnt & 1) ? (n / number) : (-n / number);
        return;
    }
    dfs(id + 1, cnt++, number);
    dfs(id + 1, cnt--, number * p[id]);
}

int main() {
    scanf("%I64d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%I64d", p + i);
    }
    sort(p, p + m);
    ll *cur = unique(p, p + m);
    m = cur - p;
    dfs(0, 0, 1);
    printf("%I64d\n", global_resu);
    return 0;
}

