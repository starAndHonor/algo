/*
 * @Author: starAndHonor
 * @Date: 2022-01-31 11:53:01
 * @Last Modified by: starAndHonor
 * @Last Modified time: 2022-01-31 12:00:15
 */

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

inline char nc() {
  // static char buf[100000], *p1 = buf, *p2 = buf;
  // return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 ==
  // p2)? EOF: *p1++;
  return getchar();
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
inline void read(int &x) {
  x = 0;
  int w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = nc();
  }
  x *= w;
}
void prt(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) prt(x / 10);
  putchar((char)(x % 10 + '0'));
}
deque<int> q;
int n, m;
vector<int> v;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  fori(i, 1, n, 1) v.push_back(read());
  for (int i = 0; i < n; i++) {
    if (!q.empty() && i - q.front() >= m) q.pop_front();
    while (!q.empty() && v[q.back()] > v[i]) q.pop_back();
    q.push_back(i);
    if (i >= m - 1) cout << v[q.front()] << " ";
  }
  puts("");
  q.clear();
  for (int i = 0; i < n; i++) {
    if (!q.empty() && i - q.front() >= m) q.pop_front();
    while (!q.empty() && v[q.back()] < v[i]) q.pop_back();
    q.push_back(i);
    if (i >= m - 1) cout << v[q.front()] << " ";
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();
  // scanf("%d", &T);                           // cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}