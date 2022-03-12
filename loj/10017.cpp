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
double ax, ay, bx, by, cx, cy, dx, dy, p, q, r, lab, lcd;
inline pair<double, double> locate(pair<double, double> a,
                                   pair<double, double> b, double k) {
  return make_pair((b.fi - a.fi) * k + a.fi, (b.se - a.se) * k + a.se);
}
inline double getdis(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.fi - b.fi, 2) + pow(a.se - b.se, 2));
}
double f(double x, double y) {
  auto f = locate({ax, ay}, {bx, by}, x);
  auto e = locate({cx, cy}, {dx, dy}, y);
  return getdis(f, {ax, ay}) / p + getdis({dx, dy}, e) / q + getdis(f, e) / r;
}
double eva(double x) {
  double l = 0, r = 1;
  while (fabs(r - l) > eps) {
    double dl = l + (r - l) / 3, dr = r - (r - l) / 3;
    if (f(x, dl) > f(x, dr)) {
      l = dl;
    } else
      r = dr;
  }
  return f(x, l);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> p >> q >> r;
  //   cout << ax << ay << bx << by << cx << cy << dx << dy << p << q << r;
  double l = 0, r = 1;
  lab = getdis({ax, ay}, {bx, by}), lcd = getdis({cx, cy}, {dx, dy});
  while (fabs(r - l) > eps) {
    double dl = l + (r - l) / 3, dr = r - (r - l) / 3;
    if (eva(dl) > eva(dr)) {
      l = dl;
    } else
      r = dr;
  }
  printf("%.2lf", eva(l));
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