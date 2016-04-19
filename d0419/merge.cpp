#include <iostream>
#include <cstdio>
#include <cstring>
#define mid(l, r) ((l + r) >> 1)
using namespace std;
typedef long long ll;

ll mergesort(int arr[], int l, int r, int SWAP[]) {
    if (l == r) return 0;
    ll rtn = mergesort(arr, l, mid(l, r), SWAP) +
        mergesort(arr, mid(l, r) + 1, r, SWAP);
    for (int i = l; i <= r; i++) {
        SWAP[i] = arr[i];
    }
    int lc = l, rc = mid(l, r) + 1, cur = l;
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

int n;
int arr[1000007], swp[1000007];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + 1 + i);
    }
    printf("%lld\n", mergesort(arr, 1, n, swp));
    return 0;
}
