#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, s, t, u, v, w, inf = 0x3f3f;
bool vis[N];
int dirx[] = {0, 0, 1, -1}, diry[] = {1, -1, 0, 0};
struct node {
  int to;
  int w;
};
vector<node> gr[N];
inline void add(int u, int v, int w) { gr[u].push_back({v, w}); }
bool check(int ans) {
  for (int i = 1; i <= n + 10; i++) {
    vis[i] = 0;
  }
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    for (auto i : gr[now]) {
      if (vis[i.to] || i.w > ans)
        continue;
      q.push(i.to);
      vis[i.to] = true;
    }
  }
  if (vis[t])
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  int l = 0, r = 1e7;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}