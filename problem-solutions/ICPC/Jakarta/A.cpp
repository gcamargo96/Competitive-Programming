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

#define INF 1000000000000000LL

const int N = 105;
int t, n, m;
int v[N];
ll dp[N][N];

ll solve(int i, int cnt){
	if(i == n){
		if(cnt == m) return 0;
		else return INF;
	}

	if(dp[i][cnt] != -1){
		return dp[i][cnt];
	}

	ll mx = -INF, mn = INF, ret = 1000000000000000005LL;
	for(int j = i; j < n; j++){
		mn = min(mn, ll(v[j]));
		mx = max(mx, ll(v[j]));
		ret = min(ret, solve(j+1, cnt+1) + mx-mn);
	}

	return dp[i][cnt] = ret;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		sort(v, v+n);

		memset(dp, -1, sizeof dp);
		ll ans = solve(0, 0);
		printf("Case #%d: %lld\n", caso, ans);
	}

	return 0;
}