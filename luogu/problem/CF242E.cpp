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
#define ls p << 1
#define rs p << 1 | 1
namespace segtr {
int n;
int tr[MAXN << 2][21];
int tag[MAXN << 2];
int a[MAXN];
inline void pushup(int p) {
  for (int i = 0; i < 20; i++) tr[p][i] = tr[ls][i] + tr[rs][i];
}
inline void build(int p = 1, int cl = 1, int cr = n) {
  if (cl == cr) {
    for (int i = 0; i < 20; i++) {
      if ((a[cl] >> i) & 1) tr[p][i] = 1;
    }
    return;
  }
  int cmid = cl + cr >> 1;
  build(ls, cl, cmid);
  build(rs, cmid + 1, cr);
  pushup(p);
}
inline void pushdown(int p, int cl, int cr) {
  int cmid = cl + cr >> 1;
  for (int i = 0; i < 20; i++) {
    if ((tag[p] >> i) & 1) {
      tr[ls][i] = (cmid + 1 - cl) - tr[ls][i];
      tr[rs][i] = (cr - cmid) - tr[rs][i];
    }
  }
  tag[ls] ^= tag[p];
  tag[rs] ^= tag[p];
  tag[p] = 0;
}
inline void _xor(int l, int r, int x, int p = 1, int cl = 1, int cr = n) {
  if (l <= cl && cr <= r) {
    for (int i = 0; i < 20; i++) {
      if ((x >> i) & 1) tr[p][i] = (cr - cl + 1) - tr[p][i];
    }
    tag[p] ^= x;
    return;
  }
  int cmid = cl + cr >> 1;
  pushdown(p, cl, cr);
  if (l <= cmid) _xor(l, r, x, ls, cl, cmid);
  if (r > cmid) _xor(l, r, x, rs, cmid + 1, cr);
  pushup(p);
}
inline int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
  if (l <= cl && cr <= r) {
    int res = 0, w = 1;
    for (int i = 0; i < 20; i++) {
      res += tr[p][i] * w;
      w <<= 1;
    }
    return res;
  }
  int cmid = cl + cr >> 1, res = 0;
  pushdown(p, cl, cr);
  if (l <= cmid) res += query(l, r, ls, cl, cmid);
  if (r > cmid) res += query(l, r, rs, cmid + 1, cr);
  return res;
}
}  // namespace segtr
using namespace segtr;
int m, op, x, y, z;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build();
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> op >> x >> y;
    if (op == 1)
      cout << query(x, y) << endl;
    else
      cin >> z, _xor(x, y, z);
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