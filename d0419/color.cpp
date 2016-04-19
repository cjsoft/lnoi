#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(a, i) for (edge *i = head[a]; i; i = i->prev)
using namespace std;
struct edge {
    int to;
    edge *prev;
} buf[100007], *head[107], *cur;
typedef long long ll;
int nclr[107];
int cnt = 0;
int n, k, m;
void addedge(int a, int b) {
    cur->to = b;
    cur->prev = head[a];
    head[a] = cur++;
}
inline bool check(int root) {
    iterate(root, i) {
        if (nclr[root] == nclr[i->to]) return false;
    }
    return true;
}
void dfs(int root) {
    if (root == n + 1) {
        ++cnt;
        return;
    }
    for (int i = 1; i <= m; ++i) {
        nclr[root] = i;
        if (check(root)) dfs(root + 1);
    }
    nclr[root] = 0;
}
// void pp() {
    // for (int i = 1; i <= n; i++) {
        // // puts("sd");
        // iterate(i, j) {
            // if (nclr[i] == nclr[j->to]) return;
        // }
    // }
    // ++cnt;
// }
// void dfs(int root, int mtch, int color) {
    // if (mtch == n) {
        // pp();
        // return;
    // }
    // if (nclr[root]) return;
    // nclr[root] = color;
    // // for (int i = 1; i <= m; i++) {
        // // iterate(root, j) {
            // // if (i == color) continue;
            // // dfs(j->to, mtch + 1, i);
        // // }
    // // }
    // iterate(root, j) {
        // for (int i = 1; i <= m; i++) {
            // if (i == color) continue;
            // dfs(j->to, mtch + 1, i);
        // }
    // }
    // nclr[root] = 0;
// }
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cur = buf;
    int u, v;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    // for (int i = 1; i <= m; i++) {
        // dfs(1, 1, i);
    // }
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}
