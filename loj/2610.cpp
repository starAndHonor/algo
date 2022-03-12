#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x, 0, sizeof(x))
#define mmst3f(x) memset(x, 0x3f, sizeof(x))
#define si(x) scanf("%d", &x) // scanf("%lld",&x) // When define int ll
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
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e5 + 3;

inline char nc() {
  // static char buf[100000], *p1 = buf, *p2 = buf;
  // return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 ==
  // p2)
  //            ? EOF
  //            : *p1++;
  return getchar();
}
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-')
      w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = nc();
  }
  return s * w;
}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FORDEBUG
inline void read(int &x) {
  char ch = nc();
  x = 0;
  while (!(ch >= '0' && ch <= '9'))
    ch = nc();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - 48, ch = nc();
} //
//  根据参数个数自动选择 void prt(int
// x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
struct eg {
  int u, v, w;
} egs[MAXN << 1];
namespace UF {
int fa[MAXN << 1];
inline void init(int n) {
  for (int i = 1; i <= n; i++)
    fa[i] = i;
}
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int i = find(x), j = find(y);
  fa[i] = j;
}
inline bool query(int x, int y) { return find(x) == find(y); }
} // namespace UF
namespace LCA {
struct node {
  int v, w;
};
int p[MAXN][25];
int d[MAXN];
int color[MAXN];
int dis[MAXN][25];
vector<node> gr[MAXN];
int cnt = 1;
inline void add(int u, int v, int w) {
  gr[u].push_back({v, w});
  gr[v].push_back({u, w});
}
inline void clear(int l, int r) {
  for (int i = l; i <= r; i++) {
    gr[i].clear();
  }
}
void dfs(int u, int fa, int we) {
  d[u] = d[fa] + 1;
  p[u][0] = fa;
  color[u] = cnt;
  dis[u][0] = we;
  for (int i = 1; (1 << i) <= d[u]; i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
    dis[u][i] = min(dis[u][i - 1], dis[p[u][i - 1]][i - 1]);
  }
  for (auto i : gr[u]) {
    if (i.v == fa)
      continue;
    dfs(i.v, u, i.w);
  }
}
int lca(int a, int b) {
  if (color[a] != color[b])
    return -1;
  int ans = INF;
  if (d[a] > d[b])
    swap(a, b);
  while (d[a] != d[b])
    ans = min(ans, dis[b][__lg(d[b] - d[a]) - 1]), b = p[b][__lg(d[b] - d[a])];
  if (a == b)
    return ans;
  for (int i = __lg(d[a]) - 1; i >= 0; i--) {
    if (p[b][i] != p[a][i])
      ans = min(dis[a][i], ans), ans = min(dis[b][i], ans), a = p[a][i],
      b = p[b][i];
  }
  ans = min(ans, min(dis[a][0], dis[b][0]));
  return ans;
}
} // namespace LCA
using namespace UF;
using namespace LCA;
int n, m, q;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  read(n), read(m);
  for (int i = 1; i <= m; i++) {
    read(egs[i].u);
    read(egs[i].v);
    read(egs[i].w);
  }
  sort(egs + 1, egs + m + 1, [](auto a, auto b) { return a.w > b.w; });
  init(n + 1);
  for (int i = 1; i <= m; i++) {
    if (!query(egs[i].u, egs[i].v))
      merge(egs[i].v, egs[i].u), add(egs[i].u, egs[i].v, egs[i].w);
  }
  for (int i = 1; i <= n; i++) {
    if (!color[i]) {
      cnt++;
      dfs(i, 0, 0);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= 23; j++)
  //     cout << dis[i][j];
  // }
  read(q);
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << lca(x, y) << endl;
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1; //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) { //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}
