#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map<int, int,greater<int> >v,v1;
map<int, int,less<int> > r,r1;
int t;
int main(int argc, char const *argv[]) {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (size_t i = 1; i <= n; i++) {
      cin >> t;
      v[i] = t;
      v1[t] = i;
    }
    for (size_t i = 1; i <= n; i++) {
      cin >> t;
      r[i] = t;
      r1[t] = i;
    }
    for (auto &&i : v)
    {
        if(r[])
    }
    
  }
  return 0;
}
