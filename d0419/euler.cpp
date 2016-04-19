#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll euler(ll n) {
    ll ans = n;
    ll m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
int main() {
    ll n;
    scanf("%lld", &n);
    ll q = sqrt(n);
    ll ans = 0;
    for (ll i = 1; i <= q; i++) {
        if (n % i == 0) {
            ans += i * euler(n / i);
            if (i * i < n) ans += n / i * euler(i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
