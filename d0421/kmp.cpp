#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void kmp(char raw[], char pattern[]) {
    int la = strlen(raw);
    int lb = strlen(pattern);
    int *fail = new int[lb + 3];
    memset(fail, 0, 4 * lb + 12);
    for (int i = 1; i < lb; ++i) {
        int j = i;
        while (j > 0) {
            j = fail[j];
            if (pattern[i] == pattern[j]) {
                fail[i + 1] = j + 1;
                break;
            }
        }
    }
    for (int i = 0, j = 0; i < la; ++i) {
        if (j < lb && raw[i] == pattern[j]) {
            ++j;
        } else {
            while (j > 0) {
                j = fail[j];
                if (raw[i] == pattern[j]) {
                    ++j;
                    break;
                }
            }
        }
        if (j == lb) {
            printf("%d\n", i - lb + 1);
        }
    }
}

int main() {
    char a[73], b[73];
    cin >> a >> b;
    kmp(a, b);
    return 0;
}
