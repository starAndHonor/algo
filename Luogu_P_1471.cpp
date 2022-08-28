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
struct node {
  double sum;
  double powSum;
  double mark;
  node() : sum(0.0), powSum(0.0), mark(0.0) {}
  node(double _sum, double _powSum, double _mark)
      : sum(_sum), powSum(_powSum), mark(_mark) {}
} tr[MAXN << 2];
inline void pushup(int p) {
  tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
  tr[p].powSum = tr[p << 1].powSum + tr[p << 1 | 1].powSum;
}
inline void pushdown(int p, int len) {
  if (tr[p].mark) {
    tr[p << 1].powSum += 2 * tr[p].mark * tr[p << 1].sum +
                         (len - len / 2) * tr[p].mark * tr[p].mark;
    tr[p << 1 | 1].powSum += 2 * tr[p].mark * tr[p << 1 | 1].sum +
                             (len / 2) * tr[p].mark * tr[p].mark;
    tr[p << 1].sum += (len - len / 2) * tr[p].mark;
    tr[p << 1 | 1].sum += (len / 2) * tr[p].mark;
    tr[p << 1].mark += tr[p].mark;
    tr[p << 1 | 1].mark += tr[p].mark;
    tr[p].mark = 0;
  }
}
double a[MAXN];
inline void build(int p, int cl, int cr) {
  if (cl == cr)
    return tr[p] = node(a[cl], a[cl] * a[cl], 0.0), void();
  int cmid = cl + cr >> 1;
  build(p << 1, cl, cmid);
  build(p << 1 | 1, cmid + 1, cr);
  pushup(p);
}
inline void update(int l, int r, double x, int p, int cl, int cr) {
  if (l <= cl && cr <= r) {
    tr[p].mark += x;
    tr[p].powSum += 2 * x * tr[p].sum + x * x * (cr - cl + 1);
    tr[p].sum += (cr - cl + 1) * x;
    return;
  }
  pushdown(p, cr - cl + 1);
  int cmid = cl + cr >> 1;
  if (l <= cmid)
    update(l, r, x, p << 1, cl, cmid);
  if (r > cmid)
    update(l, r, x, p << 1 | 1, cmid + 1, cr);
  pushup(p);
}
inline double query1(int l, int r, int p, int cl, int cr) {
  if (l <= cl && cr <= r) {
    return tr[p].sum;
  }
  int cmid = cl + cr >> 1;
  pushdown(p, cr - cl + 1);

  if (l > cmid)
    return query1(l, r, p << 1 | 1, cmid + 1, cr);
  else if (r <= cmid)
    return query1(l, r, p << 1, cl, cmid);
  else
    return query1(l, r, p << 1 | 1, cmid + 1, cr) +
           query1(l, r, p << 1, cl, cmid);
}
inline double query2(int l, int r, int p, int cl, int cr) {
  if (l <= cl && cr <= r) {
    return tr[p].powSum;
  }
  int cmid = cl + cr >> 1;
  pushdown(p, cr - cl + 1);

  if (l > cmid)
    return query2(l, r, p << 1 | 1, cmid + 1, cr);
  else if (r <= cmid)
    return query2(l, r, p << 1, cl, cmid);
  else
    return query2(l, r, p << 1 | 1, cmid + 1, cr) +
           query2(l, r, p << 1, cl, cmid);
}
int n, m;
double k;

inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%lf", a + i);
  build(1, 1, n);
  for (int opt, l, r, i = 1; i <= m; i++) {
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1) {
      scanf("%lf", &k);
      update(l, r, k, 1, 1, n);
      //   for (int i = l; i <= r; i++) {
      // cout << "ee" << query1(i, i, 1, 1, n) << " ";
      //   }
      //   cout << endl;
    } else if (opt == 2) {
      printf("%.4f\n", query1(l, r, 1, 1, n) / (r - l + 1));
    } else {
      double t = query2(l, r, 1, 1, n) / (r - l + 1);
      double b = query1(l, r, 1, 1, n) / (r - l + 1);
      printf("%.4f\n", t - b * b);
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr);
  // cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1; //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) { //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}