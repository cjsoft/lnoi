#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int tot = 0;
struct edge {
    int a, b;
    int weight;
    bool operator<(const edge &b) const {
        return weight < b.weight;
    }
} egs[10007];
int fa[107];
int getfa(int n) {
    return fa[n] == n ? n : fa[n] = getfa(fa[n]);
}
void Union(int a, int b) {
    fa[getfa(a)] = getfa(b);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        for (int j = 1; j <= n; ++j) {
            int a;
            scanf("%d", &a);
            if (i > j) {
                egs[tot].a = i;
                egs[tot].b = j;
                egs[tot++].weight = a;
            }
        }
    }
    sort(egs, egs + tot);
    int cnt = 0;
    tot = 0;
    while (n - 1) {
        if (getfa(egs[tot].a) != getfa(egs[tot].b)) {
            cnt += egs[tot].weight;
            Union(egs[tot].a, egs[tot].b);
            --n;
        }
        tot++;
    }
    printf("%d\n", cnt);
}