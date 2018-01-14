#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

int n, m;
int dp[1<<23];
vi adj[23];
vi path;

int solve(int mask){
	if(mask == (1<<n)-1){
		return dp[mask] = 0;
	}

	if(dp[mask] != -1)
		return dp[mask];

	int ret = INF;
	for(int i = 0; i < n; i++){
		if((mask & (1<<i)) == 0)
			continue;

		int aux = 0;
		for(int j : adj[i]){
			if((mask & (1<<j)) == 0){
				aux |= (1<<j);
			}
		}

		if(aux != 0){
			ret = min(ret, solve(mask | aux) + 1);
		}
	}

	return dp[mask] = ret;
}

void get_ans(int mask){
	if(mask == (1<<n)-1)
		return;

	int ret = INF;
	for(int i = 0; i < n; i++){
		if((mask & (1<<i)) == 0)
			continue;

		int aux = 0;
		for(int j : adj[i]){
			if((mask & (1<<j)) == 0){
				aux |= (1<<j);
			}
		}

		if(aux != 0){
			if(dp[mask] == dp[mask | aux]+1){
				path.pb(i+1);
				get_ans(mask | aux);
				return;
			}
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if(m == n*(n-1)/2){
		printf("0\n");
		return 0;
	}

	memset(dp, -1, sizeof dp);
	int ans = INF;
	for(int i = 0; i < n; i++){
		ans = min(ans, solve(1<<i));
	}

	for(int i = 0; i < n; i++){
		if(dp[1<<i] == ans){
			get_ans(1<<i);
			break;
		}
	}

	printf("%d\n", ans);

	for(int u : path){
		printf("%d ", u);
	}
	printf("\n");

	return 0;
}