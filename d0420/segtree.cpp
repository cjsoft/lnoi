#include <iostream>
#include <cstdio>
#include <cstring>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define update(x) (stree[x] = stree[x << 1] + stree[x << 1 | 1])
#define mid(l, r) ((l + r) >> 1)
using namespace std;
typedef long long ll;
int n;
int q;
ll stree[1000007];
ll tag[1000007];
ll raw[1000007];
void build(int root, int l, int r) {
    if (l == r) {
        stree[root] = raw[l];
        return;
    }
    build(lson(root), l, mid(l, r));
    build(rson(root), mid(l, r) + 1, r); 
    update(root);
}
void pushdown(int root, int l, int r) {
    if (l == r) return;
    if (tag[root]) {
        tag[lson(root)] += tag[root];
        tag[rson(root)] += tag[root];
        stree[lson(root)] += tag[root] * (mid(l, r) - l + 1);
        stree[rson(root)] += tag[root] * (r - mid(l, r));
        tag[root] = 0;
    }
    update(root);
}
ll query(int root, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r<= qr) return stree[root];
    pushdown(root, l, r);
    return query(lson(root), l, mid(l, r), ql, qr) +
           query(rson(root), mid(l, r) + 1, r, ql, qr);
}
void add(int root, int l, int r, int al, int ar, ll dataadd) {
    if (l > ar || r < al) return;
    if (l >= al && r <= ar) {
        tag[root] += dataadd;
        stree[root] += (r - l + 1) * dataadd;
        return;
    }
    add(lson(root), l, mid(l, r), al, ar, dataadd);
    add(rson(root), mid(l, r) + 1, r, al, ar, dataadd);
    pushdown(root, l, r);
}
int main() {
    int a, b, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", raw + i);
    }
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &x, &a, &b);
        if (x == 1) {
            scanf("%d", &y);
            add(1, 1, n, a, b, y);
        } else {
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}