#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n, m;
double qpow(double a, int b) {
    if (b == 1) return a;
    double temp = qpow(a, b >> 1);
    if (b & 1) {
        return temp * temp * a;
    } else {
        return temp * temp;
    }
}
int main() {
    scanf("%d %d", &m, &n);
    double result = 0.0;
    for (int i = 1; i <= m; i++) {
        result += (qpow((double)i / m, n) - qpow((double)(i - 1) / m, n)) * i;
    }
    printf("%.12lf\n", result);
    return 0;
}
