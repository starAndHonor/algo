#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

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
int n, m;
bool primes[MAXN];
inline void getPrimes() {
  for (int i = 1; i <= 100000; i++) {
    primes[i] = true;
  }
  for (int i = 2; i <= 100000; i++) {
    if (primes[i]) {
      for (int j = 2; j * i <= 100000; j++) {
        primes[j * i] = false;
      }
    }
  }
}
map<int, int> dis;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  queue<int> q;
  q.push(n);
  dis[n] = 0;
  dis.clear();
  if (n == m) {
    cout << 0 << endl;
    return;
  }
  while (!q.empty()) {
    int t = q.front();
    // cout << t << endl;
    if (t == m) {
      cout << dis[t] << endl;
      return;
    }
    for (int i = 0; i <= 9; i++) {
      int dt = i + t / 10 * 10;
      if (primes[dt] && !dis[dt] && dt != n) {
        q.push(dt);
        dis[dt] = dis[t] + 1;
      }
    }
    for (int i = 0; i <= 9; i++) {
      int dt = i * 10 + t / 100 * 100 + t % 10;
      if (primes[dt] && !dis[dt] && dt != n) {
        q.push(dt);
        dis[dt] = dis[t] + 1;
      }
    }
    for (int i = 0; i <= 9; i++) {
      int dt = i * 100 + t / 1000 * 1000 + t % 100;
      if (primes[dt] && !dis[dt] && dt != n) {
        q.push(dt);
        dis[dt] = dis[t] + 1;
      }
    }
    for (int i = 1; i <= 9; i++) {
      int dt = i * 1000 + t % 1000;
      if (primes[dt] && !dis[dt] && dt != n) {
        q.push(dt);
        dis[dt] = dis[t] + 1;
      }
    }
    q.pop();
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  getPrimes();

  signed T = 1;  //(signed)read();//scanf("%d",&T);
  cin >> T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ", CASE);  // printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}