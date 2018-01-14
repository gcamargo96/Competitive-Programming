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

const int N = 2002;
int pai[N], rank[N];
int n;
int mat[N][N], d[N][N];
bool vis[N];
bool res = 1;

vector<Edge> edges;
vector<int> mst[N], peso[N];

int init() {
    for(int i=0;i<N;i++) {
        pai[i] = i;
        rank[i] = 1;
    }
}
 
int find (int x) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
 
int join(int a, int b){
    a = find(a);
    b = find(b);
    if(rank[a] < rank[b]) swap(a,b); //garanto q A é a maior arvore
    if(a != b) {
        if(rank[a] == rank[b]) rank[a]++;
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

void dfs(int u, int origem, int p, ll dist){
	d[origem][u] = dist;

	For(i,0,mst[u].size()){
		int v = mst[u][i];
		if(v == p) continue;
		dfs(v, origem, u, dist+peso[u][i]);
	}
}

int main(void){
	init();
	cin >> n;

	For(i,1,n+1){
		For(j,1,n+1){
			//cin >> mat[i][j];
			scanf("%d", &mat[i][j]);
		}
	}

	For(i,1,n+1){
		if(mat[i][i] != 0){
			res = 0;
			break;
		}
	}

	For(i,2,n+1){
		For(j,1,i){
			if(mat[i][j] != mat[j][i] or mat[i][j] == 0){
				res = 0;
				break;
			}
			edges.pb(Edge(i, j, mat[i][j]));
		}
	}

	if(!res){
		//cout << "NO" << endl;
		printf("NO\n");
		return 0;
	}

	kruskal();

	For(i,1,n+1){
		dfs(i, i, -1, 0);
	}

	For(i,2,n+1){
		For(j,1,i){
			if(mat[i][j] != d[i][j]){
				res = 0;
				break;
			}
		}
		if(!res) break;
	}

	if(res) printf("YES\n");
	else printf("NO\n");

	return 0;
}
