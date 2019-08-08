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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200005;
int n;
vi adj[N];
ll subtree[N], dp[N];
ll ans = 0;

ll dfs(int u, int p){
	subtree[u] = 1;
	for(int v : adj[u]){
		if(v == p) continue;

		subtree[u] += dfs(v, u);
	}
	return subtree[u];
}

ll precalc(int u, int p){
	dp[u] = subtree[u];
	for(int v : adj[u]){
		if(v == p) continue;
		dp[u] += precalc(v, u);
	}
	return dp[u];
}

void solve(int u, int p, ll sub_p, ll ans_p){
	ll sum_ans = ans_p, sum_sub = sub_p;
	for(int v : adj[u]){
		if(v == p) continue;
		sum_sub += subtree[v];
		sum_ans += dp[v];
	}

	// printf("u = %d, p = %d, sub_p = %lld, ans_p = %lld, sum = %lld\n", u, p, sub_p, ans_p, sum_ans);

	ans = max(ans, sum_ans+n);

	for(int v : adj[u]){
		if(v == p) continue;
		solve(v, u, sum_sub + 1 - subtree[v], sum_ans - dp[v] + sum_sub - subtree[v] + 1);
	}
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);

		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 0);
	precalc(1, 0);
	solve(1, 0, 0, 0);

	// for(int u = 1; u <= n; u++){
	// 	printf("%lld %lld\n", subtree[u], dp[u]);
	// }

	printf("%lld\n", ans);

	return 0;
}