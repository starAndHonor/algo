#include <bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long  //__int128
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
const int MAXN = (int)5e5 + 3;

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
int n, m;
struct rann {
  pair<int, int> val;
  int len;
};
rann ran[MAXN];
int a[MAXN << 2], cnt;

struct node {
  int val = 0;
  int tag = 0;
} tr[MAXN << 2];
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
inline int& val(int x) { return tr[x].val; }
inline int& tag(int x) { return tr[x].tag; }
inline void pushdown(int p) {
  tag(ls(p)) += tag(p);
  tag(rs(p)) += tag(p);
  val(ls(p)) += tag(p);
  val(rs(p)) += tag(p);
  tag(p) = 0;
}
inline void pushup(int p) { val(p) = max(val(ls(p)), val(rs(p))); }
inline void build(int p, int cl, int cr) {
  val(p) = 0;
  tag(p) = 0;
  if (cl == cr) {
    return;
  }
  int cmid = cl + cr >> 1;
  build(ls(p), cl, cmid);
  build(rs(p), cmid + 1, cr);
  pushup(p);
}
inline void update(int l, int r, int d, int p, int cl, int cr) {
  if (cl >= l && cr <= r) {
    val(p) += d;
    tag(p) += d;
    return;
  }
  int cmid = cl + cr >> 1;
  pushdown(p);
  if (l <= cmid) update(l, r, d, ls(p), cl, cmid);
  if (r > cmid) update(l, r, d, rs(p), cmid + 1, cr);
  pushup(p);
}
inline int query() { return val(1); }
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ran[i].val.first >> ran[i].val.second;
    ran[i].len = ran[i].val.second - ran[i].val.first;
    a[++cnt] = ran[i].val.first;
    a[++cnt] = ran[i].val.second;
  }
  sort(a + 1, a + 1 + cnt);

  int len = unique(a + 1, a + 1 + cnt) - a - 1;

  // in and reflection
  sort(ran + 1, ran + 1 + n, [](auto a, auto b) { return a.len < b.len; });
  int lp = 0, rp = 0;
  for (int i = 1; i <= n; i++) {
    ran[i].val.first = lower_bound(a + 1, a + 1 + len, ran[i].val.first) - a;
    ran[i].val.second = lower_bound(a + 1, a + 1 + len, ran[i].val.second) - a;
  }
  int ans = INF;
  build(1, 1, len);
  int t = 0;
  while (1) {
    while (rp <= n && query() < m) {
      rp++;
      if (rp <= n) update(ran[rp].val.first, ran[rp].val.second, 1, 1, 1, len);
    }
    if (query() < m) {
      break;
    }
    while (lp <= n && query() >= m) {
      lp++;
      update(ran[lp].val.first, ran[lp].val.second, -1, 1, 1, len);
    }
    ans = min(ans, ran[rp].len - ran[lp].len);
  }
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
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