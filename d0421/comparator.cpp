#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
struct test {
  int a;
  test(int b) {
    a = b;
  }
};
struct cmp {
  bool operator()(const test &a, const test &b) {
    return a.a < b.a;
  }
};
std::priority_queue<test, std::vector<test>, cmp> q;
int main() {
  for (int i = 10; i > 0; i--) {
    q.push(i);
  }
  while (!q.empty()) {
    printf("%d\n", q.top());
    q.pop();
  }
  return 0;
}
