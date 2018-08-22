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

const int N = 205;
int pai[N], Rank[N];
int t, n, m, k;
bool vis[N];

vector<Edge> edges;
vector<int> mst[N], peso[N];

void init() {
	edges.clear();
    for(int i=0;i<N;i++) {
        pai[i] = i;
        Rank[i] = 1;
        vis[i] = 0;
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

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		init();
		scanf("%d%d%d", &n, &m, &k);

		int p;
		set<int> power;
		for(int i = 0; i < k; i++){
			scanf("%d", &p);
			power.insert(p);	
		}

		int u, v, w;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			if(power.count(u)) u = 0;
			if(power.count(v)) v = 0;
			edges.pb(Edge(u,v,w));
		}

		int total = kruskal();
		printf("Case #%d: %d\n", caso, total);
	}

	return 0;
}