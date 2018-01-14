#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002, L = 20;
int pai[N], in[N], out[N], anc[N][L], lvl[N];
int n, m, t = 0;
vector<int> adj[N], depth[N]; // tempos de entrada de todos os nós de cada profundidade

void init(){
	for(int i = 1; i <= n; i++){
		// if(pai[i] == 0) pai[i] = -1;
		anc[i][0] = pai[i];
	}

	for(int j = 1; j < L; j++){
		for(int i = 1; i <= n; i++){
			if(anc[i][j-1] != -1)
				anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
}

int find_parent(int u, int p){
	int sum = 0;
	for(int j = L-1; j >= 0; j--){
		if((sum | (1<<j)) <= p){
			u = anc[u][j];
			sum |= (1<<j);
		}
		// if(u == -1) return u;
	}

	return u;
}

void dfs(int u, int d){

	lvl[u] = d;
	in[u] = ++t;
	depth[d].pb(in[u]);
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		dfs(v, d+1);
	}
	out[u] = ++t;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &pai[i]);
		adj[pai[i]].pb(i);
	}

	for(int i = 1; i <= n; i++){
		if(pai[i] == 0){
			dfs(i, 0);
		}
	}

	init();

	scanf("%d", &m);

	int v, p;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &v, &p);
		
		if(p > lvl[v]){
			printf("0 ");
			continue;
		}

		int u = find_parent(v, p);
	
		int d = lvl[v];
		auto up = upper_bound(depth[d].begin(), depth[d].end(), out[u]);
		auto low = upper_bound(depth[d].begin(), depth[d].end(), in[u]);
		int ans = up - low - 1;
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}