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
	int u, v;
	ll w;

	Edge() {}

	Edge(int _u, int _v, ll _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const Edge& e) const{
		return w < e.w;
	}
};

const int N = 100002;
int pai[N], Rank[N];
int n, m;
bool vis[N];

vector<Edge> edges;
vector<int> mst[N], peso[N];

int init() {
    for(int i=0;i<N;i++) {
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

ll kruskal(){
	ll total = 0;
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

void dfs(int x){
	vis[x] = 1;
	printf("%d ", x);

	for(int i = 0; i < mst[x].size(); i++){
		int nxt = mst[x][i];
		if(!vis[nxt]){
			dfs(nxt);
		}
	}
}

int main(void){
	init();

	cin >> n >> m;

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		edges.pb(Edge(u,v,w));
	}

	ll total = kruskal();

	// dfs(u);
	// printf("\n");
	// printf("Peso total da mst = %d\n", total);

	printf("%lld\n", total);

	return 0;
}