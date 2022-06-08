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
int n, m, k;
struct node {
  int v;
  int w;
};
vector<node> gr[MAXN];
int edge[MAXN];
int dis[MAXN];
bool vis[MAXN];
inline bool check(int x) {
  deque<int> q;
  q.push_back(1);
  mmst3f(dis);
  dis[1] = 0;
  while (q.size()) {
    int now = q.front();
    q.pop_front();
    for (auto k : gr[now]) {
      int w = k.w > x;
      if (dis[k.v] > w + dis[now]) {
        dis[k.v] = dis[now] + w;
        if (w)
          q.push_back(k.v);
        else
          q.push_front(k.v);
      }
    }
  }
  return dis[n] <= k;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    gr[u].push_back({v, w});
    gr[v].push_back({u, w});
    edge[i] = w;
  }
  if (check(0)) {
    cout << 0 << endl;
    return;
  }

  sort(edge + 1, edge + 1 + m);
  int l = 1, r = 2 * m, mid, res = 0;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(edge[mid])) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  //   cout << 1;
  //   cout << mid;
  if (res == 0)
    cout << -1 << endl;
  else
    cout << edge[res];
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // freopen("phoneline.in", "r", stdin);
  // freopen("phoneline.out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}