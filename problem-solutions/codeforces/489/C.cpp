#include <bits/stdc++.h>
using namespace std;
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

const ll M = 1000000007;
ll x, k;

ll fastpow(ll b, ll e){
	if(e == 0) return 1LL;

	ll x = fastpow(b, e/2LL);
	if(e%2LL == 0LL){
		return (x*x)%M;
	}
	else{
		return ((x*x)%M * b)%M;
	}
}

int main(void){
	scanf("%lld%lld", &x, &k);

	if(x == 0){
		printf("0\n");
		return 0;
	}
	if(k == 0){
		printf("%lld\n", (2LL*x)%M);
		return 0;
	}

	ll p2k = fastpow(2,k);

	ll ans = 0;
	ans += (2LL * ((2LL*x)%M * p2k)%M )%M;
	ans %= M;
	ans -= (2LL*p2k)%M;
	ans = (ans + 2 + M)%M;
	ans = (ans * fastpow(2, k-1))%M;
	ans = (ans * fastpow(p2k, M-2))%M;
	ans = (ans + M)%M;

	printf("%lld\n", ans);

	return 0;
}