#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

struct Edge{
	int u, v, w;

	Edge() {}

	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const Edge& e) const{
		return w < e.w;
	}
};

const int N = 100005;
int pai[N], Rank[N];
int n, m, k;
bool vis[N], special[N];
int ans = 0;

vector<Edge> edges;
vector<int> mst[N], peso[N];

void init() {
    for(int i=0;i<N;i++) {
        pai[i] = i;
        Rank[i] = 1;
    }
}
 
int find (int x) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(Rank[a] < Rank[b]) swap(a,b); //garanto q A é a maior arvore
    if(a != b) {
        if(Rank[a] == Rank[b]) Rank[a]++;
        pai[b] = a;
    }
}

int kruskal(){
	int total = 0;
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++){
		Edge edge = edges[i];
		if(find(edge.u) != find(edge.v)){
			mst[edge.u].pb(edge.v);
			mst[edge.v].pb(edge.u);
			peso[edge.u].pb(edge.w);
			peso[edge.v].pb(edge.w);

			join(edge.u, edge.v);
			total += edge.w;
		}
	}

	return total;
}

// void dfs(int x){
// 	vis[x] = 1;
// 	printf("%d ", x);

// 	for(int i = 0; i < mst[x].size(); i++){
// 		int nxt = mst[x][i];
// 		if(!vis[nxt]){
// 			dfs(nxt);
// 		}
// 	}
// }

void dfs(int u, int mx){
	vis[u] = 1;

	for(int i = 0; i < mst[u].size(); i++){
		int v = mst[u][i];
		int w = peso[u][i];
		mx = max(mx, w);

		if(!vis[v]){
			if(special[v]){
				ans = max(ans, mx);
			}
			dfs(v, mx);
		}
	}
}

int main(void){
	init();

	// cin >> n >> m;
	scanf("%d%d%d", &n, &m, &k);

	int x;
	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		special[x] = 1;
	}

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		edges.pb(Edge(u,v,w));
	}

	int total = kruskal();

	// dfs(u);
	// printf("\n");
	// printf("Peso total da mst = %d\n", total);

	memset(vis, 0, sizeof vis);
	for(int u = 1; u <= n; u++){
		if(special[u]){
			dfs(u, 0);

			for(int i = 0; i < k; i++){
				printf("%d ", ans);
			}
			printf("\n");
			return 0;
		}
	}

	return 0;
}