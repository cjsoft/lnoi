#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char s[1000007];
int leng[1000007];
int main() {
    freopen("mao.in", "r", stdin);
    freopen("mao.out", "w", stdout);
    scanf("%s", s + 1);
    int tlen = strlen(s + 1);
    for (int i = 1; i <= tlen; i++) {
        leng[i] = s[i - 1] == s[i] ? leng[i - 1] + 1 : 1;
    }
    int m = 1;
    for (int i = 1; i <= tlen; i++) {
        m = std::max(m, leng[i]);
    }
    printf("%d\n", m);
}
