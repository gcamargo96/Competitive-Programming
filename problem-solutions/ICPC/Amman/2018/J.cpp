#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll t, a, b, x;
vector<ll> bits;

bool check(int mid){
	return ((a|bits[mid]) <= x);
}

// ll next(ll a){
// 	for(int i = 0; i < 63; i++){
// 		if(((a>>i)&1LL) == 1LL){
// 			a += (1LL<<i);
// 			return a;
// 		}
// 	}
// }

int main(void){
	// fastcin;
	// cin >> t;
	scanf("%d", &t);
	
	bits.pb(0);
	ll cur = 0;
	for(int i = 0; i < 63; i++){
		cur |= (1LL<<i);
		bits.pb(cur);
	}

	while(t--){
		// cin >> a >> b >> x;
		scanf("%lld%lld%lld", &a, &b, &x);

		ll ans = 0;
		for(int i = 0; i < 63; i++){
			if(((a>>ll(i))&1LL) == 1){
				int l = 0, r = 63;
				ll aux = 0;
				while(l <= r){
					int mid = (l+r)/2;

					if(check(mid)){
						// printf("ok %d\n", mid);
						aux = min(b, a|bits[mid]) - a + 1;
						l = mid+1;
					}
					else{
						r = mid-1;
					}
				}
				// printf("l = %d, r = %d\n", l, r);
				ans = max(ans, aux);
				// a = next(a);
				a += (1LL<<i);
			}
		}

		// cout << ans << endl;
		printf("%lld\n", ans);
	}

	return 0;
}