#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

ll n;

bool ok(ll k){
	ll eaten = 0, cur = n;
	while(cur > 0){
		eaten += min(k, cur);
		cur -= min(k, cur);
		cur -= cur/10LL;
	}

	if(n%2LL == 0LL and eaten >= n/2LL) return 1;
	if(n%2LL == 1LL and eaten > n/2LL) return 1;
	return 0;
}

int main(void){
	scanf("%lld", &n);

	ll l = 1, r = n;
	ll ans = 1;
	while(l <= r){
		ll k = (l+r)/2LL;

		if(ok(k)){
			ans = k;
			r = k-1;
		}
		else{
			l = k+1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}