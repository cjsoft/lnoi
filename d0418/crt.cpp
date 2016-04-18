#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int m1 = 23, m2 =  28, m3 = 33;
const int M1 = 28 * 33, M2 = 23 * 33, M3 = 23 * 28;
const int M = 23 * 28 * 33;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int temp = exgcd(b, a % b, x, y);
    int tx = x, ty = y;
    x = ty;
    y = tx - a / b * ty;
    return temp;
}

int mod_reverse(int a, int mod) {
    int x, y;
    exgcd(a, mod, x, y);
    // printf("%d\n", exgcd(a, mod, x, y));
    // printf("%d %d %d %d\n", a, mod, x, y);
    x %= mod;
    return x < 0 ? mod + x : x;
}

int main() {
    int a1(0), a2(0), a3(0);
    int d(0);
    scanf("%d %d %d %d", &a1, &a2, &a3, &d);
    int qw = 1;
    while (a1 != -1) {
        int q = -d + a1 * mod_reverse(M1, m1) * M1;
        q +=  a2 * mod_reverse(M2, m2) * M2;
        q +=  a3 * mod_reverse(M3, m3) * M3;
        q %= M;
        if (q <= 0) q += M;
        printf("Case %d: the next triple peak occurs in %d days.\n", qw++, q);
        scanf("%d %d %d %d", &a1, &a2, &a3, &d);
    }
}
