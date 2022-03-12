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
int n, ans = 0x7fffffff;
int cnt[30];
void dfs(int x) {
  if (x >= ans) return;
  int len = 0;
  //单顺子
  for (int i = 3; i <= 14; i++) {
    if (!cnt[i])
      len = 0;
    else {
      ++len;
      if (len >= 5) {
        for (int j = i - len + 1; j <= i; j++) cnt[j]--;
        dfs(x + 1);
        for (int j = i - len + 1; j <= i; j++) cnt[j]++;
      }
    }
  }
  len = 0;  //双
  for (int i = 3; i <= 14; i++) {
    if (cnt[i] <= 1)
      len = 0;
    else {
      ++len;
      if (len >= 3) {
        for (int j = i - len + 1; j <= i; j++) cnt[j] -= 2;
        dfs(x + 1);
        for (int j = i - len + 1; j <= i; j++) cnt[j] += 2;
      }
    }
  }
  len = 0;  //三
  for (int i = 3; i <= 14; i++) {
    if (cnt[i] <= 2)
      len = 0;
    else {
      ++len;
      if (len >= 2) {
        for (int j = i - len + 1; j <= i; j++) cnt[j] -= 3;
        dfs(x + 1);
        for (int j = i - len + 1; j <= i; j++) cnt[j] += 3;
      }
    }
  }
  for (int i = 2; i <= 14; i++) {
    if (cnt[i] <= 3) {
      if (cnt[i] > 2) {
        cnt[i] -= 3;
        for (int j = 2; j <= 15; j++) {
          if (cnt[j] <= 0 || j == i) continue;
          --cnt[j];
          dfs(x + 1);
          ++cnt[j];
        }
        for (int j = 2; j <= 14; j++) {
          if (cnt[j] <= 1 || j == i) continue;
          cnt[j] -= 2;
          dfs(x + 1);
          cnt[j] += 2;
        }
        cnt[i] += 3;
      }

    } else {
      cnt[i] -= 3;
      for (int j = 2; j <= 15; j++) {
        if (cnt[j] <= 0 || j == i) continue;
        --cnt[j];
        dfs(x + 1);
        ++cnt[j];
      }
      for (int j = 2; j <= 14; j++) {
        if (cnt[j] <= 1 || j == i) continue;
        cnt[j] -= 2;
        dfs(x + 1);
        cnt[j] += 2;
      }

      cnt[i] += 3;
      cnt[i] -= 4;
      for (int j = 2; j <= 15; j++) {
        if (cnt[j] <= 0 || j == i) continue;
        --cnt[j];
        for (int k = 2; k <= 15; k++) {
          if (cnt[k] <= 0 || j == k) continue;
          cnt[k]--;
          dfs(x + 1);
          cnt[k]++;
        }
        ++cnt[j];
      }
      for (int j = 2; j <= 14; j++) {
        if (cnt[j] <= 1 || j == i) continue;
        cnt[j] -= 2;
        for (int k = 2; k <= 15; k++) {
          if (cnt[k] <= 1 || j == k) continue;
          cnt[k] -= 2;
          dfs(x + 1);
          cnt[k] += 2;
        }
        cnt[j] += 2;
      }
      cnt[i] += 4;
    }
  }
  for (int i = 2; i <= 15; i++)
    if (cnt[i]) x++;
  ans = min(ans, x);
}

inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  mmst0(cnt);
  ans = 0x7fffffff;
  for (int a, b, i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    if (a == 0)
      cnt[15]++;
    else if (a == 1)
      cnt[14]++;
    else
      cnt[a]++;
  }
  dfs(0);
  cout << ans << endl;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();
  scanf("%d", &T);
  cin >> n;                                   // cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}