#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
ll arr[1000007];
void add(int pos, ll data) {
    while (pos < 1000007) {
        // printf("%d\n", pos);
        arr[pos] += data;
        pos += lowbit(pos);
    }
}
ll sum(int pos) {
    ll rtn = 0;
    while (pos) {
        rtn += arr[pos];
        // printf("%d\n", rtn);
        pos -= lowbit(pos);
    }
    return rtn;
}
int n;
struct da {
    int d, id;
    bool operator<(const da &b) const {
        return d < b.d;
    }
} rawarr[1000007];
int locator[1000007];
int curr = 1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &rawarr[i].d);
        rawarr[i].id = i;
    }
    sort(rawarr + 1, rawarr + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (rawarr[i].d == rawarr[i - 1].d) {
            locator[rawarr[i].id] = curr;
        } else {
            locator[rawarr[i].id] = ++curr;
        }
    }
    ll rtn = 0;
    for (int i = 1; i <= n; i++) {
        add(locator[i], 1);
        rtn += sum(curr) - sum(locator[i]);
    }
    printf("%lld\n", rtn);
    return 0;
}
