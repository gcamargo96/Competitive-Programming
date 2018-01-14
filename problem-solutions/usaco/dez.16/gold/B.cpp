#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

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

struct cow{
	int x, y;
};

const int N = 2002;
cow h[N], g[N];
int pai[N], Rank[N];
int H, G;
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
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	init();
	scanf("%d%d", &H, &G);

	For(i,0,H){
		scanf("%d%d", &h[i].x, &h[i].y);
	}

	For(i,0,G){
		scanf("%d%d", &g[i].x, &g[i].y);
	}

	For(i,0,H-1){
		for(int j = i+1; j < G; j++){
			int dist = (h[i].x-g[j].x)*(h[i].x-g[j].x) + (h[i].y-g[j].y)*(h[i].y-g[j].y);
			edges.pb(Edge(i,H+j+1,dist));
		}
	}

	For(i,0,G){
		For(j,0,H){
			int dist = (g[i].x-h[j].x)*(g[i].x-h[j].x) + (g[i].y-h[j].y)*(g[i].y-h[j].y);
			edges.pb(Edge(H+i+1,j,dist));
		}
	}

	For(i,0,H-1){
		int dist = (h[i].x-h[i+1].x)*(h[i].x-h[i+1].x) + (h[i].y-h[i+1].y)*(h[i].y-h[i+1].y);
		edges.pb(Edge(i, i+1, dist));
	}

	For(i,0,G-1){
		int dist = (g[i].x-g[i+1].x)*(g[i].x-g[i+1].x) + (g[i].y-g[i+1].y)*(g[i].y-g[i+1].y);
		edges.pb(Edge(H+i+1, H+i+2, dist));	
	}

	int res = kruskal();

	printf("%d\n", res);

	return 0;
}

