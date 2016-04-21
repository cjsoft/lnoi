#include <iostream>
#include <cstdio>
#include <cstring>
#define mid(a, b) ((a + b) >> 1)
using namespace std;
typedef long long ll;
int SWAP[1000007];
ll mergesort(int arr[], int l, int r) {
    if (l == r) return 0;
    ll rtn = mergesort(arr, l, mid(l, r));
    rtn += mergesort(arr, mid(l, r) + 1, r);
    for (int i = l; i <= r; i++) {
        SWAP[i] = arr[i];
    }
    // for (int i = l; i <= r; i++) {
        // printf("%d ", acc[i - l]);
    // }
    int lc = l, rc = mid(l, r) + 1;
    int cur = l;
    while (lc < mid(l, r) + 1 && rc < r + 1) {
        if (SWAP[lc] <= SWAP[rc]) {
            arr[cur++] = SWAP[lc++];
            rtn += rc - mid(l, r) - 1;
        } else {
            arr[cur++] = SWAP[rc++];
        }
    }
    while (lc < mid(l, r) + 1) {
        arr[cur++] = SWAP[lc++];
        rtn += rc - mid(l, r) - 1;
    }
    while (rc < r + 1) {
        arr[cur++] = SWAP[rc++];
    }
    return rtn;
}
int a[1000007];
int main() {
    freopen("reverse.in", "r", stdin);
    freopen("reverse.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    printf("%lld\n", mergesort(a, 1, n));
    return 0;
}
