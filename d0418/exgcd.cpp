#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
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
int main() {
    int a, b, x, y;
    a = 34298;
    b = 21323;
    int t = exgcd(a, b, x, y);
    printf("%d %d %d\n", t, x, y);
    return 0;
}
