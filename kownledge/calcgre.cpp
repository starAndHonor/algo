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
struct Point {
  double x, y;
};
using Vec = Point;
struct Line {
  Point P;
  Vec v;
};
struct Seg {
  Point A, B;
};
struct Circle {
  Point O;
  double r;
};
const Point O = {0, 0};

const Line Ox{O, {1, 0}}, Oy{O, {0, 1}};
const double PI = acos(-1), EPS = 1e-9;
bool eq(double a, double b) { return abs(a - b) < EPS; }
bool gt(double a, double b) { return a - b > EPS; }
bool lt(double a, double b) { return a - b < -EPS; }
bool ge(double a, double b) { return a - b > -EPS; }
bool le(double a, double b) { return a - b < EPS; }
Vec r90a(Vec v) { return {-v.y, v.x}; }
Vec r90c(Vec v) { return {v.y, -v.x}; }
bool operator<(Point A, Point B) {
  return lt(A.x, B.x) || (eq(A.x, B.x) && lt(A.y, B.y));
}
bool operator==(Point A, Point B) { return eq(A.x, B.x) && eq(A.y, B.y); }

Vec operator+(Vec a, Vec b) { return {a.x + b.x, a.y + b.y}; }
Vec operator-(Vec a, Vec b) { return {a.x - b.x, a.y - b.y}; }
Vec operator*(double k, Vec b) { return {k * b.x, k * b.y}; }
double operator*(Vec a, Vec b) { return a.x * b.x + a.y * b.y; }
double operator^(Vec a, Vec b) { return a.x * b.y - a.y * b.x; }
double len(Vec v) { return sqrt(v.x * v.x + v.y * v.y); }
double slope(Vec v) { return v.y / v.x; }
double cos_t(Vec u, Vec v) { return u * v / len(u) / len(v); }
Vec norm(Vec v) { return {v.x / len(v), v.y / len(v)}; }
Vec pnorm(Vec v) { return (v.x < 0 ? -1 : 1) / len(v) * v; }
Vec dvec(Seg l) { return l.B - l.A; }
Line line(Point A, Point B) { return {A, B - A}; }
Line line(double k, double b) { return {{0, b}, {1, k}}; }
Line line(Point P, double k) { return {P, {1, k}}; }
Line line(Seg l) { return {l.A, l.B - l.A}; }
double at_x(Line l, double x) { return l.P.y + (x - l.P.x) * l.v.y / l.v.x; }
double at_y(Line l, double y) { return l.P.x - (y + l.P.y) * l.v.x / l.v.y; }
Point pedal(Point P, Line l) {
  return l.P - (l.P - P) * l.v / (l.v * l.v) * l.v;
}
Line perp(Line l, Point p) { return {p, r90c(l.v)}; }
Line bisec(Point P, Vec u, Vec v) { return {P, norm(u) + norm(v)}; }
Point midp(Seg l) { return {(l.A.x + l.B.x) / 2, (l.A.y + l.B.y) / 2}; }
Line perp(Seg l) { return {midp(l), r90c(l.B - l.A)}; }
double dis(Point x, Point y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
using Points = vector<Point>;
double theta(Point p) { return p == O ? -1 / 0. : atan2(p.y, p.x); }
void psort(Points& ps, Point c) {
  sort(ps.begin(), ps.end(),
       [&](auto p1, auto p2) { return lt(theta(p1 - c), theta(p2 - c)); });
}
bool check(Point p, Point q, Point r) { return lt(0, (q - p) ^ (r - q)); }
Points chull(Points& ps) {
  psort(ps, *min_element(ps.begin(), ps.end()));
  Points H{ps[0]};
  for (int i = 1; i < ps.size(); i++) {
    while (H.size() > 1 && !check(H[H.size() - 2], H.back(), ps[i]))
      H.pop_back();
    H.push_back(ps[i]);
  }
  H.push_back(H[0]);
  return H;
}
Points p;
double aa = 0;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  int n;
  cin >> n;
  Point t;
  for (int i = 0; i < n; i++) {
    cin >> t.x >> t.y;
    p.push_back(t);
  }
  auto ans = chull(p);
  for (int i = 0; i < ans.size() - 1; i++) {
    // cout << ans[i].x << " " << ans[i].y << endl;
    aa += dis(ans[i], ans[i + 1]);
  }
  printf("%.2lf", aa);
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