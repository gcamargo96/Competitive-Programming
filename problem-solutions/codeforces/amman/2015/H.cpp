#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define N 100005

vi adj[N];
int dfsnum[N], low[N], p[N], pai[N], Rank[N], dist[N], vis[N];
int n, m, t, tests;
int bridges = 0;
map<int, set<int> > adj2;

void init(bool flag){
	t = bridges = 0;

	memset(dfsnum, 0, sizeof dfsnum);
	memset(low, 0, sizeof low);
	memset(p, 0, sizeof p);

	if(flag == 1){
		adj2.clear();
	}

	for(int i = 0; i < N; i++){
		if(flag == 1){
			adj[i].clear();
		}
		pai[i] = i;
		Rank[i] = 1;
	}
}

int find (int x) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
 
int join(int a, int b){
    a = find(a);
    b = find(b);
    if(Rank[a] < Rank[b]) swap(a,b); //garanto q A é a maior arvore
    if(a != b) {
        if(Rank[a] == Rank[b]) Rank[a]++;
        pai[b] = a;
    }
}

void dfs( int u ) {

	dfsnum[ u ] = ++t;
	low[ u ] = dfsnum[u];

	int children = 0;
	for(int v:adj[u])
		if( dfsnum[ v ]==0 )
		{
			p[v] = u;
			dfs( v );
			low[u] = min( low[u], low[v] );

			if(low[v] > dfsnum[u] ){ // se for uma ponte
				bridges++;
			}
			else{ // se nao for uma ponte
				join(u,v);
			}
		}
		else if( v != p[u] )
			low[u]= min( low[u], dfsnum[v] );
}

void dfs2(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v]){
			if(find(u) == find(v)){
				dist[v] = dist[u];
			}
			else{
				dist[v] = dist[u]+1;
			}
			dfs2(v);
		}
	}
}

void diam(){
	memset(vis, 0, sizeof vis);
	memset(dist, INF, sizeof dist);
	dist[1] = 0;
	dfs2(1);

	int mx = 0, u = 1, v = 1;
	for(int i = 1; i <= n; i++){
		if(dist[i] > mx){
			mx = dist[i];
			u = i;
		}
	}

	memset(vis, 0, sizeof vis);
	memset(dist, INF, sizeof dist);
	dist[u] = 0;
	dfs2(u);

	mx = 0, v = 1;
	for(int i = 1; i <= n; i++){
		if(dist[i] > mx){
			mx = dist[i];
			v = i;
		}
		if(dist[i] == mx and !adj2[u].count(i)){
			v = i;
		}
	}

	// printf("join %d, %d\n", u, v);
	adj[u].pb(v);
	adj[v].pb(u);
}

int main(void){
	scanf("%d", &tests);

	while(tests--){
		init(1);
		scanf("%d%d", &n, &m);

		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj2[u].insert(v);
			adj[v].pb(u);
			adj2[v].insert(u);
		}

		dfs(1);
		diam();

		// for(int i = 1; i <= n; i++){
		// 	printf("%d ", dist[i]);
		// }
		// printf("\n");

		init(0);
		dfs(1);

		printf("%d\n", bridges);
	}

	return 0;
}