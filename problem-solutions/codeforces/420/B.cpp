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

ll m, b;

int main(void){
	scanf("%lld%lld", &m, &b);

	ll ans = 0;
	for(ll y = 0; y <= b; y++){
		ll mx = -m*y + m*b;
		
		ll s0 = ((0 + y)*(y+1))/2LL;
		ll sn = (mx + mx+y)*(y+1)/2LL;
		ll sum = ((s0 + sn)*(mx+1))/2LL;

		// ll sum = 0;
		// for(ll x = 0; x <= mx; x++){
		// 	sum += ((x+x+y)*(y+1))/2LL;
		// }

		ans = max(ans, sum);
	}

	printf("%lld\n", ans);

	return 0;
}