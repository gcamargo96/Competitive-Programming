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

#define M 998244353

const int N = 2005;
ll n, m, k;
int dp[N][N];

ll add(ll a, ll b){
	return (a+b)%M;
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll solve(int i, int cnt){
	if(i == n){
		if(cnt == k){
			// printf("chegou\n");
			return 1;
		}
		return 0;
	}

	if(dp[i][cnt] != -1) return dp[i][cnt];

	ll ret = solve(i+1, cnt);
	ret = add(ret, mul(m-1, solve(i+1, cnt+1)));

	return dp[i][cnt] = ret;
}

int main(void){
	scanf("%lld%lld%lld", &n, &m, &k);

	memset(dp, -1, sizeof dp);
	ll ans = mul(m, solve(1, 0));

	printf("%lld\n", ans);

	return 0;
}