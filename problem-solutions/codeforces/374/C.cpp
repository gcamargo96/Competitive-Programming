#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 5002;
int n, m, t, maxtam = 0;
vector<int> g[N], peso[N];
bool vis[N];
vector<int> aux;
int res[N], frente[N];
bool ok = 0;

int dfs(int u, ll dist){
	//vis[u] = 1;

	if(u == n){
		if(aux.size() > maxtam){
			maxtam = aux.size();
		}
		return 1;
	}

	if(frente[u] != 0) return frente[u];

	For(i,0,g[u].size()){
		int v = g[u][i];
		if(/*!vis[v] and */dist+peso[u][i] <= t){
			aux.pb(v);
			frente[u] = max(frente[u], dfs(v, dist+peso[u][i]));
			aux.pop_back();
		}
	}
	return frente[u]+1;
}

void dfs2(int u, ll dist){
	//vis[u] = 1;
	if(ok) return;

	if(u == n){
		if(aux.size() == maxtam){
			printf("%d\n", maxtam);
			For(i,0,aux.size()){
				printf("%d ", aux[i]);
			}
			printf("\n");
			ok = 1;
		}
		return;
	}

	For(i,0,g[u].size()){
		if(ok) return;
		int v = g[u][i];
		if(frente[v] == frente[u]-1){
			aux.pb(v);
			dfs2(v, dist+peso[u][i]);
			aux.pop_back();
		}
	}
}

int main(void){
	scanf("%d%d%d", &n, &m, &t);

	int u, v, w;
	For(i,0,m){
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(v);
		peso[u].pb(w);
	}

	aux.pb(1);
	frente[1] = dfs(1, 0)-1;
	dfs2(1, 0);
	
	/*printf("frente: \n");
	For(i,1,n+1) printf("%d ", frente[i]);
	printf("\n");
*/
	return 0;
}

