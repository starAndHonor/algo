#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], vis[N], ans = 0x3f3f3f3f;
int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int l = 1;
  int cnt = 0;
  for (int r = 1; r <= n; r++) {
    if (!vis[r]) {
      vis[r]++;
      cnt++;
    }
    if (cnt == m)
      ans = min(ans, r - l + 1);
  }
  return 0;
}
