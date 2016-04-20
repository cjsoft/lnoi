#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int w[5], h[5];
int sequence[5];
bool pnttag[207][207];
struct CASE {
    int a, b;
    bool operator<(const CASE &b) const {
        return a < b.a;
    }
} cs[40007];
char tag[5];
bool PNTER = false;
int resu =  INT_MAX;
int tot = 0;
void solve() {
    int W, H;
    W = 0; H = 0;
    for (int i = 0; i < 4; i++) {
        W += w[i];
        H = std::max(H, h[i]);
    }
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
    W = 0; H = 0;
    W = std::max(w[0] + w[1] + w[2], w[3]);
    H = h[3] + std::max(h[0], std::max(h[1], h[2]));
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
    W = 0; H = 0;
    W = std::max(w[0] + w[1] + w[2], w[3]);
    H = std::max(h[2], std::max(h[0] + h[3], h[1] + h[3]));
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
    W = 0; H = 0;
    W = std::max(w[0] + w[1] + w[3], w[0] + w[2] + w[3]);
    H = std::max(h[0], std::max(h[1] + h[2], h[3]));
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
    W = 0; H = 0;
    W = std::max(w[0] + w[2] + w[3], w[1] + w[2] + w[3]);
    H = std::max(h[2], std::max(h[1] + h[0], h[3]));
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
    // W = 0; H = 0;
    // W = std::max(w[0] + w[2] + w[3], w[1] + w[2] + w[3]);
    // H = std::max(h[0] + h[1], std::max(h[2], h[3]));
    // resu = std::min(resu, W * H);
    // if (PNTER && W * H == resu && !pnttag[W][H]) {
    //     pnttag[W][H] = true;
    //     pnttag[H][W] = true;
    //     if (W > H) std::swap(W, H);
    //     cs[tot].a = W;
    //     cs[tot++].b = H;
    // }
    W = 0; H = 0;
    W = std::max(w[0] + w[1], w[2] + w[3]);
    W = std::max(W, w[0] + w[3]);
    H = std::max(h[0] + h[2], h[1] + h[3]);
    H = std::max(H, h[2] + h[1]);
    resu = std::min(resu, W * H);
    if (PNTER && W * H == resu && !pnttag[W][H]) {
        pnttag[W][H] = true;
        pnttag[H][W] = true;
        if (W > H) std::swap(W, H);
        cs[tot].a = W;
        cs[tot++].b = H;
    }
}
void dfs2(int pos) {
    if (pos == 4) {
        solve();
        return;
    }
    swap(w[pos], h[pos]);
    dfs2(pos + 1);
    swap(w[pos], h[pos]);
    dfs2(pos + 1);
}
void dfs(int pos) {
    if (pos == 4) {
        dfs2(0);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (tag[i]) continue;
        sequence[pos] = i;
        tag[i] = 1;
        dfs(pos + 1);
        tag[i] = 0;
    }
    sequence[pos] = 0;
}
int main() {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", w + i, h + i);
    }
    dfs(0);
    PNTER = true;
    printf("%d\n", resu);
    dfs(0);
    sort(cs, cs + tot);
    for (int i = 0; i < tot; ++i) {
        printf("%d %d\n", cs[i].a, cs[i].b);
    }
    return 0;
}
