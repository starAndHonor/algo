#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long  //__int128
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
ll a, b, c, d;
int n, m, q;
int t[25000001];
int rds[25000001];
int l[5001], r[5001];
int cnt = 0;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  rds[0] = read();
  a = read();
  b = read();
  c = read();
  d = read();
  n = read();
  m = read();
  q = read();
  for (int i = 1; i <= n * m; i++) {
    t[i] = i;
    rds[i] = (rds[i - 1] * a * rds[i - 1] + b * rds[i - 1] + c) % d;
  }
  for (int i = 1; i <= n * m; i++) {
    swap(t[i], t[rds[i] % i + 1]);
  }
  for (int i = 1; i <= q; i++) {
    swap(t[read()], t[read()]);
  }
  mmst0(rds);
  for (int i = 1; i <= n * m; i++) rds[t[i]] = i;
  for (int i = 1; i <= n; i++) l[i] = 1, r[i] = m;
  for (int i = 1; i <= n * m; i++) {
    int dx, dy;
    dx = rds[i] / m;
    if (rds[i] % m != 0) dx++;
    if (!(dy = rds[i] % m)) dy = m;
    if (dy >= l[dx] && dy <= r[dx]) {
      ++cnt;
      printf("%d ", i);
      if (cnt == n + m - 1) return;
      for (int j = 1; j <= n; j++) {
        if (j == dx) continue;
        if (j < dx)
          r[j] = min(r[j], dy);
        else
          l[j] = max(l[j], dy);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);
  // cin >> T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}