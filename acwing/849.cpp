#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long ll;
const ll inf = (1 << 31) - 1;
int n, m, s, a, b, c;
struct edge {
  ll v;
  ll w;
};
struct node {
  ll dis, v;
  bool operator>(const node a) const { return dis > a.dis; }
};
vector<edge> gr[N];
ll dis[N];
bool vis[N];
priority_queue<node, vector<node>, greater<node>> q;
inline void init(ll l, ll r) {
  for (int i = l; i <= r; i++) gr[i].clear();
}
inline void add(ll u, ll v, ll w) { gr[u].push_back(edge{v, w}); }
bool dijkstra(ll s) {
  for (int i = 1; i <= n; i++) {
    dis[i] = inf;
  }
  dis[s] = 0;
  q.push(node{0, s});
  while (!q.empty()) {
    ll no = q.top().v;
    q.pop();
    if (vis[no]) continue;
    vis[no] = true;
    for (auto ed : gr[no]) {
      if (dis[ed.v] > dis[no] + ed.w) {
        dis[ed.v] = dis[no] + ed.w;
        q.push(node{dis[ed.v], ed.v});
      }
    }
  }
  if (dis[n] != inf)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m;
  s = 1;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    add(a, b, c);
  }
  if (dijkstra(s))
    cout << dis[n];
  else
    cout << -1;
  return 0;
}