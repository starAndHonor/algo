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
#define ls(x) tr[x].ls
#define rs(x) tr[x].rs
#define val(x) tr[x].val
#define mark(x) tr[x].mark
int L = 1, R = 1e5, cnt = 1;
int n, m;
int a[MAXN];
struct node {
  int val, mark;
  int ls, rs;
} tr[MAXN << 2];
void pushdown(int p, int len) {
  if (len <= 1) return;
  if (!ls(p)) ls(p) = ++cnt;
  if (!rs(p)) rs(p) = ++cnt;
  val(ls(p)) += mark(p) * (len / 2);
  mark(ls(p)) += mark(p);
  val(rs(p)) += mark(p) * (len - len / 2);
  mark(rs(p)) += mark(p);
  mark(p) = 0;
}
void pushup(int p) { val(p) = val(ls(p)) + val(rs(p)); }
int query(int l, int r, int p = 1, int cl = L, int cr = R) {
  if (cl >= l && cr <= r) return val(p);
  pushdown(p, cr - cl + 1);
  int cmid = (cl + cr - 1) / 2, ans = 0;
  if (cmid >= l) ans += query(l, r, ls(p), cl, cmid);
  if (cmid < r) ans += query(l, r, rs(p), cmid + 1, cr);
  return ans;
}
void update(int l, int r, int d, int p = 1, int cl = L, int cr = R) {
  if (cl >= l && cr <= r)
    return val(p) += d * (cr - cl + 1), mark(p) += d, void();
  pushdown(p, cr - cl + 1);
  int cmid = (cl + cr - 1) / 2;
  if (cmid >= l) update(l, r, d, ls(p), cl, cmid);
  if (cmid < r) update(l, r, d, rs(p), cmid + 1, cr);
  pushup(p);
}
inline void build(int p = 1, int cl = L, int cr = R) {
  ls(p) = cl, rs(p) = cr;
  if (cl == cr) return void(val(p) = a[cl]);
  int cmid = (cl + cr) / 2;
  if (cmid >= cl) {
    ls(p) = ++cnt;
    build(ls(p), cl, cmid);
  }
  if (cmid < cr) {
    rs(p) = ++cnt;
    build(rs(p), cmid + 1, cr);
  }
  pushup(p);
}

inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build();
  while (m--) {
    int o, l, r, d;
    cin >> o >> l >> r;
    if (o == 1)
      cin >> d, update(l, r, d);
    else
      cout << query(l, r) << '\n';
  }
  return;
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