#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back

using namespace std;

const int N = 50005, L = 22;
int n, q;
int anc[N][L], pai[N], lvl[N];
vector <int> g[N];

void init(){
	for(int i = 0; i < n; i++) anc[i][0] = pai[i];

	for(int j = 1; (1<<j) < n; j++){
		for(int i = 0; i < n; i++){
			anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
}

void dfs(int v){
	for(int i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		if(pai[u] == -1){
			pai[u] = v;
			lvl[u] = lvl[v]+1;
			dfs(u);
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
	memset(pai, -1, sizeof pai);
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		//pai[v] = u;
	}
	
	pai[0] = 0;
	dfs(0);
	init();

	scanf("%d%d", &u, &v);

	int res = lca(u, v);
	printf("%d\n", res);

	return 0;
}
