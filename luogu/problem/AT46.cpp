#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = 100086;
void dfs(int now, int cnt) {
  if (cnt >= ans)
    return;
  if (now == m) {
    ans = min(ans, cnt);
    return;
  }
  if (now > m) {
    dfs(now - 10, cnt + 1);
    dfs(now - 5, cnt + 1);
    dfs(now - 1, cnt + 1);
  } else {
    dfs(now + 10, cnt + 1);
    dfs(now + 5, cnt + 1);
    dfs(now + 1, cnt + 1);
  }
}
int main() {
  cin >> n >> m;
  dfs(n, 0);
  cout << ans << endl;
  return 0;
}