#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m, k;
int fa[N], rk[N];
vector<int> gr[N];
int u, v, q[N];
bool vis[N];
inline void init(int n) {
  for (int i = 1; i <= n; i++)
    fa[i] = i, rk[i] = 1;
}
int find(int x) { return (fa[x] == x) ? x : (fa[x] = find(fa[x])); }
inline bool equal(int x, int y) { return find(x) == find(y); }
inline void merge(int x, int y) {
  int i = find(x), j = find(y);
  if (rk[i] <= rk[j])
    fa[i] = j;
  else
    fa[j] = i;
  if (rk[i] == rk[j] && i != j)
    rk[j]++;
}
inline int count(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (fa[i] == i && !vis[i])
      cnt++;
  return cnt;
}
vector<int> ans;
int main() {
  cin >> n >> m;
  init(n + 5);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    gr[u + 1].push_back(v + 1);
    gr[v + 1].push_back(u + 1);
  }
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> q[i];
    q[i]++;
    vis[q[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      for (auto j : gr[i])
        if (!vis[j])
          merge(i, j);
    }
  }
  int tmp = count(n);
  for (int i = k; i > 0; i--) {
    ans.push_back(tmp);
    tmp++;
    vis[q[i]] = false;
    for (auto j : gr[q[i]]) {
      if (!vis[j]) {
        if (!equal(j, q[i]))
          tmp--;
        merge(j, q[i]);
      }
    }
  }
  ans.push_back(count(n));
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << endl;
  }
  return 0;
}