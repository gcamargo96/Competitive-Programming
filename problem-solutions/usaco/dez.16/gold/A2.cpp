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

struct cow{
	ll x, y;
};

const int N = 1002;
cow cows[N];
int pai[N], Rank[N];
int n, m;
bool vis[N];

vector<Edge> edges;
vector<int> mst[N];
vector<ll> peso[N];

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
	int total = 0;
	sort(edges.begin(), edges.end());

	ll res = 0;
	for(int i = 0; i < edges.size(); i++){
		Edge edge = edges[i];
		if(find(edge.u) != find(edge.v)){
			mst[edge.u].pb(edge.v);
			mst[edge.v].pb(edge.u);
			peso[edge.u].pb(edge.w);
			peso[edge.v].pb(edge.w);

			join(edge.u, edge.v);
			//total += edge.w;
			res = max(res, edge.w);
		}
	}

	return res;
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
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	init();
	scanf("%d", &n);

	ll x, y;
	For(i,0,n){
		scanf("%lld%lld", &cows[i].x, &cows[i].y);
	}

	For(i,0,n){
		For(j,0,n){
			if(i != j){
				ll dist = (cows[i].x-cows[j].x)*(cows[i].x-cows[j].x) + (cows[i].y-cows[j].y)*(cows[i].y-cows[j].y);
				edges.pb(Edge(i,j,dist));
			}
		}
	}

	ll res = kruskal();

	printf("%lld\n", res);

	return 0;
}

