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

struct Edge{
	int u, v, w;

	Edge() {}

	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const Edge& e) const{
		return w > e.w;
	}
};

const int N = 1005;
int pai[N], Rank[N];
int n, m;
bool vis[N];

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

void dfs(int u, int p){
	pai[u] = p;

	for(int v : mst[u]){
		if(v == p) continue;

		pai[v] = u;
		dfs(v, u);
	}
}

int main(void){
	init();
	scanf("%d", &n);

	int w;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			scanf("%d", &w);
			edges.eb(i, j, w);
		}
	}

	// for(int i = 0; i < edges.size(); i++){
	// 	printf("%d %d %d\n", edges[i].u, edges[i].v, edges[i].w);
	// }

	int total = kruskal();
	printf("%d\n", total);

	dfs(1, 0);

	for(int i = 2; i <= n; i++){
		printf("%d\n", pai[i]);
	}

	return 0;
}