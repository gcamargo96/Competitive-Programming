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

const int N = 1002;
int n, m, k, u, v;
bool gov[N], vis[N];
vector<int> adj[N];
int maior = 0, mgov;
ll res = 0;

int dfs(int u){
	vis[u] = 1;

	int ret = 0;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			ret += dfs(v);
		}
	}
	return ret+1;
}

ll dfse(int u){
	vis[u] = 1;

	ll ret = 0;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			ret += dfse(v);
		}
	}

	return ret + adj[u].size();
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);
	
	For(i,0,k){
		scanf("%d", &u);
		gov[u] = 1;
	}

	For(i,0,m){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 1; i <= n; i++){
		if(gov[i] == 1){
			int tam = dfs(i);
			if(tam > maior){
				maior = tam;
				mgov = i;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			adj[i].pb(mgov);
			adj[mgov].pb(i);
			res++;
		}
	}

	memset(vis,0, sizeof vis);

	for(int i = 1; i <= n; i++){
		if(gov[i] == 1){
			ll nodes = dfs(i);
			//cout << "nodes = " << nodes << endl;
			res += (ll)nodes*(nodes-1)/2;
			memset(vis, 0, sizeof vis);
			ll e = (ll)dfse(i)/2;
			//cout << "edges = " << e << endl;
			res -= e;
		}
	}

	printf("%d\n", res);

	return 0;
}

