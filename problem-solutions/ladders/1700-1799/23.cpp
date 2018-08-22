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

const int N = 100005;
int n;
ll decr[N], inc[N], val[N];
vi adj[N];

void dfs(int u, int p){
	for(int v : adj[u]){
		if(v == p) continue;
		dfs(v, u);
		decr[u] = max(decr[u], decr[v]);
		inc[u] = max(inc[u], inc[v]);
	}

	val[u] = val[u] + inc[u] - decr[u];
	if(val[u] > 0) decr[u] += val[u];
	else inc[u] += -val[u];
}

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 1; i <= n; i++){
		scanf("%lld", &val[i]);
	}

	dfs(1, 0);
	ll ans = inc[1] + decr[1];

	// for(int i = 1; i <= n; i++){
	// 	printf("%lld %lld\n", decr[u], inc[u]);
	// }

	printf("%lld\n", ans);

	return 0;
}