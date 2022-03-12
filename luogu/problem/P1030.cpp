#include <bits/stdc++.h>
using namespace std;
string pro, in;
void solve(int l1, int l2, int n) {
  if (n <= 0)
    return;
  int root = l2 + n - 1;
  cout << pro[root];
  int len = in.find(pro[root]) - l1;
  solve(l1, l2, len);
  solve(l1 + len + 1, l2 + len, n - len - 1);
}
int main() {
  cin >> in >> pro;
  solve(0, 0, pro.length());
  return 0;
}