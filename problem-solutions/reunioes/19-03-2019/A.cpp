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

struct Edge{
	int u, v, id;
	ll w, c;

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

const int N = 200005, L = 22;
int n, q, m;
int anc[N][L], pai[N], lvl[N], Rank[N];
ll maxw[N][L], wpai[N];
// vector <int> g[N];
bool vis[N];
vector<Edge> edges, e_mst, non_mst;
vector<int> mst[N], peso[N];
int w[N], c[N];
ll s;

void init_lca(){
	for(int i = 0; i < n; i++){
		anc[i][0] = pai[i];
		maxw[i][0] = wpai[i];
	}

	for(int j = 1; (1<<j) < n; j++){
		for(int i = 0; i < n; i++){
			maxw[i][j] = max(maxw[i][j-1], maxw[anc[i][j-1]][j-1]);
			anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
}

void dfs(int u){
	vis[u] = 1;

	for(int i = 0; i < mst[u].size(); i++){
		int v = mst[u][i];
		int w = peso[u][i];
		if(!vis[v]){
			pai[v] = u;
			wpai[v] = w;
			lvl[v] = lvl[u]+1;
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

ll get_max_w(int u, int v){
	if(lvl[u] < lvl[v]) swap(u,v);

	ll ret = 0;
	for(int j = L-1; j >= 0; j--){
		if(lvl[u]-(1<<j) >= lvl[v]){
			ret = max(ret, maxw[u][j]);
			u = anc[u][j];
		}
	}

	if(u == v) return ret;
	for(int j = L-1; j >= 0; j--){
		if(anc[u][j] != anc[v][j]){
			ret = max(ret, maxw[u][j]);
			ret = max(ret, maxw[v][j]);
			u = anc[u][j];
			v = anc[v][j];
		}
	}

	ret = max(ret, maxw[u][0]);
	ret = max(ret, maxw[v][0]);

	return ret;
}

void init_kruskal() {
	e_mst.clear();
	non_mst.clear();

    for(int i=0;i<N;i++) {
        pai[i] = i;
        Rank[i] = 1;
    	mst[i].clear();
    	peso[i].clear();
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

ll kruskal(){
	ll total = 0;
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++){
		Edge edge = edges[i];
		// printf("edge = %d %d %lld\n", edge.u, edge.v, edge.w);

		if(find(edge.u) != find(edge.v)){
			mst[edge.u].pb(edge.v);
			mst[edge.v].pb(edge.u);
			peso[edge.u].pb(edge.w);
			peso[edge.v].pb(edge.w);
			e_mst.pb(edge);

			join(edge.u, edge.v);
			total += edge.w;
		}
		else{
			non_mst.pb(edge);
		}
	}

	return total;
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &c[i]);
	}

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		u--, v--;
		edges.eb(u, v, w[i]);
		edges[i].c = c[i];
		edges[i].id = i;
	}

	scanf("%lld", &s);

	init_kruskal();
	ll total = kruskal();

	dfs(0);
	init_lca();

	ll ans = total;
	int chosen_road = -1;
	ll dissatisfaction = -1;

	for(int i = 0; i < e_mst.size(); i++){
		ll reduce = (s/e_mst[i].c);
		// ans = min(ans, total - reduce);

		if(total - reduce < ans){
			ans = total - reduce;
			chosen_road = e_mst[i].id;
			dissatisfaction = e_mst[i].w - reduce;
		}
	}

	for(int i = 0; i < non_mst.size(); i++){
		ll reduce = (s/non_mst[i].c);

		ll max_w = get_max_w(non_mst[i].u, non_mst[i].v);

		// ans = min(ans, total + non_mst[i].w - reduce - max_w);
		
		if(total + non_mst[i].w - reduce - max_w < ans){
			ans = total + non_mst[i].w - reduce - max_w;
			chosen_road = non_mst[i].id;
			dissatisfaction = non_mst[i].w - reduce;
		}
	}

	printf("%lld\n", ans);
	// printf("dissatisfaction = %lld\n", dissatisfaction);
	// printf("choosen road = %d\n", chosen_road);

	// edges[chosen_road].w = dissatisfaction;
	for(int i = 0; i < edges.size(); i++){
		if(edges[i].id == chosen_road){
			edges[i].w = dissatisfaction;
			break;
		}
	}

	init_kruskal();
	kruskal();
	

	for(int i = 0; i < e_mst.size(); i++){
		printf("%d %lld\n", e_mst[i].id+1, e_mst[i].w);
	}

	return 0;
}