#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
 
int t;
ll n;
 
int main(void){
    scanf("%d", &t);
 
    while(t--){
        scanf("%lld", &n);
 
        ll root = -1;
        for(ll s = 1; s*s <= n; s++){
            if(s*s == n){
                root = s;
                break;
            }
        }
 
        if(root != -1){
            printf("0 %lld\n", root);
            continue;
        }
 
        pair<ll,ll> ans(-1,-1);
        for(ll sub = 1; sub*sub <= n; sub++){
            if(n%sub == 0){
                ll sum = n/sub;
 
                if((sum+sub)%2LL == 0){
                    ll c = (sum+sub)/2LL;
                    ll a = sum-c;
                    // if((sum-sub)%2LL == 0){
                        // ll a = (sum-sub)/2LL;
 
                        if(a >= 0 and c >= 0){
                            pair<ll,ll> aux(a,c);
 
                            if(ans.fi == -1 or aux < ans){
                                ans = aux;
                            }
                        }
                    // }
                }
            }
        }
 
        if(ans.fi != -1){
            printf("%lld %lld\n", ans.fi, ans.se);
        }
        else{
            printf("IMPOSSIBLE\n");
        }
    }
 
    return 0;
}