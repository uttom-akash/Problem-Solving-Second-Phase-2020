#include <bits/stdc++.h>
using namespace std;
    
const int sz = 2000;
    
long long userX[sz], userY[sz];
long long bikeX[sz], bikeY[sz];
int lt[sz];
int N, M, K;
bool vis[sz];
    
bool validPath(int userId, int bikerId, long long distanceAllowed) {
    long long distX = userX[userId] - bikeX[bikerId];
    distX *= distX;
    long long distY = userY[userId] - bikeY[bikerId];
    distY *= distY;
    
    return distX + distY <= distanceAllowed;
}
    
bool dfs(int u, long long distanceAllowed) {
    if(u == -1)
        return true;
    if(vis[u])
        return false;
    vis[u] = true;
    
    for(int i = 0; i < (int)M; ++i) {
        int id = lt[i];
        if(validPath(u, i, distanceAllowed) && dfs(id, distanceAllowed)) {
            lt[i] = u;
            return true;
        }
    }
    return false;
}
    
int matching(long long tm) {
    memset(lt, -1, sizeof(lt));
    
    int ret = 0;
    for(int i = 0; i < (int)N; ++i) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i, tm))
            ret++;
    }
    return ret;
}
    
long long binarySearch(long long l = 0, long long r = 1e17) {
    if(l == r)
        return l;
    long long mid = (l+r)/2;
    int match = matching(mid);
    return match >= K ? binarySearch(l, mid) : binarySearch(mid+1, r);
}
    
int main()
{
    cin >> N >> M >> K;
    assert(1 <= N); assert(N <= sz);
    assert(1 <= M); assert(M <= sz);
    assert(1 <= K); assert(K <= min(N, M));
    
    for(int i = 0; i < (int)N; ++i) {
        cin >> userX[i] >> userY[i];
        assert(0 <= userX[i]); assert(userX[i] <= 1e7);
        assert(0 <= userY[i]); assert(userY[i] <= 1e7);
    }
    for(int i = 0; i < (int)M; ++i) {
        cin >> bikeX[i] >> bikeY[i];
        assert(0 <= bikeX[i]); assert(bikeX[i] <= 1e7);
        assert(0 <= bikeY[i]); assert(bikeY[i] <= 1e7);
    }
    
    cout << binarySearch() << endl;
    
    return 0;
}