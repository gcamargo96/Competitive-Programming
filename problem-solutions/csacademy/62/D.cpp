#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1003;
int n, m, q;
vi adj[N];
int vis[N], in[N], out[N], low[N], pai[N];
int tempo = 0;
int s, t;

void init(){
/*	for(int i = 0; i < N; i++){
		adj[i].clear();
	}
*/

	memset(vis, 0, sizeof vis);
	memset(in, 0, sizeof in);
	memset(out, 0, sizeof out);
	memset(low, 0, sizeof low);

	tempo = 0;
}

bool dfs(int u, int p){
	vis[u] = 1;
	low[u] = in[u] = tempo++;
	pai[u] = p;
	// int nc = 0;

	bool ret = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];

		if(!vis[v]){
			dfs(v, u);
			
			// nc++;
			if(low[v] > in[u]){ // mudar para >= se quiser achar vertices de articulação
				// ans.pb(ii(min(u,v),max(u,v)));
			}
			low[u] = min(low[u], low[v]);
		}
		else if(v != p){
			low[u] = min(low[u], in[v]);
		}
	}

	out[u] = tempo++;
	return ret;
}

int main(void){
	scanf("%d%d%d", &n, &m, &q);

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 0; i < q; i++){
		scanf("%d%d", &s, &t);
		init();
		dfs(s, 0);

		int ans = 1;
		for(int v = t; v != s; v = pai[v]){
			int u = pai[v];
			if(!(low[v] > in[u])){
				ans = 0;
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}