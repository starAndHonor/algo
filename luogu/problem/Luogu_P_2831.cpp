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
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)20 + 3;

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
int pre[1 << MAXN];
inline void prepare() {
  for (int i = 0; i < (1 << 18); i++) {
    int j = 1;
    for (; j <= 18 && i & (1 << j - 1); j++)
      ;
    pre[i] = j;
    // cout << pre[i] << " ";
  }
}

int n, m;
double x[MAXN], y[MAXN];
int parabola[MAXN][MAXN];
int dp[1 << MAXN];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  mmst3f(dp);
  mmst0(parabola);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (fabs(x[i] - x[j]) < eps)
        continue;
      double x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
      double b = (y2 * x1 * x1 - x2 * x2 * y1) / (x1 * x1 * x2 - x1 * x2 * x2);
      double a = (y1 - b * x1) / (x1 * x1);
      if (a > -eps)
        continue;
      for (int k = 1; k <= n; k++) {
        if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps)
          parabola[i][j] |= (1 << (k - 1));
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int j = pre[i];
    dp[i | (1 << j - 1)] = min(dp[i | (1 << j - 1)], dp[i] + 1);
    for (int k = 1; k <= n; k++)
      dp[i | parabola[j][k]] = min(dp[i | parabola[j][k]], dp[i] + 1);
  }
  cout << dp[(1 << n) - 1] << endl;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  prepare();
  signed T = 1; //(signed)read();//scanf("%d",&T);
  cin >> T;
  for (signed CASE = 1; CASE <= T; CASE++) { //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}