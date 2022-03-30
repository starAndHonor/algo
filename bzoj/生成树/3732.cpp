#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long  //__int128
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
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR
// DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
// x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int fa[MAXN];
int d[MAXN], p[MAXN][23];
inline void init(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline bool query(int x, int y) { return find(x) == find(y); }
inline void merge(int x, int y) { return void(fa[find(x)] = find(y)); }
vector<int> gr[MAXN];
struct edge {
  int u, v, w;
} e[MAXN << 1];
int n, m;
int cnt = 0;
int nw[MAXN];
inline void add(int x, int y) {
  gr[x].push_back(y);
  gr[y].push_back(x);
}
inline void KruRebuild() {
  cnt = n;
  sort(e + 1, e + m + 1, [](auto a, auto b) { return a.w < b.w; });
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    u = find(u), v = find(v);
    if (u != v) {
      ++cnt;
      nw[cnt] = w;
      fa[cnt] = cnt;
      merge(u, cnt);
      merge(v, cnt);
      add(u, cnt), add(v, cnt);
    }
  }
}
void dfs(int u, int fa) {
  d[u] = d[fa] + 1;
  // cout << u;
  p[u][0] = fa;
  for (int i = 1; i <= __lg(d[u]); i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  for (auto v : gr[u]) {
    if (v != fa) dfs(v, u);
  }
}
int lca(int a, int b) {
  if (d[a] > d[b]) swap(a, b);
  while (d[a] != d[b]) b = p[b][__lg(d[b] - d[a])];
  if (a == b) return a;
  for (int i = __lg(d[a]); i >= 0; i--)
    if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}
int q;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  init(n);
  KruRebuild();

  dfs(cnt, 0);
  while (q--) {
    cout << nw[lca(read(), read())] << endl;
  }
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

// 2 3 5
// 1 3 5
// 2 1 6

// 1 2 6
// 5 3