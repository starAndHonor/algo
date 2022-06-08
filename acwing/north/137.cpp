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
const int MAXN = (int)1e5 + 10;

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
int mod = 1e5 + 3;
struct node {
  int a[6];
  int operator[](int x) { return a[x]; }
};
vector<node> v[MAXN];
inline int H(node a) {
  int s = 0, k = 1;
  for (int i = 0; i < 6; i++) {
    s = (s + a[i]) % mod;
    k = k * a[i] % mod;
  }
  return (s + k) % mod;
}
inline bool judge(node a, node b) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      bool v = true;
      for (int k = 0; k < 6; k++) {
        if (a[(i + k) % 6] != b[(j + k) % 6]) {
          v = false;
          break;
        }
      }
      if (v) {
        return true;
      }
      v = true;
      for (int k = 0; k < 6; k++) {
        if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
          v = false;
          break;
        }
      }
      if (v) {
        return true;
      }
    }
  }
  return false;
}
bool insert(node a) {
  int h = H(a);
  for (auto i : v[h]) {
    if (judge(i, a)) return true;
  }
  v[h].push_back(a);
  return false;
}
int n;
node in;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> in.a[j];
    }
    if (insert(in)) {
      cout << "Twin snowflakes found." << endl;
      return;
    }
  }
  cout << "No two snowflakes are alike." << endl;
  return;
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