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

const int N = 2005;
vi adj[2*N], rev[2*N];
int t, n, m, tempo, comp;
bool vis[2*N];
int color[N];
vi nodes;

void init(){
	memset(vis, 0, sizeof vis);
	memset(color, 0, sizeof color);
	for(int i = 0; i < N; i++){
		adj[i].clear();
		rev[i].clear();
	}
}

int ID(int a){
	return 2*a;
}

int NOT(int a){
	return 2*a+1;
}

void add_edge(int u, int v){
	adj[u].pb(v);
	rev[v].pb(u);
}

void add_xor(int a, int b){
	add_edge(NOT(a), ID(b));
	add_edge(NOT(b), ID(a));

	add_edge(ID(a), NOT(b));
	add_edge(ID(b), NOT(a));
}

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	nodes.pb(u);
}

void dfs_rev(int u){
	vis[u] = 1;
	color[u] = comp;

	// printf("coloriu %d de %d\n", u, comp);

	for(int v : rev[u]){
		if(!vis[v]){
			dfs_rev(v);
		}
	}
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d", &n, &m);

		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			add_xor(u, v);
		}


		tempo = 0;
		memset(vis, 0, sizeof vis);
		for(int u = 1; u <= n; u++){
			if(!vis[ID(u)]){
				dfs(ID(u));
			}
			if(!vis[NOT(u)]){
				dfs(NOT(u));
			}
		}

		// printf("nodes:\n");
		// for(int i = 0; i < nodes.size(); i++){
		// 	printf("%d ", nodes[i]);
		// }
		// printf("\n");

		comp = 0;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < nodes.size(); i++){
			int u = nodes[i];
			if(!vis[u]){
				comp++;
				dfs_rev(u);
			}
		}

		// for(int u = 1; u <= n; u++){
		// 	printf("%d %d\n", color[ID(u)], color[NOT(u)]);
		// }

		bool ok = 1;
		for(int u = 1; u <= n; u++){
			if(color[ID(u)] == color[NOT(u)]){
				ok = 0;
				break;
			}
		}

		printf("Scenario #%d:\n", caso);
		if(ok){
			printf("No suspicious bugs found!\n");
		}
		else{
			printf("Suspicious bugs found!\n");
		}
	}

	return 0;
}