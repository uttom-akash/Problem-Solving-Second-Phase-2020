#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'X') a[i] = 0;
      else if (s[i] == 'O') a[i] = 1;
      else a[i] = -1;
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] != -1 and a[i + 1] != -1) {
        if (a[i] != a[i + 1]) {
          ans += 1LL * (i + 1) * (n - i - 1);
          ans %= mod;
        }
      }
    }
    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n and a[i] == a[j]; j++);
      if (a[i] == -1) {
        if (i and j < n and a[i - 1] != a[j]) {
          ans += 1LL * i * (n - j);
          ans %= mod;
        }
      }
    }
    cout << "Case #" << ++cs << ": " << ans << '\n';
  }
  return 0;
}