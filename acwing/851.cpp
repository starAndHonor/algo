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
int n, m, e[MAXN], w[MAXN], ne[MAXN], h[MAXN], idx, dis[MAXN], cnt[MAXN];
bool inque[MAXN];
inline void add(int a, int b, int c) {
  //   e[idx] = b, ne[idx] = h[a], h[a] = idx, w[idx++] = c;
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}
bool sfpa() {
  //   memset(dis, 0x3f, sizeof(dis));
  queue<int> q;
  //   q.push(s);
  //   dis[s] = 0;
  //   inque[s] = true;
  for (int i = 1; i <= n; i++) {
    q.push(i);
    inque[i] = true;
  }
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    inque[v] = false;
    for (int i = h[v]; i != -1; i = ne[i]) {
      int to = e[i];
      if (dis[to] > dis[v] + w[i]) {
        dis[to] = dis[v] + w[i];
        cnt[to] = cnt[v] + 1;
        if (cnt[to] >= n) return true;
        if (!inque[to]) {
          inque[to] = true;
          q.push(to);
        }
      }
    }
  }
  return false;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  memset(h, -1, sizeof(h));
  cin >> n >> m;
  for (int a, b, c, i = 1; i <= m; i++) cin >> a >> b >> c, add(a, b, c);

  if (sfpa())
    puts("Yes");
  else
    puts("No");
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