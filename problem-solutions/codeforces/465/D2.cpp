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
	if(i == n){
		return flag;
	}

	ll& DP = dp[i][flag];
	if(DP != -1){
		return DP;
	}

	if(flag == 0){
		if(a[i] == 0 and b[i] == 0){
			ll ret1 = ((m*(m-1)))%M;
			ret1 = (ret1 * fastpow(2, M-2))%M;
			ret1 = (ret1 * solve(i+1, 1))%M;
			ll ret2 = solve(i+1, 0);
			return DP = (ret1 + ret2)%M;
		}
		else if(a[i] > 0 and b[i] == 0){
			ll ret1 = ((a[i]-1) * solve(i+1, 1))%M;
			ll ret2 = solve(i+1, 0);
			return DP = (ret1 + ret2)%M;
		}
		else if(a[i] == 0 and b[i] > 0){
			ll ret1 = ((m-b[i]) * solve(i+1, 1))%M;
			ll ret2 = solve(i+1, 0);
			return DP = (ret1 + ret2)%M;
		}
		else if(a[i] > 0 and b[i] > 0){
			if(a[i] == b[i]){
				return DP = solve(i+1, 0);
			}
			else if(a[i] > b[i]){
				return DP = solve(i+1, 1);
			}
			else if(a[i] < b[i]){
				return 0;
			}
		}
	}
	else{ // flag == 1
		if(a[i] == 0 and b[i] == 0){
			return DP = ((m*m)%M * solve(i+1, 1))%M;
		}
		else if(a[i] > 0 and b[i] == 0){
			return DP = (m * solve(i+1, 1))%M;
		}
		else if(a[i] == 0 and b[i] > 0){
			return DP = (m * solve(i+1, 1))%M;
		}
		else{
			return DP = solve(i+1, 1);
		}
	}
}

int main(void){
	ll inv2 = fastpow(2, M-2);

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
	// printf("num = %lld\n", num);
	ans %= M;
	ans += M;
	ans %= M;

	printf("%lld\n", ans);

	return 0;
}