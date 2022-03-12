#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  int n, a, b;
  while (T--) {
    cin >> n >> a >> b;
    if (a > b||n/3<a)
      cout << -1 << endl;
    else {int i = 1;
        while(i<=n&&a&&b){
            a--;
            b--;
            cout<<i+1<<i;
        }
        if(a==0&&b){
            for(;i<=n)
        }
    }
  }
  return 0;
}
