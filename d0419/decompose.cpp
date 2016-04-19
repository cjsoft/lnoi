#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int sequence[10007];
int n;
void pp(int pos) {
    for (int i = 0; i < pos; i++) {
        printf("%d", sequence[i]);
        if (i != pos - 1) putchar('+');
    }
    putchar('\n');
}
void dfs(int pos, int left, int stp) {
    if (left == 0) {
        pp(pos);
        return;
    }
    if (left < 0) return;
    for (int i = stp; i < n; i++) {
        sequence[pos] = i;
        dfs(pos + 1, left - i, i);
    }
}
int main() {
    freopen("decompose.in", "r", stdin);
    freopen("decompose.out", "w", stdout);
    scanf("%d", &n);
    dfs(0, n, 1);
    return 0;
}
