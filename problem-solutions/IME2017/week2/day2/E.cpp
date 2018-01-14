#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define M 1000000007
#define pb push_back

bool isPal(vector<int>& v, int p) {
    bool ok = true;
    for(int i = p, j = v.size()-1; i < j; ++i, --j) {
        if(v[i] != v[j]) ok = false;
    }
    return ok;
}

int n, k;
int f;

ll dp[407][2000][11];

ll solve(int p, int mask) {
    vector<int> v;
    int aux = mask;
    
    if(p == n) {
        return 1;
    }
    
    if(dp[p][mask][k] != -1) return dp[p][mask][k];
    
    
    ll ans = 0;
    for(int i = 0; i < k; ++i) {
        v.pb(aux&1);
        aux >>= 1;
    }
    reverse(v.begin(), v.end());
    
    v.pb(1);
    if(isPal(v, 0) == false && isPal(v, 1) == false) {
        aux = mask;
        aux <<= 1;
        aux %= f;
        aux |= 1;
        ans += solve(p+1, aux);
        ans %= M;
    }
    v.pop_back();
    v.pb(0);
    if(isPal(v, 0) == false && isPal(v, 1) == false) {
        aux = mask;
        aux <<= 1;
        aux %= f;
        ans += solve(p+1, aux);
        ans %= M;
    }
    return dp[p][mask][k] = ans;
}

int pot[407];

int main() {
    int t;
    scanf("%d", &t);
    
    pot[0] = 1;
    for(int i = 1; i <= 12; ++i) {
        pot[i] = (pot[i-1]*2)%M;
    }
    
    for(int i = 0; i <= 400; ++i) {
        for(int j = 0; j <= 1500; ++j) {
            for(int k = 0; k <= 10; ++k)
                dp[i][j][k] = -1;
        }
    }
    
    while(t--) {
        scanf("%d %d", &n, &k);
        f = pot[k];
        
        if(k > n) {
            cout << pot[n] << endl;
            continue;
        }
        
        ll ans = 0;
        for(int i = 0; i < pot[k]; ++i) {
            vector<int> v;
            int aux = i;
            for(int j = 0; j < k; ++j) {
                v.pb(aux&1);
                aux >>= 1;
            }
            if(isPal(v, 0) == false) {
                ans += solve(k, i);
                ans %= M;
            }
        }
        printf("%lld\n", ans);
    }

}