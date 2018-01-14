#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 150002;
int n, m;
vi adj[N];
bool vis[N];
vi comp;

void dfs(int u){
	vis[u] = 1;
	comp.pb(u);

	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	int u, v;
	For(i,0,m){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bool res = 1;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			For(j,0,comp.size()){
				u = comp[j];
				if(adj[u].size() != comp.size()-1){
					res = 0;
					break;
				}
			}
			if(!res) break;
		}
		comp.clear();
	}

	if(res) printf("YES\n");
	else printf("NO\n");

	return 0;
}

