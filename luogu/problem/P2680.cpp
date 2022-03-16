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
int n;
int h[MAXN], w[MAXN], nex[MAXN], idx, e[MAXN];
namespace st {
int tr[MAXN << 2], a[MAXN << 2], tag[MAXN << 2];
inline void pushup(int p) { tr[p] = max(tr[p << 1], tr[p << 1 + 1]); }
inline void pushdown(int p) {
  if (!tag[p]) return;
  tr[p << 1] = max(tr[p << 1], tag[p]), tag[p << 1] = max(tag[p << 1], tag[p]);
  tr[p << 1 | 1] = max(tr[p << 1 | 1], tag[p]),
              tag[p << 1 | 1] = max(tag[p << 1 | 1], tag[p]);
  tag[p] = 0;
}
inline void build(int p = 1, int l = 1, int r = n) {
  if (l == r) tr[p] = a[l];
  int mid = l + r >> 2;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
inline void update(int l, int r, int c, int p = 1, int cl = 1, int cr = n) {
  if (l >= cl && r <= cr) {
    tr[p] = max(tr[p], c), tag[p] = max(tr[p], c);
    return;
  }
  pushdown(p);
  int mid = cl + cr >> 1;
  if (l <= mid) update(l, r, c, p << 1, cl, mid);
  if (mid < r) update(l, r, c, p << 1 | 1, mid + 1, cr);
  pushup(p);
}
inline int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
  if (cl <= l && r <= cr) return tr[p];
  pushdown(p);
  int mid = cl + cr >> 1;
  int ans = -INF;
  if (l <= mid) ans = max(query(l, r, p << 1, cl, mid), ans);
  if (mid < r) ans = max(query(l, r, p << 1 | 1, mid + 1, cr), ans);
  return ans;
}
};  // namespace st
namespace zwk {
int a[MAXN], dfna[MAXN];
int N;
int tag[MAXN << 1];
int tr[MAXN << 1];
void build(int n) {
  N = 1 << (__lg(n + 5)) + 1;
  for (int i = 1; i <= n; ++i) tr[i + N] = dfna[i];
  for (int i = N; i; --i) tr[i] = tr[i << 1] + tr[i << 1 | 1];
}
void add(int u, int d) {
  for (int i = N + u; i; i >>= 1) tr[i] = d;
}
void add(int l, int r, int d) {
  int len = 1, cntl = 0, cntr = 0;
  for (l = N + l - 1, r = N + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
    tr[l] = tr[l] + d * cntl, tr[r] = tr[r] + d * cntr;
    if (~l & 1)
      tag[l ^ 1] = tag[l ^ 1] + d, tr[l ^ 1] = tr[l ^ 1] + d * len,
              cntl = cntl + len;
    if (r & 1)
      tag[r ^ 1] = tag[r ^ 1] + d, tr[r ^ 1] = tr[r ^ 1] + d * len,
              cntr = cntr + len;
  }
  for (; l; l >>= 1, r >>= 1) {
    tr[l] = tr[l] + d * cntl, tr[r] = tr[r] + d * cntr;
  }
}
int query(int l, int r) {
  int cntl = 0, cntr = 0, len = 1, ans = 0;
  for (l = N + l - 1, r = N + 1 + r; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
    if (tag[l]) ans = ans + cntl * tag[l];
    if (tag[r]) ans = ans + cntr * tag[r];
    if (~l & 1) ans = ans + tr[l ^ 1], cntl += len;
    if (r & 1) ans = ans + tr[r ^ 1], cntr += len;
  }
  for (; l; l >>= 1, r >>= 1) {
    ans = (ans + cntl * tag[l] + cntr * tag[r]);
  }
  return ans;
}
};  // namespace zwk
int fa[MAXN], dep[MAXN], sz[MAXN], id[MAXN], son[MAXN], top[MAXN], cnt,
    rk[MAXN];
inline void dfs1(int x, int rt) {
  son[x] = -1, fa[x] = rt, dep[x] = dep[rt] + 1, sz[x] = 1;
  for (int i = h[x]; ~i; i = nex[i]) {
    int y = e[i];
    if (y == rt) continue;
    dfs1(y, x);
    sz[x] += sz[y];
    if (sz[y] > sz[son[x]] || son[x] == -1) son[x] = y;
  }
}
inline void dfs2(int x, int t) {
  top[x] = t, id[x] = ++cnt, rk[id[x]] = x;
  if (son[x] == -1) return;
  dfs2(son[x], t);
  for (int i = h[x]; ~i; i = nex[i]) {
    int y = e[i];
    if (y != fa[x] && y != son[x]) dfs2(y, y);
  }
}
inline int lca(int u, int v) {
  ll ans = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] >= dep[top[v]])
      u = fa[top[u]];
    else
      v = fa[top[v]];
  }
  return dep[u] >= dep[v] ? v : u;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  memset(h, -1, sizeof(h));
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