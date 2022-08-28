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
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e5 + 3;

inline char nc() { return getchar(); }
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
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
ull p[MAXN], ans[MAXN];
ull pp = 13331;
char s[MAXN];
int n, m;
struct node {
  ull hs;
  ull len;
} tr[MAXN << 4];
inline const auto ls(int p) { return p << 1; }
inline const auto rs(int p) { return p << 1 | 1; }
inline auto &hs(int p) { return tr[p].hs; }
inline auto &len(int p) { return tr[p].len; }
inline void pushup(int p) { hs(p) = hs(ls(p)) * ::p[len(rs(p))] + hs(rs(p)); }

inline void build(int p, int cl, int cr) {
  len(p) = cr - cl + 1;
  if (cl == cr)
    return hs(p) = s[cl], void();
  int cmid = cl + cr >> 1;
  build(ls(p), cl, cmid);
  build(rs(p), cmid + 1, cr);
  pushup(p);
}
inline void update(int d, char s, int p, int cl, int cr) {
  if (cl == cr)
    return hs(p) = s, void();
  int cmid = cl + cr >> 1;
  if (d <= cmid)
    update(d, s, ls(p), cl, cmid);
  else
    update(d, s, rs(p), cmid + 1, cr);
  pushup(p);
}
inline ull query(int l, int r, int p, int cl, int cr) {
  if (l <= cl && r >= cr)
    return hs(p);
  ull ans = 0;
  int cmid = cl + cr >> 1;
  if (r <= cmid)
    return query(l, r, ls(p), cl, cmid);
  else if (cmid < l)
    return query(l, r, rs(p), cmid + 1, cr);
  else
    return query(l, r, ls(p), cl, cmid) * ::p[min(r, cr) - cmid] +
           query(l, r, rs(p), cmid + 1, cr);
  return ans;
}
inline ull query(int l, int r) { return ans[r] - ans[l - 1] * p[r - l + 1]; }
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * pp;
    ans[i] = ans[i - 1] * pp + s[i];
  }
  build(1, 1, n);
  int opt, a, b;
  char t;
  for (int i = 1; i <= m; i++) {
    cin >> opt;
    if (opt == 1) {
      cin >> a >> t;
      update(a, t, 1, 1, n);
    } else {
      cin >> a >> b;
      cout << query(a, b, 1, 1, n) << endl;
      // cout << "baoli:" << query(a, b) << endl;
    }
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