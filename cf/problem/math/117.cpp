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
deque<pair<int, int>> q[14];
inline int get(char c) {
  if (c == 'A') return 1;
  if (c == '0') return 10;
  if (c == 'J') return 11;
  if (c == 'Q') return 12;
  if (c == 'K') return 13;
  if (c >= '2' && c <= '9') return c - '0';
}
char c;
int cnt;
int num[MAXN];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  for (int i = 1; i <= 13; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> c;
      q[i].push_back({get(c), 0});
    }
  }
  auto now = q[13].front().fi;
  q[13].pop_front();
  while (cnt != 4) {
    if (now == 13) {
      cnt++;
      if (cnt != 4) {
        now = q[13].front().fi, q[13].pop_front();
      }
      continue;
    }
    q[now].push_front({now, 1});
    int t = now;
    now = q[now].back().fi;
    q[t].pop_back();
  }
  for (int i = 1; i <= 13; i++) {
    while (!q[i].empty()) {
      auto t = q[i].front();
      q[i].pop_front();
      if (t.se == 1) num[t.fi]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 13; i++) {
    if (num[i] == 4) ans++;
  }
  cout << ans;
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