#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  string s;
  while (T--) {
    cin >> s;
    int l = s.length();
    if (l & 1)
      puts("NO");
    else {
      bool f = false;
      for (int i = 0, j = (l / 2); i < l / 2 && j <= l - 1; i++, j++) {
        if (s[i] == s[j])
          continue;
        else {
          f = true;
          break;
        }
      }
      if (f)
        puts("NO");
      else {
        puts("YES");
      }
    }
  }
  return 0;
}
