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

const int N = 100005, L = 22;
int t, n, q;
vector<ii> adj[N], rev[N];
ll d[N], dr[N];

int anc[N][L], pai[N], lvl[N];

void init_graph(){
	for(int i = 0; i < N; i++){
		adj[i].clear();
		rev[i].clear();
	}
	memset(d, 0, sizeof d);
	memset(dr, 0, sizeof dr);
	memset(lvl, 0, sizeof lvl);
	memset(pai, -1, sizeof pai);
	memset(anc, 0, sizeof anc);
}


void precalc(){
	for(int i = 1; i <= n; i++) anc[i][0] = pai[i];

	for(int j = 1; (1<<j) <= n; j++){
		for(int i = 1; i <= n; i++){
			anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
}

void dfs(int v){
	for(int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].fi;

		if(pai[u] == -1){
			pai[u] = v;
			lvl[u] = lvl[v]+1;
			d[u] = d[v] + adj[v][i].se;
			dr[u] = dr[v] + rev[v][i].se;
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
	scanf("%d", &t);

	while(t--){
		init_graph();
		scanf("%d", &n);

		int u, v, c1, c2;
		ll total = 0;
		for(int i = 0; i < n-1; i++){
			scanf("%d%d%d%d", &u, &v, &c1, &c2);

			adj[u].pb(ii(v,c1));
			adj[v].pb(ii(u,c2));

			rev[u].pb(ii(v,c2));
			rev[v].pb(ii(u,c1));

			total += c1;
			total += c2;
		}

		pai[1] = 1;
		dfs(1);
		precalc();

		scanf("%d", &q);

		while(q--){
			scanf("%d%d", &u, &v);
			int a = lca(u,v);
			ll duv = d[u]-d[a] + dr[v]-dr[a];
			ll ans = total - duv;
			printf("%lld\n", ans);
		}
	}

	return 0;
}