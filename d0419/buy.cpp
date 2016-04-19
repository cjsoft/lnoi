#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
int n;
int sequence[47];
int cnt = 0;
void pp() {
        for (int i = 1; i <= (n << 1); i++) {
            printf("%d", sequence[i]);
            if (i != (n << 1)) putchar(' ');
        }
        putchar('\n');
}
void dfs(int x, int y, int dta) {
    if (x == y && x == n) {
        sequence[n << 1] = dta;
        cnt++;
        pp();
        return;
    }
    if (y > x || x > n || y > n) return;
    sequence[x + y] = dta;
    dfs(x + 1, y, 0);
    dfs(x, y + 1, 1);
}

void df(int x, int y, int dta) {
    if (x == y && x == n) {
        sequence[n << 1] = dta;
        cnt++;
        return;
    }
    if (y > x || x > n || y > n) return;
    sequence[x + y] = dta;
    df(x + 1, y, 0);
    df(x, y + 1, 1);
}
int main() {
    freopen("buy.in", "r", stdin);
    freopen("buy.out", "w", stdout);
    scanf("%d", &n);
    df(1, 0, 0);
    printf("%d\n", cnt);
    dfs(1, 0, 0);
    return 0;
}
