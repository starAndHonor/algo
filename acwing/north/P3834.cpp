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
// // using namespace __gnu_pbds; // If using pbds don't using std!
// using ll = long long;
// // typedef long double rld; // use double pls!
// using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e6 + 3;
const int mod = 1e9 + 7;
#define cmid (cl + cr >> 1)
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
struct node {
  int l, r, val;
} tr[MAXN << 5];
int cnt, n, m, a[MAXN], rel[MAXN], ori[MAXN], c[MAXN], root[MAXN];
inline int &ls(int p) { return tr[p].l; }
inline int &rs(int p) { return tr[p].r; }
inline int &val(int p) { return tr[p].val; }
inline void pushup(int p) { val(p) = val(ls(p)) + val(rs(p)); }
inline void build(int cl = 1, int cr = n, int p = 1) {
  val(p) = 0;
  if (cl != cr)
    build(cl, cmid, (ls(p) = ++cnt)), build(cmid + 1, cr, (rs(p) = ++cnt));
}
inline void update(int x, int d, int cl, int cr, int _old, int _new) {
  if (cl == cr)
    val(_new) += d;
  else {
    ls(_new) = ls(_old), rs(_new) = rs(_old);
    (x <= cmid) ? update(x, d, cl, cmid, ls(_old), (ls(_new) = ++cnt))
                : update(x, d, cmid + 1, cr, rs(_old), (rs(_new) = ++cnt));
    pushup(_new);
  }
}
inline int kth(int k, int cl, int cr, int _old, int _new) {
  if (cl == cr) return ori[cl];
  return (val(ls(_new)) - val(ls(_old)) >= k)
             ? kth(k, cl, cmid, ls(_old), ls(_new))
             : kth(k - (val(ls(_new)) - val(ls(_old))), cmid + 1, cr, rs(_old),
                   rs(_new));
}
inline void reflect() {
  memcpy(c, a, sizeof(long long) * n);
  sort(c, c + n);
  int len = unique(c, c + n) - c;
  for (int i = 0; i < n; i++)
    rel[i] = lower_bound(c, c + len, a[i]) - c + 1, ori[rel[i]] = a[i];
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  reflect();
  build(1, n, (root[0] = ++cnt));
  for (int i = 0; i < n; i++) {
    update(rel[i], 1, 1, n, root[i], (root[i + 1] = ++cnt));
  }
  for (int x, l, r, i = 1; i <= m; i++) {
    cin >> l >> r >> x;
    cout << kth(x, 1, n, root[l - 1], root[r]) << endl;
  }
}

signed main() {
  //	ios::sync_with_stdio(false);
  //	cin.tie(nullptr);
  //	cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {
    //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}