#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back

using namespace std;

const int N = 100002, L = 22;
int n, q;
int anc[N][L], pai[N], lvl[N];
ll dist[N];
vector <int> g[N];
vector<ll> peso[N];

void init(){
	for(int i = 0; i < n; i++) anc[i][0] = pai[i];

	for(int j = 1; (1<<j) < n; j++){
		for(int i = 0; i < n; i++){
			anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
}

void dfs(int u){
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(pai[v] == -1){
			pai[v] = u;
			lvl[v] = lvl[u]+1;
			dist[v] = dist[u] + peso[u][i];
			dfs(v);
		}
	}
}

int lca(int u, int v){
	if(lvl[u] < lvl[v]) swap(u,v);

	for(int j = L-1; j >= 0; j--){
		if(lvl[u]-(1<<j) >= lvl[v]) u = anc[u][j];
	}

	if(u == v) return u;
	for(int j = L-1; j >= 0; j--){
		if(anc[u][j] != anc[v][j]){
			u = anc[u][j];
			v = anc[v][j];
		}
	}

	return anc[u][0];
}

int main(void){
	bool flag = 1;
	while(scanf("%d", &n) && n != 0){
		/*if(!flag){
			printf("\n");
		}
		flag = 0;
		*/
		memset(pai, -1, sizeof pai);
		memset(dist, 0, sizeof dist);
		memset(lvl, 0, sizeof lvl);
		
		for(int i = 0; i < N; i++){
			g[i].clear();
			peso[i].clear();
		}

		int v;
		ll l;
		for(int i = 1; i <= n-1; i++){
			scanf("%d%lld", &v, &l);
			g[i].pb(v);
			g[v].pb(i);
			peso[i].pb(l);
			peso[v].pb(l);
		}
		
		pai[1] = 1;
		dfs(1);
		init();

		scanf("%d", &q);

		int u;
		while(q--){
			scanf("%d%d", &u, &v);
			ll ans = dist[u] + dist[v];
			int x = lca(u,v);
			ans -= 2LL*dist[x];
			printf("%lld", ans);
			if(q > 0) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
