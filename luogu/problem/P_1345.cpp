#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x, 0, sizeof(x))
#define mmst3f(x) memset(x, 0x3f, sizeof(x))
#define si(x) scanf("%d", &x)  // scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
#define fori(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define ford(a, b, c, d) for (int a = (b); a >= (c); a -= (d))
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e5 + 3;

inline char nc() { return getchar(); }
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = nc();
  }
  return s * w;
}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int n, m, e, s, t, x;
int u, v, c;
struct edge {
  int from, to;
  int cap, flow;
  int rev;
  edge() {}
  edge(int _from, int _to, int _cap, int _flow, int _rev)
      : from(_from), to(_to), cap(_cap), flow(_flow), rev(_rev) {}
};
vector<edge> gr[MAXN];
inline void add(int u, int v, int c) {
  gr[u].push_back(edge(u, v, c, 0, gr[v].size()));
  gr[v].push_back(edge(v, u, 0, 0, gr[u].size() - 1));
}
int cur[MAXN];
int d[MAXN];
queue<int> q;
inline bool bfs() {
  memset(d, -1, sizeof(d));
  mmst0(cur);
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    for (auto e : gr[now]) {
      if (d[e.to] == -1 && e.cap > e.flow) {
        d[e.to] = d[now] + 1;
        q.push(e.to);
      }
    }
  }
  return d[t] != -1;
}
inline int dfs(int now, int a) {
  if (!a || now == t) return a;
  int flow = 0;
  for (int &i = cur[now]; i < gr[now].size(); i++) {
    edge &e = gr[now][i];
    if (d[e.to] == d[now] + 1 && e.cap > e.flow) {
      int f = dfs(e.to, min(a, e.cap - e.flow));
      a -= f, flow += f, e.flow += f, gr[e.to][e.rev].flow -= f;
    }
    if (!a) break;
  }
  //   if (a) d[now] = -1;
  return flow;
}
inline int dinic() {
  int flow = 0;
  while (bfs()) {
    flow += dfs(s, INF);
  }
  return flow;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= n; i++) {
    if (i == s || s == t) {
      add(i, i + n, INF);
    } else
      add(i, i + n, 1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    add(u + n, v, INF);
    add(v + n, u, INF);
  }
  auto y = dinic();
  cout << y;
}
signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}