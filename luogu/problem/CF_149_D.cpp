#include <bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long  //__int128
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
int stk[MAXN];
int tp;
inline void push(int x) { stk[++tp] = x; }
inline void pop() { --tp; }
inline bool empty() { return !tp; }
inline int top() { return stk[tp]; }
char s[MAXN];
int match[MAXN], dp[706][706][3][3];
const int mod = 1e9 + 7;
void dfs(int l, int r) {
  if (r == l + 1) {
    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
    return;
  } else if (match[l] == r) {
    dfs(l + 1, r - 1);
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) {
        if (j != 1)
          dp[l][r][0][1] = dp[l][r][0][1] + (dp[l + 1][r - 1][i][j]) % mod;
        if (j != 2)
          dp[l][r][0][2] = dp[l][r][0][2] + (dp[l + 1][r - 1][i][j]) % mod;
        if (i != 1)
          dp[l][r][1][0] = dp[l][r][1][0] + (dp[l + 1][r - 1][i][j]) % mod;
        if (i != 2)
          dp[l][r][2][0] = dp[l][r][2][0] + (dp[l + 1][r - 1][i][j]) % mod;
      }
    }
    return;
  } else {
    dfs(l, match[l]);
    dfs(match[l] + 1, r);
    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++)
        for (int k = 0; k <= 2; k++)
          for (int m = 0; m <= 2; m++) {
            if ((j == 1 && k == 1) || (j == 2 && k == 2)) continue;
            dp[l][r][i][m] +=
                dp[l][match[l]][i][j] * dp[match[l] + 1][r][k][m] % mod,
                dp[l][r][i][m] %= mod;
          }
    return;
  }
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      push(i);
    else {
      match[top()] = i;
      match[i] = top();
      pop();
    }
  }
  //   for (int i = 1; i <= n; i++) {
  //     cout << match[i];
  //   }
  dfs(1, n);
  cout << ((dp[1][n][0][1] + dp[1][n][0][2]) % mod +
           (dp[1][n][1][0] + dp[1][n][2][0]) % mod) %
              mod;
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