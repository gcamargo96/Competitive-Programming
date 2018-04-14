#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
const ll M = 1000000007;
int n;
ll m;
ll a[N], b[N];
ll dp[N][2];

ll fastpow(ll b, ll e){
	if(e == 0)
		return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0)
		return (x*x)%M;
	else
		return (b * (x*x)%M )%M;
}

ll solve(int i, int flag){
	printf("i = %d\n", i);
	if(i == n){
		// printf("flag = %d\n", flag);
		return flag;
	}

	ll& DP = dp[i][flag];
	if(DP != -1)
		return DP;

	ll gr = 0, eq = 0, tot = 1;
	if(a[i] == 0 and b[i] != 0){
		gr += m-b[i];
		gr %= M;
		eq = 1;
		tot = m;
	}
	else if(a[i] != 0 and b[i] == 0){
		gr += a[i]-1;
		gr %= M;
		eq = 1;
		tot = m;
	}
	else if(a[i] == 0 and b[i] == 0){
		gr += (m*(m-1));
		gr %= M;
		gr *= fastpow(2, M-2);
		gr %= M;
		eq = m;
		tot = (m*m)%M;
	}
	else{ // a[i] != 0 and b[i] != 0
		if(a[i] == b[i]){
			return DP = solve(i+1, flag);
		}
		else if(a[i] > b[i]){
			return DP = solve(i+1, 1);
		}
		else{
			if(flag == 1){
				return DP = solve(i+1, 1);
			}
			else{
				return 0;
			}
		}
	}

	printf("pos = %d, gr = %lld, eq = %lld\n", i, gr, eq);

	if(flag == 1){
		ll ret = tot * solve(i+1, 1);
		ret %= M;
		return DP = ret;
	}

	ll ret1 = gr * solve(i+1, 1);
	ret1 %= M;
	ll ret2 = eq * solve(i+1, 0);
	ret2 %= M;

	return DP = (ret1 + ret2)%M;
}

int main(void){
	scanf("%d%lld", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lld", &b[i]);
	}

	ll den = 1;
	for(int i = 0; i < n; i++){
		if(a[i] == 0 and b[i] != 0){
			den *= m;
			den %= M;
		}
		else if(a[i] != 0 and b[i] == 0){
			den *= m;
			den %= M;
		}
		else if(a[i] == 0 and b[i] == 0){
			den *= m;
			den %= M;
			den *= m;
			den %= M;
		}
	}

	memset(dp, -1, sizeof dp);
	ll num = solve(0, 0);

	// printf("num = %lld\n", num);

	ll ans = num * fastpow(den, M-2);
	printf("num = %lld\n", num);
	ans %= M;
	ans += M;
	ans %= M;

	printf("%lld\n", ans);

	return 0;
}