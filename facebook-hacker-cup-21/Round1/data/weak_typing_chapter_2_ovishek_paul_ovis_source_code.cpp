#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll m(ll a) {
    return a < 0 ? a%mod+mod : a%mod;
}

ll mult(ll a, ll b) {
    return (1ll* (a%mod) * (b%mod)) % mod;
}

int sum(int a, int b) {
    return (a+b) % mod;
}

ll nc2(ll n) {
    // cout << n << "--  -" << endl;
    return n&1 ? mult((n+1)/2, n) : mult(n/2, n+1);
}

void print(vector<int> vt) {
    for (int x : vt) {
        cout << x << "\t";
    }
    cout << endl;
}
int main() {
    int t, tst = 1;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int nowHand = -1;
        int ans = 0;
        int LeftHand = 0;
        int RightHand = 1;
        vector<int> vt;
        int color[n];
        char st[n+3];
        for (int i = 0; i<n; i++) {
        	char ch;
        	scanf(" %c", &ch);
        	if (ch == 'X') {
        		if (nowHand != LeftHand) {
                    vt.push_back(i);
                }
        		nowHand = LeftHand;
        	} else if (ch == 'O') {
        		if (nowHand != RightHand) {
                    vt.push_back(i);
                }
        		nowHand = RightHand;
        	}
            st[i] = ch;
            color[i] = vt.size();
        }
        // vt.push_back(n);
        int N = vt.size();
        // cout << "---size " << N << endl;
        vector<int> p(N+1), c(N+1), s(N+1);
        for (int i = N-1; i >= 0; i--) {
            p[i] = sum(vt[i], p[i+1]);
            s[i] = sum(s[i+1], p[i]);
        }
        int lastIndex = 0;
        map<char, int> mp;
        for (int i = n-1; i>=0; i--) {
            if (st[i] == 'F') continue;
            mp[st[i]] = 1;
            if (mp.size() == 2) {
                lastIndex = i + 1;
                break;
            }
        }
        // cout << lastIndex << "' sdf'" << endl;
        // print(vt);
        // print(p);
        // print(s);
        //     cout << color[i] << " ";
        // for (int i = 0; i<n; i++) {
        // }
        // cout << endl;
        int lastAnswer = 0;
        for (int i = n-1; i>=0; i--) {
            int isF = st[i] == 'F';
            if (isF) { ans = sum(ans, lastAnswer); continue; }
            int col = color[i] + isF;
            int indx = vt[color[i] + isF];
            int X = N - col;
            if (i >= lastIndex) continue;
            // cout << X << ',' ;
            // cout << " ----------" << endl;
            // cout << col << " " << indx << endl;
            // cout << X << " -c- " << n << endl;
            // cout << mult(n, X) << " " << p[col] << endl;
            int now = m(mult(n, X) - p[col]);
            lastAnswer = now;
            // cout << now << " ";
            ans = sum(now, ans);
        }
        // cout << endl;
        printf("Case #%d: %d\n", tst++, ans);
    }
    return 0;
}