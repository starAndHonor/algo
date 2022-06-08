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
int n, m;
struct node {
  int l, r;
  int val;
};
node tr[MAXN << 2];
int a[MAXN];
int cnt;
inline void build(int &p, int l, int r) {
  p = ++cnt;
  if (l == r) {
    tr[p].val = a[l];
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    build(tr[p].l, l, mid);
  } else {
    build(tr[p].r, mid + 1, r);
  }
}
inline void add(int &_old, int &_new, int l, int r, int x) {
  _new = ++cnt;
  //   tr[_new].val = tr[_old].val;
  if (l == r) {
    tr[_new].val = x;
  }
  int mid = l + r >> 1;
  if (x <= mid) {
    add(tr[_old].l, tr[_new].l, l, mid, x);
    tr[_new].r = tr[_old].r;
  } else {
    add(tr[_old].r, tr[_new].r, mid + 1, r, x);
    tr[_new].l = tr[_old].l;
  }
}
inline int query(int p, int l, int r, int x) {
  if (l == r) return tr[p].val;
  int mid = l + r >> 1, t;
  if (x <= mid) {
    t = query(tr[p].l, l, mid, x);
  } else {
    t = query(tr[p].r, mid + 1, r, x);
  }
  return t;
}
int rt[MAXN];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(rt[0], 1, n);
  int opt, x, version, y;
  for (int i = 1; i <= m; i++) {
    cin >> version >> opt >> x;
    if (opt == 1) {
      cin >> y;
      add(rt[version], rt[i], 1, n, y);
    } else {
      cout << query(rt[version], 1, n, x) << endl;
      rt[i] = rt[version];
    }
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