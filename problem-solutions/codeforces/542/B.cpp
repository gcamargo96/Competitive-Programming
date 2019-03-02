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

#define INF 1000000000000000000LL

const int N = 200005;
int n;
ii v[N];
ll dp[N];

ll solve(int i){
	if(i == n) return 0;
	if(dp[i] != -1) return dp[i];

	ll ret = INF;
	ret = min(ret, solve(i+1) + abs(v[i+1].fi - v[i].fi) + abs(v[i+1].se - v[i].se));
	ret = min(ret, solve(i+1) + abs(v[i+1].fi - v[i].se) + abs(v[i+1].se - v[i].fi));

	// printf("dp[%d] = %lld\n",i, ret);

	return dp[i] = ret;
}

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < 2*n; i++){
		scanf("%d", &x);
		if(v[x].fi == 0) v[x].fi = i+1;
		else v[x].se = i+1;
	}

	memset(dp, -1, sizeof dp);
	ll ans = solve(1) + v[1].fi-1 + v[1].se-1;

	printf("%lld\n", ans);

	return 0;
}