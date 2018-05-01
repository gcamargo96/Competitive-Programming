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

const int N = 1005;
int t;
ll n, k;
ll dp[N][N];

ll solve(ll n, ll k){
	if(n < k){
		return 0;
	}
	if(n == 0){
		return k == 0;
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}

	ll ret = (k*solve(n-1, k))%M;
	ret += (k*solve(n-1, k-1))%M;
	ret %= M;

	return dp[n][k] = ret;
}

int main(void){
	freopen("galactic.in", "r", stdin);
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld", &n, &k);

		if(n < k){
			printf("0\n");
		}
		else{
			memset(dp, -1, sizeof dp);
			ll ans = solve(n, k);
			printf("%lld\n", ans);
		}
	}

	return 0;
}