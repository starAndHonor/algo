#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
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
// using namespace __gnu_pbds; // If using pbds don't using std!

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
int l, r, c;
struct point {
  int x;
  int y;
  int z;
};
char gr[35][35][35];
bool vis[35][35][35];
int dis[35][35][35];
int dirx[] = {1, -1, 0, 0, 0, 0};
int diry[] = {0, 0, 1, -1, 0, 0};
int dirz[] = {0, 0, 0, 0, 1, -1};
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  while (cin >> l >> r >> c, l, r, c) {
    mmst0(vis);
    mmst0(dis);
    point st, ed;
    for (int i = 1; i <= l; i++) {
      for (int j = 1; j <= r; j++) {
        for (int k = 1; k <= c; k++) {
          cin >> gr[i][j][k];
          if (gr[i][j][k] == 'S')
            st = {i, j, k};
          else if (gr[i][j][k] == 'E')
            ed = {i, j, k};
        }
      }
    }
    queue<point> q;
    vis[st.x][st.y][st.z] = true;
    q.push(st);
    bool f = true;
    while (!q.empty() && f) {
      point p = q.front();
      q.pop();
      for (int i = 0; (i < 6); i++) {
        point nxt = {p.x + dirx[i], p.y + diry[i], p.z + dirz[i]};
        if (nxt.x <= l && nxt.y <= r && nxt.z <= c && nxt.x >= 1 &&
            nxt.y >= 1 && nxt.z >= 1 && !vis[nxt.x][nxt.y][nxt.z] &&
            gr[nxt.x][nxt.y][nxt.z] != '#') {
          vis[nxt.x][nxt.y][nxt.z] = true;
          dis[nxt.x][nxt.y][nxt.z] = dis[p.x][p.y][p.z] + 1;
          if (nxt.x == ed.x && nxt.y == ed.y && nxt.z == ed.z) f = false;
          q.push(nxt);
        }
      }
    }
    if (dis[ed.x][ed.y][ed.z])
      printf("Escaped in %d minute(s).\n", dis[ed.x][ed.y][ed.z]);
    else
      printf("Trapped!\n");
  }
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