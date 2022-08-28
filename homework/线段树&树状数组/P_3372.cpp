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
const int MAXN = (int)3e5 + 3;

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
int tr[MAXN << 4];
int a[MAXN];
int tag[MAXN];
inline void pushup(int p) { tr[p] = tr[p << 1] + tr[p << 1 | 1]; }

inline void build(int cl, int cr, int p) {
  if (cl == cr) return void(tr[p] = a[cl]);
  int cmid = cl + cr >> 1;
  build(cl, cmid, p << 1);
  build(cmid + 1, cr, p << 1 | 1);
  pushup(p);
}
inline void pushdown(int l, int r, int p) {
  int mid = l + r >> 1;
  tr[p << 1] += tag[p] * (mid - l + 1);
  tr[p << 1 | 1] += tag[p] * (r - mid);
  tag[p << 1] += tag[p];
  tag[p << 1 | 1] += tag[p];
  tag[p] = 0;
}
inline void update(int l, int r, int x, int cl, int cr, int p) {
  if (cl >= l && cr <= r) {
    tr[p] += (cr - cl + 1) * x;
    tag[p] += x;
    return;
  }
  int cmid = cl + cr >> 1;
  pushdown(cl, cr, p);
  if (l <= cmid) update(l, r, x, cl, cmid, p << 1);
  if (r > cmid) update(l, r, x, cmid + 1, cr, p << 1 | 1);
  pushup(p);
}
inline ll query(int l, int r, int cl, int cr, int p) {
  if (cl >= l && cr <= r) return tr[p];
  int cmid = cl + cr >> 1, ans = 0;
  pushdown(cl, cr, p);
  if (l <= cmid) ans += query(l, r, cl, cmid, p << 1);
  if (cmid < r) ans += query(l, r, cmid + 1, cr, p << 1 | 1);
  return ans;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (size_t i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  while (m--) {
    ll opt, l, r;
    cin >> opt >> l >> r;
    if (opt == 1) {
      ll d;
      cin >> d;
      update(l, r, d, 1, n, 1);
    } else
      printf("%lld\n", query(l, r, 1, n, 1));
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