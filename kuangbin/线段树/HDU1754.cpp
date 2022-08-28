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
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)2e5 + 3;

inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
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
int tr[MAXN << 2];
inline const int ls(int p) { return p << 1; }
inline const int rs(int p) { return p << 1 | 1; }
int a[MAXN], n, m;
inline void pushup(int p) { tr[p] = max(tr[p << 1], tr[p << 1 | 1]); }
inline void build(int p, int cl, int cr) {
  if (cl == cr) {
    tr[p] = a[cl];
    return;
  }
  int cmid = cl + cr >> 1;
  build(ls(p), cl, cmid);
  build(rs(p), cmid + 1, cr);
  pushup(p);
}
inline void update(int d, int val, int p, int cl, int cr) {
  if (cl == cr) {
    return void(tr[p] = val);
  }
  int cmid = cl + cr >> 1;
  if (d <= cmid)
    update(d, val, p << 1, cl, cmid);
  else
    update(d, val, p << 1 | 1, cmid + 1, cr);
  pushup(p);
}
// inline int query(int d, int p, int cl, int cr) {
//   if (cl == cr) return tr[d];
//   int cmid = cl + cr >> 1;
//   if (d <= cmid)
//     return query(d, ls(p), cl, cmid);
//   else
//     return query(d, rs(p), cmid + 1, cr);
// }
inline int query(int l, int r, int p, int cl, int cr) {
  //   cout << cl << " " << cr << endl;
  if (cl >= l && cr <= r) return tr[p];
  int cmid = cl + cr >> 1, maxx = -INF;
  if (l <= cmid) maxx = max(maxx, query(l, r, p << 1, cl, cmid));
  if (r > cmid) maxx = max(maxx, query(l, r, p << 1 | 1, cmid + 1, cr));
  return maxx;
}
// int query(int l, int r, int p, int cl, int cr) {
//   if (cl >= l && cr <= r) return tr[p];
//   int cmid = cl + cr >> 1, ans = -INF;
//   if (l <= cmid) ans = max(ans, query(l, r, p << 1, cl, cmid));
//   if (r > cmid) ans = max(ans, query(l, r, p << 1 | 1, cmid + 1, cr));
//   return ans;
// }
char op;
int x, y;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
      cin >> op >> x >> y;
      if (op == 'Q') {
        cout << query(x, y, 1, 1, n) << endl;
      } else if (op == 'U') {
        update(x, y, 1, 1, n);
      }
    }
  }
  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}