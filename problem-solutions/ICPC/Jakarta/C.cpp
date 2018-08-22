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

const int N = 20005;
int t, n;
vi adj[N];
ll ans = 0;
ll sub[N];

void init(){
	memset(sub, 0, sizeof sub);
	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
}

void dfs(int u, int pai){
	sub[u] = 1;
	ll aux = 0;

	for(int v : adj[u]){
		if(v != pai){
			dfs(v, u);
			sub[u] += sub[v];
			aux += sub[v] * (n-1-sub[v]);
		}
	}
	aux += (n-sub[u]) * (sub[u]-1);
	aux /= 2LL;

	// printf("u = %d, aux = %lld\n", u, aux);

	ans = max(ans, aux);
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d", &n);

		int u, v;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}

		ans = 0;
		dfs(1, 0);
		
		// for(int u = 1; u <= n; u++){
		// 	printf("%d ", sub[u]);
		// }
		// printf("\n");

		printf("Case #%d: %lld\n", caso, ans);
	}

	return 0;
}