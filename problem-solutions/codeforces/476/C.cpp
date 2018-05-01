#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
#define M 1000000007
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
typedef complex<double> base;

ll n, k, m, d;

ll cycles(ll x){
	ll c = (n + k*x - 1)/(k*x);
	if(n%(k*x) < x){
		c--;
	}
	return c;
}

int main(void){
	scanf("%lld%lld%lld%lld", &n, &k, &m, &d);

	ll ans = m;
	for(int i = 2; i <= d; i++){
		ll l = 1, r = m, aux = 0;
		while(l <= r){
			ll x = (l+r)/2;

			ll c = cycles(x);
			if(c == i){
				// printf("OK\n");
				aux = c*x; //(c-1)*x + min(m, n - (c-1)*k*x);
				l = x+1;
			}
			else if(c < i){
				l = x+1;
			}
			else{
				r = x-1;
			}
		}

		ans = max(ans, aux);
	}

	printf("%lld\n", ans);

	return 0;
}